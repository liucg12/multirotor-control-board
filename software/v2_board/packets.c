#include <stdio.h>
#include "packets.h"
#include "defines.h"
#include "commands.h"
#include "commTask.h"
#include "usart_driver_RTOS.h"

extern UsartBuffer * usart_buffer_4;
extern volatile unsigned char trajMaxIndex;




ADDRESST ADDRESS;
TELEMETRIEST TELEMETRIES;
TELREQOPTT TELREQOPT;
LANDINGT LANDING;
TRAJECTORYT TRAJECTORY;
SETPOINTST SETPOINTS;
POSITIONST POSITIONS;
CONTROLLERST CONTROLLERS;
GESTUREST GESTURES;
COMMANDST COMMANDS;
unsigned char GET_STATUS;

void adr64Setter(unsigned char * adr,unsigned char b1,unsigned char b2,unsigned char b3,unsigned char b4,unsigned char b5,unsigned char b6,unsigned char b7,unsigned char b8){
    *adr=b1; *(adr+1)=b2; *(adr+2)=b3; *(adr+3)=b4; *(adr+4)=b5; *(adr+5)=b6; *(adr+6)=b7; *(adr+7)=b8;
}

void constInit(){
    adr64Setter(ADDRESS.COORDINATOR,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00);
    adr64Setter(ADDRESS.KC1,0x00,0x13,0xA2,0x00,0x40,0xB5,0x99,0xB9);
    adr64Setter(ADDRESS.K1,0x00,0x13,0xA2,0x00,0x40,0xB5,0x99,0xBF);
    adr64Setter(ADDRESS.BROADCAST,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF);
    ADDRESS.UNKNOWN16[0] = 0xFF;
    ADDRESS.UNKNOWN16[1] = 0xFE;

    TELEMETRIES.GROUND_DISTANCE = 0x01;
	TELEMETRIES.ELEVATOR_SPEED = 0x02;
	TELEMETRIES.AILERON_SPEED = 0x03;
	TELEMETRIES.ELEVATOR_SPEED_ESTIMATED=0x04;
	TELEMETRIES.AILERON_SPEED_ESTIMATED=0x05;
	TELEMETRIES.ELEVATOR_POS_ESTIMATED=0x06;
	TELEMETRIES.AILERON_POS_ESTIMATED=0x07;

    TELREQOPT.SENDING_OFF = 0x00;
    TELREQOPT.SENDING_ON = 0x01;
    TELREQOPT.SENDING_ONCE = 0x02;
    TELREQOPT.SENDING_STATUS = 0x00;
	
	LANDING.LAND_ON=0x00;
	LANDING.LAND_OFF=0x01;
	
	TRAJECTORY.FOLLOW=0x01;
	TRAJECTORY.NOT_FOLLOW=0x02;
	
	SETPOINTS.THROTTLE=0x01;
	SETPOINTS.ELEVATOR=0x02;
	SETPOINTS.AILERON=0x03;
	
	POSITIONS.ABSOLUT=0x01;
	POSITIONS.RELATIV=0x02;
	
	CONTROLLERS.OFF=0x01;
	CONTROLLERS.VELOCITY=0x02;
	CONTROLLERS.POSITION=0x03;
	
	GESTURES.ARM=0x01;
	GESTURES.DISARM=0x02;
	
	COMMANDS.LANDING=0x11;
	COMMANDS.SET_SETPOINTS=0x12;
	COMMANDS.CONTROLLERS=0x13;
	COMMANDS.GESTURES=0x14;
	COMMANDS.TRAJECTORY=0x15;
	COMMANDS.TRAJECTORY_POINTS=0x16;
	
	GET_STATUS=0x95;
}


