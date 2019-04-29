#include<iostream>
#include<graphics.h>
using namespace std;
int sign (int x)
{
	if(x>0)
	{
		return 1;
	}
	else if(x=0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
int bresen(int x1,int y1,int x2,int y2)
{
	int e,x,y,s1,s2,ex_change,dx,dy,temp;  
	dx=abs(x2-x1);				
	dy=abs(y2-y1);
	x=x1,y=y1;				
	s1=sign(dx);				
	s2=sign(dy);
	if(dy>dx)				
	{
		temp=dy;
		dy=dx;
		dx=temp;
		ex_change=1;
	}
	else
	{
		ex_change=0;			
	}
	e=2*dy-dx;			
	int i=1;				
	while(i<=dx)				
	{
		putpixel(x,y,10);		
		while(e>=0)			
		{
		if(ex_change==1)		
		x=x+s1;
		else				
		y=y+s2;
		e=e-2*dx;			
		}
		if(ex_change==1)			
			y=y+s2;
		else					
			x=x+s1;					
			e=e+2*dy;				
			i++;					
	}
}
int main()
{
	int gm,gd=DETECT;
	initgraph(&gm,&gd,NULL);
	
	
	bresen(50,150,150,150);
	delay(2000);
	bresen(50,150,50,300);
	delay(2000);
	bresen(150,150,150,300);
	delay(2000);
	bresen(50,300,150,300);
	delay(2000);
	bresen(75,250,125,250);
	delay(2000);
	bresen(75,250,75,300);
	delay(2000);
	bresen(125,250,125,300);
	delay(2000);
	
	
	getch();
	closegraph();
	return 0;
}

