#ifndef PACKETS_H
#define PACKETS_H


typedef struct
{
    unsigned char COORDINATOR[8];
    unsigned char KC1[8];
    unsigned char K1[8];
    unsigned char K2[8];
    unsigned char K3[8];
    unsigned char BROADCAST[8];
    unsigned char UNKNOWN16[2];
} ADDRESST;

typedef struct
{
    unsigned char KC1;
    unsigned char K1;
    unsigned char K2;
    unsigned char K3;
    unsigned char UNKNOWN;
} KOPTERST;

#define KOPTERS_COUNT 4

typedef struct
{
	unsigned char GROUND_DISTANCE_ESTIMATED;
	unsigned char GROUND_DISTANCE;
	unsigned char ELEVATOR_SPEED;
	unsigned char AILERON_SPEED;
	unsigned char ELEVATOR_SPEED_ESTIMATED;
	unsigned char AILERON_SPEED_ESTIMATED;
	unsigned char ELEVATOR_POS_ESTIMATED;
	unsigned char AILERON_POS_ESTIMATED;
	unsigned char THROTTLE_CONTROLLER_OUTPUT;
	unsigned char THROTTLE_SPEED;
	unsigned char AILERON_VEL_CONTROLLER_OUTPUT;
	unsigned char ELEVATOR_VEL_CONTROLLER_OUTPUT;
	unsigned char AILERON_POS_CONTROLLER_OUTPUT;
	unsigned char ELEVATOR_POS_CONTROLLER_OUTPUT;
	unsigned char THROTTLE_SETPOINT;
	unsigned char ELEVATOR_POS_SETPOINT;
	unsigned char AILERON_POS_SETPOINT;
	unsigned char ELEVATOR_VEL_SETPOINT;
	unsigned char AILERON_VEL_SETPOINT;
	unsigned char ELEVATOR_SPEED_ESTIMATED2;
	unsigned char AILERON_SPEED_ESTIMATED2;
	unsigned char ELEVATOR_ACC;
	unsigned char AILERON_ACC;
	unsigned char VALID_GUMSTIX;
	unsigned char ELEVATOR_DESIRED_SPEED_POS_CONT;
	unsigned char AILERON_DESIRED_SPEED_POS_CONT;
	unsigned char ELE_DES_SPEED_POS_CONT_LEADER;
	unsigned char AIL_DES_SPEED_POS_CONT_LEADER;
	unsigned char OUTPUT_THROTTLE;
	unsigned char OUTPUT_ELEVATOR;
	unsigned char OUTPUT_AILERON;
	unsigned char OUTPUT_RUDDER;
} TELEMETRIEST;

#define TELEMETRY_VARIABLES 32
typedef struct
{
	unsigned char ON;
	unsigned char OFF;
} ONOFFT;

typedef struct
{
	unsigned char THROTTLE_SP;
	unsigned char ELEVATOR_POSITION;
	unsigned char AILERON_POSITION;
	unsigned char ELEVATOR_VELOCITY;
	unsigned char AILERON_VELOCITY;
} SETPOINTST;

typedef struct
{
	unsigned char ABSOLUT;
	unsigned char RELATIV;
} POSITIONST;

typedef struct
{
	unsigned char OFF;
	unsigned char VELOCITY;
	unsigned char POSITION;
	unsigned char BOTH;
} CONTROLLERST;

typedef struct
{
	unsigned char TELEMETRY;
	unsigned char TELEMETRY_COORDINATOR;
	unsigned char LANDING;
	unsigned char SET_SETPOINTS;
	unsigned char CONTROLLERS;
	unsigned char TRAJECTORY_FOLLOW;
	unsigned char TRAJECTORY_POINTS;
	unsigned char GUMSTIX;
	unsigned char FOLLOWER_SET;
}COMMANDST;

#define REPORTS_COUNT 5



extern unsigned char GET_STATUS;

extern ADDRESST ADDRESS;
extern TELEMETRIEST TELEMETRIES;
extern ONOFFT ONOFF;
extern SETPOINTST SETPOINTS;
extern POSITIONST POSITIONS;
extern CONTROLLERST CONTROLLERS;
extern COMMANDST COMMANDS;
extern KOPTERST KOPTERS;
extern unsigned char packet[255];

void constInit();

void packetHandler(unsigned char *inPacket);
//create Transmit Request Packet 0x10
void makeTRPacket(unsigned char *adr64,unsigned char *adr16,unsigned char options,unsigned char frameID,unsigned char *data, unsigned char dataLength);
void parReceivePacket(unsigned char *inPacket,unsigned char *address64,unsigned char *address16,unsigned char *receiveOptions,unsigned char *dataIN);
void parTSPacket(unsigned char *inPacket,unsigned char *frameID,unsigned char *address16,unsigned char *TrRetryCount,unsigned char *deliveryStatus,unsigned char *discoveryStatus);
void parMSPacket(unsigned char *inPacket,unsigned char *status);

#endif /*PACKETS_H*/
