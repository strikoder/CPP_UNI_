#include "graphics.h"
#include <stdlib.h>
#include <cmath>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

struct Point{
	double x;
	double y;
	double z;
};

class Vertex{

private:
	Point worldcoord;
	Point viewcoord;
	
	friend class Edge;
	friend class Surface;
	friend class Tring;
public:
	Vertex(double x, double y, double z) : worldcoord{x,y,z}
	{}

	explicit Vertex() : worldcoord {0,0,0}
	{}

	void SetView(Point viewpoint){
		double st = sin(viewpoint.y);
		double ct = cos(viewpoint.y);
		double sf = sin(viewpoint.z);
		double cf = cos(viewpoint.z);

		viewcoord.x = worldcoord.x*(-sf)+worldcoord.y*cf;
		viewcoord.y = worldcoord.x*(-ct*cf)+worldcoord.y*(-ct*sf)+worldcoord.z*st;
		viewcoord.z = worldcoord.x*(-st*cf)+worldcoord.y*(-st*sf)+worldcoord.z*(-ct)+viewpoint.x;
	}
	bool operator == (Vertex& v) const{
		return (viewcoord.x==v.viewcoord.x&& viewcoord.y==v.viewcoord.y && viewcoord.z==v.viewcoord.z);
	}
};

class Edge {
	private:
		Vertex startvertex;
		Vertex finishvertex;
		
		friend class Surface;
		friend class Tring;
	public:
		Edge(Vertex a, Vertex b)
		{
			startvertex.viewcoord = {a.viewcoord.x, a.viewcoord.y, a.viewcoord.z};
			finishvertex.viewcoord = {b.viewcoord.x, b.viewcoord.y, b.viewcoord.z};
//			startvertex.viewcoord.x = a.viewcoord.x;
//			startvertex.viewcoord.y = a.viewcoord.y;
//			startvertex.viewcoord.z = a.viewcoord.z;
//			finishvertex.viewcoord.x = b.viewcoord.x;
//			finishvertex.viewcoord.y = b.viewcoord.y;
//			finishvertex.viewcoord.z = b.viewcoord.z;
		}
		Edge(Edge& e){
			startvertex = e.startvertex;
			finishvertex = e.finishvertex;
		}
		Edge& operator = (Edge e){
			startvertex = e.startvertex;
			finishvertex = e.finishvertex;

			return *this;
		}
		void DrawEdge(double yu, double yd, double xl, double xr, double ju, double jd, double il, double ir, double rr)
		{
			double x, y, x1, y1;
			int i, j, i1, j1;
			x=(rr/(2.0*(startvertex.viewcoord.z)))*startvertex.viewcoord.y;
			y=(rr/(2.0*(startvertex.viewcoord.z)))*startvertex.viewcoord.y;
			x1=(rr/(2.0*(finishvertex.viewcoord.z)))*finishvertex.viewcoord.x;
			y1=(rr/(2.0*(finishvertex.viewcoord.z)))*finishvertex.viewcoord.y;

			i = (int)(ir+((x-xr)*(il-ir))/(xl-xr));
			j = (int)(ju+((y-yu)*(jd-ju))/(yd-yu));
			i1= (int)(ir+((x1-xr)*(il-ir))/(xl-xr));
			j1= (int)(ju+((y1-yu)*(jd-ju))/(yd-yu));
			line(i,j,i1,j1);

		}
			//edge* next;
};


class Tring
{
	private:
		Vertex a;
		Vertex b;
		Vertex c;
		Vertex n;
		bool flag;

