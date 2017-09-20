
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#define WIDTH getmaxx()
#define HEIGHT getmaxy()
#define COLOR_RED "\x1b[31m"
#define COLOR_RESET "\x1b[0m"

int isContinue=1,d=5,del=500;

void ChangeOption()
{
   switch(getch())
   {
	case 'a'://wind to left
	case 'A':
	d=-5;
	break;

	case 'd'://wind to right
	case 'D':
	d=5;
	break;

	case 's'://no wind
	case 'S':
	d=0;
	break;

	case 'w'://increase rain speed
	case 'W':
	if(del!=100)
	del-=200;
	break;

	case 'X'://decrease rain speed
	case 'x':
	if(del!=1100)
	del+=200;
	break;

	case ' '://stop raining
	isContinue=0;
	break;
   }
}

void main()
{
clrscr();
int gd=DETECT,gm,xr,yr,i,j=0;
initgraph(&gd,&gm,"C:\\TURBOC3\\bgi");
do
  {
  textcolor(0);
  textbackground(15);

  printf(COLOR_RESET"CHANGE WIND DIRECTION:");
  printf(COLOR_RED" S(s): No wind  A(a) : right - left   D(d): left - right\n");
  printf(COLOR_RESET"CHANGE SPEED:  ");
  printf(COLOR_RED"W(w): Speed Up  X(x): Speed Down Space: Stop Rain");

  for(i=10;i<300;i++)
  {
   xr=rand()%640;
   yr=rand()%345;

   if(j%2==0)
   line(xr,yr,xr+d,yr+5);
   else
   line(xr+10,yr,xr+10+d,yr+5);
  }

   delay(del);
   clrscr();
   cleardevice();

   j++;
   if(kbhit())
   ChangeOption();
   }while(isContinue);
}

for (int i=0;i<500;i++)
{
/***CAR BODY ******/
line(50+i,370,90+i,370);
arc(110+i,370,0,180,20);
line(130+i,370,220+i,370);
arc(240+i,370,0,180,20);
line(260+i,370,300+i,370);
line(300+i,370,300+i,350);
line(300+i,350,240+i,330);
line(240+i,330,200+i,300);
line(200+i,300,110+i,300);
line(110+i,300,80+i,330);
line(80+i,330,50+i,340);
line(50+i,340,50+i,370);

/***CAR Windows***/
line(165+i,305,165+i,330);
line(165+i,330,230+i,330);
line(230+i,330,195+i,305);
line(195+i,305,165+i,305);

line(160+i,305,160+i,330);
line(160+i,330,95+i,330);
line(95+i,330,120+i,305);
line(120+i,305,160+i,305);

/**Wheels**/
circle(110+i,370,17);
circle(240+i,370,17);

delay(10);
cleardevice();

line(0,390,639,390);  //ROAD
}
getch();
}