#ifndef MANAGER_H_
#define MANAGER_H_

#include "/home/user/Desktop/host-se1/se1/includes/ValueTypes.h"
#include "/home/user/Desktop/host-se1/se1/includes/Menu.h"
#include "/home/user/Desktop/host-se1/se1/includes/lcd.h"
#include "/home/user/Desktop/host-se1/se1/includes/log.h"
#include "/home/user/Desktop/host-se1/se1/includes/ButtonCTRL.h"
#include "/home/user/Desktop/host-se1/se1/includes/thermometer.h"


#define L0 0
#define L1 1
#define INC 1
#define DEC (-1)

typedef enum managementType{
	SET,
	LOG,
	EXIT
}ManType;

typedef struct entryMode{
	int on;
	Seter vals[3];
	int seterSize;
	ManType mType;
}EntryMode;

typedef struct ManagerInfo{
	char lines[2][16];
	EntryMode enter;
}ManagerInfo;

typedef struct MenuInfo{
	ManagerInfo menu1;
	ManagerInfo menu2;
	ManagerInfo menu3;
	ManagerInfo menu4;
	ManagerInfo menu5;
	ManagerInfo menu6;
}MenuInfo;

MenuInfo menus = {
		/** MENU 1 
		 * 
		 * Definir o valor de tmax
		 * 
		 * */
		{"1 - Definir    "    , "   TMax = +020.C" , {0, {{1, 13, TEMP, -55, 125, 20}} , 1, SET} },
		/** MENU 2 
		 * 
		 *  Definir o valor de tmin 
		 * 
		 * */
		{"2 - Definir    "    , "   TMin = +010.C" , {0, {{1, 13, TEMP, -55, 125, 10}} , 1, SET} },
		/** MENU 3 
		 * 
		 * Acertar o relógio
		 *  HH-MM
		 * 
		 *         Min - Max
		 *  HH       0 -  23
		 *  MM       0 -  59
		 * */
		{"3 - Relogio    "    , "           00-00" , {0, {{1, 12, MM, 0, 23, 0}, {1, 15, MM, 0, 59, 0}} , 2,SET} },
		/** MENU 4 
		 * 
		 *  Acertar o calendário
		 *  
		 *  DD-MM-AAAA
		 *         Min - Max
		 *  DD       1 -  31
		 *  MM       1 -  12
		 *  AAAA  2014 - X
		 * */
		{"4 - Calendario "    , "      00-00-0000" , {0, {{1, 7, MM, 1, 31, 24},{1, 10, MM, 1, 12, 1},{1,15,YEAR,1900,2500,2015}} , 3, SET} },
		/** MENU 5 
		 * 
		 *  Visualizar o registo de temperaturas
		 * 
		 * */
		{"5 - Visualizar "    , "    Temperaturas" , {0, {0} , 0,LOG} },
		/** MENU 6 *
		 * 
		 *  Sair da Manutencao
		 * 
		 */
		{"6 - Sair da    "    , "      Manutencao" , {0, {0} , 0,EXIT} }
};
MenuInfo* pMenus = &menus;

char* Manager_getStringMenu(int curr, int line);
void Manager_Print(Menu *m);
ManagerInfo* Manager_getMenu(int curr);

int Manager_Entry(Menu *m, Button *buts, int nButs, RegsLog *pRegLog);

void Manager_Enter(EntryMode *e, Button *buts, int nButs, RegsLog *pRegLog);

/**
 * SET MODE
 * */
void Manager_SetMode(EntryMode e);
/**
 *	GET POS -> (x,y)
 *  GET/SET VAL -> curr up/down
 *  MOVENEXTVAL 
 *  
 *  GET/SET VALUES <-> FLASH
 * 
 **/
int Manager_EntryGetX(Seter e);
int Manager_EntryGetY(Seter e);


/**
 * LOG MODE
 * */
void Manager_LogMode(RegsLog *pRegLog, Button *buts, int nButs);
//void Manager_ExitMode(EntryMode e);

void updateVal(SetVal *vals,int x ,int y, int size, int op, int valSet);
void Manager_Setting(Seter *s, int seterSize, Button *buts, int nButs);
#endif