		friend class Surface;
		/*
		static double Sqr (double x){
			return x*x;
		}
		
		void CalcNorm(){
			Vertex v1, v2;
			v1.viewcoord.x = a.viewcoord.x - b.viewcoord.x;
			v1.viewcoord.y = a.viewcoord.y - b.viewcoord.y;
			v1.viewcoord.z = a.viewcoord.z - b.viewcoord.z;
			
			v2.viewcoord.x = b.viewcoord.x - c.viewcoord.x;
			v2.viewcoord.y = b.viewcoord.y - c.viewcoord.y;
			v2.viewcoord.z = b.viewcoord.z - c.viewcoord.z;
			
			double wrki = sqrt(Sqr(v1.viewcoord.y * v2.viewcoord.z - v1.viewcoord.z * v2.viewcoord.y)+
			Sqr(v1.viewcoord.z * v2.viewcoord.x - v1.viewcoord.x * v2.viewcoord.z)+
			Sqr(v1.viewcoord.x * v2.viewcoord.y - v1.viewcoord.y * v2.viewcoord.x));
			
			n.viewcoord.x = (v1.viewcoord.y * v2.viewcoord.z - v1.viewcoord.z * v2.viewcoord.y) / wrki;
			n.viewcoord.y = (v1.viewcoord.z * v2.viewcoord.x - v1.viewcoord.x * v2.viewcoord.z) / wrki;
			n.viewcoord.z = (v1.viewcoord.x * v2.viewcoord.y - v1.viewcoord.y * v2.viewcoord.x) / wrki;
		}*/
		
		bool Test(const Edge& e){

		}
 public:
 	Tring(Vertex x, Vertex y, Vertex z): a(x), b(y), c(z), flag(false)
	 {
			double x1, y1, x2, y2, x3, y3, k;
			x1=a.viewcoord.x;
			y1=a.viewcoord.y;
			x2=b.viewcoord.x;
			y2=b.viewcoord.y;
			x3=c.viewcoord.x;
			y3=c.viewcoord.y;
			k=x1*y2*1+y1*1*x3+1*x2*y3-1*y2*x3-x1*1*y3-y1*x2*1;
			if (k>0) flag = true;

		}

};


class Surface{

private:
		friend class Edge;
	 	vector <Vertex*> v;
		vector <Edge*> e;
		vector <Tring*> t;
		Point viewpoint; //sphere
		double yu, yd, xl, xr, ju, jd, il, ir;
		int n;
	public:
		void DrawSurface(){
			for (int i=0; i<n; i++){

				for (int j=0; j<t.size(); j++){

					if (t[j]->flag){
						if((e[i]->startvertex==t[j]->a||e[i]->startvertex==t[j]->b||e[i]->startvertex==t[j]->c)
						&&
						(e[i]->finishvertex==t[j]->a||e[i]->finishvertex==t[j]->b||e[i]->finishvertex==t[j]->c))
							e[i]->DrawEdge(yu,yd,xl,xr,ju, jd, il, ir, viewpoint.x);
						}
				}
			}
			/*
			for (int i=0; i<n; i++){
				e[i]->DrawEdge(yu,yd,xl,xr,ju, jd, il, ir, viewpoint.x);
			}*/
		}
	void SetViewPoint(Point& p){
		viewpoint = p;
		yu = -2;
        yd = 2;
        xl = -2;
        xr = 2;
        il = 0;
        ir = 1024;
        ju = 0;
        jd = 1024;
	}
		//setviewpoint function
//		void setviewpoint(point p){
//			viewpoint =p;
//		};

		void load()	{
			int v_num;
			double x, y, z;
			int a, b;
			char ch;
			int tx,ty,tz;

			ifstream f;
			f.open("test.txt");
			f>>n >>v_num;

			//v=new Vertex[v_num];
			v.resize(v_num);
			for (int i =0; i<v_num; i++)
			{
				f >>x >>y >>z;
				v[i] = new Vertex(x,y,z);
				v[i]->SetView(viewpoint);

			}

			//e=new Edge[n];
			e.reserve(n);
			for(int i=0;i<n;i++){
				f >>a >> b;
				//e[i]=new Edge(*v[a-1], *v[b-1]);
				e.push_back(new Edge(*v[a-1], *v[b-1]));
			}



			t.reserve(a);
			for(int i=0;i<a;i++){
              f >> tx >> ty>>tz;
				t.push_back(new Tring(*v[tx-1],*v[ty-1], *v[tz-1]));
          }
			f.close();

			}
};

main(){
	int gdriver=DETECT, gmode;
	initgraph(&gdriver,&gmode, " ");

	Surface draw;
	Point p = {50, M_PI/4, M_PI/4};
	draw.SetViewPoint(p);
	draw.load();
	draw.DrawSurface();

	getch();
	closegraph();
	return 0;
}