void packetHandler(unsigned char *inPacket){
    unsigned char address16[2];
    unsigned char address64[8];
    unsigned char recieveOptions[5];
    unsigned char data[25];
	
	float *f1;
	float *f2;
	float *f3;
	float *f4;
	int8_t i;
	char ch1[4];
	char ch2[4];
	char ch3[4];
	char ch4[4];

    switch ((int)*(inPacket+3)) {
    //Modem Status
    case 0x8A:

        break;
    //Transmit Status
    case 0x8B:
        parTSPacket(inPacket,recieveOptions,address16,recieveOptions+1,recieveOptions+2,recieveOptions+3);        
        break;
    //Route record indicator
    case 0xA1:
        break;
    //Receive Packet
    case 0x90:
            parReceivePacket(inPacket,address64,address16,recieveOptions,data);
            //*data is data length
            switch ((int)*(data+1)){
                //command
                case 'c':

                        //TELEMETRY REQUESTS						
                        if(*(data+2)<0x10){
                            //telemetry request options
							//TODO
                            if(      *(data+3)==TELREQOPT.SENDING_OFF){

                            }else if(*(data+3)==TELREQOPT.SENDING_ON){

                            }else if(*(data+3)==TELREQOPT.SENDING_ONCE){ 								            
                                telemetrySend(address64,address16,*(data+2),0x01);
                            }else if(*(data+3)==TELREQOPT.SENDING_STATUS){

                            }
                        } else
						//LANDING REQUEST
						if(*(data+2)==COMMANDS.LANDING){
							if(		 *(data+3)==LANDING.LAND_ON){
								kopterLand(address64,address16,1);
								kopterLandReport(address64,address16,0x01);
								
							}else if(*(data+3)==LANDING.LAND_OFF){
								kopterLand(address64,address16,0);
								kopterLandReport(address64,address16,0x01);
								
							}else if(*(data+3)==GET_STATUS){
								kopterLandReport(address64,address16,0x01);								
							}
						} else
						//TRAJECTORY FOLLOW REQUEST
						if(*(data+2)==COMMANDS.TRAJECTORY){
							if(		 *(data+3)==TRAJECTORY.FOLLOW){
								kopterTrajectory(address64,address16,1);
								kopterTrajectoryReport(address64,address16,0x01);
								
							}else if(*(data+3)==TRAJECTORY.NOT_FOLLOW){
								kopterTrajectory(address64,address16,0);
								kopterTrajectoryReport(address64,address16,0x01);
								
							}else if(*(data+3)==GET_STATUS){
								kopterTrajectoryReport(address64,address16,0x01);								
							}
						} else
						//TRAJECTORY ADD POINT REQUEST
						if(*(data+2)==COMMANDS.TRAJECTORY_POINTS){
							if(		 *(data+3)==GET_STATUS){								
								if(*(data+4)==0){
									for(i=1;i<=trajMaxIndex;i++){
										kopterTrajectoryPointReport(address64,address16,i,0x01);
									}
								}else{
									kopterTrajectoryPointReport(address64,address16,i,0x01);
								}
							}else{								
								ch1[0]=*(data+5); ch1[1]=*(data+6); ch1[2]=*(data+7); ch1[3]=*(data+8); f1=(float *)ch1;
								ch2[0]=*(data+9); ch2[1]=*(data+10); ch2[2]=*(data+11); ch2[3]=*(data+12); f2=(float *)ch2;
								ch3[0]=*(data+13); ch3[1]=*(data+14); ch3[2]=*(data+15); ch3[3]=*(data+16); f3=(float *)ch3;
								ch4[0]=*(data+17); ch4[1]=*(data+18); ch4[2]=*(data+19); ch4[3]=*(data+20); f4=(float *)ch4;
								kopterTrajectoryAddPoint(address64,address16,*(data+4),*f1,*f2,*f3,*f4);	
								if (*(data+4)==0){
									kopterTrajectoryPointReport(address64,address16,trajMaxIndex,0x01);
								}else{
									kopterTrajectoryPointReport(address64,address16,*(data+4),0x01);
								}															
							}
						} else												
						//SETPOINTS REQUEST
						if(*(data+2)==COMMANDS.SET_SETPOINTS){
							if(*(data+4)==GET_STATUS){
								kopterSetpointsReport(address64,address16,*(data+3),0x12);
							}else{
								ch1[0]=*(data+5);
								ch1[1]=*(data+6);
								ch1[2]=*(data+7);
								ch1[3]=*(data+8);
								f1=(float *)ch1;
								kopterSetpointsSet(address64,address64,*(data+3),*(data+4),*f1);
								kopterSetpointsReport(address64,address16,*(data+3),0x12);
							}
						}else
						//CONTROLLERS ON/OFF
						if(*(data+2)==COMMANDS.CONTROLLERS){
							if(*(data+3)==GET_STATUS){
								kopterControllersReport(address64,address16,0x13);
							}else{
								kopterControllers(address64,address16,*(data+3));
								kopterControllersReport(address64,address16,0x13);
							}															
						}else
						//GESTURES
						if(*(data+2)==COMMANDS.GESTURES){
							kopterGesture(address64,address16,*(data+3));
						}
                    break;
                //telemetry
                case 't':                                                                       
                        ch1[0]=*(data+3);
                        ch1[1]=*(data+4);
                        ch1[2]=*(data+5);
                        ch1[3]=*(data+6);
                        f1=(float *)ch1;                                
                        telemetryReceive(address64,address16,*(data+2),*f1);
                    break;
                //report
                case 'r':
						 //LANDING STATUS	
				         if(*(data+2)==COMMANDS.LANDING){
					         kopterLandReportRecieved(address64,address16,*(data+3));
				         } else
						 //TRAJECTORY FOLLOW STATUS
						 if(*(data+2)==COMMANDS.TRAJECTORY){
							 kopterTrajectoryReportRecieved(address64,address16,*(data+3));
						 } else
						 //TRAJECTORY POINTS
				         if(*(data+2)==COMMANDS.TRAJECTORY_POINTS){							 
							 ch1[0]=*(data+4); ch1[1]=*(data+5); ch1[2]=*(data+6); ch1[3]=*(data+7); f1=(float *)ch1;
							 ch2[0]=*(data+8); ch2[1]=*(data+9); ch2[2]=*(data+10); ch2[3]=*(data+11); f2=(float *)ch2;
							 ch3[0]=*(data+12); ch3[1]=*(data+13); ch3[2]=*(data+14); ch3[3]=*(data+15); f3=(float *)ch3;
							 ch4[0]=*(data+16); ch4[1]=*(data+17); ch4[2]=*(data+18); ch4[3]=*(data+19); f4=(float *)ch4;
							 kopterTrajectoryPointReportReceived(address64,address16,*(data+3),*f1,*f2,*f3,*f4);
				         } else
						 //SETPOINTS STATUS
						 if(*(data+2)==COMMANDS.SET_SETPOINTS){
							ch1[0]=*(data+4);
							ch1[1]=*(data+5);
							ch1[2]=*(data+6);
							ch1[3]=*(data+7);
							f1=(float *)ch1;  
							kopterSetpointsReportReceived(address64,address16,*(data+3),*f1);
						 }else
						 //CONTROLLERS STATUS
						 if(*(data+2)==COMMANDS.CONTROLLERS){
							kopterControllersReportReceived(address64,address16,*(data+3));
						 }
                    break;
                //warning
                case 'w':
                    break;
                //error
                case 'e':                   
                    break;
                default:
                        dataTypeError(address64,address16,data);
                    break;
            }
        break;
    default:
           packetTypeError(inPacket);
        break;
    }

}


