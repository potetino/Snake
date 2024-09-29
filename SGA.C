/* Игра Змейка 2024 для ПК 11/16к */

$$narg = 1;

#include "bios.h"
#include "math.h"
#include "time.h"
#include "FIG.T"

#define  MAXX  340
#define  MAXY  240
#define  XC MAXX/2
#define  YC MAXY/2
#define  MAXX1  380
#define  MAXY1  280
#define  MAXCOLOR  15
#define  TRUE -1
#define  FALSE 0
#define sndc0r (*(int*)0161010)
#define sndcsr (*(int*)0161016)
#define snlc0r (*(int*)0161020)
#define snlcsr (*(int*)0161026)

int  MODP;
int  IDENT,ANUM;
int  IDENT1,ANUM1;
char CH;
int  ERR;
struct ARETYP AR;
struct WINTYP VW;
struct PALTYP PAL;
struct PALTYP PAL1;
int  *KEYB   = 0177560;
int  *KEYBUF = 0177562;
int COLOR;
char STRET[] = "                 МОСКВА 2024   ";

/*33-------------------------------------------------*/


int KEYPRESSED()
{
  return(*KEYB & 0200);
}

int READKEY()
{
  return(*KEYBUF);
}

GETCHH()
{
  while(!KEYPRESSED());

  READKEY();
}

BOX (IDENT,X1,Y1,X2,Y2)
int IDENT,X1,Y1,X2,Y2;
{
  GMOVE (IDENT, X1, Y1);
  GLINE (IDENT, X1, Y2);
  GLINE (IDENT, X2, Y2);
  GLINE (IDENT, X2, Y1);
  GLINE (IDENT, X1, Y1);
}

/*------------------------------------------------*/

INIT()
{
  STRET[0] = 07;
  STRET[1] = 0360;
  PAL1.PMODPAL = 0;
  PLSAV(&PAL1);
  COLOR = PAL1.PAL[15];
  PAL1.PAL[15] = 0;
  PLMOD (&PAL1);
  *KEYB = 0;
  MODP=PL0+VM40;
  GCREA (MAXX, MAXY, MODP, &IDENT, &ANUM);
  GCREA (MAXX1, MAXY1, MODP, &IDENT1, &ANUM1);
  GWNDW (IDENT, 0,0, MAXX, MAXY);
	VW.WNUM=0;
	VW.AREA=ANUM1;
	VW.ARY=0;
	VW.ARX=0;
	VW.SY1=15;
	VW.SY2=MAXY1+10;
	VW.SX1=2;
	VW.SX2=26;
	VW.DEN=01002;
     VWCRE (&VW);
	VW.WNUM=0;
	VW.AREA=ANUM;
	VW.ARY=0;
	VW.ARX=0;
	VW.SY1=16;
	VW.SY2=MAXY+20;
	VW.SX1=3;
	VW.SX2=24;
	VW.DEN=01002;
     VWCRE (&VW);
     GROP(IDENT, 0);
}

MESSAGE (STR)
char STR[];
{
  STR[0]=07;
  STR[1]=0360;
  WPRINT (ANUM1, 20, MAXY1-15, STR);
}

/*--------------------------------*/

BEEP(a,b,c,i)
int a,b,c,i;
{
sndcsr = 066;
snlcsr = 034;
snlc0r = 3;
sndc0r = a;
sndc0r = b;

for(i = 0; i < c; ++i);

snlcsr = 064;
sndcsr = 066;
}

/*--------------------------------*/

#define MAXST 11
#define MAXFILLINE 18
int STYLE;
int PATTERNS[MAXST][MAXFILLINE+1];
char STRA[] = "     Игра для ЭВМ ПК11/16к Союз-Неон    ";

