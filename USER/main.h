
/********************************************************
����������ʦQQ��2809786963
����������ʦ����QQ��3036522458
�Ա����̣�������
������̣�������my
CSDN��������
bilibili��������my
QQȺ��
Ⱥ1��981140834
Ⱥ2��473982062
Ⱥ3��718245727
Ⱥ4��473982062
Ⱥ5��879981149
Ⱥ6��865052468
Ⱥ7��821740056
Ⱥ8��236914485
Ⱥ9��820408714
Ⱥ10��499163973
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
	u8 errCnt;//�������
	u8 errTime;//�ȴ�����ʱ��
}SysTemPat;


extern SysTemPat sys;

#define SYS_SAVEADDR 0x0800f000