void strInsert(unsigned char *str,unsigned char start,unsigned char *ins, unsigned char insLength){
    int i;
    for (i=0 ; i<insLength ; i++){
            *(str+start+i)=*(ins+i);
    }
}

//create Transmit Request Packet 0x10
void makeTRPacket(unsigned char *adr64,unsigned char *adr16,unsigned char options,unsigned char frameID,unsigned char *data, unsigned char dataLength){
        unsigned char outPacket[60];
        int i=0;
        //initial byte
        *outPacket=0x7E;
        //length
        *(outPacket+1)=0x00;
        *(outPacket+2)=14+dataLength;
        //frame type
        *(outPacket+3)=0x10;
        //frame ID
        *(outPacket+4)=frameID;
        //addresses
        strInsert(outPacket,5,adr64,8);
        strInsert(outPacket,13,adr16,2);
        //Broadcast Radius
        *(outPacket+15)=0x00;
        /*Options
        0x01 - Disable retries and route repair
        0x20 - Enable APS encryption (if EE=1)
        0x40 - Use the extended transmission timeout*/
        *(outPacket+16)=options;
        //data
        strInsert(outPacket,17,data,dataLength);
        //checksum
        *(outPacket+17+dataLength)=0xFF;
        for (i=3; i<17+dataLength; i++){
            *(outPacket+17+dataLength)=*(outPacket+17+dataLength)-*(outPacket+i);
        }
        *(outPacket+18+dataLength)=0x00;
        sendXBeePacket(outPacket);
}

