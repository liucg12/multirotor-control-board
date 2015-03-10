#ifndef COMMANDS_H
#define COMMANDS_H

float telemetryValue(unsigned char type);

void telemetryToCoordinatorSend();
void telemetryToCoordinatorSet(unsigned char *address64,unsigned char *address16,unsigned char type,unsigned char on, unsigned char frameID);
void telemetryToCoordinator(unsigned char *address64,unsigned char *address16,unsigned char type,unsigned char on);
void telemetryToCoordinatorStatusRequest(unsigned char *address64,unsigned char *address16,unsigned char type,unsigned char frameID);
void telemetryToCoordinatorReport(unsigned char *address64,unsigned char *address16,unsigned char type,unsigned char frameID);
void telemetryToCoordinatorReportRecieved(unsigned char *address64,unsigned char *address16,unsigned char type,unsigned char status);

void dataTypeError(unsigned char *address64,unsigned char *address16,unsigned char *data);
void packetTypeError(unsigned char *inPacket);

void kopterLandRequest(unsigned char *address64,unsigned char *address16,unsigned char options,unsigned char frameID);
void kopterLand(unsigned char *address64,unsigned char *address16,unsigned char on);
void kopterLandStatusRequest(unsigned char *address64,unsigned char *address16,unsigned char frameID);
void kopterLandReport(unsigned char *address64,unsigned char *address16,unsigned char frameID);
void kopterLandReportRecieved(unsigned char *address64,unsigned char *address16,unsigned char status);

void kopterTrajectoryAddPointRequest(unsigned char *address64,unsigned char *address16,unsigned char index,uint32_t time,float elevatorPos,float aileronPos,float throttlePos,unsigned char frameID);
void kopterTrajectoryAddPoint(unsigned char *address64,unsigned char *address16,unsigned char index,uint32_t time,float elevatorPos,float aileronPos,float throttlePos);
void kopterTrajectoryPointStatusRequest(unsigned char *address64,unsigned char *address16,unsigned char frameID);
void kopterTrajectoryPointReport(unsigned char *address64,unsigned char *address16,unsigned char index,unsigned char frameID);
void kopterTrajectoryPointReportReceived(unsigned char *address64,unsigned char *address16,unsigned char index,uint32_t time,float elevatorPos,float aileronPos,float throttlePos);

void kopterControllersRequest(unsigned char *address64,unsigned char *address16,unsigned char option,unsigned char frameID);
void kopterControllers(unsigned char *address64,unsigned char *address16,unsigned char option);
void kopterControllersStatusRequest(unsigned char *address64,unsigned char *address16,unsigned char frameID);
void kopterControllersReport(unsigned char *address64,unsigned char *address16,unsigned char frameID);
void kopterControllersReportReceived(unsigned char *address64,unsigned char *address16,unsigned char status);

void kopterFollowerSetRequest(unsigned char *address64,unsigned char *address16,unsigned char *followerAddr,unsigned char frameID);
void kopterFollowerSet(unsigned char *address64,unsigned char *address16,unsigned char *followerAddr);
void kopterFollowerSetStatusRequest(unsigned char *address64,unsigned char *address16,unsigned char frameID);
void kopterFollowerSetReport(unsigned char *address64,unsigned char *address16,unsigned char frameID);
void kopterFollowerSetReportRecieved(unsigned char *address64,unsigned char *address16,unsigned char *followerAddr);

void kopterLockOnBlobRequest(unsigned char *address64,unsigned char *address16,float distance,unsigned char frameID);
void kopterLockOnBlob(unsigned char *address64,unsigned char *address16,float distance);
void kopterLockOnBlobStatusRequest(unsigned char *address64,unsigned char *address16,unsigned char frameID);
void kopterLockOnBlobReport(unsigned char *address64,unsigned char *address16,unsigned char frameID);
void kopterLockOnBlobReportRecieved(unsigned char *address64,unsigned char *address16,float distance);

void sendXBeeMessage(unsigned char *address64,unsigned char *address16,char *message,unsigned char frameID);
void receiveXBeeMessage(unsigned char *address64,unsigned char *address16,char *message);

void kopterLeadDataSend(unsigned char *address64,unsigned char *address16,volatile float altitude,volatile float elevatorError,volatile float aileronError,unsigned char frameID);
void kopterLeadDataReceived(unsigned char *address64,unsigned char *address16,float altitude, float elevatorError, float aileronError);

void kopterTimeRequest(unsigned char *address64,unsigned char *address16,uint32_t time,unsigned char frameID);
void kopterTime(unsigned char *address64,unsigned char *address16,uint32_t time);
void kopterTimeStatusRequest(unsigned char *address64,unsigned char *address16,unsigned char frameID);
void kopterTimeReport(unsigned char *address64,unsigned char *address16,unsigned char frameID);
void kopterTimeReportReceived(unsigned char *address64,unsigned char *address16,uint32_t time);

#endif /*COMMANDS_H*/
