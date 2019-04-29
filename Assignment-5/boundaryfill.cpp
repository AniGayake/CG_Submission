#include<iostream>
#include<graphics.h>
using namespace std;

void boundaryfill(int x, int y, int f_color, int b_color)
 {
 	if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
 	 {
 	 	putpixel(x,y,f_color);
 	 	boundaryfill(x+1,y,f_color,b_color);
 	 	boundaryfill(x,y+1,f_color,b_color);
 	 	boundaryfill(x-1,y,f_color,b_color);
 	 	boundaryfill(x,y-1,f_color,b_color);
     }
 }
 
 int main()
  {
  	
  	int x,y,r;
  	x=100,y=200,r=50;
  	int gd=DETECT,gm;
  	initgraph(&gd,&gm,NULL);
  	circle(x,y,r);
  	boundaryfill(x,y,6,15);
  	getch();
  	closegraph();
  	return 0;
  }
