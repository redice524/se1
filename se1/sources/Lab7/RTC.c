/** @file RTC.c
 *  RTC module.
 */
#include "RTC.h"

/** 
 * Faz a iniciação do sistema para permitir o acesso ao periférico RTC. 
 * @param dateTime Estrutura com os valores de iniciaçao do RTC
 * Nota: A struct tm está definida na biblioteca standard da linguagem C
*/
void RTC_Init(struct tm *dateTime){
	LPC2106_BASE_RTC.ILR= 	0x00000000; 	//Interrupt Location Register
	//RTC.CTC;				//Clock Tick Counter Register
	LPC2106_BASE_RTC.CCR= 	0x00000000;	//Clock Control Register
	LPC2106_BASE_RTC.CIIR= 	0x00000000;	//Counter Increment Interrupt Register
	LPC2106_BASE_RTC.AMR= 	0x00000000;	//Alarm Mask Register- Not Used
	//LPC2106_BASE_RTC.CTIME0;				//Read-Only dateTime->tm_wday<<24| dateTime->tm_hour<<16| dateTime->tm_min << 8 | dateTime->tm_sec;
	//LPC2106_BASE_RTC.CTIME1; 			//Read-Only dateTime->tm_year| dateTime->tm_mon << 8 | dateTime->tm_mday;
	//LPC2106_BASE_RTC.CTIME2;				//Read-Only
	
	/* Time Counter Group */
	
	LPC2106_BASE_RTC.SEC=	dateTime->tm_sec;
	LPC2106_BASE_RTC.MIN=	dateTime->tm_min; 
	LPC2106_BASE_RTC.HOUR=	dateTime->tm_hour;
	LPC2106_BASE_RTC.DOM=	dateTime->tm_mday;
	LPC2106_BASE_RTC.DOW=	dateTime->tm_wday;
	LPC2106_BASE_RTC.DOY=	dateTime->tm_yday;
	LPC2106_BASE_RTC.MONTH=	dateTime->tm_mon;
	LPC2106_BASE_RTC.YEAR=	dateTime->tm_year;
	
	//LPC2106_BASE_RTC.RESERVED[8];		//Dummy
	
	/* Alarm Register Group - Not Used
	LPC2106_BASE_RTC.ALSEC; 
	LPC2106_BASE_RTC.ALMIN; 
	LPC2106_BASE_RTC.ALHOUR,
	LPC2106_BASE_RTC.ALDOM,
	LPC2106_BASE_RTC.ALDOW, 
	LPC2106_BASE_RTC.ALDOY, 
	LPC2106_BASE_RTC.ALMON, 
	LPC2106_BASE_RTC.ALYEAR;
	* 
	* 
	/* Reference Clock Divider */
	
	LPC2106_BASE_RTC.PREINT= (LPC2106_PCLK/32768) - 1;
	LPC2106_BASE_RTC.PREFRAC= LPC2106_PCLK - ((LPC2106_BASE_RTC.PREINT+1) * 32768);
	LPC2106_BASE_RTC.CCR= 	0x00000001;
}

/** 
 * Devolve o valor corrente do RTC. 
 * @param dateTime Estrutura onde sera comolcados os valores actuais do RTC
 * Nota: A struct tm está definida na biblioteca standard da linguagem C
*/
void RTC_GetValue(struct tm *dateTime){
	dateTime->tm_sec=	LPC2106_BASE_RTC.SEC;
	dateTime->tm_min=	LPC2106_BASE_RTC.MIN;
	dateTime->tm_hour=	LPC2106_BASE_RTC.HOUR;
	dateTime->tm_mday=	LPC2106_BASE_RTC.DOM;
	dateTime->tm_wday=	LPC2106_BASE_RTC.DOW;	
	dateTime->tm_yday=	LPC2106_BASE_RTC.DOY;	
	dateTime->tm_mon=	LPC2106_BASE_RTC.MONTH;	
	dateTime->tm_year=	LPC2106_BASE_RTC.YEAR;
}

/**
 * Actualiza os valores do RTC com os valores do parâmetro dateTime. 
 * @param dateTime Estrutura com os valores para actualizar o RTC
 * Nota: A struct tm está definida na biblioteca standard da linguagem C
*/
void RTC_SetValue(struct tm *dateTime){
	LPC2106_BASE_RTC.SEC=	dateTime->tm_sec;
	LPC2106_BASE_RTC.MIN=	dateTime->tm_min; 
	LPC2106_BASE_RTC.HOUR=	dateTime->tm_hour;
	LPC2106_BASE_RTC.DOM=	dateTime->tm_mday;
	LPC2106_BASE_RTC.DOW=	dateTime->tm_wday;
	LPC2106_BASE_RTC.DOY=	dateTime->tm_yday;
	LPC2106_BASE_RTC.MONTH=	dateTime->tm_mon;
	LPC2106_BASE_RTC.YEAR=	dateTime->tm_year;
}

/**
 * Faz a iniciação do Alarme do RTC. 
 * @param dateTime Estrutura com os valores de iniciaçao do alarme
 * Nota: A struct tm está definida na biblioteca standard da linguagem C
*/
void RTC_SetAlarm(struct tm *dateTime){
	LPC2106_BASE_RTC.ALSEC=	dateTime->tm_sec;
	LPC2106_BASE_RTC.ALMIN=	dateTime->tm_min; 
	LPC2106_BASE_RTC.ALHOUR=	dateTime->tm_hour;
	LPC2106_BASE_RTC.ALDOM=	dateTime->tm_mday;
	LPC2106_BASE_RTC.ALDOW=	dateTime->tm_wday;
	LPC2106_BASE_RTC.ALDOY=	dateTime->tm_yday;
	LPC2106_BASE_RTC.ALMONTH=	dateTime->tm_mon;
	LPC2106_BASE_RTC.ALYEAR=	dateTime->tm_year;
}
