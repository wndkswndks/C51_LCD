#include "sys.h"
#include "uart2.h"
#include "nor_flash.h"

#include <stdio.h>
#include <string.h>

#define NOR_FLASH_DATA_ADDR		0













//==================================================






//==================================================









//==================================================
//0x2000
//page0 use btnN
#define INITIAL_BUTTON_ADDR  	0x2000

//==================================================


//==================================================
//0x2100
//page1 use btn

#define MAIN_BUTTON_ADDR		0x2100
#define ENERGY_UP_LONG_BTN_ADDR	    	0x2102
#define ENERGY_DN_LONG_BTN_ADDR		    0x2104

#define DURATION_UP_LONG_BTN_ADDR	    0x2106
#define DURATION_DN_LONG_BTN_ADDR	    0x2108

#define POST_UP_LONG_BTN_ADDR	    	0x210A
#define POST_DN_LONG_BTN_ADDR	   	 	0x210C

//page1 use icon
#define ERR_POPUP_BOX_ICON_ADDR     0x2110//page1,2
#define EVNT_MSG_ADDR   	   	   	0x2112//page1,2
#define HAND_EN_ADDR				0x2114
#define CALIV_PULSE_ICON_ADDR		0x2116
#define VIBE_LEVEL_ICON_ADDR		0x2118
#define CIRCLE_WATE_ADDR			0x211A
#define ERROR_EVENT_ADDR		 	0x211C
#define EVENT_ICON_ADDR		 		0x211E
#define EVENT_CODE_ADDR		 		0x2120
#define EVENT_OK_ADDR		 		0x2122

//page1 use num

#define ENERGY_NUM_ADDR 			0x2150
#define PULSE_DURATION_NUM_ADDR 	0x2152
#define POST_COOLING_NUM_ADDR 		0x2154
#define INTERVAL_NUM_ADDR 			0x2156
#define TOTAL_JOULE_NUM_ADDR 		0x2158//
#define REMIND_SHOT_NUM_ADDR 		0x215A//
#define CURRENT_SHOT_NUM_ADDR 		0x215C//

#define CURRENT_SHOT1_NUM_ADDR		0x215E
#define CURRENT_SHOT2_NUM_ADDR		0x2160
#define CURRENT_SHOT3_NUM_ADDR		0x2162
#define CURRENT_SHOT4_NUM_ADDR		0x2164
#define CURRENT_SHOT5_NUM_ADDR		0x2166

#define TOTAL_ENERGY1_NUM_ADDR		0x2168
#define TOTAL_ENERGY2_NUM_ADDR		0x216A
#define TOTAL_ENERGY3_NUM_ADDR		0x216C
#define TOTAL_ENERGY4_NUM_ADDR		0x216E
#define TOTAL_ENERGY5_NUM_ADDR		0x2170

#define AVG_ENERGY1_NUM_ADDR		0x2172
#define AVG_ENERGY2_NUM_ADDR		0x2174
#define AVG_ENERGY3_NUM_ADDR		0x2176
#define AVG_ENERGY4_NUM_ADDR		0x2178
#define AVG_ENERGY5_NUM_ADDR		0x217A

#define AREA1_ICON_ADDR				0x217C
#define AREA2_ICON_ADDR				0x217E
#define AREA3_ICON_ADDR				0x2180
#define AREA4_ICON_ADDR				0x2182
#define AREA5_ICON_ADDR				0x2184



//page1 SP use
#define XY_SP_CURRENT_SHOT1_ADD  	0x5000
#define XY_SP_CURRENT_SHOT2_ADD  	0x5020
#define XY_SP_CURRENT_SHOT3_ADD  	0x5040
#define XY_SP_CURRENT_SHOT4_ADD  	0x5060
#define XY_SP_CURRENT_SHOT5_ADD  	0x5080

#define XY_SP_TOTAL_ENERGY1_ADD  	0x50A0
#define XY_SP_TOTAL_ENERGY2_ADD  	0x50C0
#define XY_SP_TOTAL_ENERGY3_ADD  	0x50E0
#define XY_SP_TOTAL_ENERGY4_ADD  	0x5100
#define XY_SP_TOTAL_ENERGY5_ADD  	0x5120

#define XY_SP_AGV_ENERGY1_ADD  		0x5140
#define XY_SP_AGV_ENERGY2_ADD  		0x5160
#define XY_SP_AGV_ENERGY3_ADD  		0x5180
#define XY_SP_AGV_ENERGY4_ADD  		0x51A0
#define XY_SP_AGV_ENERGY5_ADD  		0x51C0


//page1 un use

#define TEMP_DEBUG_NUM_ADDR			 0x2850
#define DUTY_DEBUG_NUM_ADDR			 0x2852
#define ERR_POPUP_LEVEL_ICON_ADDR    0x2702
#define ERR_POPUP_CODE_ICON_ADDR     0x2704
#define ERR_POPUP_MSG_ICON_ADDR      0x2706
#define CURRENT_JOULE_NUM_ADDR 		 0x271A

//==================================================
//0x2200
//page2 use btn
#define SETTING_BUTTON_ADDR		0x2200

//page2 use icon

//page2 use num


//page2 un use

//==================================================
//==================================================
//0x2300
//page3 use btn
#define SYSTEM_BUTTON_ADDR			 0x2300

//page3 use icon
#define SYSTEM_ICON_ADDR			 	0x2312
#define SYSTEM_CHECK_CTRL_ICON_ADDR  	0x2314
#define SYSTEM_CHECK_GEN_ICON_ADDR	 	0x2316
#define SYSTEM_CHECK_HP_ICON_ADDR	 	0x2318
#define SYSTEM_CHECK_COOL_ICON_ADDR  	0x231A

#define SYS_ERR_POPUP_BOX_ICON_ADDR     0x231C//page1,2
#define SYS_EVNT_MSG_ADDR   	   	   	0x231E//page1,2
#define SYS_EVENT_ICON_ADDR		 		0x2320
#define SYS_EVENT_CODE_ADDR		 		0x2322
#define SYS_EVENT_OK_ADDR		 		0x2324

//page3 use num



//page3 un use

//==================================================
//==================================================
//0x23C0
//page4 use btn
#define START_TOUCH_BTN_ADDR		0x23C0
#define CAL_TOUCH_TDU_ADDR			0x23C2

//page4 use icon
#define TRANDU_WATT_POINT_ADDR 		0x23D0
#define TRANDU_WATT_POINT_END_ADDR 	0x2476

//page4 use num


#define CALIV_PULSETIME_NUM_NUM_ADDR 	0x2478

#define TRANDU_FREQ_NUM_START_ADDR       	0x2500
#define TRANDU_FREQ_NUM_1_ADDR       		0x2500
#define TRANDU_FREQ_NUM_2_ADDR       		0x2502
#define TRANDU_FREQ_NUM_3_ADDR       		0x2504
#define TRANDU_FREQ_NUM_4_ADDR       		0x2506
#define TRANDU_FREQ_NUM_5_ADDR       		0x2508
#define TRANDU_FREQ_NUM_6_ADDR       		0x250A
#define TRANDU_FREQ_NUM_7_ADDR       		0x250C
#define TRANDU_FREQ_NUM_END_ADDR      	 	0x250C

#define TRANDU_WATT_START_NUM_ADDR       	0x2510

#define TRANDU_WATT_1_START_NUM_ADDR       	0x2510
#define TRANDU_WATT_1_END_NUM_ADDR       	0x2524

#define TRANDU_WATT_2_START_NUM_ADDR       	0x2526
#define TRANDU_WATT_2_END_NUM_ADDR       	0x253A

#define TRANDU_WATT_3_START_NUM_ADDR       	0x253C
#define TRANDU_WATT_3_END_NUM_ADDR       	0x2550

#define TRANDU_WATT_4_START_NUM_ADDR       	0x2552
#define TRANDU_WATT_4_END_NUM_ADDR       	0x2566

#define TRANDU_WATT_5_START_NUM_ADDR       	0x2568
#define TRANDU_WATT_5_END_NUM_ADDR       	0x257C

#define TRANDU_WATT_6_START_NUM_ADDR       	0x257E
#define TRANDU_WATT_6_END_NUM_ADDR       	0x2592

#define TRANDU_WATT_7_START_NUM_ADDR       	0x2594
#define TRANDU_WATT_7_END_NUM_ADDR       	0x25A8

#define TRANDU_WATT_END_NUM_ADDR       		0x25A8

#define TRANDU_WATT_EXP1_NUM_ADDR       	0x25AA
#define TRANDU_WATT_EXP2_NUM_ADDR       	0x25AC
#define TRANDU_WATT_EXP3_NUM_ADDR       	0x25AE
#define TRANDU_WATT_EXP4_NUM_ADDR       	0x25B0
#define TRANDU_WATT_EXP5_NUM_ADDR       	0x25B2
#define TRANDU_WATT_EXP6_NUM_ADDR       	0x25B4
#define TRANDU_WATT_EXP7_NUM_ADDR       	0x25B6


//page4 un use

//==================================================
//==================================================
//0x2600
//page9 use btn
#define ENGINEER_BUTTON_ADDR	0x2600

//page9 use icon

//page9 use num



//page9 un use

//==================================================
//==================================================
//0x2700
//page10 use btn
#define INFOMATION_BUTTON_ADDR	0x2700
#define INFOMATION_TOUCH_ADDR	0x2702


//page10 use icon
#define INFO_POINT_SATAT_ADDR       0x2710
#define INFO_POINT_UI_DESING_ADDR   0x2710
#define INFO_POINT_UI_FW_ADDR     	0x2712
#define INFO_POINT_MAIN_FW_ADDR     0x2714
#define INFO_POINT_HP_FW_ADDR     	0x2716
#define INFO_POINT_RF_FW_ADDR     	0x2718
#define INFO_POINT_YY_ADDR     		0x271A
#define INFO_POINT_MM_ADDR     		0x271C
#define INFO_POINT_DD_ADDR     		0x271E
#define INFO_POINT_HOUR_ADDR     	0x2720
#define INFO_POINT_MIN_ADDR     	0x2722
#define INFO_POINT_SEC_ADDR     	0x2724
#define INFO_POINT_END_ADDR       	0x2724
//page10 use num

#define INFO_NUM_SATAT_ADDR       	0x2750
#define INFO_NUM_UI_DESING_ADDR     0x2750
#define INFO_NUM_UI_FW_ADDR     	0x2752
#define INFO_NUM_MAIN_FW_ADDR     	0x2754
#define INFO_NUM_HP_FW_ADDR     	0x2756
#define INFO_NUM_RF_FW_ADDR     	0x2758
#define INFO_NUM_YY_ADDR     		0x275A
#define INFO_NUM_MM_ADDR     		0x275C
#define INFO_NUM_DD_ADDR     		0x275E
#define INFO_NUM_HOUR_ADDR     		0x2760
#define INFO_NUM_MIN_ADDR     		0x2762
#define INFO_NUM_SEC_ADDR     		0x2764
#define INFO_NUM_END_ADDR       	0x2764

//page10 un use

//==================================================
//==================================================
//0x2800
//page11 use btn
#define PW_NUM_BUTTON_ADDR		0x2800

//page11 use icon
#define PW_ICON_ADDR			0x2810
//page11 use num



//page11 un use

//==================================================
//==================================================
//0x2900
//page12 use btn
#define TEST_BUTTON_ADDR		0x2900
//page12 use icon

//page12 use num

#define TEST_NUM_ADDR1			0x2950
#define TEST_NUM_ADDR2			0x2952
#define TEST_NUM_ADDR3			0x2954
#define TEST_NUM_ADDR4			0x2956

#define XY_SP_TEST_ADD1  		0x51E0
#define XY_SP_TEST_ADD2  		0x5200
#define XY_SP_TEST_ADD3  		0x5220
#define XY_SP_TEST_ADD4  		0x5240


//page12 un use

//==================================================

//==================================================
//0x2A00
//page14 use btn
#define CARTRIGE_KEYPAD_ADDR	0x2A00
#define CARTRIGE_TOUCH_ADDR		0x2A02

//page14 use icon
#define CART_POINT_SATAT_ADDR   0x2A10
#define CART_POINT_1_ADDR       0x2A10
#define CART_POINT_2_ADDR       0x2A12
#define CART_POINT_3_ADDR       0x2A14
#define CART_POINT_4_ADDR       0x2A16
#define CART_POINT_5_ADDR       0x2A18
#define CART_POINT_6_ADDR       0x2A1A
#define CART_POINT_7_ADDR       0x2A1C
#define CART_POINT_8_ADDR       0x2A1E
#define CART_POINT_9_ADDR       0x2A20
#define CART_POINT_10_ADDR      0x2A22
#define CART_POINT_11_ADDR      0x2A24
#define CART_POINT_12_ADDR      0x2A26
#define CART_POINT_13_ADDR      0x2A28
#define CART_POINT_14_ADDR      0x2A2A
#define CART_POINT_15_ADDR      0x2A2C
#define CART_POINT_16_ADDR      0x2A2E
#define CART_POINT_17_ADDR      0x2A30
#define CART_POINT_18_ADDR      0x2A32
#define CART_POINT_19_ADDR      0x2A34
#define CART_POINT_20_ADDR      0x2A36
#define CART_POINT_21_ADDR      0x2A38
#define CART_POINT_22_ADDR      0x2A3A
#define CART_POINT_23_ADDR      0x2A3C
#define CART_POINT_24_ADDR      0x2A3E

#define CART_MINUS_1_ADDR      0x2A40
#define CART_MINUS_2_ADDR      0x2A42
#define CART_MINUS_3_ADDR      0x2A44
#define CART_MINUS_4_ADDR      0x2A46
#define CART_MINUS_5_ADDR      0x2A48
#define CART_MINUS_6_ADDR      0x2A4A
#define CART_MINUS_7_ADDR      0x2A4C
#define CART_MINUS_8_ADDR      0x2A4E


//page14 use num


