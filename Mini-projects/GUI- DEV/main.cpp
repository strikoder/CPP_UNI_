#include "graphics.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>
using namespace std;

static const long double pi = 3.14159265358979323846;

class point
{
protected:
	int x,y,color;
public:
	point();
	point(int px, int py);
	void draw();
	void hide();
	void move(int dx, int dy);
	void set(int xx, int yy, int cc);
};
point::point()
{
	
}
point::point(int px, int py )
{
	x=px;
	y=py;
}
void point::draw()
{
	setcolor(color);
	putpixel(x,y,color);
}
void point::hide()
{
	color=0;
}
void point::move(int dx, int dy)
{
	setcolor(color);
	int i=0;
	int j=0;
	if(dx>x)
	{
		if(dy==y)
		{
			
			while(dx!=x+i)
			{
				putpixel(x+i,y,color);
				delay(200);
				cleardevice();
				i++;
			}
		}
		//working on this case in main
		else if(dy>y)
		{
			while(dx!=x+i||dy!=y-i)
			{
				putpixel(x+i,y-j,color);
				delay(200);
				cleardevice();
				if(x+i!=dx)
					i++;
				if(y+i!=dy)
					j++;
			}
		}
		else
		{
			while(dx!=x+i||dy!=y+i)
			{
				putpixel(x+i,y+j,color);
				delay(200);
				cleardevice();
				if(x+i!=dx)
					i++;
				if(y+i!=dy)
					j++;
			}
		}
	}
	else if (dx==x)
	{
		if(dy==y)
		{
			//Here nothing to change, the point will still in place
		}
		
		else if(dy>y)
		{
			while(dy!=y-i)
			{
				putpixel(x,y-j,color);
				delay(200);
				cleardevice();
				if(y+i!=dy)
					j++;
			}
		}
		else
		{
			while(dy!=y+i)
			{
				putpixel(x,y+j,color);
				delay(200);
				cleardevice();
				if(y+i!=dy)
					j++;
			}
		}
	}
	else
	{
		if(dy==y)
		{
			
			while(dx!=x+i)
			{
				
				putpixel(x-i,y,color);
				delay(200);
				cleardevice();
				i--;
			}
		}
		else if(dy>y)
		{
			while(dx!=x+i||dy!=y+j)
			{
				putpixel(x-i,y-j,color);
				delay(200);
				cleardevice();
				if(x-i!=dx)
					i--;
				if(y+i!=dy)
					j--;
			}
		}
		else
		{
			while(dx!=x+i||dy!=y+i)
			{
				putpixel(x-i,y+j,color);
				delay(200);
				cleardevice();
				if(x-i!=dx)
					i--;
				if(y+i!=dy)
					j++;
			}
		}
	}
	
	//to draw the last place for the point
	putpixel(dx,dy,color);
}
void point::set(int xx,int yy, int cc)
{
	x=xx;
	y=yy;
	color=cc;
	point::draw();
}


class Line: public point
{
protected: 
	int dx,dy;
public:
	Line();
	Line(int px1,int py1, int lx, int ly);
	void draw();
	void hide();
	void move(int lx,int ly);
	void rotate(long double fi);		
};

Line::Line()
{
	dx=x;
	dy=y;
}

Line::Line(int px1,int py1,int lx, int ly):point(px1,py1)
{
	dx=lx;
	dy=ly;
}

void Line::draw()
{
	setcolor(9);
	line(x,y,dx,dy);
}

void Line::hide()
{
	color=0;
}

void Line::rotate(long double fi)
{
	int xn,yn;
	xn=(x*cos(fi))-(y*sin(fi));//300
	yn=(x*sin(fi))+(y*cos(fi));//-75
	line(x,y,x,y+yn);
	
}

void Line::move(int lx,int ly)
{
	
	setcolor(9);
		
	for(int i=0;i<3000;i++)
	{
		line(x+i,y,dx+2+i,dy);
		delay(50);
		cleardevice();
			
	}
		
}

class square:public Line
{
public:
	square(int sx1, int sy1, int sx2, int sy2 );
	void draw();
	void hide();
	void move(int sx,int sy);
	void rotate (long double fi);
};
square::square(int sx1, int sy1, int sx2, int sy2):Line(sx1,sy1,sx2,sy2)
{
	
}

void square::draw()
{
	rotate(90);
	rotate(90);
	rotate(90);
	rotate(90);
}
void square::hide()
{
	color=0;
}
void square::move(int sx,int sy)
{
	
	setcolor(9);
	int i=0;
	while(sx>dx+i)
	{
		line(x+i,y,dx+i,dy);
		line(x+i,y,x+i,dy+90);
		line(x+i,y+90,dx+i,dy+90);
		line(dx+i,y,dx+i,dy+90);
		delay(50);
		cleardevice();
		i++;
	}
	line(x+i,y,dx+i,dy);
	line(x+i,y,x+i,dy+90);
	line(x+i,y+90,dx+i,dy+90);
	line(dx+i,y,dx+i,dy+90);
		
}

void square::rotate(long double fi)
{
	int xn,yn;
	xn=(x*cos(fi))-(y*sin(fi));//300
	yn=(x*sin(fi))+(y*cos(fi));//-75
	line(x,y,dx,dy);
	line(x,y,x,y+yn);
	line(dx,y,dx,y+yn);
	line(x,y+yn,dx,y+yn);
}

