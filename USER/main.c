#include "sys.h"
#include "uart2.h"
#include "nor_flash.h"

#include <stdio.h>
#include <string.h>

#define NOR_FLASH_DATA_ADDR		0

#define PW_NUM_BUTTON_ADDR		0x1000
#define MAIN_BUTTON_ADDR		0x1020
#define SETTING_BUTTON_ADDR		0x1040
#define ENGINEER_BUTTON_ADDR	0x1060
#define INFOMATION_BUTTON_ADDR	0x1080
#define INITIAL_BUTTON_ADDR  	0x10A0
#define TEST_BUTTON_ADDR  		0x10C0
#define AUTOCAL_BUTTON_ADDR  	0x10C2
#define START_TOUCH_BTN_ADDR	0x1100
#define START_TOUCH_TEXT_ADDR	0x1120
#define CAL_TOUCH_ENDIS_ADDR	0x1140
#define CAL_TOUCH_FRQ_ADDR		0x1142
#define CAL_TOUCH_TDU_ADDR		0x1144

#define CARTRIGE_KEYPAD_ADDR	0x1146
#define CARTRIGE_TOUCH_ADDR		0x1148
#define SYSTEM_BUTTON_ADDR		0x1150


#define PW_ICON_ADDR				0x1600
#define SYSTEM_ICON_ADDR			0x1620
#define SYSTEM_CHECK_CTRL_ICON_ADDR	0x1640
#define SYSTEM_CHECK_GEN_ICON_ADDR	0x1660
#define SYSTEM_CHECK_HP_ICON_ADDR	0x1680
#define READY_STANDBY_ICON_ADDR 0x1980

#define EN_ICON_ADDR 0x2200
#define TRANDU_FREQ_POINT_ADDR 		0x22C2
#define TRANDU_WATT_POINT_ADDR 		0x22D0

#define START_ICON_AUTOCAL_POINT_SATAT_ADDR	0x2400
#define START_ICON_AUTOCAL_POINT_END_ADDR	0x24A6

#define START_ICON_AUTOCAL_NUM_START_ADDR		0x24A8
#define START_ICON_AUTOCAL_NUM_END_ADDR			0x254E

#define CART_POINT_SATAT_ADDR       0x2550
#define CART_POINT_END_ADDR       	0x2570

#define CART_VALUE_SATAT_ADDR       0x2590
#define CART_VALUE_CART_ID_ADDR       0x2590
#define CART_VALUE_MANUFAC_YY_ADDR       0x2592
#define CART_VALUE_MANUFAC_MM_ADDR       0x2594
#define CART_VALUE_MANUFAC_DD_ADDR       0x2596
#define CART_VALUE_ISSUED_YY_ADDR       0x2598
#define CART_VALUE_ISSUED_MM_ADDR       0x259A
#define CART_VALUE_ISSUED_DD_ADDR       0x259C
#define CART_VALUE_TRANDU1_ADDR       	0x259E
#define CART_VALUE_TRANDU2_ADDR       	0x25A0
#define CART_VALUE_TRANDU3_ADDR      	0x25A2
#define CART_VALUE_TRANDU4_ADDR      	0x25A4
#define CART_VALUE_TRANDU5_ADDR      	0x25A6
#define CART_VALUE_TRANDU6_ADDR      	0x25A8
#define CART_VALUE_TRANDU7_ADDR      	0x25AA
#define CART_VALUE_REMIND_SHOT_ADDR      0x25AC
#define CART_VALUE_STATUS_ADDR      	0x25AE
#define CART_VALUE_RTC_ADDR      		0x25B0
#define CART_VALUE_END_ADDR       		0x25B0



#define TRANDU_FREQ_NUM_ADDR       	0x2600
#define TRANDU_WATT_NUM_ADDR       	0x2610

#define ERR_POPUP_BOX_ADDR      0x2700
#define ERR_POPUP_LEVEL_ADDR    0x2702
#define ERR_POPUP_CODE_ADDR     0x2704
#define ERR_POPUP_MSG_ADDR      0x2706

#define TEMP_DEBUG_ADDR			0x2840
#define DUTY_DEBUG_ADDR			0x2842

#define ENERGY_ADDR 			0x2860
#define PULSE_DURATION_ADDR 	0x2880
#define POST_COOLING_ADDR 		0x28A0
#define INTERVAL_ADDR 			0x28C0
#define CURRENT_SHOT_ADDR 		0x28C4
#define TOTAL_JOULE_ADDR 		0x28C8
#define REMIND_SHOT_ADDR 		0x28CC
#define ENERGY_MINI_ADDR		0x28D0
#define PULSE_MINI_ADDR	 		0x28D4
#define INTERVAL_MINI_ADDR	 	0x28D8
#define COOLING_MINI_ADDR		0x28DC
#define CALIV_PULSETIME_ADDR	0x28E0

#define START_ENDIS1_ADDR		0x2900
#define START_ENDIS2_ADDR		0x2920
#define START_ENDIS3_ADDR		0x2940
#define START_ENDIS4_ADDR		0x2960
#define START_ENDIS5_ADDR		0x2980
#define START_ENDIS6_ADDR		0x29A0
#define START_ENDIS7_ADDR		0x29C0
#define START_RDY_SBY_ADDR		0x29E0

#define LIGHT_ICON_ADDR  		0x3000
#define VOLRUME_ICON_ADDR  		0x3020
#define ERROR_EVENT_ADDR		 0x6010
#define DEBUG_MSG1_ADDR		 	 0x6210
#define DEBUG_MSG2_ADDR		 	 0x6310

#define MAIN_P_START_ADDR			   0x2860
#define MAIN_P1_WATT_ADDR			   0x2860
#define MAIN_P1_DURATION_TIME_ADDR	0x2862
#define MAIN_P1_INTERVAL_TIME_ADDR	 0x2864

#define MAIN_P2_WATT_ADDR			   0x2866
#define MAIN_P2_DURATION_TIME_ADDR	0x2868
#define MAIN_P2_INTERVAL_TIME_ADDR	 0x286A

#define MAIN_P3_WATT_ADDR			   0x286C
#define MAIN_P3_DURATION_TIME_ADDR	0x286E
#define MAIN_P3_INTERVAL_TIME_ADDR	 0x2870

#define MAIN_P4_WATT_ADDR			   0x2872
#define MAIN_P4_DURATION_TIME_ADDR	0x2874
#define MAIN_POSTCO0L_TIME_ADDR		   0x2876
#define MAIN_P_END_ADDR				       0x2876

#define MAIN_P_START_POINT_ADDR			   0x2880
#define MAIN_P1_WATT_POINT_ADDR			   0x2880
#define MAIN_P1_DURATION_TIME_POINT_ADDR   0x2882
#define MAIN_P1_INTERVAL_TIME_POINT_ADDR   0x2884

#define MAIN_P2_WATT_POINT_ADDR			    0x2886
#define MAIN_P2_DURATION_TIME_POINT_ADDR	0x2888
#define MAIN_P2_INTERVAL_TIME_POINT_ADDR	 0x288A

#define MAIN_P3_WATT_POINT_ADDR			   0x288C
#define MAIN_P3_DURATION_TIME_POINT_ADDR   0x288E
#define MAIN_P3_INTERVAL_TIME_POINT_ADDR   0x2890

#define MAIN_P4_WATT_POINT_ADDR			   0x2892
#define MAIN_P4_DURATION_TIME_POINT_ADDR   0x2894
#define MAIN_POSTCO0L_TIME_POINT_ADDR	   0x2896
#define MAIN_P_END_POINT_ADDR				0x2896


typedef enum
{



	OK_FLAG = 35,


	LCD_EXP_START = 1,
	LCD_EXP_END = 2,

	STATUS_STNBY = 0,
	STATUS_PRECOOLING = 1,
	STATUS_TRET = 2,

	IDX_FLASH_SHOT_0  	= 0,
	IDX_FLASH_SHOT_1  ,
	IDX_FLASH_SHOT_2  ,
	IDX_FLASH_SHOT_3  ,
	IDX_FLASH_LIGHT		= 4,
	IDX_FLASH_VOLRUME	= 5,
	IDX_FLASH_FRQ_WATT	= 6,

	//IDX_FLASH_MAX = 174,

	IDX_FLASH_MAX = 10,

	CAL_MODE_FRQ = 1,
	CAL_MODE_WATT = 2,

	BUTTON_UP = 1,
	BUTTON_DN = 2,

	REQ_DATA = 0xffff,

	OK_MAIN = 1,
	OK_HP = 2,
	OK_RF = 3,
	OK_ERR_EVENT = 4,

	ERR_CHK_MAIN = 11,
	ERR_CHK_HP = 12,
	ERR_CHK_RF = 13,

	CART_IDX_DUMY = 0,
	CART_IDX_CART_ID,
	CART_IDX_MANUFAC_YY,
	CART_IDX_MANUFAC_MM,
	CART_IDX_MANUFAC_DD,
	CART_IDX_ISSUED_YY,
	CART_IDX_ISSUED_MM,
	CART_IDX_ISSUED_DD,
	CART_IDX_TRANDU1_FRQ,
	CART_IDX_TRANDU2_FRQ,
	CART_IDX_TRANDU3_FRQ,
	CART_IDX_TRANDU4_FRQ,
	CART_IDX_TRANDU5_FRQ,
	CART_IDX_TRANDU6_FRQ,
	CART_IDX_TRANDU7_FRQ,
	CART_IDX_REMIND_SHOT,
	CART_IDX_STATUS,
	CART_IDX_RTC,

	LIVE_ALL_DETH = 0,
	LIVE_HP_DIE_RF = 10,
	LIVE_RF_DIE_HP = 1,
	LIVE_HP_RF = 11,
	ALL_DIE = 0xFF,

	SYS_CART_OK = 1,
	SYS_CART_TIMEOUT = 2,

} TOUCH_E;