TITUL()
{
int t;
int SUMM0, SUMM1, SUMM2, SUMM3, SUMM4, SUMM5, SUMM6;
int i1,i2,i3,i4,i5,i6,i7;

  MESSAGE ("  автор А.Ермаков (potetino@gmail.com)");

    GCLRR (IDENT);
    GROP (IDENT, 0);
    SUMM0 = 0;
    SUMM1 = 0;
    SUMM2 = 0;
    SUMM3 = 0;
    SUMM4 = 0;
    SUMM5 = 0;
    SUMM6 = 0;

          PATTERNS[1][1]=4; PATTERNS[1][2]=2;
	  PATTERNS[1][3]=0110220; PATTERNS[1][4]=0;
	  GPTRN(IDENT,&PATTERNS[1][1]);
	  GFILL(IDENT,0,120);	

    for( i1 = 0; i1 <= 144; ++i1)
    {
      GFGC (IDENT, 10);
      GDOT (IDENT, XC+FIG[SUMM0][0], YC+FIG[SUMM0][1]);
      SUMM0 = SUMM0 + 1;
    };
     for( i2 = 0; i2 <= 28; ++i2)
    {
      GFGC (IDENT, 2);
      GDOT (IDENT, XC+FIG1[SUMM1][0], YC+FIG1[SUMM1][1]);
      SUMM1 = SUMM1 + 1;
    };
     for( i3 = 0; i3 <= 138; ++i3)
    {
      GFGC (IDENT, 14);
      GDOT (IDENT, XC+FIG2[SUMM2][0], YC+FIG2[SUMM2][1]);
      SUMM2 = SUMM2 + 1;
    };
     for( i4 = 0; i4 <= 45; ++i4)
    {
      GFGC (IDENT, 15);
      GDOT (IDENT, XC+FIG3[SUMM3][0], YC+FIG3[SUMM3][1]);
      SUMM3 = SUMM3 + 1;
    };
    for( i5 = 0; i5 <= 34; ++i5)
    {
      GFGC (IDENT, 6);
      GDOT (IDENT, XC+FIG4[SUMM4][0], YC+FIG4[SUMM4][1]);
      SUMM4 = SUMM4 + 1;
    };
    for( i6 = 0; i6 <= 125; ++i6)
    {
      GFGC (IDENT, 4);
      GDOT (IDENT, XC+FIG5[SUMM5][0], YC+FIG5[SUMM5][1]);
      SUMM5 = SUMM5 + 1;
    };
    for( i7 = 0; i7 <= 12; ++i7)
    {
      GFGC (IDENT, 10);
      GDOT (IDENT, XC+FIG6[SUMM6][0], YC+FIG6[SUMM6][1]);
      SUMM6 = SUMM6 + 1;
    };
	STRA[0] = 07;
	STRA[1] = 0360;
	WPRINT (ANUM,9,MAXY1-276,STRA);
	WPRINT (ANUM1,9,MAXY1-27,STRET);
    GETCHH();

}


/*198-------------------------------------------------*/
#define NULL ((void *)0)
#define rangeN 68
#define rangeM 68

int FIELDSIZE = rangeN * rangeM;
int FIELD[rangeN * rangeM];
int HX,HY, HDX,HDY, TX,TY, DELTA;
int SNLEN,SNREM;
int tdelta;
int i,tmp,z;
int tmp1=0;
int i1,i2,i3,i4,t,key;
int STEPA,STEPB,STEPC,STEPD;
int FX1,FX2,FY1,FY2;
int PAUSETIME;
int void;
int tm;
int speed;
char STRB[];
char STRC[] = "  Счет:     ";

