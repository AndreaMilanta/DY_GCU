#ifndef GCURIO_H
#define GCURIO_H

#include "can.h"
#include "buzzer.h"

#define CAN_ID_TIMES      0b11100001000        //1800
#define CAN_ID_DATA_1     0b11100001001        //1801    //dati da EFI forward to rio (H2O)
#define CAN_ID_DATA_2     0b11100001101        //1805    //dati da EFI forward to rio (Oil and Battery)
#define CAN_ID_DATA_3     0b11100001110        //1806    //dati da EFI forward to rio (Fan and Fuel)

#define CODE_SET        0
#define CODE_REFRESH    1

#define RIO_UPDATE_RATE_ms 1000     //Time between two CAN mex with same data
#define RIO_BETWEEN_TIME_ms 250      //Time between two CAN mex with different data

#define DEFAULT_DELAY       100
#define DEFAULT_UP_REBOUND  100
#define DEFAULT_UP_BRAKE    100
#define DEFAULT_UP_PUSH_1_2 100
#define DEFAULT_UP_PUSH_2_3 100
#define DEFAULT_UP_PUSH_3_4 100
#define DEFAULT_UP_PUSH_4_5 100
     //down
#define DEFAULT_CLUTCH      200
#define DEFAULT_DN_PUSH     200
#define DEFAULT_DN_BRAKE    200
#define DEFAULT_DN_REBOUND  200
     //neutral
#define DEFAULT_NT_CLUTCH_DELAY 300
#define DEFAULT_NT_REBOUND_1_N  300
#define DEFAULT_NT_REBOUND_2_N  300
#define DEFAULT_NT_BRAKE_1_N    300
#define DEFAULT_NT_BRAKE_2_N    300
#define DEFAULT_NT_PUSH_1_N     300
#define DEFAULT_NT_PUSH_2_N     300
#define DEFAULT_NT_CLUTCH_1_N   300
#define DEFAULT_NT_CLUTCH_2_N   300
     //Multiple tries
#define DEFAULT_DOWN_TIME_CHECK 400
#define DEFAULT_UP_TIME_CHECK   400
#define DEFAULT_MAX_TRIES       400

typedef enum {
     //Neutral 1->N
     NT_PUSH_1_N,
     NT_CLUTCH_1_N,
     NT_REBOUND_1_N,
     NT_BRAKE_1_N,
    //Neutral 2->N
     NT_PUSH_2_N,
     NT_CLUTCH_2_N,
     NT_REBOUND_2_N,
     NT_BRAKE_2_N,
    //Downshift
     DN_PUSH,
     CLUTCH,
     DN_REBOUND,
     DN_BRAKE,
    //Upshift gear specific
     UP_PUSH_1_2,
     UP_PUSH_2_3,
     UP_PUSH_3_4,
     UP_PUSH_4_5,
    //Up generics
     DELAY,
     UP_REBOUND,
     UP_BRAKE,
    //neutral
     NT_CLUTCH_DELAY,

     //Multiple tries
     DOWN_TIME_CHECK,
     UP_TIME_CHECK,
     MAX_TRIES,

     //Keep Last
     TIMES_LAST
     }time_id;

 typedef enum{
    //H2O
     TH2O_ENGINE,
     TH2O_IN,
     TH2O_OUT,
     H2O_DC,
    //Oil and Battery
     TOIL_IN,
     TOIL_OUT,
     BATTERY,
     POIL,
    //Fan and Fuel
     P_FUEL,
     FAN,
     INJ1,
     INJ2,
     //Keep Last
     DATA_LAST
 }efi_dataIds;

#define RIO_NUM_TIMES TIMES_LAST    //Number of times variables (enums)
#define RIO_NUM_EFI_DATA DATA_LAST    //Number of times variables (enums)

extern unsigned int gearShift_timings[RIO_NUM_TIMES];

extern void rio_sendOneTime(time_id pos);

extern void rio_sendAllTimes(void);

extern void rio_sendTimes(void);

extern void rio_send(void);

#endif