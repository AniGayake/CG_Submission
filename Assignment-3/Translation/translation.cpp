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

int bresenham(int x1,int y1,int x2,int y2)
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
bresenham(20,30,100,100);  
getch();
closegraph();
int tx=1,ty=1;
cout<<"\n enter the value of translation factor in x and y direction respectively : ";
cin>>tx>>ty;
int original_coordinates[2][3]={20,30,1,100,100,1};
int translation_matrix[3][3]={1,0,0,0,1,0,tx,ty,1};
int new_coordinates[2][3]={0};

for(int i=0;i<2;i++)
{
	for(int j=0;j<3;j++)
	{
		for(int k=0;k<3;k++)
		{
			new_coordinates[i][j]+=original_coordinates[i][k]*translation_matrix[k][j];
		}
	}
}
initgraph(&gm,&gd,NULL);
bresenham(new_coordinates[0][0],new_coordinates[0][1],new_coordinates[1][0],new_coordinates[1][1]);
getch();
closegraph();
return 0;
}
