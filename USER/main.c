#include "sys.h"
#include "uart2.h"
#include "nor_flash.h"

#include <stdio.h>

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
#define CART_VALUE_END_ADDR       	0x25B0

#define CART_VALUE_SATAT_ADDR       0x2590
#define CART_VALUE_END_ADDR       	0x25B0


#define TRANDU_FREQ_NUM_ADDR       	0x2600
#define TRANDU_WATT_NUM_ADDR       	0x2610

#define ERR_POPUP_ADDR       	0x2700

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
	OK_RF = 2,
	OK_HP = 3,




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
	LCD_MODE_MAIN_POPUP   = 14,
	LCD_MODE_SYS_CHK_POPUP =	15,


} PAGE_E;




typedef enum
{
	CMD_DUMY = 0,
	CMD_ENERGY	=	1,//LCD_REQ
	CMD_PULSE_DURATION = 2,//LCD_REQ
	CMD_POST_COOLING = 3,//LCD_REQ
	CMD_INTERVAL = 4,//LCD_REQ
	CMD_CURRENT_SHOT = 5,//MAIN_TX, LCD_TX //~~~
	CMD_TOTAL_JOULE = 6,//MAIN_TX, LCD_TX //~~~
	CMD_REMIND_SHOT = 7,//MAIN_TX, LCD_TX //~~~
	CMD_TEMPERATURE_SHOT  = 8,

	CMD_XXXX,

	CMD_FRQ_CH0 = 10,
	CMD_FRQ_CH1,
	CMD_FRQ_CH2,
	CMD_FRQ_CH3,
	CMD_FRQ_CH4,
	CMD_FRQ_CH5,
	CMD_FRQ_CH6 = 16,

	CMD_WATT_CH0 = 17,
	CMD_WATT_CH1,
	CMD_WATT_CH2,
	CMD_WATT_CH3,
	CMD_WATT_CH4,
	CMD_WATT_CH5,
	CMD_WATT_CH6 = 23,

	CMD_CAIV_DURATION = 30,

	CMD_ERR = 31,
	CMD_ALRAM = 32,
	CMD_INFO = 33,
	CMD_OK = 34,

	CMD_CART_ID  = 35,
	CMD_MANUFAC_YY,
	CMD_MANUFAC_MM,
	CMD_MANUFAC_DD,
	CMD_ISSUED_YY,
	CMD_ISSUED_MM,
	CMD_ISSUED_DD,
	CMD_DAY_REQ,
	CMD_RTC,

	CMD_LCD_STATUS = 50,
	CMD_SYS_CHK = 51,
	CMD_TRET_READY_OK = 52,
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

	ICON_MAIN_EMPTY_POP = 44,
	ICON_MAIN_POP = 45,
} ICON_E;

extern idata u16 delay_tickMy;
extern xdata u8  uartRxBuff[20];
extern xdata u8  uartRxFlag;
extern xdata u8  uartRxStep;

idata u32 textCpy=0;
xdata u16 btn,btnMain,btnSetting;

idata u32 sysTimeStamp;

idata u8 toggle = 1;

xdata u16 pwCnt;
//xdata u16 pageNum;
idata u8 lcdPage;
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



xdata u8 lcdOn,expFlag;
idata u32 dataBuff[10];
xdata u8 flashBuff[174];
xdata u32 mainDataBuff[9];


///옮기는 변수는 오직이거

xdata u16 textFrqBuff[8];
xdata u16 textWattBuff[78];
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
xdata u8 errEventBuff[30];
xdata u8 errEventFlag[30];
xdata u8 chkOkBuff[3];
xdata u16 reTxCmd;
xdata u16 reTxData;
xdata u32 reTxTimeStamp;
xdata u16 reTxCnt;




void Light_Change(u16 light);
void Volume_Change(u16 volume);

void Debug_Print(int num, int debugData)
{
	printf("[%d] %d\r\n",num, debugData);
}

