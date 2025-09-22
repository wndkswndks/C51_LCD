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


#define PW_ICON_ADDR				0x1600
#define SYSTEM_ICON_ADDR			0x1620
#define SYSTEM_CHECK_CTRL_ICON_ADDR	0x1640
#define SYSTEM_CHECK_GEN_ICON_ADDR	0x1660
#define SYSTEM_CHECK_HP_ICON_ADDR	0x1680

#define EN_ICON_ADDR 0x2200

#define READY_STANDBY_ICON_ADDR 0x1980

#define TRANDU_FREQ_NUM_ADDR       	0x2600
#define TRANDU_WATT_NUM_ADDR       	0x2610
#define TRANDU_FREQ_POINT_ADDR 		0x22C2
#define TRANDU_WATT_POINT_ADDR 		0x22D0




#define START_ICON_AUTOCAL_POINT_SATAT_ADDR	0x2400
#define START_ICON_AUTOCAL_POINT_END_ADDR	0x24A6

#define START_ICON_AUTOCAL_NUM_START_ADDR		0x24A8
#define START_ICON_AUTOCAL_NUM_END_ADDR			0x254E

//=======================================

#define TRANDU1_FREQ1_ADDR       0x2600

//=======================================

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



	ED_1 = 1,
	ED_2 = 2,
	ED_3 = 3,
	ED_4 = 4,
	ED_5 = 5,
	ED_6 = 6,
	ED_7 = 7,
	ED_RDY_SBY = 8,

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

	IDX_FLASH_MAX = 174,

	CAL_MODE_FRQ = 1,
	CAL_MODE_WATT = 2,


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
	BTN_MAIN_ENGINIER = 15,


	//SETTING MODE
	BTN_SETTING_BACKHOME = 1,
	BTN_SETTING_VOL_CHECK = 2,


	//ENGINER MODE
	BTN_EG_INFOMATION = 1,
	BTN_EG_CALIBRATION = 2,
	BTN_EG_BACKHOME = 3,
	BTN_EG_AUTOCAL = 4,

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

	//AUTO CALIBRATION
	KEY_AUTO_CAL_1_2 = 1,
	KEY_AUTO_CAL_3_4_5 = 2,
	KEY_AUTO_CAL_6_7 = 3,
	KEY_AUTO_CAL_STOP = 4,
	KEY_AUTO_CAL_BACK = 5,

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

} PAGE_E;