#define CART_VALUE_SATAT_ADDR       	0x2A50
#define CART_VALUE_CART_ID_ADDR       	0x2A50
#define CART_VALUE_MANUFAC_YY_ADDR      0x2A52
#define CART_VALUE_MANUFAC_MM_ADDR      0x2A54
#define CART_VALUE_MANUFAC_DD_ADDR      0x2A56
#define CART_VALUE_ISSUED_YY_ADDR       0x2A58
#define CART_VALUE_ISSUED_MM_ADDR       0x2A5A
#define CART_VALUE_ISSUED_DD_ADDR       0x2A5C
#define CART_VALUE_TRANDU1_ADDR       	0x2A5E
#define CART_VALUE_TRANDU2_ADDR       	0x2A60
#define CART_VALUE_TRANDU3_ADDR      	0x2A62
#define CART_VALUE_TRANDU4_ADDR      	0x2A64
#define CART_VALUE_TRANDU5_ADDR      	0x2A66
#define CART_VALUE_TRANDU6_ADDR      	0x2A68
#define CART_VALUE_TRANDU7_ADDR      	0x2A6A
#define CART_VALUE_REMIND_SHOT_ADDR     0x2A6C
#define CART_VALUE_STATUS_ADDR      	0x2A6E
#define CART_TEMP1_OFFSET_ADDR      	0x2A70
#define CART_TEMP2_OFFSET_ADDR      	0x2A72
#define CART_TEMP3_OFFSET_ADDR      	0x2A74
#define CART_TEMP4_OFFSET_ADDR      	0x2A76
#define CART_TEMP5_OFFSET_ADDR      	0x2A78
#define CART_TEMP6_OFFSET_ADDR      	0x2A7A
#define CART_TEMP7_OFFSET_ADDR      	0x2A7C
#define CART_TEMP8_OFFSET_ADDR      	0x2A7E


#define CART_VALUE_END_ADDR       		0x2A80

//page14 un use

//==================================================
//==================================================
//0x2B00
//page15 use btn
#define DEVICE_STATUS_BUTTON_ADDR 	0x2B00
//page15 use icon
#define DEBUG_STATUS_1_ADDR	 		0x2B10
#define DEBUG_STATUS_2_ADDR	 		0x2B12
#define DEBUG_STATUS_3_ADDR	 		0x2B14
#define DEBUG_STATUS_4_ADDR	 		0x2B16
#define DEBUG_STATUS_5_ADDR	 		0x2B18
#define DEBUG_STATUS_6_ADDR	 		0x2B1A
#define DEBUG_STATUS_7_ADDR	 		0x2B1C
#define DEBUG_STATUS_8_ADDR	 		0x2B1E
#define DEBUG_STATUS_9_ADDR	 		0x2B20
#define DEBUG_STATUS_10_ADDR	 	0x2B22
//page15 use num

#define DEBUG_DATA_1_ADDR	 		0x2B50
#define DEBUG_DATA_2_ADDR	 		0x2B52
#define DEBUG_DATA_3_ADDR	 		0x2B54
#define DEBUG_DATA_4_ADDR	 		0x2B56
#define DEBUG_DATA_5_ADDR	 		0x2B58
#define DEBUG_DATA_6_ADDR	 		0x2B5A
#define DEBUG_DATA_7_ADDR	 		0x2B5C
#define DEBUG_DATA_8_ADDR	 		0x2B5E
#define DEBUG_DATA_9_ADDR	 		0x2B60
#define DEBUG_DATA_10_ADDR	 		0x2B62

//page15 un use

//==================================================
//==================================================
//0x2C00
//page16 use btn
#define ERROR_EVENT_BUTTON_ADDR		  0x2C00
//page16 use icon

//page16 use num
#define DEBUG_ERRCNT_1_ADDR    0x2C10
#define DEBUG_ERRCNT_2_ADDR    0x2C12
#define DEBUG_ERRCNT_3_ADDR    0x2C14
#define DEBUG_ERRCNT_4_ADDR    0x2C16
#define DEBUG_ERRCNT_5_ADDR    0x2C18
#define DEBUG_ERRCNT_6_ADDR    0x2C1A
#define DEBUG_ERRCNT_7_ADDR    0x2C1C
#define DEBUG_ERRCNT_8_ADDR    0x2C1E
#define DEBUG_ERRCNT_9_ADDR    0x2C20
#define DEBUG_ERRCNT_10_ADDR   0x2C22
#define DEBUG_ERRCNT_11_ADDR   0x2C24
#define DEBUG_ERRCNT_12_ADDR   0x2C26
#define DEBUG_ERRCNT_13_ADDR   0x2C28
#define DEBUG_ERRCNT_14_ADDR   0x2C2A
#define DEBUG_ERRCNT_15_ADDR   0x2C2C
#define DEBUG_ERRCNT_16_ADDR   0x2C2E
#define DEBUG_ERRCNT_17_ADDR   0x2C30
#define DEBUG_ERRCNT_18_ADDR   0x2C32
#define DEBUG_ERRCNT_19_ADDR   0x2C34
#define DEBUG_ERRCNT_20_ADDR   0x2C36
#define DEBUG_ERRCNT_21_ADDR   0x2C38
#define DEBUG_ERRCNT_22_ADDR   0x2C3A
#define DEBUG_ERRCNT_23_ADDR   0x2C3C
#define DEBUG_ERRCNT_24_ADDR   0x2C3E
#define DEBUG_ERRCNT_25_ADDR   0x2C40
#define DEBUG_ERRCNT_26_ADDR   0x2C42
#define DEBUG_ERRCNT_27_ADDR   0x2C44
#define DEBUG_ERRCNT_28_ADDR   0x2C46
#define DEBUG_ERRCNT_29_ADDR   0x2C48
#define DEBUG_ERRCNT_30_ADDR   0x2C4A
#define DEBUG_ERRCNT_31_ADDR   0x2C4C
#define DEBUG_ERRCNT_32_ADDR   0x2C4E
#define DEBUG_ERRCNT_33_ADDR   0x2C50
#define DEBUG_ERRCNT_34_ADDR   0x2C52
#define DEBUG_ERRCNT_35_ADDR   0x2C54
#define DEBUG_ERRCNT_36_ADDR   0x2C56
#define DEBUG_ERRCNT_37_ADDR   0x2C58
#define DEBUG_ERRCNT_38_ADDR   0x2C5A
#define DEBUG_ERRCNT_39_ADDR   0x2C5C
#define DEBUG_ERRCNT_40_ADDR   0x2C5E
#define DEBUG_ERRCNT_41_ADDR   0x2C60
#define DEBUG_ERRCNT_42_ADDR   0x2C62
#define DEBUG_ERRCNT_43_ADDR   0x2C64
#define DEBUG_ERRCNT_44_ADDR   0x2C66
#define DEBUG_ERRCNT_45_ADDR   0x2C68
#define DEBUG_ERRCNT_46_ADDR   0x2C6A
#define DEBUG_ERRCNT_47_ADDR   0x2C6C
#define DEBUG_ERRCNT_48_ADDR   0x2C6E
#define DEBUG_ERRCNT_49_ADDR   0x2C70
#define DEBUG_ERRCNT_50_ADDR   0x2C72

//page16 un use

//==================================================

//==================================================















//==================================================













