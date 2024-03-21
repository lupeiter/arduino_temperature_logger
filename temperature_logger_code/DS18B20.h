/********************************
 Author: Markus Ritschel
 eMail:  git@markusritschel.de
 Date:   2023-02-13
*********************************/


#define IS_DS18B20_SENSOR 0x28

// ROM Commands
#define READ_ROM 0x33
#define MATCH_ROM 0x55
#define SKIP_ROM 0xCC
#define SEARCH_ROM 0xF0
#define ALARM_SEARCH 0xEC

// DS18B20 Function Commands
#define CONVERT_T 0x44
#define WRITE_SCRATCH 0x4E
#define READ_SCRATCHPAD 0xBE
#define COPY_SCRATCHPAD 0x48
#define RECALL_E2 0xB8
#define READ_PWR_SUPPLY 0xB4