typedef enum
{
	//MAIN MODE
	BTN_MAIN_ENERGY_UP = 1,
	BTN_MAIN_ENERGY_DN = 2,
	BTN_MAIN_PULSE_DURATION_UP = 3,
	BTN_MAIN_PULSE_DURATION_DN = 4,
	BTN_MAIN_POST_COOLING_UP = 5,
	BTN_MAIN_POST_COOLING_DN = 6,
	BTN_MAIN_INTERVAL_UP = 7,
	BTN_MAIN_INTERVAL_DN = 8,
	BTN_MAIN_CURRENT_SHOT_RST = 9,
	BTN_MAIN_TOTAL_JOULE_RST = 10,
	BTN_MAIN_RDY_STNBY = 11,
	BTN_MAIN_SETTING = 12,
	BTN_MAIN_ERR_OK = 13,
	BTN_MAIN_ENGINIER = 15,
	BTN_MAIN_TEST_2_PULSE = 16,
	BTN_MAIN_TEST_3_PULSE = 17,
	BTN_MAIN_TEST_4_PULSE = 18,
	BTN_MAIN_TEST_5_PULSE = 19,

	BTN_MAIN_P1_WATT = 1,
	BTN_MAIN_P1_DURATION_TIME ,
	BTN_MAIN_P1_INTERVAL_TIME ,
	BTN_MAIN_P2_WATT = 4,
	BTN_MAIN_P2_DURATION_TIME ,
	BTN_MAIN_P2_INTERVAL_TIME ,
	BTN_MAIN_P3_WATT = 7,
	BTN_MAIN_P3_DURATION_TIME ,
	BTN_MAIN_P3_INTERVAL_TIME ,
	BTN_MAIN_P4_WATT = 10,
	BTN_MAIN_P4_DURATION_TIME ,
	BTN_MAIN_POSTCO0L_TIME,

	BTN_MAIN_RDY_STNBY_N = 13,
	BTN_MAIN_CURRENT_SHOT_RST_N = 14,
	BTN_MAIN_TOTAL_JOULE_RST_N = 15,
	BTN_MAIN_ENGINIER_N = 16,
	BTN_MAIN_UP = 17,
	BTN_MAIN_DN = 18,
	BTN_MAIN_SETTING_N = 19,


	//SYSTEM MODE
	BTN_SYSTEM_ERROK = 1,

	//SETTING MODE
	BTN_SETTING_BACKHOME = 1,
	BTN_SETTING_VOL_CHECK = 2,


	//ENGINER MODE
	BTN_EG_INFOMATION = 1,
	BTN_EG_CALIBRATION = 2,
	BTN_EG_BACKHOME = 3,
	BTN_EG_AUTOCAL = 4,
	BTN_EG_CART_SET = 5,

	//INFOMATION MODE
	BTN_INFO_BACKHOME = 1,

	//CALIBRATION,PASSWARD
	KEY_1 = 1,
	KEY_2 = 2,
	KEY_3 = 3,
	KEY_4 = 4,
	KEY_5 = 5,
	KEY_6 = 6,
	KEY_7 = 7,
	KEY_8 = 8,
	KEY_9 = 9,
	KEY_0 = 10,
	KEY_DEL = 11,
	KEY_CLEAR = 12,
	KEY_CAL_BACK_MAIN = 13,
	KEY_CAL_WATT_LOAD = 14,
	KEY_CAL_WATT_SAVE = 17,
	KEY_CAL_UP = 19,
	KEY_CAL_DN = 20,


	EN_1 = 1,
	EN_2 = 2,
	EN_3 = 3,
	EN_4 = 4,
	EN_5 = 5,
	EN_6 = 6,
	EN_7 = 7,
	ED_RDY_SBY = 8,


	//AUTO CALIBRATION
	KEY_AUTO_CAL_1_2 = 1,
	KEY_AUTO_CAL_3_4_5 = 2,
	KEY_AUTO_CAL_6_7 = 3,
	KEY_AUTO_CAL_STOP = 4,
	KEY_AUTO_CAL_BACK = 5,

	AUTOCAL_START = 150,
	AUTOCAL_STOP = 160,

	//CARTRIGE SET

	KEY_CART1_SET = 0x0E,
	KEY_CART2_SET,
	KEY_CART3_SET,
	KEY_CART4_SET,
	KEY_CART5_SET,
	KEY_CART6_SET,
	KEY_CART7_SET,
	KEY_CART8_SET,
	KEY_CART9_SET,
	KEY_CART10_SET,
	KEY_CART11_SET,
	KEY_CART12_SET,
	KEY_CART13_SET,

} BUTTON_E;


typedef enum
{
	LCD_MODE_INIT = 0,
	LCD_MODE_MAIN   = 1,
	LCD_MODE_SETTING =  2,
	LCD_MODE_SYS_CHK =	3,
	LCD_MODE_CALIBRATION =	4,
	LCD_MODE_ENGINIEER = 9,
	LCD_MODE_INFOMATION = 10,
	LCD_MODE_PASSWARD =   11,
	LCD_MODE_TEST =   12,
	LCD_MODE_AUTOCAL =   13,
	LCD_MODE_CART_SETTING    = 14,
	LCD_MODE_SYS_CHK_POPUP =	15,


} PAGE_E;




typedef enum
{
	CMD_DUMY = 0,
	CMD_ENERGY	=	1,
	CMD_PULSE_DURATION = 2,
	CMD_POST_COOLING = 3,
	CMD_INTERVAL = 4,
	CMD_CURRENT_SHOT = 5,
	CMD_TOTAL_JOULE = 6,
	CMD_REMIND_SHOT = 7,
	CMD_TEMPERATURE_SHOT  = 8,
	CMD_PELTIER_DUTY =9,

	CMD_FRQ_CH0	= 10,
	CMD_FRQ_CH1,
	CMD_FRQ_CH2,
	CMD_FRQ_CH3,
	CMD_FRQ_CH4,
	CMD_FRQ_CH5,
	CMD_FRQ_CH6	= 16,

	CMD_WATT_CH0	= 17,
	CMD_WATT_CH1,
	CMD_WATT_CH2,
	CMD_WATT_CH3,
	CMD_WATT_CH4,
	CMD_WATT_CH5,
	CMD_WATT_CH6	= 23,

	CMD_PLUSE_NUM	= 24,
	CMD_PLUSE_EN	= 25,
	CMD_PLUSE_BTN_UP_DN	= 26,
	CMD_PLUSE_VALUE 	= 27,

	CMD_CAIV_DURATION = 30,

	CMD_ERR = 31,
	CMD_ALRAM = 32,
	CMD_INFO = 33,
	CMD_OK = 34,

	CMD_CART_ID  = 35,
	CMD_MANUFAC_YY = 36,
	CMD_MANUFAC_MM = 37,
	CMD_MANUFAC_DD = 38,
	CMD_ISSUED_YY = 39,
	CMD_ISSUED_MM = 40,
	CMD_ISSUED_DD = 41,
	CMD_DAY_REQ = 42,
	CMD_RTC = 43,
	CMD_RTC_YY = 44,
	CMD_RTC_MM = 45,
	CMD_RTC_DD = 46,
	CMD_RTC_HOUR = 47,
	CMD_RTC_MIN = 48,
	CMD_RTC_SEC = 49,

	CMD_CATRIDGE_STATUS    = 56,
	CMD_CATRIDGE_EVENT= 57,
	CMD_FRQ_REQ = 58,
	CMD_WATT_REQ = 59,

	CMD_LCD_STATUS = 60,
	CMD_SYS_CHK = 61,
	CMD_TRET_READY_OK = 62,

	CMD_DO_ALL_LIVE = 70,
	CMD_GET_ALL_CART = 71,
	CMD_GET_ALL_CART_END = 72,

	CMD_TEST_PULSE = 73,
	CMD_TEST_FORCE_PAGE_CHANGE = 75,

	CMD_LCD_EXP = 85,
	CMD_LCD_AUTO_CAL = 87,


	CMD_TRANDU_FRQ_BASE	= 90,
	CMD_TRANDU1_FRQ	= 91,
	CMD_TRANDU2_FRQ	= 92,
	CMD_TRANDU3_FRQ	= 93,
	CMD_TRANDU4_FRQ	= 94,
	CMD_TRANDU5_FRQ	= 95,
	CMD_TRANDU6_FRQ	= 96,
	CMD_TRANDU7_FRQ	= 97,

	CMD_TRANDU_WATT_BASE	= 100,
	// TRANDU1
	CMD_TRANDU1_WATT10	= 101,
	CMD_TRANDU1_WATT09	= 102,
	CMD_TRANDU1_WATT08	= 103,
	CMD_TRANDU1_WATT07	= 104,
	CMD_TRANDU1_WATT06	= 105,
	CMD_TRANDU1_WATT05	= 106,
	CMD_TRANDU1_WATT04	= 107,
	CMD_TRANDU1_WATT03	= 108,
	CMD_TRANDU1_WATT02	= 109,
	CMD_TRANDU1_WATT01	= 110,
	CMD_TRANDU1_WATT005	= 111,

	// TRANDU2
	CMD_TRANDU2_WATT10	= 112,
	CMD_TRANDU2_WATT09	= 113,
	CMD_TRANDU2_WATT08	= 114,
	CMD_TRANDU2_WATT07	= 115,
	CMD_TRANDU2_WATT06	= 116,
	CMD_TRANDU2_WATT05	= 117,
	CMD_TRANDU2_WATT04	= 118,
	CMD_TRANDU2_WATT03	= 119,
	CMD_TRANDU2_WATT02	= 120,
	CMD_TRANDU2_WATT01	= 121,
	CMD_TRANDU2_WATT005	= 122,

	// TRANDU3
	CMD_TRANDU3_WATT10	= 123,
	CMD_TRANDU3_WATT09	= 124,
	CMD_TRANDU3_WATT08	= 125,
	CMD_TRANDU3_WATT07	= 126,
	CMD_TRANDU3_WATT06	= 127,
	CMD_TRANDU3_WATT05	= 128,
	CMD_TRANDU3_WATT04	= 129,
	CMD_TRANDU3_WATT03	= 130,
	CMD_TRANDU3_WATT02	= 131,
	CMD_TRANDU3_WATT01	= 132,
	CMD_TRANDU3_WATT005	= 133,

	// TRANDU4
	CMD_TRANDU4_WATT10	= 134,
	CMD_TRANDU4_WATT09	= 135,
	CMD_TRANDU4_WATT08	= 136,
	CMD_TRANDU4_WATT07	= 137,
	CMD_TRANDU4_WATT06	= 138,
	CMD_TRANDU4_WATT05	= 139,
	CMD_TRANDU4_WATT04	= 140,
	CMD_TRANDU4_WATT03	= 141,
	CMD_TRANDU4_WATT02	= 142,
	CMD_TRANDU4_WATT01	= 143,
	CMD_TRANDU4_WATT005	= 144,

	// TRANDU5
	CMD_TRANDU5_WATT10	= 145,
	CMD_TRANDU5_WATT09	= 146,
	CMD_TRANDU5_WATT08	= 147,
	CMD_TRANDU5_WATT07	= 148,
	CMD_TRANDU5_WATT06	= 149,
	CMD_TRANDU5_WATT05	= 150,
	CMD_TRANDU5_WATT04	= 151,
	CMD_TRANDU5_WATT03	= 152,
	CMD_TRANDU5_WATT02	= 153,
	CMD_TRANDU5_WATT01	= 154,
	CMD_TRANDU5_WATT005	= 155,

	// TRANDU6
	CMD_TRANDU6_WATT10	= 156,
	CMD_TRANDU6_WATT09	= 157,
	CMD_TRANDU6_WATT08	= 158,
	CMD_TRANDU6_WATT07	= 159,
	CMD_TRANDU6_WATT06	= 160,
	CMD_TRANDU6_WATT05	= 161,
	CMD_TRANDU6_WATT04	= 162,
	CMD_TRANDU6_WATT03	= 163,
	CMD_TRANDU6_WATT02	= 164,
	CMD_TRANDU6_WATT01	= 165,
	CMD_TRANDU6_WATT005	= 166,

	// TRANDU7
	CMD_TRANDU7_WATT10	= 167,
	CMD_TRANDU7_WATT09	= 168,
	CMD_TRANDU7_WATT08	= 169,
	CMD_TRANDU7_WATT07	= 170,
	CMD_TRANDU7_WATT06	= 171,
	CMD_TRANDU7_WATT05	= 172,
	CMD_TRANDU7_WATT04	= 173,
	CMD_TRANDU7_WATT03	= 174,
	CMD_TRANDU7_WATT02	= 175,
	CMD_TRANDU7_WATT01	= 176,
	CMD_TRANDU7_WATT005	= 177,

} CMD_E;


typedef enum
{
	//MAIN
	EVENT_START_NUM = 1,
	ERR_FLOW_LIMIT_ZERO = 1,
	ERR_FLOW_LIMIT_UNDER,
	ERR_WATER_LEVEL_LIMIT_UNDER,
	ERR_RTC_BATTERY_LIMIT_OVER,
	ERR_RTC_BATTERY_LIMIT_UNDER,
	ERR_RTC_TIME,
	ERR_MAIN_COMMU,

	//RF
	ERR_RF_GENERATOR_COMMU,
	ERR_RF_GENERATOR_STATUS,

	//HP
	ERR_HP_COMMU,
	ERR_TRANSDUCER_TEMP,
	ERR_TRANSDUCER_TEMP_LIMIT_UNDER,
	ERR_COOLING_TIMEOUT,
	ERR_CARTRIDGE_MANUFAC,
	ERR_CARTRIDGE_ISSUED,
	ERR_CARTRIDGE_FRQ,
	ERR_CARTRIDGE_WATT_DA,
	ERR_CARTRIDGE_MAX_SHOT,
	ERR_CARTRIDGE_REMAINING_SHOT,
	ERR_CARTRIDGE_ID,
	ERR_CARTRIDGE_MANUFAC_OVER,
	ERR_CARTRIDGE_ISSUED_OVER,



	ALRAM_01,
	ALRAM_02,
	ALRAM_03,
	ALRAM_04,
	ALRAM_05,
	ALRAM_06,

	INFO_01,
	INFO_02,
	INFO_03,
	INFO_04,
	INFO_05,
	INFO_06,

	EVENT_MAX_NUM = INFO_06,

	EVENT_ICON_BASE = 50,// 임의의수

	LEVEL_ERROR = 1,
	LEVEL_ALRAM = 2,
	LEVEL_INFO = 3,

	LEVEL_UNIT = 1000,
	ERR_ENDIS_UNIT = 100,
	ERR_ENABLE = 100,
	ERR_DISABLE = 0,
	ERR_DATA_UNIT = 0,

	ERR_NOT_EXIST = 0,
	ERR_EXIST = 1,
} ERR_CMD_E;