typedef enum
{

	CURRENT_SHOT_POS_X	= 641,
	TOTAL_ENERGY_POS_X	= 	967,
	AGV_ENERGY_POS_X =   1300,
	HIDE_NUM_X	 = 2000,

	POS_1_Y = 630,
	POS_2_Y = 684,
	POS_3_Y = 738,
	POS_4_Y = 792,
	POS_5_Y = 846,

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
	CART_IDX_TEMP_OFFS_1,
	CART_IDX_TEMP_OFFS_2,
	CART_IDX_TEMP_OFFS_3,
	CART_IDX_TEMP_OFFS_4,
	CART_IDX_TEMP_OFFS_5,
	CART_IDX_TEMP_OFFS_6,
	CART_IDX_TEMP_OFFS_7,
	CART_IDX_TEMP_OFFS_8,
	INFO_IDX_DUMY = 0,
	INFO_IDX_UI_DESIGN,
	INFO_IDX_UI_FW,
	INFO_IDX_MAIN_FW,
	INFO_IDX_HP_FW,
	INFO_IDX_RF_FW,
	INFO_IDX_YY,
	INFO_IDX_MM,
	INFO_IDX_DD,
	INFO_IDX_HOUR,
	INFO_IDX_MIN,
	INFO_IDX_SEC,

	LIVE_ALL_DETH = 0,
	LIVE_HP_DIE_RF = 10,
	LIVE_RF_DIE_HP = 1,
	LIVE_HP_RF = 11,
	ALL_DIE = 0xFF,

	SYS_CART_OK = 1,
	SYS_CART_TIMEOUT = 2,

	POPUP_MODE_1 = 1,
	POPUP_MODE_2 = 2,

	CART_EVENT_UNDETECT = 0,
	CART_EVENT_DETECT = 1,
	CART_EVENT_DETECT_NEW = 2,
	CART_EVENT_EXPRATION = 3,

	CATRIGE_CHK_OK = 0,
	CATRIGE_CHK_NEW = 1,
	CATRIGE_CHK_I2C_READ_ERR = 2,
	CATRIGE_CHK_I2C_WRITE_ERR = 3,
	CATRIGE_CHK_REMIND_ZERO_ERR = 4,
	CATRIGE_CHK_UN_DETECT = 5,


	IDX_DEBUG_TEMP 			= 1,
	IDX_DEBUG_MAIN_COMMU = 2,
	IDX_DEBUG_HAND_COMMU = 3,
	IDX_DEBUG_RF_COMMU 		= 4,
	IDX_DEBUG_RF_STATUS 	= 5,
	IDX_DEBUG_RTC_BATTRY 	= 6,
	IDX_DEBUG_FLOW_SENSOR   = 7,
	IDX_DEBUG_LEVEL_SENSOR  = 8,
	IDX_DEBUG_INSERT_HP	= 9,
	IDX_DEBUG_DETECTE_CART = 10,

	SWITCH_HAND = 0,
	SWITCH_FOOT = 1,

	LIVE_HP = 10,
	LIVE_RF = 1,
	LIVE_HP_DETH = 20,
	LIVE_RF_DETH = 2,

	ERR_ADDER = 0,
	ALRAM_ADDER = 100,
	INFO_ADDER = 200,
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
	BTN_MAIN_ALL_RST = 9,
	BTN_MAIN_PULSE_CHANGE = 10,
	BTN_MAIN_RDY_STNBY = 11,
	BTN_MAIN_SETTING = 12,
	BTN_MAIN_ERR_OK_CENTER = 13,
	BTN_MAIN_VIBE_LEVEL = 14,
	BTN_MAIN_ENGINIER = 15,
	BTN_MAIN_NEW_AREA = 16,
	BTN_MAIN_HAND_FOOT = 17,
	BTN_MAIN_ERR_OK_LEFT = 18,
	BTN_MAIN_ERR_CANCEL_RIGHT = 19,





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
	BTN_MAIN_P1_ENDIS = 20,
	BTN_MAIN_P2_ENDIS = 21,
	BTN_MAIN_P3_ENDIS = 22,
	BTN_MAIN_P4_ENDIS = 23,
	BTN_MAIN_ERR_OK_CENTER_N = 24,
	BTN_MAIN_ERR_OK_LEFT_N = 25,
	BTN_MAIN_ERR_CANCEL_RIGHT_N = 26,


	//SYSTEM MODE
	BTN_SYSTEM_ERROK = 1,

	//SETTING MODE
	BTN_SETTING_BACKHOME = 1,
	BTN_SETTING_VOL_CHECK = 2,


	//ENGINER MODE
	BTN_EG_INFOMATION = 1,
	BTN_EG_CALIBRATION = 2,
	BTN_EG_CART_SET = 3,
	BTN_EG_ERR_EVENT = 4,
	BTN_EG_DEVICE_STATUS = 5,
	BTN_EG_BACKHOME = 6,

	//INFOMATION MODE
	BTN_INFO_BACKHOME = 13,
	BTN_INFO_UI_DESING_ADDR = 14,
	BTN_INFO_UI_FW_ADDR = 15,
	BTN_INFO_MAIN_FW_ADDR = 16,
	BTN_INFO_HP_FW_ADDR = 17,
	BTN_INFO_RF_FW_ADDR = 18,
	BTN_INFO_DAY_ADDR = 19,
	BTN_INFO_TIME_ADDR = 20,

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
	KEY_CLEAR = 11,
	KEY_DEL = 12,
	KEY_CAL_BACK_MAIN = 13,
	KEY_CAL_WATT_LOAD = 14,
	KEY_CAL_WATT_SAVE = 15,
	KEY_CAL_AUTOCAL = 16,
	KEY_CAL_TEMP_RST = 17,
	KEY_CAL_UP = 19,
	KEY_CAL_DN = 20,
	KEY_CAL_SHOT = 21,


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
	KEY_CART_ROAD,

	//DEVICE_STATUS

	KEY_DEVICE_BACKHOME =1,

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
	LCD_MODE_CART_SETTING  = 14,
	LCD_MODE_DEVICE_STATUS = 15,
	LCD_MODE_ERROR_EVENT = 	 16,
	LCD_MODE_MAIN_MAX = 	 17,


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

	CMD_TEMP_OFFSET = 29,

	CMD_CALIV_SHOT = 30,

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

	CMD_RTC_YY = 44,
	CMD_RTC_MM = 45,
	CMD_RTC_DD = 46,
	CMD_RTC_HOUR = 47,
	CMD_RTC_MIN = 48,
	CMD_RTC_SEC = 49,
	CMD_RTC_EN = 50,
	CMD_CART_ALLOW = 51,
	CMD_VIBE_LEVEL = 52,
	CMD_DEBUG_VIBE = 53,


	CMD_CATRIDGE_STATUS    = 56,
	CMD_CATRIDGE_EVENT= 57,
	CMD_FRQ_REQ = 58,
	CMD_WATT_REQ = 59,

	CMD_LCD_STATUS = 60,
	CMD_SYS_CHK = 61,
	CMD_INFOMATION = 62,
	CMD_DEVICE_STATUS = 63,
	CMD_ERR_EVENT = 64,
	CMD_AGING_BUTTON = 65,
	CMD_AUTO_EXP = 66,
	CMD_SYS_CHK_OK = 67,
	CMD_IS_CATRIDGE    = 68,
	CMD_HAND_FOOT    = 69,

	CMD_DO_ALL_LIVE = 70,
	CMD_GET_ALL_CART = 71,
	CMD_GET_ALL_CART_END = 72,
	CMD_TEST_PULSE = 73,
	CMD_GET_WATT_CART = 74,
	CMD_TEST_FORCE_PAGE_CHANGE = 75,
	CMD_TEMP_DUTY_ON = 76,

	CMD_INFO_UI_FW = 77,
	CMD_INFO_MAIN_FW = 78,
	CMD_INFO_HP_FW = 79,
	CMD_INFO_RF_FW = 80,
	CMD_PWM_DUTY = 81,
	CMD_TEMPERATURE= 82,
	CMD_COOLING = 83,
	CMD_ADC_CHANGE = 84,

	CMD_LCD_EXP = 85,
	CMD_LCD_AUTO_CAL = 87,
	CMD_PULSE_TRIGER = 88,
	CMD_INFO_UI_DESING = 89,



	CMD_RF_ALL_SETTING = 188,
	CMD_RF_WATT_MEATER_Z = 189,
	CMD_RF_SINGLE_EXP = 190,
	CMD_RF_WATT_MEATER_IP = 191,
	CMD_AUTO_CAL_START = 192,

	CMD_DEBUG_PUMP = 193,
	CMD_DEBUG_CHILLER = 194,
	CMD_DEBUG_PELTIER = 195,
	CMD_WATT_FEEDBACK = 196,
	CMD_BODY_LED_TEST = 197,
	CMD_DEBUG_CHLLER_TEST = 198,
	CMD_TTTEST = 199,

	CMD_HP1_ADD = 200,
	CMD_MAIN_RESET = 201,
	CMD_HP_RESET = 202,


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
	ICON_EVENT_NUM,//15
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
	ICON_SYS_CHK_COOL_DIS = 33,
	ICON_SYS_CHK_COOL_EN,

	ICON_MAIN_COOLING2,
	ICON_MAIN_COOLING3,
	ICON_MAIN_TREAT = 37,

	ICON_EVENT_INFO_BLK = 38,//38
	ICON_EVENT_ERR,
	ICON_EVENT_ALRAM,
	ICON_EVENT_INFO,



	ICON_CALIB_EMPTY_POINT = 42,
	ICON_CALIB_POINT = 43,

	ICON_HAND_EN = 44,
	ICON_HAND_DIS,

	ICON_MAIN_EMPTY_POP = 46,
	ICON_MAIN_POP = 47,
	ICON_MAIN_POP_SELLEC = 48,

	ICON_PULSE_BOX_ENABLE = 49,
	ICON_PULSE_BOX_DISABLE,
	ICON_PULSE_4_BOX_DISABLE,

	ICON_PULSE_BLOCK_ENABLE = 52,
	ICON_PULSE_BLOCK_DISABLE,

	ICON_PLUSE_EMPTY = 54,
	ICON_MINUS,

	ICON_STATUS_OK = 56,
	ICON_STATUS_ERR = 57,
	ICON_PULSE_1 	= 58,
	ICON_PULSE_2 	= 59,
	ICON_PULSE_3 	= 60,
	ICON_PULSE_4 	= 61,

	ICON_VIBE_OFF	= 62,
	ICON_VIBE_LV1	= 63,
	ICON_VIBE_LV2	= 64,
	ICON_VIBE_LV3	= 65,
	ICON_VIBE_LV4	= 66,

	ICON_OK_BLANK	 = 67,
	ICON_OK_IDLE	 = 68,
	ICON_CANCLE_IDLE = 69,
	ICON_OK_ACTIVE	 = 70,
	ICON_CANCLE_ACTIVE	= 71,

	ICON_STANDBY_BOX	= 72,
	ICON_CIRCLE_WATE0_BOX	= 73,
	ICON_CIRCLE_WATE1_BOX	= 74,
	ICON_CIRCLE_WATE2_BOX	= 75,
	ICON_CIRCLE_WATE3_BOX	= 76,
	ICON_CIRCLE_WATE4_BOX	= 77,
	ICON_CIRCLE_WATE5_BOX	= 78,
	ICON_CIRCLE_WATE6_BOX	= 79,
	ICON_CIRCLE_WATE7_BOX	= 80,
	ICON_CIRCLE_WATE8_BOX	= 81,

	ICON_CIRCLE_WATE9_BOX	= 82,
	ICON_CIRCLE_WATE10_BOX	= 83,
	ICON_CIRCLE_WATE11_BOX	= 84,
	ICON_CIRCLE_WATE12_BOX	= 85,
	ICON_CIRCLE_WATE13_BOX	= 86,
	ICON_CIRCLE_WATE14_BOX	= 87,
	ICON_CIRCLE_WATE15_BOX	= 88,
	ICON_CIRCLE_WATE16_BOX	= 89,
	ICON_CIRCLE_WATE17_BOX	= 90,
	ICON_CIRCLE_WATE18_BOX	= 91,
	ICON_CIRCLE_WATE19_BOX	= 92,
	ICON_CIRCLE_WATE_FULL_BOX	= 93,
	ICON_READY_BOX	= 94,

	ICON_AREA1 = 95,
	ICON_AREA2 = 96,
	ICON_AREA3 = 97,
	ICON_AREA4 = 98,
	ICON_AREA5 = 99,

	ICON_HAND = 100,
	ICON_FOOT = 101,

	ICON_MSG_BLK = 102,
	ICON_MSG_TEMP_OUT = 103,
	ICON_MSG_TEMP_LIMIT_UNDER = 104,
	ICON_MSG_TEMP_LOW = 105,
	ICON_MSG_FLOW_LIMIT_UNDER = 106,
	ICON_MSG_LEVEL_LOW = 107,
	ICON_MSG_AUTO_CAL_COMU_ERR = 108,
	ICON_MSG_BATTRY_LIMIT_OVER = 109,
	ICON_MSG_BATTRY_LIMIT_UNDER = 110,
	ICON_MSG_BATTRY_LIMIT_LOW = 111,
	ICON_MSG_RTC_ERR = 112,
	ICON_MSG_PRE_COOL_ERR = 113,
	ICON_MSG_HAND_COMU_ERR = 114,
	ICON_MSG_CATRIGE_I2C_ERR = 115,
	ICON_MSG_CATRIGE_NEW_DETECT = 116,
	ICON_MSG_CATRIGE_ID_ERR = 117,
	ICON_MSG_CATRIGE_MANU_ERR = 118,
	ICON_MSG_CATRIGE_MANU_OVER_ERR = 119,
	ICON_MSG_CATRIGE_ISUE_ERR = 120,
	ICON_MSG_CATRIGE_ISUE_OVER_ERR = 121,
	ICON_MSG_CATRIGE_WATT_ERR = 122,
	ICON_MSG_CATRIGE_FRQ_ERR = 123,
	ICON_MSG_CATRIGE_RESHOT_ERR = 124,
	ICON_MSG_CATRIGE_RESHOT_LOW = 125,
	ICON_MSG_CATRIGE_RESHOT_ZERO = 126,
	ICON_MSG_CATRIGE_DETECT = 127,
	ICON_MSG_CATRIGE_UN_DETECT = 128,
	ICON_MSG_RF_COMU_ERR = 129,
	ICON_MSG_RF_STATUS_ERR = 130,
	ICON_CODE_BLK = 131,
	ICON_ERROR_CODE_1 = 132,
	ICON_ERROR_CODE_2,
	ICON_ERROR_CODE_3,
	ICON_ERROR_CODE_4,
	ICON_ERROR_CODE_5,
	ICON_ERROR_CODE_6,
	ICON_ERROR_CODE_7,
	ICON_ERROR_CODE_8,
	ICON_ERROR_CODE_9,
	ICON_ERROR_CODE_10,
	ICON_ERROR_CODE_11,
	ICON_ERROR_CODE_12,
	ICON_ERROR_CODE_13,
	ICON_ERROR_CODE_14,
	ICON_ERROR_CODE_15,
	ICON_ERROR_CODE_16,
	ICON_ERROR_CODE_17,
	ICON_ERROR_CODE_18,
	ICON_ERROR_CODE_19,
	ICON_ERROR_CODE_20,
	ICON_ERROR_CODE_21,
	ICON_ERROR_CODE_22,
	ICON_ERROR_CODE_23,
	ICON_ERROR_CODE_24,
	ICON_ERROR_CODE_25,
	ICON_ERROR_CODE_26,
	ICON_ALRAM_CODE_1 = 158,
	ICON_ALRAM_CODE_2,
	ICON_ALRAM_CODE_3,
	ICON_ALRAM_CODE_4,
	ICON_ALRAM_CODE_5,
	ICON_ALRAM_CODE_6,
	ICON_INFO_CODE_1 = 164,
	ICON_INFO_CODE_2,
	ICON_INFO_CODE_3,
	ICON_INFO_CODE_4,
	ICON_INFO_CODE_5,
	ICON_INFO_CODE_6,
	ICON_INFO_CODE_7 = 170,


} ICON_E;

typedef enum
{
  IDX_MAIN_EVENT_START = 1,
  IDX_TEMP_OUT = IDX_MAIN_EVENT_START,
  IDX_TEMP_LIMIT_UNDER =2,//
  IDX_TEMP_LOW =3,//
  IDX_FLOW_LIMIT_UNDER =4,//
  IDX_LEVEL_LOW =5,//
  IDX_AUTO_CAL_COMU_ERR =6,//
  IDX_BATTRY_LIMIT_OVER =7,//
  IDX_BATTRY_LIMIT_UNDER =8,//
  IDX_BATTRY_LIMIT_LOW =9,//
  IDX_RTC_ERR =10,
  IDX_MAIN_EVENT_END =11,//~~~~~
//------------------------------
  IDX_HP_EVENT_START =12,//
  IDX_PRE_COOL_ERR = IDX_HP_EVENT_START,//
  IDX_HAND_COMU_ERR =13,//
  IDX_CATRIGE_I2C_ERR  =14,//
  IDX_CATRIGE_NEW_DETECT= 15,//
  IDX_CATRIGE_ID_ERR =16,//
  IDX_CATRIGE_MANU_ERR =17,//
  IDX_CATRIGE_MANU_OVER_ERR =18,//
  IDX_CATRIGE_ISUE_ERR =19,//
  IDX_CATRIGE_ISUE_OVER_ERR =20,//
  IDX_CATRIGE_WATT_ERR =21,//
  IDX_CATRIGE_FRQ_ERR =22,//
  IDX_CATRIGE_RESHOT_ERR =23,//
  IDX_CATRIGE_RESHOT_LOW =24,//
  IDX_CATRIGE_RESHOT_ZERO =25,//
  IDX_CATRIGE_DETECT =26,
  IDX_CATRIGE_UN_DETECT =27,//
  IDX_HP_EVENT_END =28,//~~~~~
//------------------------------
  IDX_RF_EVENT_START =29,
  IDX_RF_COMU_ERR = IDX_RF_EVENT_START,
  IDX_RF_STATUS_ERR =30,//
  IDX_RF_EVENT_END =31,//~~~~~
//------------------------------

  IDX_LCD_COMU_ERR,
  IDX_LCD_TIMEOUT,
  IDX_IS_CURRNTSHOT_RESET,
  IDX_IS_TOTALJULE_RESET,
  IDX_CATRIGE_NEW,
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
	STEP9,
	STEP10,
	STEP11,
	STEP12,
} STEP_E;

extern idata u32 delay_tickMy;
extern xdata u8  uartRxFlag;
extern xdata u8  uartRxStep;
extern xdata u8  uartCmdTemp;
extern xdata u16  uartValueTemp;

idata u32 textCpy=0;
xdata u16 btn,btnMain,btnSetting;


idata u8 toggle = 1;

xdata u16 pwCnt;
idata u8 lcdPage;


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



xdata u8 expFlag;
xdata u8 flashBuff[174];


///옮기는 변수는 오직이거

xdata u16 textFrqBuff[8];
xdata u16 textWattBuff[85];
xdata u16 textCartrigeBuff[25];
xdata u16 textinfoBuff[20];
xdata u16 cmdBuff[4][2];

xdata u8 wattIdxMain = 0;
xdata u16 iconMove;





idata u32 textNum=0;
idata u32 onTimeCalv=0;

///옮기는 변수는 오직이거

idata u8 egCnt = 0;
idata u8 engineerKey;
idata u16 lightLevel;
idata u16 volumeLevel;

idata u8 btnLight[4];
idata u8 btnVol[4];

xdata u8 calMode;
xdata u16 prePointAddr;

xdata u8 cartId;
xdata u16 manufacYY;
xdata u16 manufacMMDD;
xdata u16 manufacMM;
xdata u16 manufacDD;


xdata u16 issuedYY;
xdata u16 issuedMMDD;
xdata u16 issuedMM;
xdata u16 issuedDD;


xdata u8 sysChkFlag;


xdata u8 errEvent;
xdata u8 errCartEvent;

xdata u16 chkOkBuff[3];

xdata u32 reTxTimeStamp;

xdata u8 cartTouch;
xdata u8 cartIdx;
xdata u32 cartValue;
xdata u16 cartPrePointAddr;

xdata u8 infoTouch;
xdata u8 infoIdx;
xdata u32 infoValue;
xdata u16 infoPrePointAddr;


xdata u8 systemStep;
xdata u32 systemTimeStamp;
xdata u32 systemTimeTerm;

xdata u16 systemLive;
xdata u8 systemCartEnd;