class romb: public Line
{
public:
	romb(int rx1, int ry1, int rx2, int ry2 );
	void draw();
	void hide();
	void move(int rx,int ry);
	void rotate (long double fi);
};
void romb::draw()
{
	rotate(90);
	rotate(90);
	rotate(90);
	rotate(90);
}
void romb::hide()
{
	color=0;
}
void romb::move(int rx,int ry)
{
	
	setcolor(9);
	int i=0;
	while(rx>dx+i)
	{
		
		line(x+i,y,dx+i,dy);
		line(x+i,y,x+x/2+i,dy);
		line(x+i,dy+y,x+x/2+i,dy);
		line(dx+i,dy,x+i,dy+y);
		delay(50);
		cleardevice();
		i++;
	}
		line(x+i,y,dx+i,dy);
		line(x+i,y,x+x/2+i,dy);
		line(x+i,dy+y,x+x/2+i,dy);
		line(dx+i,dy,x+i,dy+y);
		
}

void romb::rotate(long double fi)
{
	int xn,yn;
	xn=(x*cos(fi))-(y*sin(fi));//300
	yn=(x*sin(fi))+(y*cos(fi));//-75
	line(x,y,dx,dy);
	line(x,y,x+x/2,dy);
	line(x,dy+y,x+x/2,dy);
	line(dx,dy,x,dy+y);
}

romb::romb(int rx1, int ry1, int rx2, int ry2):Line(rx1,ry1,rx2,ry2)
{
	
}

class rect:public square
{
public:
	rect(int rx1,int ry1, int rx2, int ry2);
	void draw();
	void hide();
	void move(int rx,int ry);
	void rotate(long double fi);
};
rect::rect(int rx1,int ry1, int rx2, int ry2):square(rx1,ry1,rx2,ry2)
{
	
}
void rect::draw()
{

	
	rect::rotate(90);
	rect::rotate(90);
	rect::rotate(90);
	rect::rotate(90);
	
}
void rect::hide()
{
	color=0;
}
void rect::move(int rx, int ry)
{
	setcolor(9);
	int i=0;
	while(rx>dx+i)
	{
		line(x+i,y,dx+i,dy);
		line(x+i,y+90,dx+i,dy+90);
		line(x+x+i,y,dx+i,dy+90);
		line(x+i,y+90,dx-x+i,dy);
		delay(50);
		cleardevice();
		i++;
	}
		line(x+i,y,dx+i,dy);
		line(x+i,y+90,dx+i,dy+90);
		line(x+x+i,y,dx+i,dy+90);
		line(x+i,y+90,dx-x+i,dy);
}

void rect::rotate(long double fi)
{
	int xn,yn;
	xn=(x*cos(fi))-(y*sin(fi));//300
	yn=(x*sin(fi))+(y*cos(fi));//-75
	line(x,y,dx,dy);
	line(x,y+90,dx,dy+90);
	line(x+x,y,dx,dy+90);
	line(x,y+90,dx-x,dy);
}

class para:public rect {
public:
	para(int px1,int py1, int px2, int py2);
	void draw();
	void hide();
	void move(int px,int py);
	void rotate(long double fi);
}; 

para::para(int px1, int py1, int px2, int py2):rect(px1,py1,px2,py2)
{
	
}
void para::draw()
{
		rotate(60);
		rotate(120);
		rotate(60);
		rotate(120);
}
void para::hide()
{
	color=0;
}
void para::move(int px, int py)
{
	setcolor(9);
	int i=0;
	while(px>dx+i)
	{
		line(x+i,y,dx+i,dy);
    	line(x+i,y,x+y+i,x);
    	line(x+y+i,x,dx+dy+i,x);
    	line(dx+i,y,dx+dy+i,x);
		delay(50);
		cleardevice();
		i++;
	}
	line(x+i,y,dx+i,dy);
    line(x+i,y,x+y+i,x);
    line(x+y+i,x,dx+dy+i,x);
    line(dx+i,y,dx+dy+i,x);
}

void para::rotate(long double fi)
{
	int xn,yn;
	xn=(x*cos(fi))-(y*sin(fi));
	yn=(x*sin(fi))+(y*cos(fi));
	line(x,y,dx,dy);
    line(x,y,x+y,x);
    line(x+y,x,dx+dy,x);
    line(dx,y,dx+dy,x);
}

int main()
{
	int gddriver = DETECT, gmode, errorcode;
    initgraph(&gddriver, &gmode, "");
	
	/*
	point p;
	p.set(75,75,9);
	p.move(100,100);
	p.hide();
	p.draw();
	*/
	
	/*
	Line l(75,300,275,300);
	l.draw();
	l.rotate(-90);
	*/
	
	
	/*
	Line l(75,75,150,75);
    l.draw();	
    l.move(75,75);
    */
    
	/*
	Here I draw with the degree
   	square s(75,300,150,300);		
    s.draw();
    */
    
    /*
	square s(250,100,350,100);
   	s.move(450,100);
    */
   	/* 
    rect r(200,50,400,50);
    r.draw();
    */
    
    /*
    romb ro(200,100,100,200);
    ro.draw();
    ro.move(300,300);
    */
    /*
    rect r(200,50,400,50);
    r.move(600,600);
    */
    
    para p(200,50,400,50);
    //p.draw();
    p.move(500,500);

    //feek t3ml delete l 25r line tb3 move, add if i about to exit the loop, then don't delete the paint
    getch();
    closegraph();
    return 0;
}


