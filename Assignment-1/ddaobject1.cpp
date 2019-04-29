#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;
void dda(int x1, int y1, int x2, int y2);
int sign(float value) 
 {
		if(value<0)
		return -1;
		else 
		return 1;
}


int main() 
{
	
	int gm = DETECT, gd = DETECT;
	initgraph(&gm,&gd,NULL);

	dda(150, 80, 80, 200);
	delay(500);
	dda(150, 80, 200, 200);
	delay(100);
	dda(80, 200, 500, 200);
	delay(500);
	dda(150, 80, 420, 80);
	delay(500);
	dda(420, 80, 500, 200);
	delay(500);
	dda(80, 200, 80, 450);
	delay(500);
	dda(200, 200, 200, 450);
	delay(500);
	dda(500, 200, 500, 450);
	delay(500);
	dda(80, 450, 500, 450);
	delay(500);
	dda(105, 450, 105, 350);
	delay(500);
	dda(155, 450, 155, 350);
	delay(500);
	dda(105, 350, 155, 350);
	delay(1000);
	
	getch();
	closegraph();
	return 0;



}


void dda(int x1, int y1, int x2, int y2) {
	int length;
	float dx,dy;
	float x,y;

	 if(x1 ==x2 && y1 == y2){
	   putpixel(x1,y1,RED);
	   }
	else {
		dx = abs(x2 - x1);
		dy = abs(y2 - y1);

	if(dx >= dy) {
			length = dx;
		} else {
			length = dy;
		}
		
		dx = (x2-x1)/length;
		dy = (y2-y1)/length;

		x = x1 + 0.5 + sign(dx);
		y = y1 + 0.5 + sign(dy);
		
		int i=1;
		while(i<=length) {
			putpixel(int(x),int(y), WHITE);
			x = x + dx;
			y = y + dy;
			i= i + 1;
		}
	}
}