xdata u8 popUpMode;
xdata u8 agingFlag;

xdata u8 agingLongFlag;

xdata u8 newAreaCnt;
xdata u32 shotSum;
xdata u32 totaljouleSum;


xdata u8 cmdRxRingCnt;
xdata u8 cmdPassingRingCnt;
xdata u16 yPointBuff[5];
xdata u32 testNum;
xdata u32 testNum2;
xdata u32 timeStampShot;
xdata u16 errCodeBuff[50];


void Light_Change(u16 light);
void Volume_Change(u8       id, u16 volume);
void Event_PopUp(u16 eventData);
void Area_Reset(u8 rst);


void Debug_Print(int num, int debugData)
{
	printf("debug <%d> <%d>\r\n",num, debugData);
}

void TX_Msg(u16 txCmd, u16 txData)
{
	while(delay_tickMy-reTxTimeStamp<100);

	printf("[%u,%u]\r\n",txCmd, txData);

	reTxTimeStamp = delay_tickMy;

}
void lcon_Printf(u16 addr, u16 icon)
{
	sys_write_vp(addr, (u8*)&icon,2);
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



void Calv_Tx_Msg()
{
	int i =0;
	u16 add = 0;
	u16 value = 0;
	u16 addIcon = 0;
	const u16 icon9 = 9;

	sys_delay_ms(100);

	value = onTimeCalv;

	TX_Msg(CMD_WATT_CH0, textWattBuff[78]);
	sys_delay_ms(50);
	TX_Msg(CMD_WATT_CH1, textWattBuff[79]);
	sys_delay_ms(50);
	TX_Msg(CMD_WATT_CH2, textWattBuff[80]);
	sys_delay_ms(50);
	TX_Msg(CMD_WATT_CH3, textWattBuff[81]);
	sys_delay_ms(50);
	TX_Msg(CMD_WATT_CH4, textWattBuff[82]);
	sys_delay_ms(50);
	TX_Msg(CMD_WATT_CH5, textWattBuff[83]);
	sys_delay_ms(50);
	TX_Msg(CMD_WATT_CH6, textWattBuff[84]);
	sys_delay_ms(50);

	TX_Msg(CMD_CALIV_SHOT, value);//
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
void XY_Change(u16 spAddr, u16 Xpoint, u16 Ypoint)
{
	u8 buf[4];

	buf[0] = (Xpoint>>8)&0xff;
	buf[1] = Xpoint&0xff;
	buf[2] = (Ypoint>>8)&0xff;
	buf[3] = Ypoint&0xff;
 	sys_write_vp(spAddr+1,buf,2);
}


void XY_test()
{
	u8 buf[4];

	buf[0] = 7;
	buf[1] = 8;
	buf[2] = 0;
	buf[3] = 255;
 	sys_write_vp(0x5021,buf,2);
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

void Volume_Off(u8   id, u16 volume)
{
	u8 buf[4];

	buf[0] = id;//id
	buf[1] = 0x01;
	buf[2] = volume;
	buf[3] = 0x00;
 	sys_write_vp(0x00a0,buf,2);
}


void NumColor_Change(u8       id, u16 volume)
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

void Err_Code_Select(u8 errNum)
{
	u16 eventCode = 0;
	u16 eventCodeIcon = 0;
	u16 eventNum = 0;
	u16 eventNumIcon = 0;

	eventCode = errCodeBuff[errNum]/100;
	eventCodeIcon = ICON_EVENT_ERR + eventCode;
	eventNum = errCodeBuff[errNum]%100;


	eventCode *= 100;
	switch (eventCode)
	{
		case ERR_ADDER:
			eventNumIcon = (ICON_ERROR_CODE_1-1) + eventNum;
		break;

		case ALRAM_ADDER:
			eventNumIcon = (ICON_ALRAM_CODE_1-1) + eventNum;
		break;

		case INFO_ADDER:
			eventNumIcon = (ICON_INFO_CODE_1-1) + eventNum;
		break;
	}

	if(lcdPage == LCD_MODE_SYS_CHK)
	{
		sys_write_vp(SYS_EVENT_ICON_ADDR,(u8*)&eventCodeIcon ,2);
		sys_write_vp(SYS_EVENT_CODE_ADDR,(u8*)&eventNumIcon ,2);

	}
	else
	{
		sys_write_vp(EVENT_ICON_ADDR,(u8*)&eventCodeIcon ,2);
		sys_write_vp(EVENT_CODE_ADDR,(u8*)&eventNumIcon ,2);

	}
}


void Err_Code_Clear()
{
	u16 eventCodeIcon = ICON_EVENT_INFO_BLK;
	u16 eventNumIcon = ICON_CODE_BLK;

	if (lcdPage == LCD_MODE_SYS_CHK)
	{
		sys_write_vp(SYS_EVENT_ICON_ADDR,(u8*)&eventCodeIcon ,2);
		sys_write_vp(SYS_EVENT_CODE_ADDR,(u8*)&eventNumIcon ,2);

	}
	else
	{
		sys_write_vp(EVENT_ICON_ADDR,(u8*)&eventCodeIcon ,2);
		sys_write_vp(EVENT_CODE_ADDR,(u8*)&eventNumIcon ,2);
	}
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
//	case IDX_FLOW_ZERO_IDX: 		  Ascii_text("FLOW_ZERO_IDX", add);	 break;
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
	case IDX_IS_CURRNTSHOT_RESET:	  Ascii_text("IS_CURRNTSHOT_RESET", add);	 break;
  	case IDX_IS_TOTALJULE_RESET:	  Ascii_text("IS_TOTALJULE_RESET", add);	 break;

	}
}

void Evnt_Msg_Up(u8 num)
{
	u16 msgIcon = 0;
	switch (num)
	{
		case 0:						msgIcon = 	ICON_MSG_BLK;		  		break;
		case IDX_TEMP_OUT:			msgIcon = 	ICON_MSG_TEMP_OUT;		  	break;
		case IDX_TEMP_LIMIT_UNDER:	msgIcon = 	ICON_MSG_TEMP_LIMIT_UNDER;		  break;
		case IDX_TEMP_LOW:			msgIcon = 	ICON_MSG_TEMP_LOW;		  		  break;
		case IDX_FLOW_LIMIT_UNDER:	msgIcon = 	ICON_MSG_FLOW_LIMIT_UNDER;		  break;
		case IDX_LEVEL_LOW: 		msgIcon = 	ICON_MSG_LEVEL_LOW;		  		  break;
		case IDX_AUTO_CAL_COMU_ERR: msgIcon = 	ICON_MSG_AUTO_CAL_COMU_ERR;		  break;
		case IDX_BATTRY_LIMIT_OVER:  msgIcon = 	ICON_MSG_BATTRY_LIMIT_OVER;		  break;
		case IDX_BATTRY_LIMIT_UNDER: msgIcon = 	ICON_MSG_BATTRY_LIMIT_UNDER;	  break;
		case IDX_BATTRY_LIMIT_LOW:	msgIcon = 	ICON_MSG_BATTRY_LIMIT_LOW;		  break;
		case IDX_RTC_ERR:			msgIcon = 	ICON_MSG_RTC_ERR;		  		  break;
		case IDX_PRE_COOL_ERR:		msgIcon = 	ICON_MSG_PRE_COOL_ERR;		  	  break;
		case IDX_HAND_COMU_ERR: 	msgIcon = 	ICON_MSG_HAND_COMU_ERR;	      	  break;
		case IDX_CATRIGE_I2C_ERR:	msgIcon = 	ICON_MSG_CATRIGE_I2C_ERR;		  break;
		case IDX_CATRIGE_NEW_DETECT: msgIcon = 	ICON_MSG_CATRIGE_NEW_DETECT;	  break;
		case IDX_CATRIGE_ID_ERR:	msgIcon = 	ICON_MSG_CATRIGE_ID_ERR;		  break;
		case IDX_CATRIGE_MANU_ERR:	msgIcon = 	ICON_MSG_CATRIGE_MANU_ERR;		  break;
		case IDX_CATRIGE_MANU_OVER_ERR: msgIcon = 	ICON_MSG_CATRIGE_MANU_OVER_ERR;	   break;
		case IDX_CATRIGE_ISUE_ERR:		msgIcon = 	ICON_MSG_CATRIGE_ISUE_ERR;	  	   break;
		case IDX_CATRIGE_ISUE_OVER_ERR:  msgIcon = 	ICON_MSG_CATRIGE_ISUE_OVER_ERR;	   break;
		case IDX_CATRIGE_WATT_ERR:		msgIcon = 	ICON_MSG_CATRIGE_WATT_ERR;	  	   break;
		case IDX_CATRIGE_FRQ_ERR:		msgIcon = 	ICON_MSG_CATRIGE_FRQ_ERR;	  	   break;
		case IDX_CATRIGE_RESHOT_ERR:	msgIcon = 	ICON_MSG_CATRIGE_RESHOT_ERR;	  break;
		case IDX_CATRIGE_RESHOT_LOW:	msgIcon = 	ICON_MSG_CATRIGE_RESHOT_LOW;	  break;
		case IDX_CATRIGE_RESHOT_ZERO:	msgIcon = 	ICON_MSG_CATRIGE_RESHOT_ZERO;	  break;
		case IDX_CATRIGE_DETECT:		msgIcon = 	ICON_MSG_CATRIGE_DETECT;	  	  break;
		case IDX_CATRIGE_UN_DETECT: 	msgIcon = 	ICON_MSG_CATRIGE_DETECT;	      break;
		case IDX_RF_COMU_ERR:			msgIcon = 	ICON_MSG_RF_COMU_ERR;	  break;
		case IDX_RF_STATUS_ERR: 		msgIcon = 	ICON_MSG_RF_STATUS_ERR;	  break;


	}

	if (lcdPage == LCD_MODE_SYS_CHK)
	{
		sys_write_vp(SYS_EVNT_MSG_ADDR,(u8*)&msgIcon ,2);
	}
	else
	{
		sys_write_vp(EVNT_MSG_ADDR,(u8*)&msgIcon ,2);
	}
}


void EXP_FreeCool_Motion()
{
	static u32 timeStamp;


	if(rdyStnbyMode != STATUS_PRECOOLING) return;

	if(delay_tickMy-timeStamp >= 200)
	{

		sys_write_vp(CIRCLE_WATE_ADDR,(u8*)&iconMove ,2);
		iconMove++;
		if(iconMove>ICON_CIRCLE_WATE_FULL_BOX)iconMove = ICON_CIRCLE_WATE0_BOX;

		timeStamp = delay_tickMy;

	}

}


void Event_PopUp(u16 eventData)
{
	u16 iconErrIcon= 0;
	const u16 iconErrBack1= ICON_MAIN_POP; // 고정
	const u16 iconOk= ICON_OK_IDLE; // 고정
	const u16 iconIcon= ICON_EVENT_INFO; // 고정
	u16 iconErrCode= 0;
	u16 iconErrMsg= 0;
	u16 errData;//errEnDis;

	errEvent = eventData;
	sysChkFlag = 0;
	errData = eventData;


//	popUpMode = POPUP_MODE_1;

	switch (errData)
	{
		case IDX_CATRIGE_NEW:
			popUpMode = POPUP_MODE_2;
//			sys_write_vp(ERR_POPUP_BOX_ICON_ADDR, (u8*)&iconErrBack2,2);//backGround
		break;

		default:
			popUpMode = POPUP_MODE_1;
//			sys_write_vp(ERR_POPUP_BOX_ICON_ADDR, (u8*)&iconErrBack1,2);//backGround
		break;
	}

	if(lcdPage == LCD_MODE_SYS_CHK)
	{
		sys_write_vp(SYS_ERR_POPUP_BOX_ICON_ADDR, (u8*)&iconErrBack1,2);//backGround
		sys_write_vp(SYS_EVENT_OK_ADDR, (u8*)&iconOk,2);//backGround
	}
	else
	{
		sys_write_vp(ERR_POPUP_BOX_ICON_ADDR, (u8*)&iconErrBack1,2);//backGround
		sys_write_vp(EVENT_OK_ADDR, (u8*)&iconOk,2);//backGround
	}




	Evnt_Msg_Up(errData);
	Err_Code_Select(errData);
	Volume_Change(6, volumeLevel);
}

void Event_PopDown_Ok()
{
	const u16 iconErrBack= ICON_MAIN_EMPTY_POP; // 고정
	const u16 iconOk= ICON_OK_BLANK; // 고정
	const u16 iconIcon= ICON_EVENT_INFO_BLK; // 고정
	popUpMode = 0;
	if(errEvent)
	{
#if 1
		switch (errEvent)
		{

			case IDX_CATRIGE_NEW:
				TX_Msg(CMD_CART_ALLOW, 1);
			break;
		}

#endif
		errEvent = 0;
		Evnt_Msg_Up(0);
		Err_Code_Clear();

		if (lcdPage == LCD_MODE_SYS_CHK)
		{
			sys_write_vp(SYS_ERR_POPUP_BOX_ICON_ADDR, (u8*)&iconErrBack,2);//backGround
			sys_write_vp(SYS_EVENT_OK_ADDR, (u8*)&iconOk,2);//backGround
		}
		else
		{
			sys_write_vp(ERR_POPUP_BOX_ICON_ADDR, (u8*)&iconErrBack,2);//backGround
			sys_write_vp(EVENT_OK_ADDR, (u8*)&iconOk,2);//backGround
		}
	}

}

void Event_PopDown_Cancel()
{
	const u16 iconErrBack= ICON_MAIN_EMPTY_POP; // 고정
	const u16 iconOk= ICON_OK_BLANK; // 고정
	popUpMode = 0;
	if(errEvent)
	{
		errEvent = 0;
		Evnt_Msg_Up(0);
		Err_Code_Clear();

		if (lcdPage == LCD_MODE_SYS_CHK)
		{
			sys_write_vp(SYS_ERR_POPUP_BOX_ICON_ADDR, (u8*)&iconErrBack,2);//backGround
			sys_write_vp(SYS_EVENT_OK_ADDR, (u8*)&iconOk,2);//backGround
		}
		else
		{
			sys_write_vp(ERR_POPUP_BOX_ICON_ADDR, (u8*)&iconErrBack,2);//backGround
			sys_write_vp(EVENT_OK_ADDR, (u8*)&iconOk,2);//backGround

		}
	}

}
void Event_PopUp_ORG(u16 eventData)
{
	u16 iconErrIcon= 0;
	const u16 iconErrBack1= ICON_MAIN_POP; // 고정
	const u16 iconOk= ICON_OK_IDLE; // 고정
	const u16 iconIcon= ICON_EVENT_INFO; // 고정
	u16 iconErrCode= 0;
	u16 iconErrMsg= 0;
	u16 errData;//errEnDis;

	errEvent = eventData;
	sysChkFlag = 0;
	errData = eventData;

//	switch (errData)
//	{
//		case IDX_CATRIGE_NEW:
//		case IDX_CATRIGE_DETECT:
//			popUpMode = POPUP_MODE_2;
//			sys_write_vp(ERR_POPUP_BOX_ICON_ADDR, (u8*)&iconErrBack2,2);//backGround
//		break;

//		default:
//			popUpMode = POPUP_MODE_1;
//			sys_write_vp(ERR_POPUP_BOX_ICON_ADDR, (u8*)&iconErrBack1,2);//backGround
//		break;
//	}

	popUpMode = POPUP_MODE_1;
	sys_write_vp(ERR_POPUP_BOX_ICON_ADDR, (u8*)&iconErrBack1,2);//backGround
	sys_write_vp(EVENT_OK_ADDR, (u8*)&iconOk,2);//backGround


	Evnt_Msg_Up(errData);
	Err_Code_Select(errData);
	Volume_Change(6, volumeLevel);
}

void Event_PopDown_Ok_ORG()
{
	const u16 iconErrBack= ICON_MAIN_EMPTY_POP; // 고정
	const u16 iconOk= ICON_OK_BLANK; // 고정
	const u16 iconIcon= ICON_EVENT_INFO_BLK; // 고정
	popUpMode = 0;
	if(errEvent)
	{
#if 0
		switch (errEvent)
		{

			case IDX_CATRIGE_NEW:
			case IDX_CATRIGE_DETECT:
				TX_Msg(CMD_CART_ALLOW, 1);
			break;
		}

#endif
		errEvent = 0;
		Evnt_Msg_Up(0);
		Err_Code_Clear();
		sys_write_vp(ERR_POPUP_BOX_ICON_ADDR, (u8*)&iconErrBack,2);//backGround
		sys_write_vp(EVENT_OK_ADDR, (u8*)&iconOk,2);//backGround
	}

}

void Event_PopDown_Cancel_ORG()
{
	const u16 iconErrBack= ICON_MAIN_EMPTY_POP; // 고정
	const u16 iconOk= ICON_OK_BLANK; // 고정
	popUpMode = 0;
	if(errEvent)
	{
		errEvent = 0;
		Evnt_Msg_Up(0);
		Err_Code_Clear();
		sys_write_vp(ERR_POPUP_BOX_ICON_ADDR, (u8*)&iconErrBack,2);//backGround
		sys_write_vp(EVENT_OK_ADDR, (u8*)&iconOk,2);//backGround
	}

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

void Device_Satatus_Passing(u16 passingValue)
{
	u16 add = 0;
	u32 statusData = 0;
	const u16 iconSatusOk = ICON_STATUS_OK, iconSatusErr = ICON_STATUS_ERR;
	add = passingValue/1000;
	statusData = passingValue%1000;
	switch (add)
	{
		case IDX_DEBUG_TEMP:
			sys_write_vp(DEBUG_DATA_1_ADDR, (u8*)&statusData ,2);
			if(20<=statusData && statusData<200) sys_write_vp(DEBUG_STATUS_1_ADDR, (u8*)&iconSatusOk ,2);
			else sys_write_vp(DEBUG_STATUS_1_ADDR, (u8*)&iconSatusErr ,2);

		break;

		case IDX_DEBUG_MAIN_COMMU:
			sys_write_vp(DEBUG_DATA_2_ADDR, (u8*)&statusData ,2);
			if(0<=statusData && statusData<5) sys_write_vp(DEBUG_STATUS_2_ADDR, (u8*)&iconSatusOk ,2);
			else sys_write_vp(DEBUG_STATUS_2_ADDR, (u8*)&iconSatusErr ,2);
		break;

		case IDX_DEBUG_HAND_COMMU:
			sys_write_vp(DEBUG_DATA_3_ADDR, (u8*)&statusData ,2);
			if(0<=statusData && statusData<5) sys_write_vp(DEBUG_STATUS_3_ADDR, (u8*)&iconSatusOk ,2);
			else sys_write_vp(DEBUG_STATUS_3_ADDR, (u8*)&iconSatusErr ,2);
		break;

		case IDX_DEBUG_RF_COMMU:
			sys_write_vp(DEBUG_DATA_4_ADDR, (u8*)&statusData ,2);
			if(0<=statusData && statusData<5) sys_write_vp(DEBUG_STATUS_4_ADDR, (u8*)&iconSatusOk ,2);
			else sys_write_vp(DEBUG_STATUS_4_ADDR, (u8*)&iconSatusErr ,2);
		break;

		case IDX_DEBUG_RF_STATUS:
			sys_write_vp(DEBUG_DATA_5_ADDR, (u8*)&statusData ,2);
			if(0<=statusData && statusData<1) sys_write_vp(DEBUG_STATUS_5_ADDR, (u8*)&iconSatusOk ,2);
			else sys_write_vp(DEBUG_STATUS_5_ADDR, (u8*)&iconSatusErr ,2);
		break;

		case IDX_DEBUG_RTC_BATTRY:
			sys_write_vp(DEBUG_DATA_6_ADDR, (u8*)&statusData ,2);
			if(10<=statusData && statusData<40) sys_write_vp(DEBUG_STATUS_6_ADDR, (u8*)&iconSatusOk ,2);
			else sys_write_vp(DEBUG_STATUS_6_ADDR, (u8*)&iconSatusErr ,2);
		break;

		case IDX_DEBUG_FLOW_SENSOR:
			sys_write_vp(DEBUG_DATA_7_ADDR, (u8*)&statusData ,2);
			if(3<=statusData && statusData<35) sys_write_vp(DEBUG_STATUS_7_ADDR, (u8*)&iconSatusOk ,2);
			else sys_write_vp(DEBUG_STATUS_7_ADDR, (u8*)&iconSatusErr ,2);
		break;

		case IDX_DEBUG_LEVEL_SENSOR:
			sys_write_vp(DEBUG_DATA_8_ADDR, (u8*)&statusData ,2);
			if(statusData == 0) sys_write_vp(DEBUG_STATUS_8_ADDR, (u8*)&iconSatusOk ,2);
			else sys_write_vp(DEBUG_STATUS_8_ADDR, (u8*)&iconSatusErr ,2);
		break;

		case IDX_DEBUG_INSERT_HP:
			sys_write_vp(DEBUG_DATA_9_ADDR, (u8*)&statusData ,2);
			if(statusData == 1) sys_write_vp(DEBUG_STATUS_9_ADDR, (u8*)&iconSatusOk ,2);
			else sys_write_vp(DEBUG_STATUS_9_ADDR, (u8*)&iconSatusErr ,2);
		break;

		case IDX_DEBUG_DETECTE_CART:
			sys_write_vp(DEBUG_DATA_10_ADDR, (u8*)&statusData ,2);
			if(statusData == 0) sys_write_vp(DEBUG_STATUS_10_ADDR, (u8*)&iconSatusOk ,2);
			else sys_write_vp(DEBUG_STATUS_10_ADDR, (u8*)&iconSatusErr ,2);
		break;
	}

}

void RX_Parssing_Config()
{
	u16 add = 0;
	u32 statusData = 0;
	u16 cmd = 0;
	u32 value=0;
	float agvF = 0;
	u32 agv = 0;
	u16 errData = 0, errNum= 0,errAddr= 0;
	u32 errCnt= 0;
	u16 pluseNum = 0;
	u32 pluseValue = 0;
	u16 pluseAddr = 0;
	u16 iconPulse = 0;
	const u16 iconCalEmptyPoint = ICON_CALIB_EMPTY_POINT;
	const u16 iconStandby = ICON_STANDBY_BOX, iconReady = ICON_READY_BOX;
	const u16 iconHandEn = ICON_HAND_EN;
	const u16 iconHandDis = ICON_HAND_DIS;

	u16 iconVibeLv = ICON_VIBE_OFF;
	u16 ToffsetAdd = 0;
	u16 ToffsetIdx = 0;
	u32 ToffsetVal = 0;
	int i = 0;
	//if(uartRxFlag)
	if(cmdRxRingCnt > cmdPassingRingCnt)
	{
		uartRxFlag = 0;




//		cmd = uartCmdTemp;
//		value = uartValueTemp;
		cmd = cmdBuff[cmdPassingRingCnt][0];
		value = cmdBuff[cmdPassingRingCnt][1];
		switch (cmd)
		{

			case CMD_ERR:
				errData = value;
				Event_PopUp(errData);
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


			case CMD_INFO_UI_DESING:
				textinfoBuff[INFO_IDX_UI_DESIGN] = value;
				sys_write_vp(INFO_NUM_UI_DESING_ADDR,(u8*)&value,2);
			break;

			case CMD_INFO_UI_FW:
				textinfoBuff[INFO_IDX_UI_FW] = value;
				sys_write_vp(INFO_NUM_UI_FW_ADDR,(u8*)&value,2);
			break;

			case CMD_INFO_MAIN_FW:
				textinfoBuff[INFO_IDX_MAIN_FW] = value;
				sys_write_vp(INFO_NUM_MAIN_FW_ADDR,(u8*)&value,2);
			break;

			case CMD_INFO_HP_FW:
				textinfoBuff[INFO_IDX_HP_FW] = value;
				sys_write_vp(INFO_NUM_HP_FW_ADDR,(u8*)&value,2);
			break;

			case CMD_INFO_RF_FW:
				textinfoBuff[INFO_IDX_RF_FW] = value;
				sys_write_vp(INFO_NUM_RF_FW_ADDR,(u8*)&value,2);
			break;

			case CMD_RTC_YY:
				textinfoBuff[INFO_IDX_YY] = value;
				sys_write_vp(INFO_NUM_YY_ADDR,(u8*)&value,2);
			break;

			case CMD_RTC_MM:
				textinfoBuff[INFO_IDX_MM] = value;
				sys_write_vp(INFO_NUM_MM_ADDR,(u8*)&value,2);
			break;

			case CMD_RTC_DD:
				textinfoBuff[INFO_IDX_DD] = value;
				sys_write_vp(INFO_NUM_DD_ADDR,(u8*)&value,2);
			break;

			case CMD_RTC_HOUR:
				textinfoBuff[INFO_IDX_HOUR] = value;
				sys_write_vp(INFO_NUM_HOUR_ADDR,(u8*)&value,2);
			break;

			case CMD_RTC_MIN:
				textinfoBuff[INFO_IDX_MIN] = value;
				sys_write_vp(INFO_NUM_MIN_ADDR,(u8*)&value,2);
			break;

			case CMD_RTC_SEC:
				textinfoBuff[INFO_IDX_SEC] = value;
				sys_write_vp(INFO_NUM_SEC_ADDR,(u8*)&value,2);
			break;

			case CMD_CATRIDGE_EVENT:

				switch (value)
				{
					case CATRIGE_CHK_OK:
						Event_PopUp(IDX_CATRIGE_DETECT);
					break;

					case CATRIGE_CHK_NEW:
						Event_PopUp(IDX_CATRIGE_NEW);
					break;

					case CATRIGE_CHK_I2C_READ_ERR:
						Event_PopUp(IDX_CATRIGE_I2C_ERR);
					break;

					case CATRIGE_CHK_I2C_WRITE_ERR:
						Event_PopUp(IDX_CATRIGE_I2C_ERR);
					break;

					case CATRIGE_CHK_REMIND_ZERO_ERR:
						Event_PopUp(IDX_CATRIGE_RESHOT_ZERO);
					break;

					case CATRIGE_CHK_UN_DETECT:
						Event_PopUp(IDX_CATRIGE_UN_DETECT);
					break;
				}
			break;


			case CMD_ENERGY:
				energy = value;
				sys_write_vp(ENERGY_NUM_ADDR,(u8*)&energy ,2);

			break;

			case CMD_PULSE_DURATION:
				pulseDuration = value;
				sys_write_vp(PULSE_DURATION_NUM_ADDR,(u8*)&pulseDuration ,2);
			break;

			case CMD_POST_COOLING:
				postCooling = value;
				sys_write_vp(POST_COOLING_NUM_ADDR,(u8*)&postCooling ,2);
			break;

			case CMD_INTERVAL:
				interval = value;
				sys_write_vp(INTERVAL_NUM_ADDR,(u8*)&interval ,2);
			break;


			case CMD_CURRENT_SHOT: // Always totaljul first, currentshot after
				currentShot = value;
				add = CURRENT_SHOT1_NUM_ADDR + (newAreaCnt*2);
				sys_write_vp(add,(u8*)&currentShot ,2);


				if(totalJoule && currentShot)
				{
					agvF = (float)totalJoule/(float)currentShot;
					agv = agvF*10.0;

					add = AVG_ENERGY1_NUM_ADDR + (newAreaCnt*2);
					sys_write_vp(add,(u8*)&agv ,2);
				}


			break;

			case CMD_TOTAL_JOULE:
				totalJoule = value;
				add = TOTAL_ENERGY1_NUM_ADDR + (newAreaCnt*2);
				sys_write_vp(add,(u8*)&totalJoule ,2);


			break;


			case CMD_REMIND_SHOT:
				remindShot = value;
				textCartrigeBuff[CART_IDX_REMIND_SHOT] = value;
				sys_write_vp(REMIND_SHOT_NUM_ADDR,(u8*)&remindShot ,2);
				sys_write_vp(CART_VALUE_REMIND_SHOT_ADDR,(u8*)&value ,2);

			break;

			case CMD_TEMPERATURE_SHOT:
				temperature = value;
				sys_write_vp(TEMP_DEBUG_NUM_ADDR,(u8*)&temperature ,2);

			break;

			case CMD_PELTIER_DUTY:
				peltierDuty = value;
				sys_write_vp(DUTY_DEBUG_NUM_ADDR,(u8*)&peltierDuty ,2);

			break;


			case CMD_LCD_STATUS:
				rdyStnbyMode = value;

					if(rdyStnbyMode == STATUS_STNBY)
					{
						sys_write_vp(CIRCLE_WATE_ADDR,(u8*)&iconStandby ,2);
					}
					else if(rdyStnbyMode == STATUS_TRET)
					{
						sys_write_vp(CIRCLE_WATE_ADDR,(u8*)&iconReady ,2);
						Volume_Change(6, volumeLevel);
					}
					else if(rdyStnbyMode == STATUS_PRECOOLING)
					{
						iconMove = ICON_CIRCLE_WATE0_BOX;
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
//					Volume_Change(1, volumeLevel);
				}
				else if(value == LCD_EXP_END)
				{
					expFlag = 0;
					totaljouleSum += energy;
					sys_write_vp(TOTAL_JOULE_NUM_ADDR,(u8*)&totaljouleSum ,2);
					shotSum++;
					sys_write_vp(CURRENT_SHOT_NUM_ADDR,(u8*)&shotSum ,2);
					Volume_Change(4, volumeLevel);

//					Volume_Off(1, 0);


				}
			break;

			case CMD_TEST_FORCE_PAGE_CHANGE:
				lcdPage = value;
				Page_Change(value);
				engineerKey = 1;
			break;



			case CMD_DEVICE_STATUS:
				Device_Satatus_Passing(value);
			break;

			case CMD_ERR_EVENT:
				errNum = (value/1000);
				errCnt = value%1000;
				errAddr = DEBUG_ERRCNT_1_ADDR + (errNum -1)*2;
				sys_write_vp(errAddr,(u8*)&errCnt ,2);
			break;

			case CMD_AGING_BUTTON:
				if(value <= 30)
				{
					agingFlag = value;
				}
				else
				{
					agingLongFlag = value;
				}


			break;

			case CMD_TEST_PULSE:
				switch (value)
				{
					case 1:  iconPulse = ICON_PULSE_1;  break;
					case 2:  iconPulse = ICON_PULSE_2;  break;
					case 3:  iconPulse = ICON_PULSE_3;  break;
					case 4:  iconPulse = ICON_PULSE_4;  break;
				}
				sys_write_vp(CALIV_PULSE_ICON_ADDR,(u8*)&iconPulse ,2);
			break;

			case CMD_VIBE_LEVEL:
				iconVibeLv += value;
				sys_write_vp(VIBE_LEVEL_ICON_ADDR,(u8*)&iconVibeLv ,2);
			break;


			case CMD_HAND_FOOT:
				if (value == SWITCH_HAND)
				{
					sys_write_vp(HAND_EN_ADDR,(u8*)&iconHandEn ,2);

				}
				else if (value == SWITCH_FOOT)
				{
					sys_write_vp(HAND_EN_ADDR,(u8*)&iconHandDis ,2);
				}
			break;

			case CMD_TEMP_OFFSET:
				  ToffsetIdx = (value/100);
				  ToffsetAdd = CART_TEMP1_OFFSET_ADDR + ToffsetIdx*2;
				  ToffsetVal = value%100;
				  textCartrigeBuff[CART_IDX_TEMP_OFFS_1+ToffsetIdx] = ToffsetVal;
				  sys_write_vp(ToffsetAdd,(u8*)&ToffsetVal ,2);

			break;


			default:
				if(CMD_TRANDU1_FRQ <= cmd && cmd <=CMD_TRANDU7_FRQ)
				{
					cmd  = cmd-90;
					textFrqBuff[cmd] = value;
					textCartrigeBuff[(CART_IDX_TRANDU1_FRQ-1)+cmd] = value;
					add = (u16)(CART_VALUE_TRANDU1_ADDR + (cmd-1)*0x02);
					sys_write_vp(add,(u8*)&value ,2);

					add = (u16)(TRANDU_FREQ_NUM_START_ADDR + (cmd-1)*0x02);
					sys_write_vp(add,(u8*)&value ,2);
				}
				else if(CMD_TRANDU1_WATT10 <= cmd && cmd <=CMD_TRANDU7_WATT005)
				{
					cmd  = cmd-100;
					textWattBuff[cmd] = value;
					add = (u16)(TRANDU_WATT_START_NUM_ADDR + (cmd-1)*0x02);
					sys_write_vp(add,(u8*)&value ,2);
				}
			break;
		}


//		TX_Msg(197, cmdRxRingCnt);//
//		TX_Msg(198, cmdPassingRingCnt);//
//		TX_Msg(199, uartRxFlag);//
		if(cmdRxRingCnt > cmdPassingRingCnt)
		{
			cmdPassingRingCnt++;
			if(cmdRxRingCnt == cmdPassingRingCnt)
			{
				cmdPassingRingCnt = 0;
				cmdRxRingCnt = 0;
			}
		}
//		TX_Msg(210, cmdRxRingCnt);//
//		TX_Msg(211, cmdPassingRingCnt);//
//		TX_Msg(212, uartRxFlag);//
	}

}







u8 Test_Config()
{
	u8 returnValue = 0;
	u16 btn =0;
	int indData[4] ={0,};
	int Tint =10100;
	u8 Tu8 =120;
	u16 Tu16 =13130;
	u32 Tu32 =14140;

	returnValue = LCD_MODE_TEST;
#if 0
		if(delay_tickMy-timeStampQ >= 3000)
		{
	//		TX_Msg(111, Tint);
	//		TX_Msg(222, Tu8);
	//		TX_Msg(333, Tu16);
	//		TX_Msg(444, Tu32);

			timeStampQ = delay_tickMy;
		}

#endif
	sys_read_vp(TEST_BUTTON_ADDR,(u8*)&btn,1);
	if(btn)
	{
		switch (btn)
		{
			case 1:
				testNum += 200;
				if(testNum>2500) testNum = 50;
				XY_Change(XY_SP_TEST_ADD1 , (u16)testNum, (u16)testNum2);
				XY_Change(XY_SP_TEST_ADD2 , (u16)testNum+10, (u16)testNum2+10);
				XY_Change(XY_SP_TEST_ADD3 , (u16)testNum+20, (u16)testNum2+20);
				XY_Change(XY_SP_TEST_ADD4 , (u16)testNum+30, (u16)testNum2+30);

				sys_write_vp(TEST_NUM_ADDR1,(u8*)&testNum ,2);
				sys_write_vp(TEST_NUM_ADDR2,(u8*)&testNum ,2);
				sys_write_vp(TEST_NUM_ADDR3,(u8*)&testNum ,2);
				sys_write_vp(TEST_NUM_ADDR4,(u8*)&testNum ,2);
			break;

			case 2:
				testNum2 += 200;
				if(testNum2>1200) testNum2 = 50;
				XY_Change(XY_SP_TEST_ADD1 , (u16)testNum, (u16)testNum2);
				XY_Change(XY_SP_TEST_ADD2 , (u16)testNum+10, (u16)testNum2+10);
				XY_Change(XY_SP_TEST_ADD3 , (u16)testNum+20, (u16)testNum2+20);
				XY_Change(XY_SP_TEST_ADD4 , (u16)testNum+30, (u16)testNum2+30);

				sys_write_vp(TEST_NUM_ADDR1,(u8*)&testNum2 ,2);
				sys_write_vp(TEST_NUM_ADDR2,(u8*)&testNum2 ,2);
				sys_write_vp(TEST_NUM_ADDR3,(u8*)&testNum2 ,2);
				sys_write_vp(TEST_NUM_ADDR4,(u8*)&testNum2 ,2);

			break;


		}

		btn= 0;
		sys_write_vp(TEST_BUTTON_ADDR,(u8*)&btn,2);
	}




	return LCD_MODE_TEST;
}


void Cartrige_Init()
{
	u16 add =0;
	u32 value =0;

	int i;
	for(i =1 ;i <25; i++)
	{
		add = (u16)(CART_VALUE_SATAT_ADDR + (i-1)*0x02);
//		textCartrigeBuff[i] = i*10;
		value = textCartrigeBuff[i];
		sys_write_vp(add,(u8*)&value,2);
	}

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
	u16 add = 0, pointAdd = 0, idx = 0;
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
		calMode = CAL_MODE_WATT;
		wattIdxMain = btnTtext;
		textNum = textWattBuff[wattIdxMain];


		btnTtext= 0;
		sys_write_vp(CAL_TOUCH_TDU_ADDR,(u8*)&btnTtext,2);
	}


}

void Watt_All_Zero()
{
	u16 add;
	int i = 0;
	u32 defultWatt =0;

	for(i =1 ;i <= 77;i++)
	{
		textWattBuff[i] = 0;
		defultWatt = 0;
		add = (u16)(TRANDU_WATT_START_NUM_ADDR + (i-1)*0x02);
		sys_write_vp(add,(u8*)&defultWatt,2);
	}
}

void Watt_Exp_zero()
{
	u16 add;
	int i = 0;
	u32 defultWatt =0;

	for(i = 0 ;i < 7;i++)
	{
		textWattBuff[i+78] = 0;
		defultWatt = 0;
		add = (u16)(TRANDU_WATT_EXP1_NUM_ADDR + i*0x02);
		sys_write_vp(add,(u8*)&defultWatt,2);
	}
}
void Info_Parts()//
{

	u16 btnTtext;
	u16 add = 0, pointAdd = 0;
	const u16 iconEmptyPoint = ICON_CALIB_EMPTY_POINT,  iconPoint = ICON_CALIB_POINT;

	sys_read_vp(INFOMATION_TOUCH_ADDR, (u8*)&btnTtext,1);
	if (btnTtext)
	{
		pointAdd = (u16)(INFO_POINT_SATAT_ADDR + (btnTtext-1)*0x02);

		if(infoPrePointAddr &&infoPrePointAddr != pointAdd)
		{
			sys_write_vp(infoPrePointAddr,(u8*)&iconEmptyPoint,2);
		}
		sys_write_vp(pointAdd,(u8*)&iconPoint,2);


		infoPrePointAddr = pointAdd;

		infoIdx = btnTtext;
		infoTouch = 1;
		infoValue = textinfoBuff[infoIdx];

		btnTtext= 0;
		sys_write_vp(INFOMATION_TOUCH_ADDR,(u8*)&btnTtext,2);
	}


}

void Aging_Button()
{
	if(agingFlag)
	{
		btnMain = agingFlag;
		agingFlag = 0;
	}
}

void Main_LongKey(u16 keyAddr, u16 cmd, u16 upDn, u16 agingTrg)
{
	u16 key = 0;
	sys_read_vp(keyAddr,(u8*)&key,1);
//	Aging_Up_Button();
	if(key || agingLongFlag == agingTrg)
	{
		Volume_Change(15, volumeLevel);
		agingLongFlag = 0;
		TX_Msg(cmd, upDn);
		key= 0;
		sys_write_vp(keyAddr,(u8*)&key,2);
	}

}

void Area_Move(u8 row, u8 hideEn)
{
	if (hideEn)
	{
		XY_Change(XY_SP_CURRENT_SHOT1_ADD +(row*0x20) , HIDE_NUM_X, yPointBuff[row]);
		XY_Change(XY_SP_TOTAL_ENERGY1_ADD +(row*0x20) , HIDE_NUM_X + 20, yPointBuff[row]);
		XY_Change(XY_SP_AGV_ENERGY1_ADD +(row*0x20) , HIDE_NUM_X + 40, yPointBuff[row]);

	}
	else
	{
		XY_Change(XY_SP_CURRENT_SHOT1_ADD +(row*0x20) , CURRENT_SHOT_POS_X, yPointBuff[row]);
		XY_Change(XY_SP_TOTAL_ENERGY1_ADD +(row*0x20) , TOTAL_ENERGY_POS_X, yPointBuff[row]);
		XY_Change(XY_SP_AGV_ENERGY1_ADD +(row*0x20) , AGV_ENERGY_POS_X, yPointBuff[row]);
	}
}


void Area_test()
{
	XY_test();

}

void Area_Reset(u8 rst)
{
	u16 add = 0;
	u32 zero = 0;
	int i = 0;

	if(rst)
	{
		totaljouleSum = 0;
		shotSum = 0;
		sys_write_vp(TOTAL_JOULE_NUM_ADDR,(u8*)&totaljouleSum ,2);
		sys_write_vp(CURRENT_SHOT_NUM_ADDR,(u8*)&shotSum ,2);
	}

	newAreaCnt = 0;
//	TX_Msg(CMD_CURRENT_SHOT, 0);
//	TX_Msg(CMD_TOTAL_JOULE, 0);

	for(i =0 ;i < 5;i++)
	{
		add = CURRENT_SHOT1_NUM_ADDR + (i*2);
		sys_write_vp(add,(u8*)&zero ,2);

		add = TOTAL_ENERGY1_NUM_ADDR + (i*2);
		sys_write_vp(add,(u8*)&zero ,2);

		add = AVG_ENERGY1_NUM_ADDR + (i*2);
		sys_write_vp(add,(u8*)&zero ,2);

	}
	Area_Move(1,1);
	Area_Move(2,1);
	Area_Move(3,1);
	Area_Move(4,1);

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
		cartTouch = 1;
		cartValue = textCartrigeBuff[cartIdx];

		btnTtext= 0;
		sys_write_vp(CARTRIGE_TOUCH_ADDR,(u8*)&btnTtext,2);
	}


}


void Shot_Sound_Play()
{

	if(expFlag)
	{
		if(delay_tickMy-timeStampShot >= 2000)
		{

			Volume_Change(10, volumeLevel);
			timeStampShot = delay_tickMy;
		}
	}


}
void ErrCode_Init()
{
	errCodeBuff[IDX_TEMP_OUT] = 5;
	errCodeBuff[IDX_TEMP_LIMIT_UNDER] = 6;
	errCodeBuff[IDX_TEMP_LOW] = ALRAM_ADDER + 1;//A
	errCodeBuff[IDX_FLOW_LIMIT_UNDER] = 9;
	errCodeBuff[IDX_LEVEL_LOW] = 7;
	errCodeBuff[IDX_AUTO_CAL_COMU_ERR] = 12;
	errCodeBuff[IDX_BATTRY_LIMIT_OVER] = 10;
	errCodeBuff[IDX_BATTRY_LIMIT_UNDER] = 11;
	errCodeBuff[IDX_BATTRY_LIMIT_LOW] = ALRAM_ADDER + 4;//A
	errCodeBuff[IDX_RTC_ERR] = 23;
	errCodeBuff[IDX_PRE_COOL_ERR] = 15;
	errCodeBuff[IDX_HAND_COMU_ERR] = 4;
	errCodeBuff[IDX_CATRIGE_I2C_ERR] = 22;
	errCodeBuff[IDX_CATRIGE_NEW_DETECT ]= INFO_ADDER + 4;//I
	errCodeBuff[IDX_CATRIGE_ID_ERR] = 24;
	errCodeBuff[IDX_CATRIGE_MANU_ERR] = 16;
	errCodeBuff[IDX_CATRIGE_MANU_OVER_ERR] = 26;
	errCodeBuff[IDX_CATRIGE_ISUE_ERR] = 17;
	errCodeBuff[IDX_CATRIGE_ISUE_OVER_ERR] = 25;
	errCodeBuff[IDX_CATRIGE_WATT_ERR] = 19;
	errCodeBuff[IDX_CATRIGE_FRQ_ERR] = 18;
	errCodeBuff[IDX_CATRIGE_RESHOT_ERR] = 21;
	errCodeBuff[IDX_CATRIGE_RESHOT_LOW] = INFO_ADDER + 1;//I
	errCodeBuff[IDX_CATRIGE_RESHOT_ZERO] = ALRAM_ADDER + 6;//A
	errCodeBuff[IDX_CATRIGE_DETECT] = INFO_ADDER + 5;//I
	errCodeBuff[IDX_CATRIGE_UN_DETECT] = INFO_ADDER + 6;//I
	errCodeBuff[IDX_RF_COMU_ERR] = 2;
	errCodeBuff[IDX_RF_STATUS_ERR] = 1;


}

void System_Circle_Icon(u16 icon)
{
	sys_write_vp(SYSTEM_ICON_ADDR, (u8*)&icon,2);
}
u8 System_Check_Config()
{
	u8 returnValue = 0;
	u16 btn =0;
	const u16 iconMainEn = ICON_SYS_CHK_MAIN_EN, iconGenEn = ICON_SYS_CHK_GEN_EN, iconHpEn = ICON_SYS_CHK_HP_EN, iconCoolEn = ICON_SYS_CHK_COOL_EN;

	returnValue = LCD_MODE_SYS_CHK;


	if(delay_tickMy -systemTimeStamp >= 1000)
	{

		systemTimeStamp = delay_tickMy;

		if(sysChkFlag)
		{
			switch (systemStep)
			{
				case STEP0:
					TX_Msg(CMD_TEMP_DUTY_ON, 0);
					TX_Msg(CMD_COOLING, 1);
					TX_Msg(CMD_OK, ERR_CHK_MAIN);
					chkOkBuff[0] = 0;
					System_Circle_Icon(ICON_SYS_CHK_PER_10);
					systemStep = STEP1;
				break;

				case STEP1:
					if(chkOkBuff[0] == OK_MAIN)
					{
						TX_Msg(CMD_SYS_CHK_OK, 1);
					}
					else
					{
						TX_Msg(CMD_SYS_CHK_OK, 11);

					}
					sys_write_vp(SYSTEM_CHECK_COOL_ICON_ADDR, (u8*)&iconCoolEn,2);
					System_Circle_Icon(ICON_SYS_CHK_PER_20);
					systemStep = STEP2;

				break;

				case STEP2:
					sys_write_vp(SYSTEM_CHECK_CTRL_ICON_ADDR, (u8*)&iconMainEn,2);
					TX_Msg(CMD_DO_ALL_LIVE, LIVE_HP);
					systemLive = 0;
					System_Circle_Icon(ICON_SYS_CHK_PER_30);
					systemStep = STEP3;
				break;


				case STEP3:
					if(systemLive == LIVE_HP)
					{
						TX_Msg(CMD_SYS_CHK_OK, 2);
					}
					else if(systemLive == LIVE_HP_DETH)
					{
						Event_PopUp(IDX_HAND_COMU_ERR);
						TX_Msg(CMD_SYS_CHK_OK, 12);
					}
					else if(systemLive == 0)
					{
						Event_PopUp(IDX_HAND_COMU_ERR);
						TX_Msg(CMD_SYS_CHK_OK, 22);
					}
					TX_Msg(CMD_GET_ALL_CART, 0);
					systemCartEnd = 0;
					systemTimeTerm = delay_tickMy;
					systemStep = STEP4;
				break;

				case STEP4:
					if(systemCartEnd)
					{
						systemStep = STEP5;
						System_Circle_Icon(ICON_SYS_CHK_PER_40);
					}
					if(delay_tickMy - systemTimeTerm > 15000)
					{
						systemStep = STEP5;
						System_Circle_Icon(ICON_SYS_CHK_PER_40);
					}

				break;


				case STEP5:
					if(systemCartEnd)
					{
						TX_Msg(CMD_GET_ALL_CART_END, 55);
						TX_Msg(CMD_SYS_CHK_OK, 3);
					}
					else
					{
						Event_PopUp(IDX_HAND_COMU_ERR);
						TX_Msg(CMD_SYS_CHK_OK, 13);
					}

					TX_Msg(CMD_OK, ERR_CHK_HP);
					systemStep = STEP6;
					chkOkBuff[2] = 0;
				break;

				case STEP6:
					if(chkOkBuff[2] == OK_HP)
					{
						TX_Msg(CMD_SYS_CHK_OK, 4);
					}
					else
					{
						TX_Msg(CMD_SYS_CHK_OK, 14);
					}
					System_Circle_Icon(ICON_SYS_CHK_PER_50);
					systemStep = STEP7;

				break;

				case STEP7:
					sys_write_vp(SYSTEM_CHECK_HP_ICON_ADDR, (u8*)&iconHpEn,2);
					TX_Msg(CMD_DO_ALL_LIVE, LIVE_RF);
					System_Circle_Icon(ICON_SYS_CHK_PER_60);
					systemLive = 0;
					systemStep = STEP8;
				break;

				case STEP8:
					if(systemLive == LIVE_RF)
					{
						TX_Msg(CMD_SYS_CHK_OK, 5);
					}
					else if(systemLive == LIVE_RF_DETH)
					{
						Event_PopUp(IDX_RF_COMU_ERR);
						TX_Msg(CMD_SYS_CHK_OK, 15);
					}
					else if(systemLive == 0)
					{
						Event_PopUp(IDX_RF_COMU_ERR);
						TX_Msg(CMD_SYS_CHK_OK, 25);
					}
					TX_Msg(CMD_OK, ERR_CHK_RF);
					chkOkBuff[3] = 0;
					System_Circle_Icon(ICON_SYS_CHK_PER_70);
					systemStep = STEP9;
				break;

				case STEP9:
					if(chkOkBuff[3] == OK_RF)
					{
						TX_Msg(CMD_SYS_CHK_OK, 6);
					}
					else
					{
						TX_Msg(CMD_SYS_CHK_OK, 16);
					}
					System_Circle_Icon(ICON_SYS_CHK_PER_80);
					systemStep = STEP10;
				break;

				case STEP10:
					sys_write_vp(SYSTEM_CHECK_GEN_ICON_ADDR, (u8*)&iconGenEn,2);
					System_Circle_Icon(ICON_SYS_CHK_PER_90);
					systemStep = STEP11;
				break;

				case STEP11:

					System_Circle_Icon(ICON_SYS_CHK_PER_100);
					sys_delay_ms(2000);
					TX_Msg(CMD_TEMP_DUTY_ON, 1);
					TX_Msg(CMD_SYS_CHK, 1);

					Page_Change(LCD_MODE_MAIN);
					Area_Reset(1);
					returnValue = LCD_MODE_MAIN;
					systemStep = STEP0;

				break;


			}
		}
	}


	sys_read_vp(SYSTEM_BUTTON_ADDR,(u8*)&btn,1);
	if(btn)
	{
		switch (btn)
		{
			case BTN_SYSTEM_ERROK:
			if(errEvent)
			{
				sysChkFlag = 1;
				Event_PopDown_Ok();
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
		switch (btn)
		{
			case 1:
				Page_Change(LCD_MODE_PASSWARD);
				returnValue = LCD_MODE_PASSWARD;
			break;

			case 2: //test
				TX_Msg(CMD_TEST_FORCE_PAGE_CHANGE, LCD_MODE_MAIN);
				TX_Msg(CMD_SYS_CHK, 1);
				Page_Change(LCD_MODE_MAIN);
				engineerKey = 1;

				Area_Reset(1);
				returnValue = LCD_MODE_MAIN;

			break;
		}

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
		Volume_Change(15, volumeLevel);
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
					lcon_Printf(PW_ICON_ADDR,pwCnt);
				}
			break;

			case KEY_DEL:
				if(pwCnt>ICON_PASSWARD_0)
				{
					textCpy = textCpy/10;
					pwCnt--;
					lcon_Printf(PW_ICON_ADDR,pwCnt);
				}
			break;

			case KEY_CLEAR:
				pwCnt = ICON_PASSWARD_0;
				textCpy = 0;
				lcon_Printf(PW_ICON_ADDR,pwCnt);
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
				lcon_Printf(PW_ICON_ADDR,pwCnt);
				returnValue = LCD_MODE_SYS_CHK;

				Page_Change(LCD_MODE_SYS_CHK);
			}
			else
			{

				sys_delay_ms(300);

				pwCnt = ICON_PASSWARD_ERR;
				lcon_Printf(PW_ICON_ADDR,pwCnt);
				sys_delay_ms(1000);

				pwCnt = ICON_PASSWARD_0;
				textCpy = 0;
				lcon_Printf(PW_ICON_ADDR,pwCnt);
			}

		}

		btn= 0;
		sys_write_vp(PW_NUM_BUTTON_ADDR,(u8*)&btn,2);

	}


	return returnValue;

}

