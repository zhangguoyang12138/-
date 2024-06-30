
/********************************************************
化作尘工程师QQ：2809786963
化作尘工程师助理QQ：3036522458
淘宝店铺：化作尘
咸鱼店铺：化作尘my
CSDN：化作尘
bilibili：化作尘my
QQ群：
群1：981140834
群2：473982062
群3：718245727
群4：473982062
群5：879981149
群6：865052468
群7：821740056
群8：236914485
群9：820408714
群10：499163973
********************************************************/
#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "usart2.h"
#include "oled.h"
#include "button4_4.h"
#include "walkmotor.h"
#include "beep.h"
#include "MFRC522.h"
#include "rtc.h" 	
#include "stmflash.h"
#include "as608.h"


typedef struct 
{
	u32 HZCFlag;
	u8 passwd1[7];
	u8 passwd2[7];
	u8 cardid[10][6];
	u8 errCnt;//错误计数
	u8 errTime;//等待错误时间
}SysTemPat;


extern SysTemPat sys;

#define SYS_SAVEADDR 0x0800f000