typedef enum
{
	ICON_PASSWARD_0 = 0,
	ICON_PASSWARD_1,
	ICON_PASSWARD_2,
	ICON_PASSWARD_3,
	ICON_PASSWARD_4,
	ICON_PASSWARD_ERR,

	ICON_CALIB_READY = 6,
	ICON_CALIB_STANDBY,

	ICON_CALIB_DISABLE = 8,
	ICON_CALIB_ENABLE,

	ICON_NO_USE1,//10
	ICON_SETTING_BOLL = 11,// 소스내에는 없음
	ICON_NO_USE2,//12
	ICON_NO_USE3,
	ICON_NO_USE4,
	ICON_NO_USE5,//15
	ICON_SYS_CHK_PER_0 = 16,
	ICON_SYS_CHK_PER_10,
	ICON_SYS_CHK_PER_20,
	ICON_SYS_CHK_PER_30,
	ICON_SYS_CHK_PER_40,
	ICON_SYS_CHK_PER_50,
	ICON_SYS_CHK_PER_60,
	ICON_SYS_CHK_PER_70,
	ICON_SYS_CHK_PER_80,
	ICON_SYS_CHK_PER_90,
	ICON_SYS_CHK_PER_100 = 26,


	ICON_SYS_CHK_MAIN_DIS = 27,
	ICON_SYS_CHK_MAIN_EN,
	ICON_SYS_CHK_GEN_DIS,
	ICON_SYS_CHK_GEN_EN,
	ICON_SYS_CHK_HP_DIS,
	ICON_SYS_CHK_HP_EN = 32,

	ICON_MAIN_STANDBY = 33,
	ICON_MAIN_COOLING1,
	ICON_MAIN_COOLING2,
	ICON_MAIN_COOLING3,
	ICON_MAIN_TREAT = 37,

	ICON_NO_USE6,//38
	ICON_NO_USE7,//39

	ICON_NO_USE8,//40
	ICON_NO_USE9,//41

	ICON_CALIB_EMPTY_POINT = 42,
	ICON_CALIB_POINT = 43,

	ICON_MAIN_EMPTY_POP = 46,
	ICON_MAIN_POP = 47,


} ICON_E;

typedef enum
{
  IDX_ERR_DUMY = 0,
  IDX_TEMP_OUT,
  IDX_TEMP_LIMIT_UNDER,
  IDX_TEMP_LOW,
  IDX_FLOW_LIMIT_UNDER,
  IDX_FLOW_ZERO_IDX,
  IDX_LEVEL_LOW,
  IDX_AUTO_CAL_COMU_ERR,
  IDX_BATTRY_LIMIT_OVER,
  IDX_BATTRY_LIMIT_UNDER,
  IDX_BATTRY_LIMIT_LOW,
  IDX_RTC_ERR,
//------------------------------

  IDX_PRE_COOL_ERR,
  IDX_HAND_COMU_ERR,
  IDX_CATRIGE_ID_ERR,
  IDX_CATRIGE_MANU_ERR,
  IDX_CATRIGE_MANU_OVER_ERR,
  IDX_CATRIGE_ISUE_ERR,
  IDX_CATRIGE_ISUE_OVER_ERR,
  IDX_CATRIGE_WATT_ERR,
  IDX_CATRIGE_FRQ_ERR,
  IDX_CATRIGE_RESHOT_ERR,
  IDX_CATRIGE_RESHOT_LOW,
  IDX_CATRIGE_RESHOT_ZERO,
  IDX_CATRIGE_DETECT,
  IDX_CATRIGE_UN_DETECT,
//------------------------------

  IDX_RF_COMU_ERR,
  IDX_RF_STATUS_ERR,
//------------------------------

  IDX_HAND_TIMEOUT,
  IDX_LCD_COMU_ERR,
  IDX_LCD_TIMEOUT,
  IDX_ERROR_MAX,

} ERROR_IDX_E;

typedef enum
{
	STEP0,
	STEP1,
	STEP2,
	STEP3,
	STEP4,
	STEP5,
	STEP6,
	STEP7,
	STEP8,
} STEP_E;

extern idata u16 delay_tickMy;
extern xdata u8  uartRxBuff[20];
extern xdata u8  uartRxFlag;
extern xdata u8  uartRxStep;
extern xdata u8  uartCmdTemp;
extern xdata u16  uartValueTemp;

idata u32 textCpy=0;
xdata u16 btn,btnMain,btnSetting;

idata u32 sysTimeStamp;

idata u8 toggle = 1;

xdata u16 pwCnt;
//xdata u16 pageNum;
idata u8 lcdPage;
xdata u8 lcdPageForceFlag;

xdata u16 iconCircle;
xdata u16 iconSystemCircle;

idata u8 watt=0;

idata u32 energy=0;
idata u32 pulseDuration=0;
idata u32 postCooling=0;
idata u32 interval=0;
idata u32 currentShot=0;
idata u32 totalJoule=0;
idata u8 rdyStnbyMode=0;
idata u32 remindShot=0;
idata u32 temperature=0;
idata u32 peltierDuty=0;



xdata u8 lcdOn,expFlag;
idata u32 dataBuff[10];
xdata u8 flashBuff[174];
xdata u32 mainDataBuff[9];


///옮기는 변수는 오직이거

xdata u16 textFrqBuff[8];
xdata u16 textWattBuff[78];
xdata u16 textCartrigeBuff[20];

xdata u8 frqIdx = 0;
xdata u8 wattIdxMain = 0, wattIdxSub = 0;
xdata u16 iconMove;





idata u32 textNum=0;
idata u32 onTimeCalv=0;

xdata u8 edBuff[9] = {0,};
///옮기는 변수는 오직이거

idata u8 egCnt = 0;
idata u8 engineerKey;
idata u16 lightLevel;
idata u16 volumeLevel;

idata u8 btnLight[4];
idata u8 btnVol[4];
xdata u16 autoCalAdd;
xdata u8 autoCalAddPre;
xdata u8 autoCalStart;

xdata u8 autoCalIng;
xdata u8 calMode;
xdata u16 prePointAddr;
xdata u8 autoCalRcvCnt;
xdata u8 calRcvCnt;

xdata u8 cartId;
xdata u16 manufacYY;
xdata u16 manufacMMDD;
xdata u16 manufacMM;
xdata u16 manufacDD;


xdata u16 issuedYY;
xdata u16 issuedMMDD;
xdata u16 issuedMM;
xdata u16 issuedDD;

xdata u16 Rtc;

xdata u8 sysChkFlag;
xdata u8 sysChkStart;
xdata u32 sysChkStartTime;

xdata u8 errEventBuff[30];
xdata u8 errEventFlag[30];
xdata u8 errEvent;
xdata u8 errCartEvent;

xdata u16 chkOkBuff[3];
xdata u8 chkOk;

xdata u16 reTxCmd;
xdata u16 reTxData;
xdata u32 reTxTimeStamp;
xdata u16 reTxCnt;

xdata u8 cartTouch;
xdata u8 cartIdx;
xdata u32 cartValue;
xdata u16 cartPrePointAddr;

xdata u8 getCartStep;
xdata u8 systemStep;

xdata u16 systemLive;
xdata u8 systemCartEnd;
xdata u8 systemLiveStatus;
xdata u8 systemCartStatus;

xdata u8 systemErr;

xdata u32 systemTimeStemp;
xdata u8 systemNorsvCnt;
xdata u16 pulseStrAddr;
xdata u16 pulsePointAddr;

xdata u16 pulseAddr;


void Light_Change(u16 light);
void Volume_Change(u8       id, u16 volume);
void Event_PopUp(u16 eventData);

void Debug_Print(int num, int debugData)
{
	printf("debug <%d> <%d>\r\n",num, debugData);
}

void TX_Msg(u16 txCmd, u16 txData)
{
	while(delay_tickMy-reTxTimeStamp<100);

	printf("[%u,%u]\r\n",txCmd, txData);

	reTxCmd = txCmd;
	reTxData = txData;
	reTxTimeStamp = delay_tickMy;

}

void TX_Rx_Msg(u16 txCmd, u16 txData , u16* rxValue, u16 wateTime)
{
	u16 rxCmd = 0;
	u32 value=0;
	u8 txCnt = 0;
	int i = 0;

	for(i =0 ;i < 5;i++)
	{
		printf("[%u,%u]\r\n",txCmd, txData);
		txCnt++;
		sys_delay_ms(wateTime);
		if(uartRxFlag)
		{
			uartRxFlag = 0;
			rxCmd = uartCmdTemp;
			value =uartValueTemp;
			if(txCmd == rxCmd)
			{
				*rxValue = value;
				break;
			}
		}
	}
	if(txCnt==5)
	{
		//err
		errCartEvent = 1;
	}

}

void TX_RF_DA_Req_Msg(u16 txCmd)
{
	u16 rxCmd = 0;
	u32 rxData =0;
	u32 timeStamp = 0;
	u8 txCnt = 0;
	const u8 maxCnt = 10;
	u16 add = 0;
	u16 cmd = 0;
	u32 value = 0;

	printf("[%u,%u]\r\n",txCmd, REQ_DATA);

	timeStamp = delay_tickMy;

	while (1)
	{
		if(uartRxFlag)
		{
			uartRxFlag = 0;
			rxCmd = uartCmdTemp;
			rxData = uartValueTemp;

			if(rxCmd == txCmd)
			{
				if(CMD_TRANDU1_WATT10 <= rxCmd && rxCmd <=CMD_TRANDU7_WATT005)
				{
					rxCmd = rxCmd -100;
					textWattBuff[rxCmd] = rxData;
				}
				break;
			}
			else
			{
//				printf("rfERR\r\n");
			}

		}
		if(delay_tickMy-timeStamp >= 500)
		{
			printf("[%u,%u]\r\n",txCmd, REQ_DATA);
			txCnt++;
			if(txCnt>maxCnt)
			{
//				printf("req timeOut\r\n");
				break;
			}
			timeStamp = delay_tickMy;
		}
	}


}


void Watt_Frq_All_Set()
{
	u16 add = 0;
	int i = 0,j = 0;
	u32 defultWatt=0;
	u32 defultFrq=0;


	for(i =1 ;i < 8;i++)
	{
		defultFrq = textFrqBuff[i];
		add = (u16)(TRANDU_FREQ_NUM_ADDR + (i-1)*0x02);
		sys_write_vp(add,(u8*)&defultFrq,2);
	}

	for(i =1 ;i <= 77;i++)
	{
		defultWatt = textWattBuff[i];
		add = (u16)(TRANDU_WATT_NUM_ADDR + i*0x02);
		sys_write_vp(add,(u8*)&defultWatt,2);
	}


}



void Calv_Tx_Msg()
{
	int i =0;
	u16 add = 0;
	u16 value = 0;
	u16 addIcon = 0;
	const u16 icon9 = 9;

	sys_delay_ms(100);

	value = onTimeCalv;
	TX_Msg(CMD_CAIV_DURATION, value);//

	for(i =0 ;i < 7;i++)
	{
		if(edBuff[i+1] )
		{
			add = i+CMD_WATT_CH0;
			value = textWattBuff[wattIdxMain];
			TX_Msg(add, value);//
		}
	}


	sys_delay_ms(1000);
	TX_Msg(CMD_TRET_READY_OK, 1);//
}