u8 Main_Config()
{
	u8 returnValue = 0;
	int i =0;
	u16 add = 0;
	u32 zero = 0;
	returnValue = LCD_MODE_MAIN;


	sys_read_vp(MAIN_BUTTON_ADDR,(u8*)&btnMain,1);
	Aging_Button();
	if(btnMain)
	{
		Volume_Change(15, volumeLevel);
		switch (btnMain)
		{
			/*
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
			*/
			case BTN_MAIN_INTERVAL_UP:
				TX_Msg(CMD_INTERVAL, BUTTON_UP);//

			break;
			case BTN_MAIN_INTERVAL_DN:
				TX_Msg(CMD_INTERVAL, BUTTON_DN);//
			break;
			case BTN_MAIN_ALL_RST:
				TX_Msg(CMD_CURRENT_SHOT, 0);
				TX_Msg(CMD_TOTAL_JOULE, 0);
				Area_Reset(1);
			break;
			case BTN_MAIN_PULSE_CHANGE:
				TX_Msg(CMD_TEST_PULSE, 1);
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


			case BTN_MAIN_ERR_OK_CENTER:
				if(popUpMode == POPUP_MODE_1)
				{
					Event_PopDown_Cancel();
				}
			break;

			case BTN_MAIN_ERR_OK_LEFT:
				if(popUpMode == POPUP_MODE_2)
				{
					Event_PopDown_Ok();
				}
			break;

			case BTN_MAIN_ERR_CANCEL_RIGHT:
				if(popUpMode == POPUP_MODE_2)
				{
					Event_PopDown_Cancel();
				}


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

			case BTN_MAIN_NEW_AREA:

				newAreaCnt++;
				newAreaCnt %= 5;
				TX_Msg(CMD_CURRENT_SHOT, 0);
				TX_Msg(CMD_TOTAL_JOULE, 0);

				add = AVG_ENERGY1_NUM_ADDR + (newAreaCnt*2);
				sys_write_vp(add,(u8*)&zero ,2);
				if (!newAreaCnt)
				{
					Area_Reset(0);
				}
				else
				{
					Area_Move(newAreaCnt, 0);
				}

			break;

			case BTN_MAIN_VIBE_LEVEL:
				TX_Msg(CMD_VIBE_LEVEL, 1);
			break;

			case BTN_MAIN_HAND_FOOT:
				TX_Msg(CMD_HAND_FOOT, 1);
			break;


		}

		btnMain= 0;
		sys_write_vp(MAIN_BUTTON_ADDR,(u8*)&btnMain,2);
	}


	Main_LongKey(ENERGY_UP_LONG_BTN_ADDR, CMD_ENERGY, BUTTON_UP, 31);
	Main_LongKey(ENERGY_DN_LONG_BTN_ADDR, CMD_ENERGY, BUTTON_DN, 32);
	Main_LongKey(DURATION_UP_LONG_BTN_ADDR, CMD_PULSE_DURATION, BUTTON_UP, 33);
	Main_LongKey(DURATION_DN_LONG_BTN_ADDR, CMD_PULSE_DURATION, BUTTON_DN, 34);
	Main_LongKey(POST_UP_LONG_BTN_ADDR, CMD_POST_COOLING, BUTTON_UP, 35);
	Main_LongKey(POST_DN_LONG_BTN_ADDR, CMD_POST_COOLING, BUTTON_DN, 36);

	EXP_FreeCool_Motion();

	Shot_Sound_Play();



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






u8 Calibration_Config()//
{
	u8 returnValue = 0;
	u16 add = 0;
	u16 btn;
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
			case KEY_CLEAR:
				if(calMode == 0) break;

				if(btn==KEY_0) textNum = textNum*10 + 0;
				else if(btn==KEY_DEL && textNum) textNum = textNum/10;
				else if(btn==KEY_CLEAR) textNum = 0;
				else textNum = textNum*10 + btn;

				if(textNum > 400) textNum = 400;
				else if(textNum < 0) textNum = 0;

				textWattBuff[wattIdxMain] = textNum;
				add = (u16)(TRANDU_WATT_START_NUM_ADDR + (wattIdxMain-1)*0x02);
				sys_write_vp(add,(u8*)&textNum,2);


			break;

			case KEY_CAL_WATT_LOAD:
				Watt_All_Zero();
				TX_Msg(CMD_GET_WATT_CART, 1);
			break;

			case KEY_CAL_WATT_SAVE:
				Watt_Save();
			break;

			case KEY_CAL_AUTOCAL:
				TX_Msg(CMD_AUTO_CAL_START, 1);
			break;


			case KEY_CAL_BACK_MAIN:
				if(expFlag)
				{
					expFlag = 0;
				}

				Page_Change(LCD_MODE_ENGINIEER);
				returnValue = LCD_MODE_ENGINIEER;
			break;

			case KEY_CAL_TEMP_RST:
				Watt_Exp_zero();
			break;


			case KEY_CAL_UP:
				if(onTimeCalv<130)onTimeCalv++;
				sys_write_vp(CALIV_PULSETIME_NUM_NUM_ADDR,(u8*)&onTimeCalv ,4);
			break;

			case KEY_CAL_DN:
				if(onTimeCalv>0)onTimeCalv--;
				sys_write_vp(CALIV_PULSETIME_NUM_NUM_ADDR,(u8*)&onTimeCalv ,4);
			break;

			case KEY_CAL_SHOT:
				Calv_Tx_Msg();
			break;

		}
		btn= 0;
		sys_write_vp(START_TOUCH_BTN_ADDR,(u8*)&btn,2);

	}

	Calibration_TDU_Parts();


	return returnValue;

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
	const u16 iconEmptyPoint = ICON_CALIB_EMPTY_POINT;
	u16 btn;
	u16 tempOffsetVal = 0;

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
			case KEY_CLEAR:
				if(cartTouch == 0) break;

				if(btn==KEY_0) cartValue = cartValue*10 + 0;
				else if(btn==KEY_DEL && cartValue) cartValue = cartValue/10;
				else if(btn==KEY_CLEAR) cartValue = 0;
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
				TX_Msg(CMD_MANUFAC_MM, textCartrigeBuff[CART_IDX_MANUFAC_MM]);
				TX_Msg(CMD_MANUFAC_DD, textCartrigeBuff[CART_IDX_MANUFAC_DD]);
			break;

			case KEY_CART3_SET:
				TX_Msg(CMD_ISSUED_YY, textCartrigeBuff[CART_IDX_ISSUED_YY]);
				TX_Msg(CMD_ISSUED_MM, textCartrigeBuff[CART_IDX_ISSUED_MM]);
				TX_Msg(CMD_ISSUED_DD, textCartrigeBuff[CART_IDX_ISSUED_DD]);
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

			break;

			case KEY_CART13_SET:
				for(i =0 ;i < 8;i++)
				{
					tempOffsetVal = i*100 + textCartrigeBuff[CART_IDX_TEMP_OFFS_1+i];
					TX_Msg(CMD_TEMP_OFFSET,tempOffsetVal);
				}
			break;

			case KEY_CART_ROAD:
				sys_write_vp(cartPrePointAddr,(u8*)&iconEmptyPoint,2);
				cartTouch = 0;
				cartIdx = 0;
				cartValue = 0;
				TX_Msg(CMD_GET_ALL_CART, 0);
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



