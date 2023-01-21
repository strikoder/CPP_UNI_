#include "graphics.h"
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;

class Point
{
	private:
		double x;
		double y;
		double z;
	public:
		Point()
		{
			x=0;
			y=0;
			z=0;
		}
		Point(double a, double b, double c)
		{
			x=a;
			y=b;
			z=c;
		}
		double getX(){return x;}
		double getY(){return y;}
		double getZ(){return z;}
		void setX(double X){x=X;}
		void setY(double Y){y=Y;}
		void setZ(double Z){z=Z;}
};
//vershin
class Vertex
{
	public:
		//double ro;
		Point world;
		Point view;
	// stay pub
	int num;
	//Constructer x=ro, y=teta, z=fi
	Vertex(double x,double y,double z, int n=0)
	{
		Point p(x,y,z);
		world=p;
	}
	Vertex()
	{
		Point p(0,0,0);
		world=p;
	}
	void setViewCoord(Point point_view)//the hardest one... 
	{
		double st=sin(point_view.getY());
		double ct=cos(point_view.getY());
		double sf=sin(point_view.getZ());
		double cf=cos(point_view.getZ());
		view.setX(world.getX()*(-sf)+world.getY()*cf);
		view.setY(world.getX()*(ct*cf)+world.getY()*(-ct*sf)+world.getZ()*st);
		view.setZ(world.getX()*(-st*cf)+world.getY()*(-st*sf)+world.getZ()*(-ct)+point_view.getX());
	}
	bool operator == (Vertex v)
	{
		bool flag=false;
		if(view.getX()==v.view.getX()&&view.getY()==v.view.getY()&&view.getZ()==v.view.getZ())
			flag=true;
		return flag;
	}
	Vertex *next;//I can code without pointers using the numbers of vershin written on the paper

};
//repro
class Edge
{
	static int ir=999; // rashernya ekrana
	static int il=0; //levaya shast ekrana
	static double xr=1000*0.8;// pravaya
	static double xl= -1000*0.8//levaya  razshernya(ramki)
	static int ju=0 // verkhna
	static int jd=999// nij okna
	static double yu=0.8; //verkhnaya 
	static double yd=-0.8; //nijnaya shast (2shtekak)
	public:
		//switch to private
		//Vertex *start_vertex;
		//Vertex *finish_vertex;
		Vertex start_vec;
		Vertex finish_vect;
	// stay in pub
	//edge() build a consturcter
	Edge(Vertex a, Vertex b)
	{
		start_vec.view.setX(a.view.getX());
		start_vec.view.setY(a.view.getY());
		start_vec.view.setZ(a.view.getZ());
		finish_vect.view.setX(b.view.getX());
		finish_vect.view.setY(b.view.getY());
		finish_vect.view.setZ(b.view.getZ());
	}
	Edge ()
	{
		
	}
	void drawEdge(double yu, double yd, double xl,double xr, double ju, double jd, double il, double ir,double rr)// to draw the edges it's 2 vertexes and draw a line between them, we need to think where to save "ramki"?
	{
		double x,y,x1,y1;
		int i,j,i1,j1;
		setcolor(3);
		x=(rr/(2.0*(start_vec.view.getZ())))*start_vec.view.getX();
		y=(rr/(2.0*(start_vec.view.getZ())))*start_vec.view.getY();
		x1=(rr/(2.0*(finish_vect.view.getZ())))*finish_vect.view.getX();
		y1=(rr/(2.0*(finish_vect.view.getZ())))*finish_vect.view.getY();
		i=(int)(ir+((x-xr)*(il-ir))/(xl-xr));
		j=(int)(ju+((y-yu)*(jd-ju))/(yd-yu));
		i1=(int)(ir+((x1-xr)*(il-ir))/(xl-xr));
		j1=(int)(ju+((y1-yu)*(jd-ju))/(yd-yu));
		line(i,j,i1,j1);
		
	}
	Edge *next;
	
};