void Flash_Read()////
{
	norflash_read(NOR_FLASH_DATA_ADDR,flashBuff,IDX_FLASH_MAX);
	lightLevel = (u16)flashBuff[IDX_FLASH_LIGHT];
	volumeLevel = (u16)flashBuff[IDX_FLASH_VOLRUME];

	Light_Change(lightLevel);
	Volume_Change(1, volumeLevel);//intro
}





void Flash_Volume_Write()
{
	flashBuff[IDX_FLASH_VOLRUME] = (u8)volumeLevel;
	norflash_write(NOR_FLASH_DATA_ADDR,flashBuff,6);
}
void Flash_Light_Write()
{
	flashBuff[IDX_FLASH_LIGHT] = (u8)lightLevel;
	norflash_write(NOR_FLASH_DATA_ADDR,flashBuff,6);
}


void Page_Change(u16 PageID)
{
	u8 buf[4];

	buf[0] = 0x5a;
	buf[1] = 0x01;
	buf[2] = (u8)(PageID >> 8);
	buf[3] = (u8)PageID;
 	sys_write_vp(0x0084,buf,2);
}

void Light_Change(u16 light)
{
	u8 buf[4];
	buf[0] = light;
	buf[1] = light;
	buf[2] = 0x32;
	buf[3] = 0xe8;
 	sys_write_vp(0x0082,buf,2);
}

void Volume_Change(u8       id, u16 volume)
{
	u8 buf[4];

	buf[0] = id;//id
	buf[1] = 0x01;
	buf[2] = volume;
	buf[3] = 0x02;
 	sys_write_vp(0x00a0,buf,2);
}

void Ascii_Clear(u16 add)
{
	int i =0;
	u8 buf[40];

	for(i =0 ;i < 40;i++)
	{
		buf[i] = 0;
	}


 	sys_write_vp(add,(u8*)buf,20);
}


void Ascii_text(char* str, u16 add)
{
	u8 len;
	len = strlen(str);
	len /= 2;
	if(len%2==1) len = len+2;


 	sys_write_vp(add,(u8*)str,len);
}

void Evnt_Ascii_Msg(u8 num)
{
	const u16 add = ERROR_EVENT_ADDR;
	Ascii_Clear(add);
	switch (num)
	{
	case IDX_TEMP_OUT:				  Ascii_text("TEMP_OUT", add);	break;
	case IDX_TEMP_LIMIT_UNDER:		  Ascii_text("TEMP_LIMIT_UNDER", add);	break;
	case IDX_TEMP_LOW:				  Ascii_text("TEMP_LOW", add);	break;
	case IDX_FLOW_LIMIT_UNDER:		  Ascii_text("FLOW_LIMIT_UNDER", add);	break;
	case IDX_FLOW_ZERO_IDX: 		  Ascii_text("FLOW_ZERO_IDX", add);	 break;
	case IDX_LEVEL_LOW: 			  Ascii_text("LEVEL_LOW", add);	 break;
	case IDX_AUTO_CAL_COMU_ERR: 	  Ascii_text("AUTO_CAL_COMU_ERR", add);	 break;
	case IDX_BATTRY_LIMIT_OVER: 	  Ascii_text("BATTRY_LIMIT_OVER", add);	 break;
	case IDX_BATTRY_LIMIT_UNDER:	  Ascii_text("BATTRY_LIMIT_UNDER", add);   break;
	case IDX_BATTRY_LIMIT_LOW:		  Ascii_text("BATTRY_LIMIT_LOW", add);	break;
	case IDX_RTC_ERR:				  Ascii_text("RTC_ERR", add);   break;
	case IDX_PRE_COOL_ERR:			  Ascii_text("PRE_COOL_ERR", add);	break;
	case IDX_HAND_COMU_ERR: 		  Ascii_text("HAND_COMU_ERR", add);	 break;
	case IDX_CATRIGE_ID_ERR:		  Ascii_text("CATRIGE_ID_ERR", add);   break;
	case IDX_CATRIGE_MANU_ERR:		  Ascii_text("CATRIGE_MANU_ERR", add);	break;
	case IDX_CATRIGE_MANU_OVER_ERR:   Ascii_text("CATRIGE_MANU_OVER_ERR", add);	 break;
	case IDX_CATRIGE_ISUE_ERR:		  Ascii_text("CATRIGE_ISUE_ERR", add);	break;
	case IDX_CATRIGE_ISUE_OVER_ERR:   Ascii_text("CATRIGE_ISUE_OVER_ERR", add);	 break;
	case IDX_CATRIGE_WATT_ERR:		  Ascii_text("CATRIGE_WATT_ERR", add);	break;
	case IDX_CATRIGE_FRQ_ERR:		  Ascii_text("CATRIGE_FRQ_ERR", add);   break;
	case IDX_CATRIGE_RESHOT_ERR:	  Ascii_text("CATRIGE_RESHOT_ERR", add);   break;
	case IDX_CATRIGE_RESHOT_LOW:	  Ascii_text("CATRIGE_RESHOT_LOW", add);   break;
	case IDX_CATRIGE_RESHOT_ZERO:	  Ascii_text("CATRIGE_RESHOT_ZERO", add);   break;
	case IDX_CATRIGE_DETECT:		  Ascii_text("CATRIGE_DETECT", add);   break;
	case IDX_CATRIGE_UN_DETECT: 	  Ascii_text("CATRIGE_UN_DETECT", add);	 break;
	case IDX_RF_COMU_ERR:			  Ascii_text("RF_COMU_ERR", add);   break;
	case IDX_RF_STATUS_ERR: 		  Ascii_text("RF_STATUS_ERR", add);	 break;

	}
}


void EXP_FreeCool_Motion()
{
	static u32 timeStamp;


	if(rdyStnbyMode != STATUS_PRECOOLING) return;

	if(delay_tickMy-timeStamp >= 1000)
	{
		sys_write_vp(READY_STANDBY_ICON_ADDR,(u8*)&iconMove ,2);
		iconMove++;
		if(iconMove>36)iconMove = 34;
		timeStamp = delay_tickMy;
	}

}

void Event_PopUp_org(u16 eventData)
{
	u16 iconErrIcon= 0;
	const u16 iconErrBack= ICON_MAIN_POP; // 고정
	u16 iconErrCode= 0;
	u16 iconErrMsg= 0;
	u16 errLevel, errData;//errEnDis;

	errEvent = 1;
	errLevel = eventData / LEVEL_UNIT;
	errData = eventData % ERR_ENDIS_UNIT;
//	if(1 > errData || errData >6)
//	{
//		return;
//	}
//	if(errLevel == LEVEL_ERROR)iconErrIcon = 1;
//	else if(errLevel == LEVEL_ALRAM)iconErrIcon = 2;
//	else if(errLevel == LEVEL_INFO)iconErrIcon = 3;
//	else return;

	sys_write_vp(ERR_POPUP_BOX_ADDR, (u8*)&iconErrBack,2);//backGround
//	sys_delay_ms(500);
	sys_write_vp(ERR_POPUP_MSG_ADDR, (u8*)&errData,2);//icon



#if 0

	iconErrCode = EVENT_ICON_BASE +eventData;// if codeIcon== 51, 50+1
	sys_write_vp(0x2222, (u8*)&iconErrCode,2);//code

	iconErrMsg = EVENT_ICON_BASE + EVENT_MAX_NUM+ eventData;//msg는 code 뒤에 있음
	sys_write_vp(0x3333, (u8*)&iconErrMsg,2);//msg
#endif

}

void Event_PopDown_org()
{
	const u16 iconErrBack= ICON_MAIN_EMPTY_POP; // 고정
	const u16 iconErrMsgBack= 1; // 고정

	sys_write_vp(ERR_POPUP_MSG_ADDR, (u8*)&iconErrBack,2);//backGround
//	sys_delay_ms(500);
	sys_write_vp(ERR_POPUP_BOX_ADDR, (u8*)&iconErrMsgBack,2);//backGround
}

void Event_PopUp(u16 eventData)
{
	u16 iconErrIcon= 0;
	const u16 iconErrBack= ICON_MAIN_POP; // 고정
	u16 iconErrCode= 0;
	u16 iconErrMsg= 0;
	u16 errLevel, errData;//errEnDis;

	errEvent = 1;
	sysChkFlag = 0;
	errLevel = eventData / LEVEL_UNIT;
	errData = eventData % ERR_ENDIS_UNIT;

	sys_write_vp(ERR_POPUP_BOX_ADDR, (u8*)&iconErrBack,2);//backGround
	Evnt_Ascii_Msg(errData);
}

void Event_PopDown()
{
	const u16 iconErrBack= ICON_MAIN_EMPTY_POP; // 고정
	const u16 iconErrMsgBack= 1; // 고정

	Ascii_Clear(ERROR_EVENT_ADDR);
	sys_write_vp(ERR_POPUP_BOX_ADDR, (u8*)&iconErrMsgBack,2);//backGround
}


void SYS_CHK_OK(u16 device)
{
	switch (device)
	{
		case OK_MAIN:
			chkOkBuff[0] = OK_MAIN;
		break;

		case OK_RF:
			chkOkBuff[1] = OK_RF;
		break;

		case OK_HP:
			chkOkBuff[2] = OK_HP;
		break;
	}
}


void ReTry_Reset()
{
	reTxCmd = 0;
	reTxData = 0;
//	reTxTimeStamp = 0;
	reTxCnt = 0;
}

void ReTry_Tx()
{

	if(reTxCmd)
	{
		if(delay_tickMy-reTxTimeStamp >= 500)
		{

			printf("[%u,%u]\r\n",reTxCmd, reTxData);
			reTxTimeStamp = delay_tickMy;
			reTxCnt++;
			if(reTxCnt>=5) ReTry_Reset();
		}
	}

}
void RX_AUTOCAL_Parssing_Config()
{
	u16 add = 0;
	u16 cmd = 0;
	u32 value=0;
	const u16 iconCalEmptyPoint = ICON_CALIB_EMPTY_POINT;
	if(uartRxFlag)
	{
		uartRxFlag = 0;
		ReTry_Reset();
		cmd = uartCmdTemp;
		value = uartValueTemp;

//		if(CMD_TRANDU1_WATT10 <= cmd && cmd <=CMD_TRANDU7_WATT005)
//		{
//			if(value == AUTOCAL_START)
//			{
//				if(autoCalStart==0)
//				{
//					autoCalStart = cmd;
//					cmd = cmd -100;
//					autoCalAdd = (u16)(START_ICON_AUTOCAL_POINT_SATAT_ADDR + ((cmd-1)*0x02));
//				}
//			}
//			else if(value == AUTOCAL_STOP)
//			{
//				if(autoCalStart == cmd)
//				{
//					autoCalStart = 0;
//					sys_write_vp(autoCalAdd, (u8*)&iconCalEmptyPoint,2);
//				}
//			}
//			else
//			{
//				cmd  = cmd-100;
//				textWattBuff[cmd] = value;
//				autoCalRcvCnt++;
//			}

//		}

	}
	ReTry_Tx();
}