SNAKEGAME()
{
	long clock;	
	PATTERNS[2][1]=4; PATTERNS[2][2]=1;
	PATTERNS[2][3]=0x4444;
	GCLRR(IDENT1);
	GCLRR(IDENT);
	GROP(IDENT,2);
	GPTRN(IDENT1,&PATTERNS[1][1]);
	GFILL(IDENT1,0,120);
	GPTRN(IDENT,&PATTERNS[2][1]);
	GFILL(IDENT,0,0);	
	PAL.PMODPAL=MODP;
	PLSAV (&PAL);
	tmp=PAL.PAL[15];
	PLMOD(&PAL);
	PAL.PAL[15]=tmp;
	PLMOD (&PAL);

	FX1 = RANDOM(67)*5;
	FX2 = FX1+4;
	FY1 = RANDOM(47)*5;
	FY2 = FY1+4;
	GFGC(IDENT,6);
	BOX(IDENT,FX1,FY1,FX2,FY2);

	MESSAGE ("    Управление стрелками, выход <0> ");
	WPRINT (ANUM1, 20, MAXY1-30, STRC);	

	for (i = 0; i < FIELDSIZE; ++i) FIELD[i] = 0;
	HX = rangeN / 2;  TX = HX;
	HY = 24;  TY = HY;
	/* draw the head */
	GFGC(IDENT,2);
	BOX(IDENT, HX * 5, HY * 5, HX * 5 + 4, HY * 5 + 4);
	HDX = 1;  HDY = 0;  DELTA = 1;
	SNLEN = 1;  SNREM = 5;
	speed = 11;
	while (TRUE) {
		
		if (HX * 5 == FX1 && HY * 5 == FY1) {
			SNREM = 1;
			GFGC(IDENT,6);  
			BOX(IDENT,FX1,FY1,FX2,FY2);
			srand(time(&clock));
			FX1 = (1 + rand()%(67-1))*5;
			FX2 = FX1 + 4;
			FY1 = (1 + rand()%(47-1))*5;
			FY2 = FY1 + 4;
			BOX(IDENT,FX1,FY1,FX2,FY2);
			GFGC(IDENT,2);

			tmp1 = tmp1+1;
			STRB[0]=07;
			STRB[1]=0360;
			sprintf(STRB,"%d",tmp1);
			WPRINT (ANUM1, 55, MAXY1-30, STRB);
			
			if (tmp1%10 == 0) speed = speed-2;
			if (speed <= 1) speed = 11;
			BEEP(193,17,3000,0);
			}
		if (KEYPRESSED()) {
			key = GETCHH();
			if (key == 060) break;
			else if (key == 0103) {
				HDX = 1;
				HDY = 0;
				DELTA = 1;
			}
			else if (key == 0102) {
				HDX = 0;
				HDY = 1;
				DELTA = 2;
			}
			else if (key == 0104) {
				HDX = -1;
				HDY = 0;
				DELTA = -1;
			}
			else if (key == 0101) {
				HDX = 0;
				HDY = -1;
				DELTA = -2;
			}
			else continue;
		}

		/* update the head */
		FIELD[HY * rangeN + HX] = DELTA;
		HX = HX + HDX;
		HY = HY + HDY;
		if (HX >= rangeM) HX = 0;
		else if (HX < 0) HX = rangeN - 1;
		if (HY >= 48) HY = 0;
		else if (HY < 0) HY = 48;
		if (FIELD[HY * rangeN +HX] != 0) { 
		BEEP(220,39,6000,0);
		break;
		}
		/* draw the head */
		for(t=0; t < speed; ++t)
		    for(z=0; z < 255; ++z);
		BOX(IDENT, HX * 5, HY * 5, HX * 5 + 4, HY * 5 + 4);

		if (SNREM > 0) {
			--SNREM;  ++SNLEN;
		}
		else {
			/* erase the tail */
			for(t=0; t < speed; ++t)
			    for(z=0; z < 255; ++z);
			BOX(IDENT, TX * 5, TY * 5, TX * 5 + 4, TY * 5 + 4);
			/* update the tail */
			tdelta = FIELD[TY * rangeN + TX];
			FIELD[TY * rangeN + TX] = 0;
			if (tdelta == -1)
				--TX;
			else if (tdelta == 1)
				++TX;
			else if (tdelta == -2)
				--TY;
			else if (tdelta == 2)
				++TY;
			if (TX >= rangeM) TX = 0;
			else if (TX < 0) TX = rangeN - 1;
			if (TY >= 48) TY = 0;
			else if (TY < 0) TY = 48;
		}
	}
}

/*-------------------------------------------------*/

char STRZ[] = "   Змейка для ПК 11/16к является свободным"; 
char STRY[] = "   вариантом  игры  SNAKE  и  создана в   "; 
char STRX[] = "   демонстрационно-развлекательных  целях.";
char STRW[] = "   Отдельное спасибо Н.Зимину и А.Кислому.";

GAMEOVER()
{
	int i,i1,i2,t;
	int SUMM = 0;
	int SUMM1 = 0;
	int SUMM2 = 0;
	*KEYB |= 0100;
	GCLRR (IDENT1);
	GCLRR (IDENT);

	STRZ[0] = 07;
	STRZ[1] = 0360;
	WPRINT (ANUM,5,MAXY1-276,STRZ);
	STRY[0] = 07;
	STRY[1] = 0360;
	WPRINT (ANUM,5,MAXY1-260,STRY);
	STRX[0] = 07;
	STRX[1] = 0360;
	WPRINT (ANUM,5,MAXY1-244,STRX);
	STRW[0] = 07;
	STRW[1] = 0360;
	WPRINT (ANUM,5,MAXY1-214,STRW);

	for( i=0; i <= 138; ++i)
	{
		GFGC (IDENT,14);
		GDOT (IDENT,XC+50+FIG2[SUMM][0], YC+50+FIG2[SUMM][1]);
		SUMM = SUMM + 1;
	};
	for( i1=0; i1 <= 28; ++i1)
	{
		GFGC (IDENT,2);
		GDOT (IDENT,XC+50+FIG1[SUMM1][0], YC+50+FIG1[SUMM1][1]);
		SUMM1 = SUMM1 + 1;
	};
	for (i2=0; i2 <= 45; ++i2)
	{
		GFGC (IDENT, 15);
		GDOT (IDENT,XC+50+FIG3[SUMM2][0], YC+50+FIG3[SUMM2][1]);
		SUMM2 = SUMM2 + 1;
	};
	for(t = 0; t < 250; ++t)
	MESSAGE ("           Конец игры      ");
	PAL1.PAL[15]=COLOR;
	PLMOD (&PAL1);
	GKILL (IDENT);
	GKILL (IDENT1);
	
}

/*-------------------------------------------------*/

main()
{
	INIT();
	TITUL();
	SNAKEGAME();
	GAMEOVER();
}
