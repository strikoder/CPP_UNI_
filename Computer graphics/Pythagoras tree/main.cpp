#include "graphics.h"
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include<iostream>
using namespace std;
int co;

void pifagor(int n,double x0,double y0,double a,double fi,double alpha) {
	double x1,y1,x2,y2,x3,y3,x4,y4;
	double grad = M_PI/180;
	//
	x1=x0-a*cos(fi*grad);
	y1=y0-a*sin(fi*grad);
	x2=x1+a*sin(fi*grad);
	y2=y1-a*cos(fi*grad);
	x3=x0+a*sin(fi*grad);
	y3=y0-a*cos(fi*grad);
	x4=x3-a*cos(alpha*grad)*cos((fi+alpha)*grad);
	y4=y3-a*cos(alpha*grad)*sin((fi+alpha)*grad);
	//
	

	line(x0,y0,x1,y1);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x0,y0,x3,y3);
	
	co++;
	co=co%16;
	if(co==0)
		co++;
	setcolor(co);
	
	if (n>0) 
	{
      	line(x3,y3,x4,y4);
		line(x2,y2,x4,y4);
		pifagor(n-1,x3,y3,a*cos(alpha*grad),fi+alpha,alpha);
		pifagor(n-1,x4,y4,a*sin(alpha*grad),fi+alpha-90,alpha);
	}

}
int main()
{
    int gddriver = DETECT, gmode, errorcode;
    initgraph(&gddriver, &gmode, "");
    pifagor(12,400,getmaxy()-15,80,0,60);//Required tree
    //pifagor(5,340,getmaxy()-20,75,0,45); //another breathtaking shape
    
    getch();
    closegraph;
    return 0;
}