void RX_Parssing_Config()
{
	u16 add = 0;
	u16 cmd = 0;
	u32 value=0;
	u16 errData = 0;
	u16 pluseNum = 0;
	u32 pluseValue = 0;
	u16 pluseAddr = 0;
	const u16 iconCalEmptyPoint = ICON_CALIB_EMPTY_POINT;
	const u16 iconStandby = ICON_MAIN_STANDBY, iconTreat = ICON_MAIN_TREAT;
	if(uartRxFlag)
	{
		uartRxFlag = 0;
		ReTry_Reset();
		cmd = uartCmdTemp;
		value = uartValueTemp;
		switch (cmd)
		{

			case CMD_ERR:
				errData = value;
				Event_PopUp(errData);
//				errEventBuff[errData] = errData;
//				errEventFlag[errData] = CMD_ERR;
			break;

			case CMD_OK://앞에 커멘드는 고정 뒤에는 장치명
				SYS_CHK_OK(value);
			break;

			case CMD_CART_ID:
				cartId = value;
				textCartrigeBuff[CART_IDX_CART_ID] = value;
				sys_write_vp(CART_VALUE_CART_ID_ADDR,(u8*)&value ,2);
			break;

			case CMD_MANUFAC_YY:
				manufacYY = value;
				textCartrigeBuff[CART_IDX_MANUFAC_YY] = value;
				sys_write_vp(CART_VALUE_MANUFAC_YY_ADDR,(u8*)&value ,2);
			break;

			case CMD_MANUFAC_MM:
				manufacMM = value;
				textCartrigeBuff[CART_IDX_MANUFAC_MM] = value;
				sys_write_vp(CART_VALUE_MANUFAC_MM_ADDR,(u8*)&value ,2);
			break;

			case CMD_MANUFAC_DD:
				manufacDD = value;
				textCartrigeBuff[CART_IDX_MANUFAC_DD] = value;
				sys_write_vp(CART_VALUE_MANUFAC_DD_ADDR,(u8*)&value ,2);
			break;

			case CMD_ISSUED_YY:
				issuedYY=value;
				textCartrigeBuff[CART_IDX_ISSUED_YY] = value;
				sys_write_vp(CART_VALUE_ISSUED_YY_ADDR,(u8*)&value ,2);
			break;
			case CMD_ISSUED_MM:
				issuedMM = value;
				textCartrigeBuff[CART_IDX_ISSUED_MM] = value;
				sys_write_vp(CART_VALUE_ISSUED_MM_ADDR,(u8*)&value ,2);
			break;

			case CMD_ISSUED_DD:
				issuedDD = value;
				textCartrigeBuff[CART_IDX_ISSUED_DD] = value;
				sys_write_vp(CART_VALUE_ISSUED_DD_ADDR,(u8*)&value ,2);
			break;

			case CMD_RTC:
				Rtc = value;
				textCartrigeBuff[CART_IDX_RTC] = value;
				sys_write_vp(CART_VALUE_RTC_ADDR,(u8*)&value ,2);
			break;

			case CMD_ENERGY:
				energy = value;
				sys_write_vp(ENERGY_ADDR,(u8*)&energy ,2);
				sys_write_vp(ENERGY_MINI_ADDR,(u8*)&energy ,2);

			break;

			case CMD_PULSE_DURATION:
				pulseDuration = value;
				sys_write_vp(PULSE_DURATION_ADDR,(u8*)&pulseDuration ,2);
				sys_write_vp(PULSE_MINI_ADDR,(u8*)&pulseDuration ,2);
			break;

			case CMD_POST_COOLING:
				postCooling = value;
				sys_write_vp(POST_COOLING_ADDR,(u8*)&postCooling ,2);
				sys_write_vp(COOLING_MINI_ADDR,(u8*)&postCooling ,2);
			break;

			case CMD_INTERVAL:
				interval = value;
				sys_write_vp(INTERVAL_ADDR,(u8*)&interval ,2);
				sys_write_vp(INTERVAL_MINI_ADDR,(u8*)&interval ,2);
			break;


			case CMD_CURRENT_SHOT:
				currentShot = value;
				sys_write_vp(CURRENT_SHOT_ADDR,(u8*)&currentShot ,2);

			break;

			case CMD_TOTAL_JOULE:
				totalJoule = value;
				sys_write_vp(TOTAL_JOULE_ADDR,(u8*)&totalJoule ,2);
			break;

			case CMD_REMIND_SHOT:
				remindShot = value;
				textCartrigeBuff[CART_IDX_REMIND_SHOT] = value;
				sys_write_vp(REMIND_SHOT_ADDR,(u8*)&remindShot ,2);
				sys_write_vp(CART_VALUE_REMIND_SHOT_ADDR,(u8*)&value ,2);

			break;

			case CMD_TEMPERATURE_SHOT:
				temperature = value;
				sys_write_vp(TEMP_DEBUG_ADDR,(u8*)&temperature ,2);

			break;

			case CMD_PELTIER_DUTY:
				peltierDuty = value;
				sys_write_vp(DUTY_DEBUG_ADDR,(u8*)&peltierDuty ,2);

			break;


			case CMD_LCD_STATUS:
				rdyStnbyMode = value;
				if(lcdPage == LCD_MODE_MAIN)
				{
					if(rdyStnbyMode == STATUS_STNBY)
					{
						sys_write_vp(READY_STANDBY_ICON_ADDR,(u8*)&iconStandby ,2);
					}
					else if(rdyStnbyMode == STATUS_TRET)
					{
						sys_write_vp(READY_STANDBY_ICON_ADDR,(u8*)&iconTreat ,2);
						Volume_Change(6, volumeLevel);
					}
					else if(rdyStnbyMode == STATUS_PRECOOLING)
					{
						iconMove = ICON_MAIN_COOLING1;
					}
				}
			break;

			case CMD_DO_ALL_LIVE:
				systemLive = value;
			break;

			case CMD_GET_ALL_CART_END:
				systemCartEnd = value;
			break;


			case CMD_LCD_EXP:
				if(value == LCD_EXP_START)
				{
					expFlag = 1;
//					Volume_Change(6, volumeLevel);
				}
				else if(value == LCD_EXP_END)
				{
					expFlag = 0;
					Volume_Change(10, volumeLevel);
				}
			break;

			case CMD_TEST_FORCE_PAGE_CHANGE:
				lcdPage = value;
				Page_Change(value);
				lcdPageForceFlag = 1;
			break;

			case CMD_PLUSE_VALUE:
				pluseNum = value/100;
				pluseValue = value%100;
				pluseAddr =  MAIN_P_START_ADDR + (pluseNum-1)*2;
				sys_write_vp(pluseAddr, (u8*)&pluseValue ,2);
			break;


			default:
				if(CMD_TRANDU1_FRQ <= cmd && cmd <=CMD_TRANDU7_FRQ)
				{
					cmd  = cmd-90;
					textFrqBuff[cmd] = value;
					textCartrigeBuff[CART_IDX_ISSUED_DD+cmd] = value;
					add = (u16)(CART_VALUE_TRANDU1_ADDR + (cmd-1)*0x02);
					sys_write_vp(add,(u8*)&value ,2);
				}
				else if(CMD_TRANDU1_WATT10 <= cmd && cmd <=CMD_TRANDU7_WATT005)
				{
					cmd  = cmd-100;
					textWattBuff[cmd] = value;
				}
			break;
		}

	}
//	ReTry_Tx();
}

idata u16 numTest =0;


u8 Get_All_Catrige()
{
	if(systemErr ||systemCartStatus)
	{
		return 0;
	}
	switch (getCartStep)
	{
		case STEP0:
			systemLive = ALL_DIE;
			systemCartStatus = 0;
			systemErr = 0;
			TX_Rx_Msg(CMD_DO_ALL_LIVE, 0,&systemLive, 3000);

			switch (systemLive)
			{
				case LIVE_HP_DIE_RF:
					Event_PopUp(IDX_RF_COMU_ERR);// 0xFF IS TEMP
					systemLiveStatus = LIVE_HP_DIE_RF;
					systemErr = 1;
				break;

				case LIVE_RF_DIE_HP:
					Event_PopUp(IDX_HAND_COMU_ERR);// 0xFF IS TEMP
					systemLiveStatus = LIVE_RF_DIE_HP;
					systemErr = 2;
				break;

				case LIVE_ALL_DETH:
				case ALL_DIE:
					systemNorsvCnt++;
					if(systemNorsvCnt >= 3)
					{
						Event_PopUp(IDX_RF_COMU_ERR);// 0xFF IS TEMP
						sys_delay_ms(2000);
						Event_PopUp(IDX_HAND_COMU_ERR);// 0xFF IS TEMP

						systemLiveStatus = ALL_DIE;
						systemErr = 3;
					}
				break;


				break;
				case LIVE_HP_RF:
					TX_Msg(CMD_GET_ALL_CART, 0);
					systemTimeStemp = delay_tickMy;
					systemLiveStatus = LIVE_HP_RF;
					systemCartEnd = 0;
					getCartStep = STEP1;
				break;
			}

		break;

		case STEP1:
			if(systemCartEnd)
			{
				TX_Msg(CMD_GET_ALL_CART_END, 55);
				systemCartStatus = SYS_CART_OK;
				return 1;
			}
			else if(delay_tickMy - systemTimeStemp > 15000)// 7.5s
			{
				systemCartStatus = SYS_CART_TIMEOUT;
				systemErr = 4;
			}

		break;

	}

	return 0;
}

u8 System_Err_Check()
{
	u8 returnValue = 0;
	const u16 iconMainEn = ICON_SYS_CHK_MAIN_EN, iconGenEn = ICON_SYS_CHK_GEN_EN, iconHpEn = ICON_SYS_CHK_HP_EN;
	static u32 timeStamp = 0;
	returnValue = LCD_MODE_SYS_CHK;

	if(delay_tickMy-timeStamp >= 2000)
	{
		sys_write_vp(SYSTEM_ICON_ADDR, (u8*)&iconSystemCircle,2);
		if(sysChkFlag) iconSystemCircle++;

		if(iconSystemCircle == ICON_SYS_CHK_PER_30)
		{
			chkOkBuff[0] = 0;
			TX_Rx_Msg(CMD_OK, ERR_CHK_MAIN,&chkOkBuff[0], 500);
			if(chkOkBuff[0] == OK_MAIN)
			{
				sys_write_vp(SYSTEM_CHECK_CTRL_ICON_ADDR, (u8*)&iconMainEn,2);
				sysChkFlag = 1;
			}
			else
			{
				sysChkFlag = 0;
			}

		}

		if(iconSystemCircle == ICON_SYS_CHK_PER_60)
		{
			chkOkBuff[1] = 0;
			TX_Rx_Msg(CMD_OK, ERR_CHK_HP,&chkOkBuff[1], 500);
			if(chkOkBuff[1] == OK_HP)
			{
				sys_write_vp(SYSTEM_CHECK_GEN_ICON_ADDR, (u8*)&iconGenEn,2);
				sysChkFlag = 1;
			}
			else
			{
				sysChkFlag = 0;
			}
		}

		if(iconSystemCircle == ICON_SYS_CHK_PER_90)
		{
			chkOkBuff[2] = 0;
			TX_Rx_Msg(CMD_OK, ERR_CHK_RF,&chkOkBuff[2], 500);
			if(chkOkBuff[2] == OK_RF)
			{
				sys_write_vp(SYSTEM_CHECK_HP_ICON_ADDR, (u8*)&iconHpEn,2);
				sysChkFlag = 1;
			}
			else
			{
				sysChkFlag = 0;
			}
		}


		if(iconSystemCircle>ICON_SYS_CHK_PER_100)
		{
			if(systemLiveStatus == LIVE_HP_RF && systemCartStatus == SYS_CART_OK)
			{
				iconSystemCircle = ICON_SYS_CHK_PER_0;
				Page_Change(LCD_MODE_MAIN);
				returnValue = LCD_MODE_MAIN;
			}
			else
			{
				systemErr = 5;
			}

		}
		timeStamp = delay_tickMy;
	}

	return returnValue;

}


void Touch_Pluse(u16 num)
{
	const u16 iconEmptyPoint = ICON_CALIB_EMPTY_POINT,  iconPoint = ICON_CALIB_POINT;
	pulseAddr = num;

	pulseStrAddr = MAIN_P_START_ADDR +(num-1)*2;
	TX_Msg(CMD_PLUSE_NUM, num);

	if(pulsePointAddr)
	{
		sys_write_vp(pulsePointAddr,(u8*)&iconEmptyPoint,2);
	}
	pulsePointAddr = MAIN_P_START_POINT_ADDR +(num-1)*2;
	sys_write_vp(pulsePointAddr,(u8*)&iconPoint,2);

}


