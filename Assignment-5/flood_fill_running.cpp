#include<iostream>
#include<graphics.h>
using namespace std;
void floodFill(int x,int y,int oldcolor,int newcolor)
{
	if(getpixel(x,y) == oldcolor)
	{
		putpixel(x,y,newcolor);
		floodFill(x+1,y,oldcolor,newcolor);

		floodFill(x,y+1,oldcolor,newcolor);

		floodFill(x-1,y,oldcolor,newcolor);

		floodFill(x,y-1,oldcolor,newcolor);

	}
}
//getpixel(x,y) gives the color of specified pixel 
 
int main()
{
	int gm,gd=DETECT,radius;
	int x,y;
	
	cout<<"Enter x and y positions for circle\n";
	cin>>x>>y;
	cout<<"Enter radius of circle\n";
	cin>>radius;
	
	initgraph(&gd,&gm,NULL);
	circle(x,y,radius);
	floodFill(x,y,0,15);
	delay(10000);
	closegraph();
	
	return 0;
}

//export LD_LIBRARY_PATH=''/usr/local/lib''

