#include "graphics.h"
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int co;

void myline(int x1, int y1, int x2, int y2, int c){
	/*
	int e, i, j, M, N;
	int i1, i2, j1, j2;
	
	i1=x1, i2=x2, j1=y1, j2=y2;
	j=j1;
	M = abs(j2-j1);
	N= abs(i2-i1); 
	
	putpixel(x1, j1, c);
	e = 0;
	for(i = i1+1; i<=i2; i++){
		e+=M;
		if(e>=N){
			while(e>=N){
				j++;
				e-=N;
				putpixel(i, j, c);
			}
		}
		else{
			putpixel(i,j,c);
		}
	}
	*/
	int dx,dy,sx,sy;
    putpixel(x2,y2,c);
    if(x2-x1>=0)
		dx = (int)(x2-x1);
    else
		dx = (int)(x1-x2);
		
    if(y2-y1>=0)
		dy = (int)(y2-y1);
    else
		dy = (int)(y1-y2);
    if(x1<x2)
		sx = 1;
    else
		sx = -1;
    if(y1<y2)
		sy = 1;
    else
		sy = -1;
    int error = dx-dy;
    while(x1!=x2||y1!=y2) 
	{
        putpixel(x1,y1,c);
        int error2 = error*2;
        if(error2 > -dy)
		{
			error -= dy;    
	        x1 += sx;
		}
        if(error2 < dx)
		{
			error += dx;
	        y1 += sy;
		}
	}

}

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
	

	myline(x0,y0,x1,y1,co);
	myline(x1,y1,x2,y2,co);
	myline(x2,y2,x3,y3,co);
	myline(x0,y0,x3,y3,co);
	
	co++;
	co=co%16;
	if(co==0)
		co++;
	setcolor(co);
	
	if (n>0) 
	{
      	myline(x3,y3,x4,y4,co);
		myline(x2,y2,x4,y4,co);
		pifagor(n-1,x3,y3,a*cos(alpha*grad),fi+alpha,alpha);
		pifagor(n-1,x4,y4,a*sin(alpha*grad),fi+alpha-90,alpha);
	}

}



void drawCircle(int x, int y, int i, int j)
{
    putpixel(x+i, y+j, RED);
    putpixel(x-i, y+j, RED);
    putpixel(x+i, y-j, RED);
    putpixel(x-i, y-j, RED);
    putpixel(x+j, y+i, RED);
    putpixel(x-j, y+i, RED);
    putpixel(x+j, y-i, RED);
    putpixel(x-j, y-i, RED);
}

void mycirc(int x, int y, int r, int c){
	int i=0, j=r;
	drawCircle(x,y,i,j);
	while (j>=i){
		//calculate e, eg, ed, ev
		int e=pow(i,2)+ pow(j,2) - pow(r,2);
		int eg = pow(i+1, 2)+pow(j, 2) - pow(r,2);
		int ed = pow(i+1, 2) + pow (j-1, 2) - pow(r,2);
		int ev = pow(i+1, 2) + pow(j-1, 2) - pow(r,2);
		
		if(e<0)
			if (abs(eg)<abs(ed))
				i++;
			
			else
			{
				i++;
				j--;
			}
		
		else
			j--;
		
		drawCircle(x, y, i, j);
	}
	
}
main(){
	int gdriver=DETECT, gmode;
	initgraph(&gdriver,&gmode, " ");
	
	
	mycirc(getmaxx()-290, getmaxy()-60, 50, 1);
  	pifagor(10,380,getmaxy()-15,80,0,60);//Required tree
	//pifagor(5,340,getmaxy()-20,75,0,45); //another breathtaking shape
    
	getch();
	closegraph();
	return 0;
}