u8 Test_Config()
{
	u8 returnValue = 0;
	static u32 timeStampQ = 0;
	u16 btn =0;
	int indData[4] ={0,};
	int Tint =10100;
	u8 Tu8 =120;
	u16 Tu16 =13130;
	u32 Tu32 =14140;

	returnValue = LCD_MODE_TEST;

	if(delay_tickMy-timeStampQ >= 3000)
	{
		TX_Msg(111, Tint);
		TX_Msg(222, Tu8);
		TX_Msg(333, Tu16);
		TX_Msg(444, Tu32);

		timeStampQ = delay_tickMy;
		numTest++;
	}
	sys_read_vp(TEST_BUTTON_ADDR,(u8*)&btn,1);
	if(btn)
	{
		switch (btn)
		{
			case 1:
				Ascii_Clear(ERROR_EVENT_ADDR);
				Ascii_text("0123453789012345378901234537890123453789", ERROR_EVENT_ADDR);
			break;

			case 2:
				Ascii_Clear(ERROR_EVENT_ADDR);
				Ascii_text("ABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJ", ERROR_EVENT_ADDR);
			break;
		}
		btn= 0;
		//Ascii_text("QWER MSG");
		sys_write_vp(TEST_BUTTON_ADDR,(u8*)&btn,2);
	}




	return LCD_MODE_TEST;
}


void Cartrige_Init()
{
	u16 add =0;
	u32 value =0;

	int i;
	for(i =1 ;i <18; i++)
	{
		add = (u16)(CART_VALUE_SATAT_ADDR + (i-1)*0x02);
//		textCartrigeBuff[i] = i*10;
		value = textCartrigeBuff[i];
		sys_write_vp(add,(u8*)&value,2);
	}

}

u8 System_Check_Config()
{
	u8 returnValue = 0;
	u16 btn =0;

	returnValue = LCD_MODE_SYS_CHK;
	switch (systemStep)
	{
		case STEP0:
			if(Get_All_Catrige())
			{
				systemStep = STEP1;
			}
		break;

		case STEP1:
			returnValue = System_Err_Check();
		break;
	}

	sys_read_vp(SYSTEM_BUTTON_ADDR,(u8*)&btn,1);
	if(btn)
	{
		switch (btn)
		{
			case BTN_SYSTEM_ERROK:
			if(errEvent)
			{
				errEvent = 0;
				sysChkFlag = 1;
				Event_PopDown();
			}
			break;
		}

		btn= 0;
		sys_write_vp(SYSTEM_BUTTON_ADDR,(u8*)&btn,2);
	}



	return returnValue;
}

u8 Init_Config()
{
	u8 returnValue = 0;
	u16 btn =0;

	returnValue = LCD_MODE_INIT;

	sys_read_vp(INITIAL_BUTTON_ADDR,(u8*)&btn,1);
	if(btn)
	{
		Page_Change(LCD_MODE_PASSWARD);
		returnValue = LCD_MODE_PASSWARD;

		btn= 0;
		sys_write_vp(INITIAL_BUTTON_ADDR,(u8*)&btn,2);
	}

	return returnValue;
}

u8 PassWard_Config()
{
	int ccpy = 0;
	u16 add = 0;
	u8 returnValue = 0;
	returnValue = LCD_MODE_PASSWARD;
	sys_read_vp(PW_NUM_BUTTON_ADDR,(u8*)&btn,1);
	if(btn)
	{
		switch (btn)
		{
			case KEY_0:
			case KEY_1:
			case KEY_2:
			case KEY_3:
			case KEY_4:
			case KEY_5:
			case KEY_6:
			case KEY_7:
			case KEY_8:
			case KEY_9:
				if(pwCnt<ICON_PASSWARD_4)
				{
					if(btn == KEY_0) textCpy = textCpy*10 + 0;
					else textCpy = textCpy*10 + btn;
					pwCnt++;
					sys_write_vp(PW_ICON_ADDR, (u8*)&pwCnt,2);
				}
			break;

			case KEY_DEL:
				if(pwCnt>ICON_PASSWARD_0)
				{
					textCpy = textCpy/10;
					pwCnt--;
					sys_write_vp(PW_ICON_ADDR, (u8*)&pwCnt,2);
				}
			break;

			case KEY_CLEAR:
				pwCnt = ICON_PASSWARD_0;
				textCpy = 0;
				sys_write_vp(PW_ICON_ADDR, (u8*)&pwCnt,2);
			break;


		}

		if(pwCnt == ICON_PASSWARD_4)
		{
			if(textCpy == 4444||textCpy == 1111)
			{
				if(textCpy == 1111) engineerKey = 1;

				sys_delay_ms(300);
				pwCnt = ICON_PASSWARD_0;
				textCpy = 0;
				sys_write_vp(PW_ICON_ADDR, (u8*)&pwCnt,2);
				returnValue = LCD_MODE_SYS_CHK;

				Page_Change(LCD_MODE_SYS_CHK);
				sysTimeStamp = delay_tickMy;
			}
			else
			{

				sys_delay_ms(300);

				pwCnt = ICON_PASSWARD_ERR;
				sys_write_vp(PW_ICON_ADDR, (u8*)&pwCnt,2);
				sys_delay_ms(1000);

				pwCnt = ICON_PASSWARD_0;
				textCpy = 0;
				sys_write_vp(PW_ICON_ADDR, (u8*)&pwCnt,2);
			}

		}

		btn= 0;
		sys_write_vp(PW_NUM_BUTTON_ADDR,(u8*)&btn,2);

	}


	return returnValue;

}

u8 Main_Config_old()
{
	u8 returnValue = 0;
	int i =0;
	const u16 icon44 = 44, icon45 = 45;
	returnValue = LCD_MODE_MAIN;


	sys_read_vp(MAIN_BUTTON_ADDR,(u8*)&btnMain,1);
	if(btnMain)
	{
		switch (btnMain)
		{
			case BTN_MAIN_ENERGY_UP:
				TX_Msg(CMD_ENERGY, BUTTON_UP);//
			break;
			case BTN_MAIN_ENERGY_DN:
				TX_Msg(CMD_ENERGY, BUTTON_DN);//
			break;
			case BTN_MAIN_PULSE_DURATION_UP:
				TX_Msg(CMD_PULSE_DURATION, BUTTON_UP);//
			break;
			case BTN_MAIN_PULSE_DURATION_DN:
				TX_Msg(CMD_PULSE_DURATION, BUTTON_DN);//
			break;
			case BTN_MAIN_POST_COOLING_UP:
				TX_Msg(CMD_POST_COOLING, BUTTON_UP);//
			break;
			case BTN_MAIN_POST_COOLING_DN:
				TX_Msg(CMD_POST_COOLING, BUTTON_DN);//
			break;
			case BTN_MAIN_INTERVAL_UP:
				TX_Msg(CMD_INTERVAL, BUTTON_UP);//
			break;
			case BTN_MAIN_INTERVAL_DN:
				TX_Msg(CMD_INTERVAL, BUTTON_DN);//
			break;
			case BTN_MAIN_CURRENT_SHOT_RST:
				TX_Msg(CMD_CURRENT_SHOT, 0);
			break;
			case BTN_MAIN_TOTAL_JOULE_RST:
				TX_Msg(CMD_TOTAL_JOULE, 0);//
			break;
			case BTN_MAIN_RDY_STNBY:
				if(rdyStnbyMode==STATUS_STNBY)
				{TX_Msg(CMD_LCD_STATUS, STATUS_PRECOOLING);}//
				else
				{TX_Msg(CMD_LCD_STATUS, STATUS_STNBY);}//
			break;

			case BTN_MAIN_SETTING:
				Page_Change(LCD_MODE_SETTING);
				returnValue = LCD_MODE_SETTING;
			break;

			case BTN_MAIN_ERR_OK:
				if(errEvent)
				{
					errEvent = 0;
					Event_PopDown();
				}
			break;
			case BTN_MAIN_ENGINIER:
				if(engineerKey)
				{
					egCnt++;
					if(egCnt==1)
					{
						egCnt = 0;
						Page_Change(LCD_MODE_ENGINIEER);
						returnValue = LCD_MODE_ENGINIEER;
					}
				}
			break;


			case BTN_MAIN_TEST_2_PULSE:
				TX_Msg(CMD_TEST_PULSE, 2);
			break;

			case BTN_MAIN_TEST_3_PULSE:
				TX_Msg(CMD_TEST_PULSE, 3);
			break;

			case BTN_MAIN_TEST_4_PULSE:
				TX_Msg(CMD_TEST_PULSE, 4);
			break;

			case BTN_MAIN_TEST_5_PULSE:
				TX_Msg(CMD_TEST_PULSE, 5);
			break;
		}

		btnMain= 0;
		sys_write_vp(MAIN_BUTTON_ADDR,(u8*)&btnMain,2);
	}

	EXP_FreeCool_Motion();
//	RX_MODE_MAIN_Parssing_Config();
//	if(errEventFlag)
//	{
//		Page_Change(LCD_MODE_MAIN_POPUP);
//		returnValue = LCD_MODE_MAIN_POPUP;
//	}


	return returnValue;

}



u8 Main_Config()
{
	u8 returnValue = 0;

	returnValue = LCD_MODE_MAIN;


	sys_read_vp(MAIN_BUTTON_ADDR,(u8*)&btnMain,1);
	if(btnMain)
	{
		switch (btnMain)
		{
			case BTN_MAIN_P1_WATT:
			case BTN_MAIN_P1_DURATION_TIME :
			case BTN_MAIN_P1_INTERVAL_TIME :
			case BTN_MAIN_P2_WATT:
			case BTN_MAIN_P2_DURATION_TIME :
			case BTN_MAIN_P2_INTERVAL_TIME :
			case BTN_MAIN_P3_WATT:
			case BTN_MAIN_P3_DURATION_TIME :
			case BTN_MAIN_P3_INTERVAL_TIME :
			case BTN_MAIN_P4_WATT:
			case BTN_MAIN_P4_DURATION_TIME :
			case BTN_MAIN_POSTCO0L_TIME:
				Touch_Pluse(btnMain);
			break;

			case BTN_MAIN_UP:
				TX_Msg(CMD_PLUSE_BTN_UP_DN, BUTTON_UP);
			break;

			case BTN_MAIN_DN:
				TX_Msg(CMD_PLUSE_BTN_UP_DN, BUTTON_DN);
			break;

			case BTN_MAIN_RDY_STNBY_N:
				if(rdyStnbyMode == STATUS_STNBY)
				{TX_Msg(CMD_LCD_STATUS, STATUS_PRECOOLING);}//
				else
				{TX_Msg(CMD_LCD_STATUS, STATUS_STNBY);}//
			break;
			case BTN_MAIN_CURRENT_SHOT_RST_N:
				TX_Msg(CMD_CURRENT_SHOT, 0);
			break;
			case BTN_MAIN_TOTAL_JOULE_RST_N:
				TX_Msg(CMD_TOTAL_JOULE, 0);//
			break;

			case BTN_MAIN_ENGINIER_N:
				if(engineerKey)
				{
					egCnt++;
					if(egCnt==1)
					{
						egCnt = 0;
						Page_Change(LCD_MODE_ENGINIEER);
						returnValue = LCD_MODE_ENGINIEER;
					}
				}
			case BTN_MAIN_SETTING_N:
				Page_Change(LCD_MODE_SETTING);
				returnValue = LCD_MODE_SETTING;
			break;


			break;



		}

		btnMain= 0;
		sys_write_vp(MAIN_BUTTON_ADDR,(u8*)&btnMain,2);
	}

	EXP_FreeCool_Motion();

	return returnValue;

}


