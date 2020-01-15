#include <stdio.h>
#include <GL/freeglut.h>
#include <math.h>

int s=0;
int mwh=700,mww=800;
int padding=2;
float rw=1,rh=1;
void display()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}



void display_s4()
{glClearColor(0.0,1.0,1.0,1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 int a=200,b=100;
 double p;
 float root2=pow(2,0.5);
 int x=0,y=b;
 int xn,yn;
 p=b*b-a*a*b+a*a/4.0;
 glColor3ub(100,0,0);
 glBegin(GL_POINTS);
	 while(b*b*x<=a*a*y)
	 {
	 	glVertex2i(x,y);
	 	glVertex2i(x,-1*y);
	 	glVertex2i(-1*x,y);
	 	glVertex2i(-1*x,-1*y);
	 	if(p>0)
	 	{
	 		p=p+b*b*(2*x+3)-a*a*(2*y-2);
	 		x++;
	 		y--;
	 	}
	 	else
	 	{
	 		p=p+b*b*(2*x+3);
	 		x++;
	 	}
	 	xn=x;
	 	yn=y;
	 }

	 p=(double)b*b*(xn+0.5)*(xn+0.5)+(double)a*a*(yn-1)*(yn-1)-(double)a*a*b*b;
	 
	 x=xn;
	 y=yn;
	 
	while(y>=0)
	 {
	 	
	 	glVertex2i(x,y);
	 	glVertex2i(x,-1*y);
	 	glVertex2i(-1*x,y);
	 	glVertex2i(-1*x,-1*y);

	 	if(p<=0)
	 	{
	 		p=p-2*a*a*(y-1)+a*a+b*b*(2*x+2);
	 		x++;
	 		y--;
	 	}
	 	else
	 	{
	 		p=p-2*a*a*(y-1)+a*a;
	 		y--;
	 	}

	 }
 glEnd();
 glRasterPos2i(rh*mww/3*-1,rw*mwh/3);
	 glutBitmapString(GLUT_BITMAP_HELVETICA_18,"Mid Point Algo");
 glFlush();

}

void myinit()
{glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-1*rh*(float)mww/2,rh*(float)mww/2,-1*rw*(float)mwh/2,rw*(float)mwh/2);
 }

void init()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-1*rh*(float)(mww-3*padding)/2,rh*(float)(mww-3*padding)/2,-1*rw*(float)(mwh-3*padding)/2,rw*(float)(mwh-3*padding)/2);
}

int m,s4;

void initdisplay()
{
	int w=glutGetWindow();

		
	 if(w==s4)
		{
			glClearColor(0.0,1.0,1.0,1.0);
		    glClear(GL_COLOR_BUFFER_BIT);
		}

}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
    glutInitWindowSize(800,700);
 	glutInitWindowPosition(100,20);
 	
 	glutDisplayFunc(initdisplay);
    
    
 	glutMainLoop();
	return 0;
}
