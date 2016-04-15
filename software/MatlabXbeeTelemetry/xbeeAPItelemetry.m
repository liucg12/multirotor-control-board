if exist('COM')
    fclose(COM);
    delete(COM);
    clear COM;
end

clear all

global COM;

COM = serial('COM19');
set(COM,'BaudRate', 115200);
COM.DataBits = 8;
COM.Parity = 'none';
COM.StopBits = 1;
fopen(COM);

xbeeAdresses{1} = [0 hex2dec('13') hex2dec('A2') 0 hex2dec('40') hex2dec('B5') hex2dec('99') hex2dec('BF')];
xbeeAdresses{2} = [0 hex2dec('13') hex2dec('A2') 0 hex2dec('40') hex2dec('B5') hex2dec('99') hex2dec('B4')];
xbeeAdresses{3} = [0 hex2dec('13') hex2dec('A2') 0 hex2dec('40') hex2dec('B5') hex2dec('99') hex2dec('BD')];
xbeeAdresses{4} = [0 hex2dec('13') hex2dec('A2') 0 hex2dec('40') hex2dec('B5') hex2dec('99') hex2dec('BB')];

cibulka = 1;

figure(1);

while COM.bytesavailable > 0
    
    nic = fread(COM, 1);
    
end

timeStamps(1, 1:4) = 0;

startTime = posixtime(datetime);

while true
    
    actualTime = posixtime(datetime) - startTime;
    
    for i=1:3
        if ((posixtime(datetime) - (4+i*0.5)) > timeStamps(i))

            packet = createTRPacket(xbeeAdresses{i}, ['M' typecast(uint32(actualTime), 'uint8')]);
            
            fprintf('UAV %d is out\n', i);
            
            % clear the figure             
            if (i == 1) || (i == 4)
                
                subplot(1, 3, 2);
                cla
                axis off
                drawnow;
                
            elseif (i == 2)
                
                subplot(1, 3, 1);
                cla
                axis off
                drawnow;
                
            elseif (i == 3)
                
                subplot(1, 3, 3);
                cla
                axis off
                drawnow;
                
            end
            
            write(packet);
            timeStamps(i) = posixtime(datetime);
       end
    end
        
   if COM.bytesavailable > 0
       
        packetIN = fread(COM, 1); 
        
        if packetIN==hex2dec('7E')
            
            hlp = fread(COM, 2)';
            packetIN = [packetIN hlp];
            hlp = fread(COM, packetIN(3) + 1)'; 
            packetIN = [packetIN hlp];
            dec2hex(packetIN);
            data = packetIN(16:end-1);
            from = packetIN(12);
            
            if (data(1) == 88)
               fprintf('broadcast');
               continue; 
            end
            
            numOfBlobs = data(2);

            idx = 3;
            
            posx = typecast(uint8(data(idx:idx+3)), 'single');
            idx = idx + 4;
            posy = typecast(uint8(data(idx:idx+3)), 'single');
            idx = idx + 4;
            
            setx = typecast(uint8(data(idx:idx+3)), 'single');
            idx = idx + 4;
            sety = typecast(uint8(data(idx:idx+3)), 'single');
            idx = idx + 4;
            
            if (from == hex2dec('B4'))
                subplot(1, 3, 1);
                packet = createTRPacket(xbeeAdresses{2}, ['M' typecast(uint32(actualTime), 'uint8')]);
                timeStamps(2) = posixtime(datetime);
                fprintf('received telemetry\n');
            elseif (from == hex2dec('BD'))
                subplot(1, 3, 3);
                packet = createTRPacket(xbeeAdresses{3}, ['M' typecast(uint32(actualTime), 'uint8')]);
                timeStamps(3) = posixtime(datetime);
            elseif (from == hex2dec('BF'))
                subplot(1, 3, 2);
                packet = createTRPacket(xbeeAdresses{1}, ['M' typecast(uint32(actualTime), 'uint8')]);
                timeStamps(1) = posixtime(datetime);
            elseif (from == hex2dec('BB'))
                subplot(1, 3, 2);
                packet = createTRPacket(xbeeAdresses{4}, ['M' typecast(uint32(actualTime), 'uint8')]);
                timeStamps(4) = posixtime(datetime);
            end
            
            hold off
            plot(0, 0);
            hold on
            drawUAV(-posy, posx, numOfBlobs);

            blobs = zeros(2, numOfBlobs);
            for i=1:numOfBlobs
               for j=1:2
                  blobs(j, i) = typecast(uint8(data(idx:idx+3)), 'single');
                  idx = idx + 4;
               end
               
               if (i == 1)
                blobColor = 'r';
               elseif (i == 2)
                blobColor = 'b';
               elseif (i == 3)
                blobColor = 'k';
               end
             
               scatter(-blobs(2, i)-posy, blobs(1, i)+posx, 150, blobColor, 'filled'); 
            end
            
            scatter(-sety, setx, 75, 'k', 'filled'); 
            
            blobs;
            osy = 4;
            axis([-posy-osy, -posy+osy, posx-osy, posx+osy]);
            axis equal;
            set(gca,'xtick',[(round(-posy)-2*osy):1:(round(-posy)+2*osy)]);
            set(gca,'ytick',[(round(posx)-2*osy):1:(round(posx)+2*osy)]);
            grid on;
            drawnow;
            
            write(packet);
                       
        end  
        
   end     
   
end