u8 Setting_Config()
{
	int ccpy = 0;
	u16 add = 0;
	u8 returnValue = 0;

	returnValue = LCD_MODE_SETTING;
	sys_read_vp(SETTING_BUTTON_ADDR,(u8*)&btnSetting,1);
	if(btnSetting)
	{
		switch (btnSetting)
		{
			case BTN_SETTING_BACKHOME:
				sys_read_vp(0x82,(u8*)btnLight,1);
				sys_read_vp(0xa1,(u8*)btnVol,1);

				lightLevel = (u16)btnLight[0];
				volumeLevel = (u16)btnVol[0];

				Flash_Volume_Write();
				Flash_Light_Write();

				returnValue = LCD_MODE_MAIN;
				Page_Change(LCD_MODE_MAIN);
			break;

			case BTN_SETTING_VOL_CHECK:
				sys_read_vp(0xa1,(u8*)btnVol,1);

				volumeLevel = (u16)btnVol[0];
				Volume_Change(3, volumeLevel);
			break;

		}




		btnSetting= 0;
		sys_write_vp(SETTING_BUTTON_ADDR,(u8*)&btnSetting,2);
	}


	return returnValue;

}




void Watt_Save()
{
	u16 add = 0;
	int i=0, j=0 ;
	u16 cmd = 0;
	u32 value = 0;

	for(i =1 ;i <= 77;i++)
	{
		cmd = i+CMD_TRANDU_WATT_BASE;// 101~177
		value = textWattBuff[i];
		TX_Msg(cmd, value);//
	}

}

void Calibration_TDU_Parts()//
{

	u16 btnTtext;
	u16 add = 0, pointAdd = 0;
	const u16 iconEmptyPoint = ICON_CALIB_EMPTY_POINT,  iconPoint = ICON_CALIB_POINT;

	sys_read_vp(CAL_TOUCH_TDU_ADDR, (u8*)&btnTtext,1);
	if (btnTtext)
	{
		pointAdd = (u16)(TRANDU_WATT_POINT_ADDR + (btnTtext-1)*0x02);

		if(prePointAddr &&prePointAddr != pointAdd)
		{
			sys_write_vp(prePointAddr,(u8*)&iconEmptyPoint,2);
		}
		sys_write_vp(pointAdd,(u8*)&iconPoint,2);


		prePointAddr = pointAdd;

		wattIdxMain = btnTtext;
		calMode = CAL_MODE_WATT;
		textNum = textWattBuff[wattIdxMain];

		btnTtext= 0;
		sys_write_vp(CAL_TOUCH_TDU_ADDR,(u8*)&btnTtext,2);
	}


}


u8 Calibration_Config()//
{
	u8 returnValue = 0;
	int value = 0;
	int ccpy = 0;
	u16 add = 0,addSub = 0;
	u16 addIcon = 0;
	int i = 0;
	const u16 iconReady = ICON_CALIB_READY, iconStandby = ICON_CALIB_STANDBY, iconDis = ICON_CALIB_DISABLE, iconEn = ICON_CALIB_ENABLE;
	u16 btn,bntED;
	returnValue = LCD_MODE_CALIBRATION;
	sys_read_vp(START_TOUCH_BTN_ADDR,(u8*)&btn,1);
	if(btn)
	{
		switch (btn)
		{
			case KEY_0:
			case KEY_1:
			case KEY_2:
			case KEY_3:
			case KEY_4:
			case KEY_5:
			case KEY_6:
			case KEY_7:
			case KEY_8:
			case KEY_9:
			case KEY_DEL:
				if(calMode == 0) break;

				if(btn==KEY_0) textNum = textNum*10 + 0;
				else if(btn==KEY_DEL )
				{
					if(textNum !=0) textNum = textNum/10;
				}
				else textNum = textNum*10 + btn;

				if(textNum > 100) textNum = 100;
				else if(textNum < 0) textNum = 0;

				textWattBuff[wattIdxMain] = textNum;
				add = (u16)(TRANDU_WATT_NUM_ADDR + (wattIdxMain-1)*0x02);
				sys_write_vp(add,(u8*)&textNum,2);


			break;

			case KEY_CAL_WATT_LOAD:
				////==Watt_Load();
			break;

			case KEY_CAL_WATT_SAVE:
				Watt_Save();
			break;

			case KEY_CAL_BACK_MAIN:
				if(expFlag)
				{
					expFlag = 0;
				}
				TX_Msg(CMD_CAIV_DURATION, 0xff);//

				Page_Change(LCD_MODE_ENGINIEER);
				returnValue = LCD_MODE_ENGINIEER;
			break;

			case KEY_CAL_UP:
				if(onTimeCalv<130)onTimeCalv++;
				sys_write_vp(CALIV_PULSETIME_ADDR,(u8*)&onTimeCalv ,4);
			break;

			case KEY_CAL_DN:
				if(onTimeCalv>0)onTimeCalv--;
				sys_write_vp(CALIV_PULSETIME_ADDR,(u8*)&onTimeCalv ,4);
			break;
		}
		btn= 0;
		sys_write_vp(START_TOUCH_BTN_ADDR,(u8*)&btn,2);

	}

	Calibration_TDU_Parts();

	sys_read_vp(CAL_TOUCH_ENDIS_ADDR,(u8*)&bntED,1);
	if(bntED)
	{
		add = (u16)(EN_ICON_ADDR + (bntED-1)*0x02);
		if(edBuff[bntED])
		{
			edBuff[bntED] = 0;
			if(bntED==ED_RDY_SBY)
			{
				sys_write_vp(add, (u8*)&iconStandby,2);
				TX_Msg(CMD_TRET_READY_OK, 0);//
			}
			else sys_write_vp(add, (u8*)&iconDis,2);

		}
		else
		{
			edBuff[bntED] = 1;
			if(bntED==ED_RDY_SBY)
			{
				sys_write_vp(add, (u8*)&iconReady,2);
				Calv_Tx_Msg();
			}
			else sys_write_vp(add, (u8*)&iconEn,2);

		}
		bntED= 0;
		sys_write_vp(CAL_TOUCH_ENDIS_ADDR,(u8*)&bntED,2);
	}


//	RX_CALIBRATION_Parssing_Config();
	return returnValue;

}

void Cartrige_Parts()//
{

	u16 btnTtext;
	u16 add = 0, pointAdd = 0;
	const u16 iconEmptyPoint = ICON_CALIB_EMPTY_POINT,  iconPoint = ICON_CALIB_POINT;

	sys_read_vp(CARTRIGE_TOUCH_ADDR, (u8*)&btnTtext,1);
	if (btnTtext)
	{
		pointAdd = (u16)(CART_POINT_SATAT_ADDR + (btnTtext-1)*0x02);

		if(cartPrePointAddr &&cartPrePointAddr != pointAdd)
		{
			sys_write_vp(cartPrePointAddr,(u8*)&iconEmptyPoint,2);
		}
		sys_write_vp(pointAdd,(u8*)&iconPoint,2);


		cartPrePointAddr = pointAdd;

		cartIdx = btnTtext;
		Debug_Print(0,cartIdx);
		cartTouch = 1;
		cartValue = textCartrigeBuff[cartIdx];

		btnTtext= 0;
		sys_write_vp(CARTRIGE_TOUCH_ADDR,(u8*)&btnTtext,2);
	}


}

u8 Cartrige_Set_Config()//
{
	u8 returnValue = 0;
	int value = 0;
	int ccpy = 0;
	u16 add = 0,addSub = 0;
	u16 addIcon = 0;
	int i = 0;
	const u16 iconReady = ICON_CALIB_READY, iconStandby = ICON_CALIB_STANDBY, iconDis = ICON_CALIB_DISABLE, iconEn = ICON_CALIB_ENABLE;
	u16 btn;
	returnValue = LCD_MODE_CART_SETTING;
	sys_read_vp(CARTRIGE_KEYPAD_ADDR,(u8*)&btn,1);
	if(btn)
	{
		switch (btn)
		{
			case KEY_0:
			case KEY_1:
			case KEY_2:
			case KEY_3:
			case KEY_4:
			case KEY_5:
			case KEY_6:
			case KEY_7:
			case KEY_8:
			case KEY_9:
			case KEY_DEL:
				if(cartTouch == 0) break;

				if(btn==KEY_0) cartValue = cartValue*10 + 0;
				else if(btn==KEY_DEL )
				{
					if(cartValue !=0) cartValue = cartValue/10;
				}
				else cartValue = cartValue*10 + btn;

				if(cartValue < 0) cartValue = 0;

				textCartrigeBuff[cartIdx] = cartValue;
				add = (u16)(CART_VALUE_SATAT_ADDR + (cartIdx-1)*0x02);
				sys_write_vp(add,(u8*)&cartValue,2);


			break;

			case KEY_CART1_SET:
				TX_Msg(CMD_CART_ID, textCartrigeBuff[CART_IDX_CART_ID]);
			break;

			case KEY_CART2_SET:
				TX_Msg(CMD_MANUFAC_YY, textCartrigeBuff[CART_IDX_MANUFAC_YY]);
//				sys_delay_ms(200);
				TX_Msg(CMD_MANUFAC_MM, textCartrigeBuff[CART_IDX_MANUFAC_MM]);
//				sys_delay_ms(200);
				TX_Msg(CMD_MANUFAC_DD, textCartrigeBuff[CART_IDX_MANUFAC_DD]);
//				sys_delay_ms(200);
			break;

			case KEY_CART3_SET:
				TX_Msg(CMD_ISSUED_YY, textCartrigeBuff[CART_IDX_ISSUED_YY]);
//				sys_delay_ms(200);
				TX_Msg(CMD_ISSUED_MM, textCartrigeBuff[CART_IDX_ISSUED_MM]);
//				sys_delay_ms(200);
				TX_Msg(CMD_ISSUED_DD, textCartrigeBuff[CART_IDX_ISSUED_DD]);
//				sys_delay_ms(200);
			break;

			case KEY_CART4_SET:
				TX_Msg(CMD_TRANDU1_FRQ, textCartrigeBuff[CART_IDX_TRANDU1_FRQ]);
			break;

			case KEY_CART5_SET:
				TX_Msg(CMD_TRANDU2_FRQ, textCartrigeBuff[CART_IDX_TRANDU2_FRQ]);
			break;

			case KEY_CART6_SET:
				TX_Msg(CMD_TRANDU3_FRQ, textCartrigeBuff[CART_IDX_TRANDU3_FRQ]);
			break;

			case KEY_CART7_SET:
				TX_Msg(CMD_TRANDU4_FRQ, textCartrigeBuff[CART_IDX_TRANDU4_FRQ]);
			break;

			case KEY_CART8_SET:
				TX_Msg(CMD_TRANDU5_FRQ, textCartrigeBuff[CART_IDX_TRANDU5_FRQ]);
			break;

			case KEY_CART9_SET:
				TX_Msg(CMD_TRANDU6_FRQ, textCartrigeBuff[CART_IDX_TRANDU6_FRQ]);
			break;

			case KEY_CART10_SET:
				TX_Msg(CMD_TRANDU7_FRQ, textCartrigeBuff[CART_IDX_TRANDU7_FRQ]);
			break;

			case KEY_CART11_SET:
				TX_Msg(CMD_REMIND_SHOT, textCartrigeBuff[CART_IDX_REMIND_SHOT]);
			break;

			case KEY_CART12_SET:
				//Watt_Load();
			break;

			case KEY_CART13_SET:
				TX_Msg(CMD_RTC, textCartrigeBuff[CART_IDX_RTC]);
			break;


			case KEY_CAL_BACK_MAIN:

				Page_Change(LCD_MODE_ENGINIEER);
				returnValue = LCD_MODE_ENGINIEER;
			break;


		}
		btn= 0;
		sys_write_vp(CARTRIGE_KEYPAD_ADDR,(u8*)&btn,2);
	}

	Cartrige_Parts();

	return returnValue;

}

void AutoCal_PointToggle()
{
	u16 add = 0;
	const u16 iconEmptyPoint = ICON_CALIB_EMPTY_POINT, iconPoint = ICON_CALIB_POINT;
	static u32 timeStamp = 0;

	if(autoCalStart == 0)return;

	if(delay_tickMy-timeStamp >= 500)
	{

		if(toggle)
		{
			toggle = 0;
			sys_write_vp(autoCalAdd, (u8*)&iconEmptyPoint,2);
		}
		else
		{
			toggle = 1;
			sys_write_vp(autoCalAdd, (u8*)&iconPoint,2);

		}
		timeStamp = delay_tickMy;
	}

}