void TX_Msg(u16 txCmd, u16 txData)
{
	printf("[%u,%u]\r\n",txCmd, txData);

	reTxCmd = txCmd;
	reTxData = txData;
	reTxTimeStamp = delay_tickMy;

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
			rxCmd = uartRxBuff[0];
			rxData = ((uartRxBuff[1]<<8)|uartRxBuff[2])&0xffff;

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
	Volume_Change(volumeLevel);
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

void Volume_Change(u16 volume)
{
	u8 buf[4];

	buf[0] = 0x02;
	buf[1] = 0x01;
	buf[2] = volume;
	buf[3] = 0x02;
 	sys_write_vp(0x00a0,buf,2);
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


void Event_PopUp(u16 eventCmd, u16 eventData)
{
	u16 iconErrIcon= 0;
	const u16 iconErrBack= 28; // 고정
	u16 iconErrCode= 0;
	u16 iconErrMsg= 0;


	if(EVENT_START_NUM > eventData || eventData >EVENT_MAX_NUM)
	{
		return;
	}
	sys_write_vp(0x1001, (u8*)&iconErrBack,2);//backGround

	if(eventCmd == CMD_ERR)iconErrIcon = 1;
	else if(eventCmd == CMD_ALRAM)iconErrIcon = 2;
	else if(eventCmd == CMD_INFO)iconErrIcon = 3;
	sys_write_vp(0x1111, (u8*)&iconErrIcon,2);//icon

	iconErrCode = EVENT_ICON_BASE +eventData;// if codeIcon== 51, 50+1
	sys_write_vp(0x2222, (u8*)&iconErrCode,2);//code

	iconErrMsg = EVENT_ICON_BASE + EVENT_MAX_NUM+ eventData;//msg는 code 뒤에 있음
	sys_write_vp(0x3333, (u8*)&iconErrMsg,2);//msg

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
	reTxTimeStamp = 0;
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

void RX_SYS_CHK_Parssing_Config()
{
	u16 add = 0;
	u16 cmd = 0;
	u32 value=0;

	if(uartRxFlag)
	{
		uartRxFlag = 0;
		ReTry_Reset();
		cmd = uartRxBuff[0];
		value = ((uartRxBuff[1]<<8)|uartRxBuff[2])&0xffff;
		switch (cmd)
		{

			case CMD_ERR:
				Event_PopUp(CMD_ERR, value);
				errEventBuff[value] = value;
				errEventFlag[value] = CMD_ERR;
			break;

			case CMD_ALRAM:
//				Event_PopUp(CMD_ALRAM, value);
				errEventBuff[value] = value;
				errEventFlag[value] = CMD_ALRAM;
			break;

			case CMD_INFO:
//				Event_PopUp(CMD_INFO, value);
				errEventBuff[value] = value;
				errEventFlag[value] = CMD_INFO;
			break;

			case CMD_OK://앞에 커멘드는 고정 뒤에는 장치명
				SYS_CHK_OK(value);
			break;

			case CMD_CART_ID:
				cartId = value;
			break;

			case CMD_MANUFAC_YY:
				manufacYY = value;
			break;

			case CMD_MANUFAC_MM:
				manufacMM = value;
			break;

			case CMD_MANUFAC_DD:
				manufacDD = value;
			break;

			case CMD_ISSUED_YY:
				issuedYY=value;
			break;
			case CMD_ISSUED_MM:
				issuedMM = value;
			break;

			case CMD_ISSUED_DD:
				issuedDD = value;
			break;

			case CMD_RTC:
				Rtc = value;
			break;


			case CMD_REMIND_SHOT:
				remindShot = value;
			break;

			default:
				if(CMD_TRANDU1_FRQ <= cmd && cmd <=CMD_TRANDU7_FRQ)
				{
					cmd  = cmd-90;
					textFrqBuff[cmd] = value;
				}
			break;
		}
	}
	ReTry_Tx();
}


void RX_MODE_MAIN_Parssing_Config()
{
	u16 cmd = 0;
	u32 value=0;
	const u16 iconStandby = ICON_MAIN_STANDBY, iconTreat = ICON_MAIN_TREAT;

	if(uartRxFlag)
	{
		uartRxFlag = 0;
		ReTry_Reset();
		cmd = uartRxBuff[0];
		value = ((uartRxBuff[1]<<8)|uartRxBuff[2])&0xffff;
		switch (cmd)
		{
			case CMD_ERR:
				Event_PopUp(CMD_ERR, value);
			break;

			case CMD_ALRAM:
				Event_PopUp(CMD_ALRAM, value);
			break;

			case CMD_INFO:
				Event_PopUp(CMD_INFO, value);
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
				sys_write_vp(REMIND_SHOT_ADDR,(u8*)&remindShot ,2);
			break;

			case CMD_LCD_STATUS:
				rdyStnbyMode = value;
				if(rdyStnbyMode == STATUS_STNBY)
				{
					sys_write_vp(READY_STANDBY_ICON_ADDR,(u8*)&iconStandby ,2);
				}
				else if(rdyStnbyMode == STATUS_TRET)
				{
					sys_write_vp(READY_STANDBY_ICON_ADDR,(u8*)&iconTreat ,2);
				}
				else if(rdyStnbyMode == STATUS_PRECOOLING)
				{
					iconMove = ICON_MAIN_COOLING1;
				}

			break;
			case CMD_LCD_EXP:
				if(value == LCD_EXP_START) expFlag = 1;
				else if(value == LCD_EXP_END) expFlag = 0;
			break;

			default:
			break;
		}
	}
	ReTry_Tx();
}

void RX_ENGINIEER_Parssing_Config()
{
	u16 add = 0;
	u16 cmd = 0;
	u32 value = 0;

	if(uartRxFlag)
	{
		uartRxFlag = 0;
		ReTry_Reset();
		cmd = uartRxBuff[0];
		value = ((uartRxBuff[1]<<8)|uartRxBuff[2])&0xffff;


//		if(CMD_TRANDU1_FRQ <= cmd && cmd <=CMD_TRANDU7_FRQ)
//		{
//			cmd  = cmd-90;
//			textFrqBuff[cmd] = value;
//		}
//		if(CMD_TRANDU1_WATT10 <= cmd && cmd <=CMD_TRANDU7_WATT005)
//		{
//			cmd  = cmd-100;
//			textWattBuff[cmd] = value;
//			calRcvCnt++;
//			autoCalRcvCnt++;
//		}


	}
	ReTry_Tx();
}
void RX_CALIBRATION_Parssing_Config()
{
	u16 add = 0;
	u16 cmd = 0;
	u32 value=0;

	if(uartRxFlag)
	{
		uartRxFlag = 0;
		ReTry_Reset();
		cmd = uartRxBuff[0];
		value = ((uartRxBuff[1]<<8)|uartRxBuff[2])&0xffff;
		switch (cmd)
		{
			case CMD_LCD_STATUS:
				rdyStnbyMode = value;
			break;

			case CMD_LCD_EXP:
				if(value == LCD_EXP_START) expFlag = 1;
				else if(value == LCD_EXP_END) expFlag = 0;
			break;


			default:
			break;
		}
	}
	ReTry_Tx();
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
		cmd = uartRxBuff[0];
		value = ((uartRxBuff[1]<<8)|uartRxBuff[2])&0xffff;

		if(CMD_TRANDU1_WATT10 <= cmd && cmd <=CMD_TRANDU7_WATT005)
		{
			if(value == AUTOCAL_START)
			{
				if(autoCalStart==0)
				{
					autoCalStart = cmd;
					cmd = cmd -100;
					autoCalAdd = (u16)(START_ICON_AUTOCAL_POINT_SATAT_ADDR + ((cmd-1)*0x02));
				}
			}
			else if(value == AUTOCAL_STOP)
			{
				if(autoCalStart == cmd)
				{
					autoCalStart = 0;
					sys_write_vp(autoCalAdd, (u8*)&iconCalEmptyPoint,2);
				}
			}
			else
			{
				cmd  = cmd-100;
				textWattBuff[cmd] = value;
				autoCalRcvCnt++;
			}

		}

	}
	ReTry_Tx();
}



idata u16 numTest =0;

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
	if(btn==1)
	{
		btn= 0;
		sys_write_vp(TEST_BUTTON_ADDR,(u8*)&btn,2);
	}


	return LCD_MODE_TEST;
}


u8 System_Check_Config()
{
	u8 returnValue = 0;
	int i =0 ;
	static u32 timeStamp = 0;
	const u16 iconMainEn = ICON_SYS_CHK_MAIN_EN, iconGenEn = ICON_SYS_CHK_GEN_EN, iconHpEn = ICON_SYS_CHK_HP_EN;

	returnValue = LCD_MODE_SYS_CHK;

	if(sysChkFlag==0)
	{
		sysChkFlag = 1;
		TX_Msg(CMD_SYS_CHK, 0);
	}

	if(delay_tickMy-timeStamp >= 100)
	{
		sys_write_vp(SYSTEM_ICON_ADDR, (u8*)&iconSystemCircle,2);
		iconSystemCircle++;

		if(iconSystemCircle == ICON_SYS_CHK_PER_30)
		{
			if(chkOkBuff[0])
				sys_write_vp(SYSTEM_CHECK_CTRL_ICON_ADDR, (u8*)&iconMainEn,2);
			else
			{
				//popup
				for(i =0 ;i < EVENT_MAX_NUM;i++)
				{
					if(errEventBuff[i] != 0)
					{
//						Event_PopUp(errEventFlag[i], errEventBuff[i]);
//						sys_delay_ms(1000);
					}
				}
			}

		}

		if(iconSystemCircle == ICON_SYS_CHK_PER_60)
		{
			if(chkOkBuff[1])
				sys_write_vp(SYSTEM_CHECK_CTRL_ICON_ADDR, (u8*)&iconGenEn,2);
			else
			{
				//popup
				for(i =0 ;i < EVENT_MAX_NUM;i++)
				{
					if(errEventBuff[i] != 0)
					{
//						Event_PopUp(errEventFlag[i], errEventBuff[i]);
//						sys_delay_ms(1000);
					}
				}
			}
		}

		if(iconSystemCircle == ICON_SYS_CHK_PER_90)
		{
			if(chkOkBuff[2])
				sys_write_vp(SYSTEM_CHECK_CTRL_ICON_ADDR, (u8*)&iconHpEn,2);
			else
			{
				//popup
				for(i =0 ;i < EVENT_MAX_NUM;i++)
				{
					if(errEventBuff[i] != 0)
					{
//						Event_PopUp(errEventFlag[i], errEventBuff[i]);
//						sys_delay_ms(1000);
					}
				}
			}
		}


		if(iconSystemCircle>ICON_SYS_CHK_PER_100)
		{
			iconSystemCircle = ICON_SYS_CHK_PER_0;
			Page_Change(LCD_MODE_MAIN);
			returnValue = LCD_MODE_MAIN;
		}
		timeStamp = delay_tickMy;
	}

	RX_SYS_CHK_Parssing_Config();
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

u8 Main_Config()
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
//				if(errEventFlag)
//				{
//					errEventFlag = 0;
//					sys_write_vp(ERR_POPUP_ADDR,(u8*)&icon44 ,2);
//				}
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
		}

		btnMain= 0;
		sys_write_vp(MAIN_BUTTON_ADDR,(u8*)&btnMain,2);
	}

	EXP_FreeCool_Motion();
	RX_MODE_MAIN_Parssing_Config();