u8 Information_Config()//
{
		u8 returnValue = 0;
		u16 add = 0;
		int i = 0;
		u16 btn;
		returnValue = LCD_MODE_INFOMATION;
		sys_read_vp(INFOMATION_BUTTON_ADDR,(u8*)&btn,1);
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
				case KEY_CLEAR:
					if(infoTouch == 0) break;

					if(btn==KEY_0) infoValue = infoValue*10 + 0;
					else if(btn==KEY_DEL && infoValue) infoValue = infoValue/10;
					else if(btn == KEY_CLEAR) infoValue = 0;
					else infoValue = infoValue*10 + btn;

					if(infoValue < 0) infoValue = 0;

					textinfoBuff[infoIdx] = infoValue;
					add = (u16)(INFO_NUM_SATAT_ADDR + (infoIdx-1)*0x02);
					sys_write_vp(add,(u8*)&infoValue,2);


				break;

				case BTN_INFO_BACKHOME:

					Page_Change(LCD_MODE_ENGINIEER);
					returnValue = LCD_MODE_ENGINIEER;
				break;

				case BTN_INFO_UI_DESING_ADDR:
					TX_Msg(CMD_INFO_UI_DESING, textinfoBuff[INFO_IDX_UI_DESIGN]);
				break;

				case BTN_INFO_UI_FW_ADDR:
					TX_Msg(CMD_INFO_UI_FW, textinfoBuff[INFO_IDX_UI_FW]);
				break;

				case BTN_INFO_MAIN_FW_ADDR:
					TX_Msg(CMD_INFO_MAIN_FW, textinfoBuff[INFO_IDX_MAIN_FW]);
				break;

				case BTN_INFO_HP_FW_ADDR:
					TX_Msg(CMD_INFO_HP_FW, textinfoBuff[INFO_IDX_HP_FW]);
				break;

				case BTN_INFO_RF_FW_ADDR:
					TX_Msg(CMD_INFO_RF_FW, textinfoBuff[INFO_IDX_RF_FW]);
				break;

				case BTN_INFO_DAY_ADDR:

					TX_Msg(CMD_RTC_EN, 0);
					sys_delay_ms(1000);
					TX_Msg(CMD_RTC_YY, textinfoBuff[INFO_IDX_YY]);
					TX_Msg(CMD_RTC_MM, textinfoBuff[INFO_IDX_MM]);
					TX_Msg(CMD_RTC_DD, textinfoBuff[INFO_IDX_DD]);
					sys_delay_ms(1000);
					TX_Msg(CMD_RTC_EN, 1);
				break;

				case BTN_INFO_TIME_ADDR:
					TX_Msg(CMD_RTC_EN, 0);
					sys_delay_ms(1000);
					TX_Msg(CMD_RTC_HOUR, textinfoBuff[INFO_IDX_HOUR]);
					TX_Msg(CMD_RTC_MIN, textinfoBuff[INFO_IDX_MIN]);
					TX_Msg(CMD_RTC_SEC, textinfoBuff[INFO_IDX_SEC]);
					sys_delay_ms(1000);
					TX_Msg(CMD_RTC_EN, 1);
				break;
			}
			btn= 0;
			sys_write_vp(INFOMATION_BUTTON_ADDR,(u8*)&btn,2);
		}

		Info_Parts();

		return returnValue;

}