//parse Modem Status 0x8A
void parMSPacket(unsigned char *inPacket,unsigned char *status){
    *status=*(inPacket+4);
    /*0 = Hardware reset
    1 = Watchdog timer reset
    2 =Joined network (routers and end devices)
    3 =Disassociated
    6 =Coordinator started
    7 = Network security key was updated
    0x0D = Voltage supply limit exceeded (PRO S2B only)
    0x11 = Modem configuration changed while join in progress
    0x80+ = stack error*/
}

//parse Transmit Status 0x8B
void parTSPacket(unsigned char *inPacket,unsigned char *frameID,unsigned char *address16,unsigned char *TrRetryCount,unsigned char *deliveryStatus,unsigned char *discoveryStatus){
    *frameID=*(inPacket+4);
    *address16=*(inPacket+5);
    *(address16+1)=*(inPacket+6);
    *TrRetryCount=*(inPacket+7);
    *deliveryStatus=*(inPacket+8);
    /*0x00 = Success
    0x01 = MAC ACK Failure
    0x02 = CCA Failure
    0x15 = Invalid destination endpoint
    0x21 = Network ACK Failure
    0x22 = Not Joined to Network
    0x23 = Self-addressed
    0x24 = Address Not Found
    0x25 = Route Not Found
    0x26 = Broadcast source failed to hear a neighbor relay the message
    0x2B = Invalid binding table index
    0x2C = Resource error lack of free buffers, timers, etc.
    0x2D = Attempted broadcast with APS transmission
    0x2E = Attempted unicast with APS transmission, but EE=0
    0x32 = Resource error lack of free buffers, timers, etc.
    0x74 = Data payload too large*/
    *discoveryStatus=*(inPacket+9);
    /*0x00 = No Discovery Overhead
    0x01 = Address Discovery
    0x02 = Route Discovery
    0x03 = Address and Route
    0x40 = Extended Timeout Discovery*/
}

//parse Receive Packet 0x90
void parReceivePacket(unsigned char *inPacket,unsigned char *address64,unsigned char *address16,unsigned char *receiveOptions,unsigned char *data){
    int i=0;
    for (i=0 ; i<8 ; i++){
        *(address64+i)=*(inPacket+4+i);
    }
    for (i=0 ; i<2 ; i++){
        *(address16+i)=*(inPacket+12+i);
    }
    *receiveOptions=*(inPacket+14);
    /*0x01 - Packet Acknowledged
    0x02 - Packet was a broadcast packet
    0x20 - Packet encrypted with APS encryption
    0x40 - Packet was sent from an end device (if known)*/

    //the *data is dataLength
    *data=*(inPacket+2)-12;
    for (i=0 ; i<*data ; i++){
        *(data+i+1)=*(inPacket+15+i);
    }

}