//	if(errEventFlag)
//	{
//		Page_Change(LCD_MODE_MAIN_POPUP);
//		returnValue = LCD_MODE_MAIN_POPUP;
//	}


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
				Volume_Change(volumeLevel);
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
				//Watt_Load();
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


	RX_CALIBRATION_Parssing_Config();
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

	RX_AUTOCAL_Parssing_Config();
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
	static u32 timeStampQ = 0;

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
				calRcvCnt = 0;

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
			break;

			case BTN_EG_BACKHOME:
				Page_Change(LCD_MODE_MAIN);
				returnValue = LCD_MODE_MAIN;
			break;

			case BTN_EG_AUTOCAL:
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
			break;
		}
		btn= 0;
		sys_write_vp(ENGINEER_BUTTON_ADDR,(u8*)&btn,2);

	}


	RX_ENGINIEER_Parssing_Config();


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


		indData1 = rdyStnbyMode;
		indData2 = (int)iconMove;
		indData3 = (int)autoCalAdd;

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

//		case LCD_MODE_MAIN_POPUP:
//			lcdPage = Pop_Main_Config();
//		break;

//		case LCD_MODE_SYS_CHK_POPUP:
//			lcdPage = Pop_System_Chk_Config();
//		break;

	}
	Debug_PrintConfig();

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
	sysChkFlag = 0;
	Rtc = 0;
	reTxCmd = 0;
	reTxData = 0;
	reTxTimeStamp = 0;
	reTxCnt = 0;


	Flash_Read();



	sys_write_vp(READY_STANDBY_ICON_ADDR,(u8*)&iconStandby ,2);

	uartRxStep = 0;
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



/////////////////////


	for( i =0 ;i < 9;i++)
	{
		edBuff[i] = 0;
	}
	engineerKey = 0;




#if 1
	lcdPage = LCD_MODE_INIT;

#else //  시간단축 하이패스
	lcdPage = LCD_MODE_MAIN;
	Page_Change(LCD_MODE_MAIN);

//	DefultValue_Set();



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

