#include "sys.h"
#include "lcd.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//测试硬件：单片机STC12LE5A60S2,晶振30M  单片机工作电压3.3V
//QDtech-TFT液晶驱动 for C51
//xiao冯@ShenZhen QDtech co.,LTD
//公司网站:www.qdtech.net
//淘宝网站：http://qdtech.taobao.com
//我司提供技术支持，任何技术问题欢迎随时交流学习
//固话(传真) :+86 0755-23594567 
//手机:15989313508（冯工） 
//邮箱:QDtech2008@gmail.com 
//Skype:QDtech2008
//技术交流QQ群:324828016
//创建日期:2013/5/13
//版本：V1.1
//版权所有，盗版必究。
//Copyright(C) 深圳市全动电子技术有限公司 2009-2019
//All rights reserved
//********************************************************************************

/****************************************************************************************************
//=========================================电源接线================================================//
//5V接DC 5V电源
//GND接地
//=======================================液晶屏数据线接线==========================================//
//本模块默认数据总线类型为8位并行模式
//8位模式接线：8位模式9481模块接高8位总线，即:
//液晶屏LCD_D0对应单片机P2.0
//液晶屏LCD_D1对应单片机P2.1
//液晶屏LCD_D2对应单片机P2.2
//液晶屏LCD_D3对应单片机P2.3
//液晶屏LCD_D4对应单片机P2.4
//液晶屏LCD_D5对应单片机P2.5
//液晶屏LCD_D6对应单片机P2.6
//液晶屏LCD_D7对应单片机P2.7
//=======================================液晶屏控制线接线==========================================//
//LCD_RST	接P3.3	//复位信号
//LCD_CS	接P1.3	//片选信号
//LCD_RS	接P1.2	//寄存器/数据选择信号
//LCD_WR	接P1.1	//写信号
//LCD_RD	接P1.0	//读信号
//=========================================触摸屏触接线=========================================//
//本模块触摸测试需连接外部XPT2046触摸采样芯片，所以本程序不进行触摸测试。
//不使用触摸或者模块本身不带触摸，则可不连接
**************************************************************************************************/	

//STC单片机IO推挽输出设置定义
//其他普通C51单片机无此配置请屏蔽下面这条语句
sfr P3M1  = 0xB1;	//P3M1.n,P3M0.n 	=00--->Standard,	01--->push-pull
sfr P3M0  = 0xB2;	//					=10--->pure input,	11--->open drain

//主函数
void main(void)
{ 

	//设置STC_12LE5A60S2单片机的P3.2为推挽输出，用于控制背光亮灭
	//其他普通C51单片机无此配置请屏蔽下面这条语句
	P3M1 &= ~(1<<2),P3M0 |=  (1<<2); 

	//液晶屏初始化
	LCD_Init();

	//循环进行各项测试	
	while(1)
	{	
		LCD_Clear(RED);delay_ms(1000);	delay_ms(1000);	
		LCD_Clear(GREEN);delay_ms(1000);	delay_ms(1000);	
		LCD_Clear(BLUE);delay_ms(1000);	delay_ms(1000);	
	}   
}