u8 Device_Status_Config()
{
	u8 returnValue = 0;
	u16 btn =0;

	returnValue = LCD_MODE_DEVICE_STATUS;

	sys_read_vp(DEVICE_STATUS_BUTTON_ADDR, (u8*)&btn,1);
	if(btn)
	{
		if(btn ==KEY_DEVICE_BACKHOME)
		{
			TX_Msg(CMD_DEVICE_STATUS, 0);
			Page_Change(LCD_MODE_ENGINIEER);
			returnValue = LCD_MODE_ENGINIEER;
		}

		btn= 0;
		sys_write_vp(DEVICE_STATUS_BUTTON_ADDR,(u8*)&btn,2);
	}

	return returnValue;
}


u8 Error_Event_Config()
{
	u8 returnValue = 0;
	u16 btn =0;

	returnValue = LCD_MODE_ERROR_EVENT;

	sys_read_vp(ERROR_EVENT_BUTTON_ADDR,(u8*)&btn,1);
	if(btn)
	{
		Page_Change(LCD_MODE_ENGINIEER);
		returnValue = LCD_MODE_ENGINIEER;

		btn= 0;
		sys_write_vp(ERROR_EVENT_BUTTON_ADDR,(u8*)&btn,2);
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
				TX_Msg(CMD_INFOMATION, 1);
				Page_Change(LCD_MODE_INFOMATION);
				returnValue = LCD_MODE_INFOMATION;
			break;

			case BTN_EG_CALIBRATION:
				TX_Msg(CMD_GET_WATT_CART, 1);
				Page_Change(LCD_MODE_CALIBRATION);
				returnValue = LCD_MODE_CALIBRATION;

			break;

			case BTN_EG_CART_SET:
				Cartrige_Init();
				Page_Change(LCD_MODE_CART_SETTING);
				returnValue = LCD_MODE_CART_SETTING;
			break;

			case BTN_EG_ERR_EVENT:
				TX_Msg(CMD_ERR_EVENT, 1);
				Page_Change(LCD_MODE_ERROR_EVENT);
				returnValue = LCD_MODE_ERROR_EVENT;
			break;

			case BTN_EG_DEVICE_STATUS:
				TX_Msg(CMD_DEVICE_STATUS, 1);
				Page_Change(LCD_MODE_DEVICE_STATUS);
				returnValue = LCD_MODE_DEVICE_STATUS;
			break;

			case BTN_EG_BACKHOME:
				Page_Change(LCD_MODE_MAIN);
				returnValue = LCD_MODE_MAIN;
			break;


		}
		btn= 0;
		sys_write_vp(ENGINEER_BUTTON_ADDR,(u8*)&btn,2);

	}