typedef enum
{
	CMD_DUMY = 0,
	CMD_ENERGY,
	CMD_PULSE_DURATION,
	CMD_POST_COOLING,
	CMD_INTERVAL,
	CMD_CURRENT_SHOT,
	CMD_TOTAL_JOULE,
	CMD_REMIND_SHOT,
	CMD_TEMPERATURE_SHOT,
	CMD_XXXX,

	CMD_FRQ_CH0 = 10,
	CMD_FRQ_CH1,
	CMD_FRQ_CH2,
	CMD_FRQ_CH3,
	CMD_FRQ_CH4,
	CMD_FRQ_CH5,
	CMD_FRQ_CH6,

	CMD_WATT_CH0 = 17,
	CMD_WATT_CH1,
	CMD_WATT_CH2,
	CMD_WATT_CH3,
	CMD_WATT_CH4,
	CMD_WATT_CH5,
	CMD_WATT_CH6,
	CMD_ENGINER_ON = 30,

	CMD_LCD_EXP = 85,
	CMD_LCD_COOL_FINISH = 86,
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



extern idata u16 delay_tickMy;
extern xdata u8  uartRxBuff[20];
extern xdata u8  uartRxFlag;
extern xdata u8  uartRxStep;

idata u32 textCpy=0;
xdata u16 btn,btnMain,btnSetting;

idata u32 sysTimeStamp;

idata u8 toggle = 1;
xdata u8 toggleCalvBox;

xdata u16 pwCnt;
//xdata u16 pageNum;
idata u8 lcdPage;
xdata u16 iconCircle;
xdata u16 iconSystemCircle;

idata u32 energy=0;
idata u8 watt=0;
idata u16 energyNum=0;

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
xdata u16 wattBuff[7][34];
xdata u16 frqBuff[7];


///옮기는 변수는 오직이거
xdata u32 textBuffNew[92];
xdata u16 textBuffSave[92];

xdata u16 textFrqBuff[8];
xdata u16 textWattBuff[8][12];
xdata u8 frqIdx = 0;
xdata u8 wattIdxMain = 0, wattIdxSub = 0;





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
idata u16 coolCnt = 33;
idata u16 coolCntTemp;
idata u8 coolFinish;
xdata u8 autoCalAdd;
xdata u8 autoCalAddPre;
xdata u8 autoCalStart;

xdata u8 autoCalIng;
xdata u8 calMode;
xdata u16 prePointAddr;


void Light_Change(u16 light);
void Volume_Change(u16 volume);

void Debug_Print(int num, int debugData)
{
	printf("[%d] %d\r\n",num, debugData);
}

void TX_Msg(u16 txCmd, u16 txData)
{
	int txCmdInt = 0;
	int txDataInt =0;
	u16 rxCmd = 0;
	u32 rxData =0;
	u32 timeStamp = 0;
	u8 txCnt = 0;
	const u8 maxCnt = 3;
	printf("[%u,%u]\r\n",txCmd, txData);

	timeStamp = delay_tickMy;
	return;
	while (1)
	{
		if(uartRxFlag)
		{
			uartRxFlag = 0;
			rxCmd = uartRxBuff[0];
			rxData = ((uartRxBuff[1]<<8)|uartRxBuff[2])&0xffff;

			if((rxCmd == txCmd) && (rxData == txData))
			{
				//printf("OK\r\n");
				break;
			}
			else
			{
				//printf("ERR\r\n");
			}

		}
		if(delay_tickMy-timeStamp >= 500)
		{
			printf("[%u,%u]\r\n",txCmd, txData);
			txCnt++;
			if(txCnt>maxCnt)
			{
				printf("timeOut\r\n");
				break;
			}
			timeStamp = delay_tickMy;
		}
	}


}

void DefultValue_Set()
{
	u16 add = 0;
	int i = 0,j = 0;
	u32 defultWatt=0;
	u32 defultFrq=0;

//	for(i =0 ;i < 92;i++)
//	{
//		textBuffNew[i] = 0;
//	}
	for(i =1 ;i < 8;i++)
	{
		textFrqBuff[i] = 11000;
		defultFrq = textFrqBuff[i];
		add = (u16)(TRANDU_FREQ_NUM_ADDR + (i-1)*0x02);
		sys_write_vp(add,(u8*)&defultFrq,2);
	}

	for(i =1 ;i < 8;i++)
	{
		for(j =1 ;j < 12;j++)
		{
			textWattBuff[i][j] = 44;
			defultWatt = textWattBuff[i][j];
			add = (u16)(TRANDU_WATT_NUM_ADDR + ((i-1)*11+(j-1))*0x02);
			sys_write_vp(add,(u8*)&defultWatt,2);
		}
	}

//	for(i =1 ;i < 85;i++)
//	{
//		add = (u16)(TRANDU_WATT_NUM_ADDR + (i-1)*0x02);
////		defultWatt = textBuffSave[i];
//		sys_write_vp(add,(u8*)&defultWatt,2);
//		textBuffNew[i] = textBuffSave[i];
//	}

}



void TextAll_Uart_Send()
{
	int i =0;
	u16 add = 0;
	u16 value = 0;
	u16 addIcon = 0;
	const u16 icon9 = 9;

	sys_delay_ms(100);

	add = CMD_ENGINER_ON;
	value = onTimeCalv;
	TX_Msg(add, value);

	for(i =0 ;i < 7;i++)
	{
		add = i+CMD_FRQ_CH0;
		value = textFrqBuff[i+1];
		TX_Msg(add, value);
		Debug_Print(add,value);
	}
	for(i =0 ;i < 7;i++)
	{
		if(edBuff[i+1] )
		{
			add = i+CMD_WATT_CH0;
			value = textWattBuff[wattIdxMain][wattIdxSub];
			TX_Msg(add, value);
			Debug_Print(add,value);
		}
	}


	sys_delay_ms(1000);
	TX_Msg(40, 1);
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


void Data_Uart_Send()
{
	int i =0 ;
	int dataValue = 0;
	float wattF = 0;
	for(i =1 ;i <10;i++)
	{
		dataValue = (int)dataBuff[i];
		printf("[%d,%d]\r\n",i,dataValue);
	}


	wattF = (float)energy/(float)pulseDuration;
	watt  = wattF*10;
	if(watt>29)watt = 29;

	for(i =0 ;i <7;i++)
	{
		dataValue = frqBuff[i];
		printf("[%d,%d]\r\n",i+CMD_FRQ_CH0,dataValue);
	}
	for(i =0 ;i <7;i++)
	{
		dataValue = wattBuff[i][watt];
		printf("[%d,%d]\r\n",i+CMD_WATT_CH0,dataValue);
	}

	TX_Msg(40, 1);
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

void RX_Parssing_Config()
{
	u16 add = 0;
	u16 position = 0;
	u32 text=0;
	const u16 icon42 = 42, icon43 = 43;

	if(uartRxFlag)
	{
		uartRxFlag = 0;
		position = uartRxBuff[0];
		if(position>0)
		{
			text = ((uartRxBuff[1]<<8)|uartRxBuff[2])&0xffff;

			if(position == CMD_LCD_EXP)
			{
				if(text == LCD_EXP_START)
				{
					expFlag = 1;
					if (lcdPage == LCD_MODE_MAIN)
					{
						currentShot++;
						sys_write_vp(CURRENT_SHOT_ADDR,(u8*)&currentShot ,2);
						dataBuff[CMD_CURRENT_SHOT] = currentShot;

						totalJoule = totalJoule + energy;
						sys_write_vp(TOTAL_JOULE_ADDR,(u8*)&totalJoule ,2);
						dataBuff[CMD_TOTAL_JOULE] = totalJoule;

						remindShot--;
						sys_write_vp(REMIND_SHOT_ADDR,(u8*)&remindShot ,2);
						dataBuff[CMD_REMIND_SHOT] = remindShot;
						TX_Msg(CMD_REMIND_SHOT, remindShot);
					}

				}
				else if(text == LCD_EXP_END)
				{
					expFlag = 0;
				}
			}
			else if(position == CMD_LCD_COOL_FINISH)
			{
				coolFinish = 1;
			}
			else if((position == CMD_LCD_AUTO_CAL) && (lcdPage == LCD_MODE_AUTOCAL))
			{
				if(text == 10)
				{
					autoCalStart = 1;
				}
				else if(text == 11)
				{
					autoCalStart = 0;
					add = (u16)(START_ICON_AUTOCAL_POINT_SATAT_ADDR + ((autoCalAdd-1)*0x02));
					sys_write_vp(add, (u8*)&icon43,2);
				}
			}
//			else if((KEY_TRANDU1_WATT10<= position && position <= KEY_TRANDU7_WATT005) && (lcdPage == LCD_MODE_AUTOCAL))
//			{

//				textBuffNew[position] = text;
//				if(position == 1)
//				{

//				}
//				else
//				{

//					autoCalAdd = position +1;
//				}

//				add = (u16)(START_ICON_AUTOCAL_NUM_START_ADDR + (position-1)*0x02);
//				sys_write_vp(add,(u8*)&textBuffNew[position] ,2);
//			}
//			else
//			{

//			}



		}

	}


}


idata u16 numTest =0;

u8 Test_Config()
{
	u8 returnValue = 0;
	static u32 timeStampQ = 0;
	u16 btn =0;
	int indData[4] ={0,};

	returnValue = LCD_MODE_TEST;

	if(delay_tickMy-timeStampQ >= 3000)
	{
		TX_Msg(1, 11);
		TX_Msg(2, 12);
		TX_Msg(3, 13);
		TX_Msg(4, 14);

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
	static u32 timeStamp = 0;
	const u16 icon28 = 28, icon30 = 30, icon32 = 32;

	returnValue = LCD_MODE_SYS_CHK;



	if(delay_tickMy-timeStamp >= 100)
	{
		sys_write_vp(SYSTEM_ICON_ADDR, (u8*)&iconSystemCircle,2);
		iconSystemCircle++;

		if(iconSystemCircle==19)
		{
			sys_write_vp(SYSTEM_CHECK_CTRL_ICON_ADDR, (u8*)&icon28,2);
		}

		if(iconSystemCircle==22)
		{
			sys_write_vp(SYSTEM_CHECK_GEN_ICON_ADDR, (u8*)&icon30,2);
		}

		if(iconSystemCircle==25)
		{
			sys_write_vp(SYSTEM_CHECK_HP_ICON_ADDR, (u8*)&icon32,2);
		}


		if(iconSystemCircle>26)
		{
			iconSystemCircle = 16;
			Page_Change(LCD_MODE_MAIN);
			returnValue = LCD_MODE_MAIN;
		}
		timeStamp = delay_tickMy;
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
			case KEY_1:
			case KEY_2:
			case KEY_3:
			case KEY_4:
			case KEY_5:
			case KEY_6:
			case KEY_7:
			case KEY_8:
			case KEY_9:
				if(pwCnt<4)
				{
					textCpy = textCpy*10 + btn;
					pwCnt++;
					sys_write_vp(PW_ICON_ADDR, (u8*)&pwCnt,2);
				}
			break;

			case KEY_0:
				if(pwCnt<4)
				{
					textCpy = textCpy*10 + 0;
					pwCnt++;
					sys_write_vp(PW_ICON_ADDR, (u8*)&pwCnt,2);
				}
			break;

			case KEY_DEL:
				if(pwCnt>0)
				{
					textCpy = textCpy/10;
					pwCnt--;
					sys_write_vp(PW_ICON_ADDR, (u8*)&pwCnt,2);
				}
			break;

			case KEY_CLEAR:
				pwCnt = 0;
				textCpy = 0;
				sys_write_vp(PW_ICON_ADDR, (u8*)&pwCnt,2);
			break;


		}

		if(pwCnt==4)
		{
			if(textCpy == 4444||textCpy == 1111)
			{
				if(textCpy == 1111) engineerKey = 1;

				sys_delay_ms(300);
				pwCnt = 0;
				textCpy = 0;
				sys_write_vp(PW_ICON_ADDR, (u8*)&pwCnt,2);
				returnValue = LCD_MODE_SYS_CHK;

				Page_Change(LCD_MODE_SYS_CHK);
				sysTimeStamp = delay_tickMy;
			}
			else
			{

				sys_delay_ms(300);

				pwCnt = 5;
				sys_write_vp(PW_ICON_ADDR, (u8*)&pwCnt,2);
				sys_delay_ms(1000);

				pwCnt = 0;
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
	u16 add = 0;
	u8 returnValue = 0;
	const u16 icon33 = 33, icon34 = 34, icon35 = 35, icon36 = 36, icon37 = 37;
	int i =0;
	static u32 timeStamp;



	returnValue = LCD_MODE_MAIN;


	sys_read_vp(MAIN_BUTTON_ADDR,(u8*)&btnMain,1);
	if(btnMain)
	{
		switch (btnMain)
		{
			case BTN_MAIN_ENERGY_UP:
				if(energy<100)
				{
					energy++;
					energyNum++;
					sys_write_vp(ENERGY_ADDR,(u8*)&energy ,4);
					sys_write_vp(ENERGY_MINI_ADDR,(u8*)&energy ,4);
					dataBuff[CMD_ENERGY]= energy;
				}

			break;

			case BTN_MAIN_ENERGY_DN:
				if(energy>0)
				{
					energy--;
					energyNum--;
					sys_write_vp(ENERGY_ADDR,(u8*)&energy ,4);
					sys_write_vp(ENERGY_MINI_ADDR,(u8*)&energy ,4);
					dataBuff[CMD_ENERGY]= energy;
				}
			break;

			case BTN_MAIN_PULSE_DURATION_UP:
				if(pulseDuration<100)
				{
					pulseDuration++;
					sys_write_vp(PULSE_DURATION_ADDR,(u8*)&pulseDuration ,4);
					sys_write_vp(PULSE_MINI_ADDR,(u8*)&pulseDuration ,4);
					dataBuff[CMD_PULSE_DURATION] = pulseDuration;
				}
			break;

			case BTN_MAIN_PULSE_DURATION_DN:
				if(pulseDuration>0)
				{
					pulseDuration--;
					sys_write_vp(PULSE_DURATION_ADDR,(u8*)&pulseDuration ,4);
					sys_write_vp(PULSE_MINI_ADDR,(u8*)&pulseDuration ,4);
					dataBuff[CMD_PULSE_DURATION] = pulseDuration;
				}
			break;

			case BTN_MAIN_POST_COOLING_UP:
				if(postCooling<30)
				{
					postCooling++;
					sys_write_vp(POST_COOLING_ADDR,(u8*)&postCooling ,4);
					sys_write_vp(COOLING_MINI_ADDR,(u8*)&postCooling ,4);
					dataBuff[CMD_POST_COOLING] = postCooling;
				}
			break;

			case BTN_MAIN_POST_COOLING_DN:
				if(postCooling>0)
				{
					postCooling--;
					sys_write_vp(POST_COOLING_ADDR,(u8*)&postCooling ,4);
					sys_write_vp(COOLING_MINI_ADDR,(u8*)&postCooling ,4);
					dataBuff[CMD_POST_COOLING] = postCooling;
				}
			break;

			case BTN_MAIN_INTERVAL_UP:
				if(interval<30)
				{
					interval++;
					sys_write_vp(INTERVAL_ADDR,(u8*)&interval ,4);
					sys_write_vp(INTERVAL_MINI_ADDR,(u8*)&interval ,4);
					dataBuff[CMD_INTERVAL] = interval;
				}
			break;

			case BTN_MAIN_INTERVAL_DN:
				if(interval>0)
				{
					interval--;
					sys_write_vp(INTERVAL_ADDR,(u8*)&interval ,4);
					sys_write_vp(INTERVAL_MINI_ADDR,(u8*)&interval ,4);
					dataBuff[CMD_INTERVAL] = interval;
				}
			break;

			case BTN_MAIN_CURRENT_SHOT_RST:
				currentShot = 0;
				sys_write_vp(CURRENT_SHOT_ADDR,(u8*)&currentShot ,2);
				dataBuff[CMD_CURRENT_SHOT] = currentShot;
			break;

			case BTN_MAIN_TOTAL_JOULE_RST:
				totalJoule = 0;
				sys_write_vp(TOTAL_JOULE_ADDR,(u8*)&totalJoule ,2);
				dataBuff[CMD_TOTAL_JOULE] = totalJoule;
			break;

			case BTN_MAIN_RDY_STNBY:
				if (rdyStnbyMode == STATUS_TRET)
				{
					rdyStnbyMode = STATUS_STNBY;
					sys_write_vp(READY_STANDBY_ICON_ADDR,(u8*)&icon33 ,2);
					printf("[40,0]\r\n");
				}
				else if (rdyStnbyMode == STATUS_PRECOOLING)
				{
					rdyStnbyMode = STATUS_STNBY;
					sys_write_vp(READY_STANDBY_ICON_ADDR,(u8*)&icon33 ,2);
				}
				else if (rdyStnbyMode == STATUS_STNBY)
				{

					rdyStnbyMode = STATUS_PRECOOLING;
					coolCnt = 33;
				}
			break;

			case BTN_MAIN_SETTING:
				Page_Change(LCD_MODE_SETTING);
				returnValue = LCD_MODE_SETTING;
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


		if(btnMain != BTN_MAIN_RDY_STNBY && (rdyStnbyMode == STATUS_TRET ||rdyStnbyMode == STATUS_PRECOOLING ))
		{
			rdyStnbyMode = STATUS_STNBY;
			coolCntTemp = 0;
			coolCnt = 33;
			sys_write_vp(READY_STANDBY_ICON_ADDR,(u8*)&icon33 ,2);
			TX_Msg(40, 0);
		}

		btnMain= 0;
		sys_write_vp(MAIN_BUTTON_ADDR,(u8*)&btnMain,2);
	}


	if(rdyStnbyMode == STATUS_PRECOOLING)
	{
		if(delay_tickMy-timeStamp >= 1000)
		{

			coolCnt++;
			if(coolCnt==37) coolCnt = 34;
			sys_write_vp(READY_STANDBY_ICON_ADDR,(u8*)&coolCnt ,2);

			coolCntTemp++;
			if(coolCntTemp==40 ||coolFinish)
			{
				coolFinish = 0;
				coolCntTemp = 0;
				coolCnt = 33;
				rdyStnbyMode = STATUS_TRET;
				sys_write_vp(READY_STANDBY_ICON_ADDR,(u8*)&icon37 ,2);
				Data_Uart_Send();
			}
			timeStamp = delay_tickMy;
		}
	}

	RX_Parssing_Config();


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
	for(i =1 ;i < 8;i++)
	{
		cmd = i+CMD_TRANDU_FRQ_BASE;
		value = textFrqBuff[i];
		TX_Msg(cmd, value);
	}

	for(i =1 ;i < 8;i++)
	{
		for(j =1 ;j < 12;j++)
		{
			cmd = (i-1)*11+j+CMD_TRANDU_WATT_BASE;// 101~177
			value = textWattBuff[i][j];
			TX_Msg(cmd, value);
		}
	}

}

void Calibration_TDU_Parts()//
{

	u16 btnTtext;
	u16 add = 0, pointAdd = 0;
	const u16 icon42 = 42,  icon43 = 43;
	sys_read_vp(CAL_TOUCH_FRQ_ADDR, (u8*)&btnTtext,1);
	if (btnTtext)
	{
		if(prePointAddr &&prePointAddr != pointAdd)
		{
			sys_write_vp(prePointAddr,(u8*)&icon42,2);
		}
		pointAdd = (u16)(TRANDU_FREQ_POINT_ADDR + (btnTtext-1)*0x02);
		sys_write_vp(pointAdd,(u8*)&icon43,2);
		prePointAddr = pointAdd;

		textNum = textFrqBuff[btnTtext];
		add = (u16)(TRANDU_FREQ_NUM_ADDR + (btnTtext-1)*0x02);
		sys_write_vp(add,(u8*)&textNum,2);

		calMode = CAL_MODE_FRQ;
		frqIdx = btnTtext;
		btnTtext= 0;
		sys_write_vp(CAL_TOUCH_FRQ_ADDR,(u8*)&btnTtext,2);
	}

	sys_read_vp(CAL_TOUCH_TDU_ADDR, (u8*)&btnTtext,1);
	if (btnTtext)
	{
		if(prePointAddr &&prePointAddr != pointAdd)
		{
			sys_write_vp(prePointAddr,(u8*)&icon42,2);
		}
		pointAdd = (u16)(TRANDU_WATT_POINT_ADDR + (btnTtext-1)*0x02);
		sys_write_vp(pointAdd,(u8*)&icon43,2);
		prePointAddr = pointAdd;

		wattIdxMain = ((btnTtext-1)/11)+1;
		wattIdxSub = ((btnTtext-1)%11)+1;
		calMode = CAL_MODE_WATT;

		textNum = textWattBuff[wattIdxMain][wattIdxSub];
		add = (u16)(TRANDU_WATT_NUM_ADDR + (btnTtext-1)*0x02);
		sys_write_vp(add,(u8*)&textNum,2);

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
	const u16 icon6 = 6, icon7 = 7, icon8 = 8, icon9 = 9;
	const u32 bntED0= 0,bntED1 = 1;
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

				if(calMode == CAL_MODE_FRQ)
				{
//					if(textNum > 13000) textNum = 13000;
//					else if(textNum < 11000) textNum = 0;

					textFrqBuff[frqIdx] = textNum;
					add = (u16)(TRANDU_FREQ_NUM_ADDR + (frqIdx-1)*0x02);
					sys_write_vp(add,(u8*)&textNum,2);
				}
				else if(calMode == CAL_MODE_WATT)
				{
					if(textNum > 100) textNum = 100;
					else if(textNum < 0) textNum = 0;

					textWattBuff[wattIdxMain][wattIdxSub] = textNum;
					addSub = (wattIdxMain-1)*11+ (wattIdxSub-1);
					add = (u16)(TRANDU_WATT_NUM_ADDR + addSub*0x02);
					sys_write_vp(add,(u8*)&textNum,2);
				}
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
				TX_Msg(CMD_ENGINER_ON, 0xff);

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
		if(edBuff[bntED])
		{
			edBuff[bntED] = 0;
			add = (u16)(EN_ICON_ADDR + (bntED-1)*0x02);
			if(bntED==8) sys_write_vp(add, (u8*)&icon7,2);
			else sys_write_vp(add, (u8*)&icon8,2);
			if(bntED == ED_RDY_SBY) TX_Msg(40,0);
		}
		else
		{
			edBuff[bntED] = 1;
			add = (u16)(EN_ICON_ADDR + (bntED-1)*0x02);
			if(bntED==8) sys_write_vp(add, (u8*)&icon6,2);
			else sys_write_vp(add, (u8*)&icon9,2);
			if(bntED == ED_RDY_SBY) TextAll_Uart_Send();
		}
		bntED= 0;
		sys_write_vp(CAL_TOUCH_ENDIS_ADDR,(u8*)&bntED,2);
	}


	RX_Parssing_Config();
	return returnValue;

}



u8 Auto_Calibration_Config()//
{
	u8 returnValue = 0;
	int value = 0;
	u16 add = 0;
	u16 addIcon = 0;
	int i = 0;
	const u16 icon42 = 42, icon43 = 43;
	u16 btn,bntED = 0;

	static u32 timeStamp = 0;
	returnValue = LCD_MODE_AUTOCAL;
	sys_read_vp(AUTOCAL_BUTTON_ADDR,(u8*)&btn,1);
	if(btn)
	{
		switch (btn)
		{
			case KEY_AUTO_CAL_1_2:
				TX_Msg(87, 1);
				autoCalIng = 1;
				autoCalAdd =1;
				autoCalAddPre = 1;
			break;

			case KEY_AUTO_CAL_3_4_5:
				TX_Msg(87, 2);
				autoCalIng = 2;
				autoCalAdd =25;
				autoCalAddPre =25;
			break;

			case KEY_AUTO_CAL_6_7:
				TX_Msg(87, 3);
				autoCalIng = 3;
				autoCalAdd =60;
				autoCalAddPre =60;
			break;

			case KEY_AUTO_CAL_STOP:
				autoCalIng = 0;
				autoCalAddPre = 0;
				autoCalAdd = 0;
				autoCalStart = 0;
				TX_Msg(87, 4);
			break;

			case KEY_AUTO_CAL_BACK:
				autoCalIng = 0;
				autoCalAddPre = 0;
				autoCalAdd = 0;
				autoCalStart = 0;
				Page_Change(LCD_MODE_ENGINIEER);
				returnValue = LCD_MODE_ENGINIEER;
				TX_Msg(87, 5);
			break;

		}
		btn= 0;
		sys_write_vp(AUTOCAL_BUTTON_ADDR,(u8*)&btn,2);

	}

	if(autoCalIng && autoCalStart)
	{
		if(delay_tickMy-timeStamp >= 500)
		{
			if(autoCalAddPre != autoCalAdd) // 새로운 주소가 들어오면 기존주소는 고정
			{
				add = (u16)(START_ICON_AUTOCAL_POINT_SATAT_ADDR + ((autoCalAddPre-1)*0x02));
				sys_write_vp(add, (u8*)&icon43,2);
			}
			autoCalAddPre = autoCalAdd;

			add = (u16)(START_ICON_AUTOCAL_POINT_SATAT_ADDR + ((autoCalAdd-1)*0x02));

			if(toggle)
			{
				toggle = 0;
				sys_write_vp(add, (u8*)&icon42,2);
			}
			else
			{
				toggle = 1;
				sys_write_vp(add, (u8*)&icon43,2);

			}
			timeStamp = delay_tickMy;
		}
	}

	RX_Parssing_Config();
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
				Page_Change(LCD_MODE_CALIBRATION);
				DefultValue_Set();
				returnValue = LCD_MODE_CALIBRATION;
			break;

			case BTN_EG_BACKHOME:
				Page_Change(LCD_MODE_MAIN);
				returnValue = LCD_MODE_MAIN;
			break;
			case BTN_EG_AUTOCAL:
				Page_Change(LCD_MODE_AUTOCAL);
				returnValue = LCD_MODE_AUTOCAL;
			break;
		}
		btn= 0;
		sys_write_vp(ENGINEER_BUTTON_ADDR,(u8*)&btn,2);

	}



	return returnValue;

}
void Debug_PrintConfig()
{
#if 0
	static u32 timeStamp;
	if(delay_tickMy-timeStamp >= 2000)
	{
		int indData1 = 0,indData2 = 0,indData3 = 0;


		indData1 = lcdPage;
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

	}
	Debug_PrintConfig();

}





void Lcd_Init()//
{
	int i = 0;
	int j = 0;
	const u16 icon33 = 33;

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
	energyNum=0;
	coolCnt = 33;
	coolCntTemp = 0;
	coolFinish = 0;
	onTimeCalv=0;
	toggle = 1;
	toggleCalvBox = 0;
	autoCalAdd = 0;
	autoCalAddPre = 0;
	autoCalIng = 0;
	autoCalStart = 0;
	calMode = 0;
	frqIdx = 0;
	wattIdxMain = 0;
	wattIdxSub = 0;
	prePointAddr = 0;

	Flash_Read();



	sys_write_vp(READY_STANDBY_ICON_ADDR,(u8*)&icon33 ,2);

	uartRxStep = 0;
	for(i =0 ;i < 20;i++)
	{
		uartRxBuff[i] = 0;
	}
	uartRxFlag = 0;
	for(i =0 ;i < 10;i++)
	{
		dataBuff[i] = 0;
	}

	for(i =0 ;i < 7;i++)
	{
		frqBuff[i] = 0;
		for(j =0 ;j <34;j++)
		{
			wattBuff[i][j]= 11000 +j;
		}
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
	lcdPage = LCD_MODE_TEST;
	Page_Change(LCD_MODE_TEST);

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