u8 Auto_Calibration_Config()//
{
	u8 returnValue = 0;
	int value = 0;
	u16 addIcon = 0;
	int i = 0;
	u16 btn,bntED = 0;
	returnValue = LCD_MODE_AUTOCAL;
	sys_read_vp(AUTOCAL_BUTTON_ADDR,(u8*)&btn,1);
	if(btn)
	{
		switch (btn)
		{
			case KEY_AUTO_CAL_1_2:
				TX_Msg(CMD_LCD_AUTO_CAL, KEY_AUTO_CAL_1_2);//
			break;

			case KEY_AUTO_CAL_3_4_5:
				TX_Msg(CMD_LCD_AUTO_CAL, KEY_AUTO_CAL_3_4_5);//
			break;

			case KEY_AUTO_CAL_6_7:
				TX_Msg(CMD_LCD_AUTO_CAL, KEY_AUTO_CAL_6_7);//
			break;

			case KEY_AUTO_CAL_STOP:
				TX_Msg(CMD_LCD_AUTO_CAL, KEY_AUTO_CAL_STOP);//
			break;

			case KEY_AUTO_CAL_BACK:
				Page_Change(LCD_MODE_ENGINIEER);
				returnValue = LCD_MODE_ENGINIEER;
				TX_Msg(CMD_LCD_AUTO_CAL, KEY_AUTO_CAL_BACK);//
			break;

		}
		btn= 0;
		sys_write_vp(AUTOCAL_BUTTON_ADDR,(u8*)&btn,2);

	}

	AutoCal_PointToggle();

//	RX_AUTOCAL_Parssing_Config();
	return returnValue;

}


u8 Information_Config()//
{
	u8 returnValue = 0;
	u16 btn =0;
	returnValue = LCD_MODE_INFOMATION;
	sys_read_vp(INFOMATION_BUTTON_ADDR,(u8*)&btn,1);
	if(btn)
	{
		switch (btn)
		{
			case BTN_INFO_BACKHOME:
				Page_Change(LCD_MODE_ENGINIEER);
				returnValue = LCD_MODE_ENGINIEER;
			break;

		}
		btn= 0;
		sys_write_vp(INFOMATION_BUTTON_ADDR,(u8*)&btn,2);

	}

	return returnValue;
}

u8 Engineer_Config()//
{
	u8 returnValue = 0;
	u16 btn =0;
	u16 add =0;
	u32 value =0;

	int i =0;

	returnValue = LCD_MODE_ENGINIEER;

	sys_read_vp(ENGINEER_BUTTON_ADDR,(u8*)&btn,1);
	if(btn)
	{
		switch (btn)
		{
			case BTN_EG_INFOMATION:
				Page_Change(LCD_MODE_INFOMATION);
				returnValue = LCD_MODE_INFOMATION;
			break;

			case BTN_EG_CALIBRATION:
#if 0
			calRcvCnt = 0;

			for(i =1 ;i <= 7; i++)
			{
				add = (u16)(TRANDU_FREQ_NUM_ADDR + (i-1)*0x02);
				value = textFrqBuff[i];
				sys_write_vp(add,(u8*)&value,2);
			}
			for(i =1 ;i <= 77; i++)
			{
				TX_Rx_Msg(CMD_TRANDU_WATT_BASE+i, REQ_DATA, textWattBuff+i );
				add = (u16)(TRANDU_WATT_NUM_ADDR + (i-1)*0x02);
				value = textWattBuff[i];
				sys_write_vp(add,(u8*)&value,2);
			}


#endif
			break;

			case BTN_EG_BACKHOME:
				Page_Change(LCD_MODE_MAIN);
				returnValue = LCD_MODE_MAIN;
			break;

			case BTN_EG_AUTOCAL:
#if 0
			autoCalRcvCnt = 0;

			for(i =CMD_TRANDU1_FRQ ;i <= CMD_TRANDU7_FRQ; i++)
			{
				add = (u16)(TRANDU_FREQ_NUM_ADDR + (i-1)*0x02);
				value = textFrqBuff[i];
				sys_write_vp(add,(u8*)&value,2);
			}
			for(i =CMD_TRANDU1_WATT10 ;i <= CMD_TRANDU7_WATT005; i++)
			{
				TX_RF_DA_Req_Msg(i);
			}

			for(i =1 ;i <= 77; i++)
			{
				add = (u16)(TRANDU_WATT_NUM_ADDR + (i-1)*0x02);
				value = textWattBuff[i];
				sys_write_vp(add,(u8*)&value,2);
			}
			timeStampQ = delay_tickMy;
#endif
			break;

			case BTN_EG_CART_SET:
				Cartrige_Init();
				Page_Change(LCD_MODE_CART_SETTING);
				returnValue = LCD_MODE_CART_SETTING;
			break;


		}
		btn= 0;
		sys_write_vp(ENGINEER_BUTTON_ADDR,(u8*)&btn,2);

	}


//	RX_ENGINIEER_Parssing_Config();


	return returnValue;

}

#if 0
u8 Pop_Main_Config()//
{
	u8 returnValue = 0;
	u16 btn =0;
	u16 add =0;
	u32 value =0;

	int i =0;

	returnValue = LCD_MODE_MAIN_POPUP;

	sys_read_vp(ENGINEER_BUTTON_ADDR,(u8*)&btn,1);
	if(btn)
	{
		switch (btn)
		{
			case BTN_EG_INFOMATION:
				Page_Change(LCD_MODE_MAIN);
				returnValue = LCD_MODE_MAIN;
			break;
		}
		btn= 0;
		sys_write_vp(ENGINEER_BUTTON_ADDR,(u8*)&btn,2);

	}

	return returnValue;

}

u8 Pop_System_Chk_Config()//
{
	u8 returnValue = 0;
	u16 btn =0;
	u16 add =0;
	u32 value =0;

	int i =0;

	returnValue = LCD_MODE_SYS_CHK_POPUP;

	sys_read_vp(ENGINEER_BUTTON_ADDR,(u8*)&btn,1);
	if(btn)
	{
		switch (btn)
		{
			case BTN_EG_INFOMATION:
				Page_Change(LCD_MODE_SYS_CHK);
				returnValue = LCD_MODE_SYS_CHK;
			break;
		}
		btn= 0;
		sys_write_vp(ENGINEER_BUTTON_ADDR,(u8*)&btn,2);

	}

	return returnValue;

}

#endif

void Debug_PrintConfig()
{
#if 0
	static u32 timeStamp;
	if(delay_tickMy-timeStamp >= 2000)
	{
		int indData1 = 0,indData2 = 0,indData3 = 0;


		indData1 = uartCmdTemp;
		indData2 = uartValueTemp;
		indData3 = lcdPage;

		printf("debug %d %d %d \r\n",indData1, indData2, indData3);
		timeStamp = delay_tickMy;
	}

#endif
}

void Mode_Config()//
{
	switch (lcdPage)
	{
		case LCD_MODE_INIT:
			lcdPage = Init_Config();
		break;
		case LCD_MODE_PASSWARD:
			lcdPage = PassWard_Config();
		break;

		case LCD_MODE_MAIN:
			lcdPage = Main_Config();
		break;

		case LCD_MODE_SETTING:
			lcdPage = Setting_Config();
		break;

		case LCD_MODE_SYS_CHK:
			lcdPage = System_Check_Config();
		break;

		case LCD_MODE_CALIBRATION:
			lcdPage = Calibration_Config();
		break;

		case LCD_MODE_ENGINIEER:
			lcdPage = Engineer_Config();
		break;

		case LCD_MODE_INFOMATION:
			lcdPage = Information_Config();
		break;

		case LCD_MODE_TEST:
			lcdPage = Test_Config();
		break;

		case LCD_MODE_AUTOCAL:
			lcdPage = Auto_Calibration_Config();
		break;

		case LCD_MODE_CART_SETTING:
			lcdPage = Cartrige_Set_Config();
		break;


//		case LCD_MODE_MAIN_POPUP:
//			lcdPage = Pop_Main_Config();
//		break;

//		case LCD_MODE_SYS_CHK_POPUP:
//			lcdPage = Pop_System_Chk_Config();
//		break;

	}
	Debug_PrintConfig();
	RX_Parssing_Config();

}





void Lcd_Init()//
{
	int i = 0;
	int j = 0;
	const u16 iconStandby = ICON_MAIN_STANDBY;

	pwCnt = 0;
	iconCircle = 0;
	iconSystemCircle = 16;

	sys_delay_ms(500);


	expFlag = 0;

	energy=0;
	pulseDuration=0;
	postCooling=0;
	interval=0;
	currentShot=0;
	totalJoule=0;
	rdyStnbyMode=0;
	egCnt= 0;
	onTimeCalv=0;
	toggle = 1;
	autoCalAdd = 0;
	autoCalAddPre = 0;
	autoCalIng = 0;
	autoCalStart = 0;
	calMode = 0;
	frqIdx = 0;
	wattIdxMain = 0;
	wattIdxSub = 0;
	prePointAddr = 0;
	autoCalRcvCnt = 0;
	calRcvCnt = 0;
	iconMove = ICON_MAIN_COOLING1;

	manufacYY = 0;
	manufacMM = 0;
	manufacDD = 0;
	issuedYY=0;
	issuedMM = 0;
	issuedDD = 0;
	sysChkFlag = 1;
	Rtc = 0;
	reTxCmd = 0;
	reTxData = 0;
	reTxTimeStamp = 0;
	reTxCnt = 0;

	cartTouch = 0;
	cartIdx = 0;
	cartValue = 0;
	cartPrePointAddr = 0;
	errEvent = 0;
	errCartEvent = 0;
	sysChkStart = 0;
	sysChkStartTime = 0;
	getCartStep = STEP0;
	systemStep = STEP0;
	systemLive = 0;
	systemLiveStatus = 0;
	systemCartStatus = 0;
	systemErr = 0;
	systemTimeStemp = 0;
	systemNorsvCnt = 0;
	systemCartEnd = 0;
	chkOk = 0;
	temperature = 0;
	peltierDuty = 0;
	lcdPageForceFlag = 0;
	pulseStrAddr = 0;
	pulsePointAddr = 0;
	pulseAddr = 0;
	Flash_Read();



	sys_write_vp(READY_STANDBY_ICON_ADDR,(u8*)&iconStandby ,2);

	uartRxStep = 0;
	uartCmdTemp = 0;
	uartValueTemp = 0;
	for(i =0 ;i < 20;i++) uartRxBuff[i] = 0;
	for(i =0 ;i < 30;i++) errEventFlag[i] = 0;

	uartRxFlag = 0;
	for(i =0 ;i < 10;i++)
	{
		dataBuff[i] = 0;
	}
	for(i =0 ;i < 9;i++)
	{
		mainDataBuff[i] = 0;
	}
	for(i =0 ;i < 30;i++)
	{
		errEventBuff[i] = 0;
	}
	for(i =0 ;i < 3;i++)
	{
		chkOkBuff[i] = 0;
	}

	for(i =1 ;i <18; i++)
	{
		textCartrigeBuff[i] = 0;
	}





/////////////////////


	for( i =0 ;i < 9;i++)
	{
		edBuff[i] = 0;
	}
	engineerKey = 0;




#if 0
	lcdPage = LCD_MODE_INIT;

#else //  시간단축 하이패스
	lcdPage = LCD_MODE_MAIN;

	Page_Change(LCD_MODE_MAIN);




#endif


}

void main(void)
{
	sys_init();//溝固놓迦뺏
	uart2_init(115200);//놓迦뺏눔왯2
	Lcd_Init();
	sys_delay_ms(1000);




	while(1)
	{
		Mode_Config();
	}
}