//	RX_ENGINIEER_Parssing_Config();


	return returnValue;

}


void Debug_PrintConfig()
{
#if 0
	static u32 timeStamp;
	if(delay_tickMy-timeStamp >= 2000)
	{
		int indData1 = 0,indData2 = 0,indData3 = 0;


		indData1 = iconMove;
		indData2 = 0;
		indData3 = 0;

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

		case LCD_MODE_SYS_CHK:
			lcdPage = System_Check_Config();
		break;

		case LCD_MODE_MAIN:
			lcdPage = Main_Config();
		break;

		case LCD_MODE_SETTING:
			lcdPage = Setting_Config();
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

		case LCD_MODE_CART_SETTING:
			lcdPage = Cartrige_Set_Config();
		break;

		case LCD_MODE_DEVICE_STATUS:
			lcdPage = Device_Status_Config();
		break;

		case LCD_MODE_ERROR_EVENT:
			lcdPage = Error_Event_Config();
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
	const u16 iconStandby = ICON_STANDBY_BOX;//ICON_MAIN_STANDBY;
	u32 defultWatt =0;

	System_Circle_Icon(ICON_SYS_CHK_PER_0);

	sys_delay_ms(500);


	pwCnt = 0;
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
	calMode = 0;
	wattIdxMain = 0;
	prePointAddr = 0;

	iconMove = ICON_STANDBY_BOX;//ICON_MAIN_COOLING1;

	manufacYY = 0;
	manufacMM = 0;
	manufacDD = 0;
	issuedYY=0;
	issuedMM = 0;
	issuedDD = 0;
	sysChkFlag = 1;
	reTxTimeStamp = 0;
	cartTouch = 0;
	cartIdx = 0;
	cartValue = 0;
	cartPrePointAddr = 0;

	infoTouch = 0;
	infoIdx = 0;
	infoValue = 0;
	infoPrePointAddr = 0;

	errEvent = 0;
	errCartEvent = 0;

	systemStep = STEP0;
	systemTimeStamp = 0;
	systemTimeTerm = 0;
	systemLive = 0;
	systemCartEnd = 0;
	temperature = 0;
	peltierDuty = 0;
	popUpMode = 0;

	btn = 0;
	btnMain = 0;

	btnSetting = 0;
	timeStampShot = 0;

	Flash_Read();



	sys_write_vp(CIRCLE_WATE_ADDR,(u8*)&iconStandby ,2);

	uartRxStep = 0;
	uartCmdTemp = 0;
	uartValueTemp = 0;

	uartRxFlag = 0;


	for(i =0 ;i < 3;i++)
	{
		chkOkBuff[i] = 0;
	}

	for(i =1 ;i <25; i++)
	{
		textCartrigeBuff[i] = 0;
	}
	for(i =1 ;i <20; i++)
	{
		textinfoBuff[i] = 0;
	}

	Watt_All_Zero();
	Watt_Exp_zero();

	onTimeCalv = 7;
	sys_write_vp(CALIV_PULSETIME_NUM_NUM_ADDR,(u8*)&onTimeCalv ,4);


/////////////////////


	engineerKey = 0;

	agingFlag = 0;
	agingLongFlag = 0;
	newAreaCnt = 0;


	for(i =0 ;i < 4;i++)
	{
		for(j =0 ;j < 2;j++)
		{
			cmdBuff[i][j] = 0;
		}
	}

	cmdRxRingCnt = 0;
	cmdPassingRingCnt = 0;
	shotSum = 0;
	totaljouleSum = 0;

	yPointBuff[0] = POS_1_Y;
	yPointBuff[1] = POS_2_Y;
	yPointBuff[2] = POS_3_Y;
	yPointBuff[3] = POS_4_Y;
	yPointBuff[4] = POS_5_Y;
	testNum = 50;
	testNum2 = 200;

	ErrCode_Init();

#if 1
	lcdPage = LCD_MODE_INIT;

#else //  시간단축 하이패스
	lcdPage = LCD_MODE_TEST;

	Page_Change(LCD_MODE_TEST);




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