class Triangle
{
	public:
		Vertex a;
		Vertex b;
		Vertex c;
		bool flag;
		Triangle(Vertex x, Vertex y, Vertex z)
		{
			flag=false;
			a=x;
			b=y;
			c=z;
			double x1,y1,x2,y2,x3,y3,k;
			x1=a.view.getX();
			y1=a.view.getY();
			x2=b.view.getX();
			y2=b.view.getY();
			x3=c.view.getX();
			y3=c.view.getY();
			k=x1*y2*1+y1*1*x3+1*x2*y3-1*y2*x3-x1*1*y3-y1*x2*1;
			if(k>0)
				flag=true;
		}
		Triangle()
		{
		}
};

class Surface
{
	public:
	friend class Edge;
		Vertex *v;
		Edge *ed;
		Triangle *tri;
		/*static*/ Point viewpoint;
		/*static*/ double yu,yd,xl,xr,ju,jd,il,ir;
		int n;
	
	
	void load()//read funtion
	{
		int x,y,z,a,*m,*m1;
		ifstream f("coords.txt");
		f>>n;
		f>>a;
		v=new Vertex[a];
		for(int i=0;i<a;i++)
		{
			f>>x;
			f>>y;
			f>>z;
			v[i]=Vertex(x,y,z);
			v[i].setViewCoord(viewpoint);
		}
		m=new int[2*n];
		for(int i=0;i<2*n;i++)
			f>>m[i];
		
		ed=new Edge[n];
		for(int i=0;i<n;i++)
			ed[i]=Edge(v[m[i*2]],v[m[i*2+1]]);
			
		m1=new int[a*3];
		
		for(int i=0;i<a*3;i++)
			f>>m1[i];
			
		tri=new Triangle[a];
		for(int i=0;i<a;i++)
			tri[i]=Triangle(v[m1[i*3]],v[m1[i*3+1]],v[m1[i*3+2]]);
			
		f.close();
	}
	//sphere ro,tetta, fi
	void setViewPoint(double ro, double tetta, double fi)//to calculate distance between them 
	{
		viewpoint.setX(ro);
		viewpoint.setY(tetta);
		viewpoint.setZ(fi);
	}
	/*void setviewpoint(Point p)
	{
		viewpoint=p;
	}*/
	void drawSurface()// to draw line between edges
	{
		for (int i=0;i<n;i++)
			for(int j=0;j<4;j++)
				if(tri[j].flag==true)
					if((ed[i].start_vec==tri[j].a||ed[i].start_vec==tri[j].b||ed[i].start_vec==tri[j].c)&&
					(ed[i].finish_vect==tri[j].a||ed[i].finish_vect==tri[j].b||ed[i].finish_vect==tri[j].c))
						ed[i].drawEdge(yu,yd,xl,xr,ju,jd,il,ir,viewpoint.getX());
					
	}
};



/*
class Point
{
	public:
		double x=0,y=0,z=0;
	
};
//vershin
class Vertex
{
	public:
	//switch to private
		public double ro;
		Point world_coord;
		Point view_coord;
	// stay pub
	int num;
	//Constructer x=ro, y=teta, z=fi
	Vertex(double x,double y,double z, int n);
	void setViewCoord(Point view_point);//the hardest one... 
	Vertex *next;//I can code without pointers using the numbers of vershin written on the paper

};
//repro
class Edge
{
	public:
		//switch to private
		Vertex *start_vertex;
		Vertex *finish_vertex;
	// stay in pub
	//edge() build a consturcter
	void drawEdge();// to draw the edges it's 2 vertexes and draw a line between them, we need to think where to save "ramki"?
	Edge *next;
	
};

class Surface
{
	public:
		Vertex *vlist;
		Edge *elist;
	//stay pub
	
	void load();//read funtion
	static Point view_point; //sphere ro,tetta, fi
	void setViewPoint(double ro, double tetta, double fi);//to calculate distance between them 
	void drawSurface();// to draw line between edges
		
};
*/

int main()
{
    int gddriver = DETECT, gmode, errorcode;
    initgraph(&gddriver, &gmode, "");
    
	double b=M_PI/2;
    Surface s1;
    s1.load();
    s1.setViewPoint(10.0,b,1.6);
    s1.drawSurface();
    
    getch();
    closegraph;
    return 0;
}

