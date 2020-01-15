//AIM::To build a hut;
#include <GL/freeglut.h>
#include<stdio.h>
#include<iostream>

void display()
{


  glLineWidth(10);
  glBegin(GL_LINES);
  glColor3f(0,1,1);
  glVertex2f(-500,500);
  glVertex2f(500,-500);
  glEnd();

  glLineWidth(10);
  glBegin(GL_LINES);
  glColor3f(0,1,1);
  glVertex2f(500,500);
  glVertex2f(-500,-500);
  glEnd();

    glFlush();



}
init()
{
      gluOrtho2D(0,500,0,500);
   glClearColor(0.5,1,0.5,1);
  glClear(GL_COLOR_BUFFER_BIT);

}
 int counter=0,A=0,B=0,C=0,D=0;
void mouse_event(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
       std::cout<<" X Coordinate is ::"<<x<<"\n";
       std::cout<<" Y Coordinate is ::"<<y<<"\n";
        A=x;
        B=500-y;
        counter++;
    }
     if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN&&counter==1)
     {
         std::cout<<"\n X Coordinate is ::"<<x<<"\n";
         std::cout<<" Y Coordinate is ::"<<y<<"\n\n\n";
          std::cout<<"\n";
          C=x;
          D=500-y;
          counter=0;
     }
     glBegin(GL_LINES);
     glVertex2f(A,B);
     glVertex2f(C,D);
     glEnd();
     glFlush();
    //glutPostRedisplay();
}



int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(200,200);
 glutCreateWindow("Green Triangle");
 init();
 glutDisplayFunc(display);
 glutMouseFunc(mouse_event);
 glutMainLoop();
 return 0;
}

/*
#include<GL/freeglut.h>
#include<stdio.h>
#include<math.h>

int xc1,yc1,xc2,yc2;
int onMouse=0;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  float x;
  float y;
  float m;
  m=(float)(yc2-yc1)/(float)(xc2-xc1);
  glColor3f(0,1,0);
  glBegin(GL_POINTS);
  if(m>0 && m<=1)
 {
  x=(xc1<xc2)?xc1:xc2;
  y=(x==xc1)?yc1:yc2;
 while((x<=xc2 && x>=xc1) || (x>=xc2 && x<=xc1))
   {
    glVertex2i(x,y);
    x+=1;
    y=y+m;
   }
}
  else if(m>1)
 {
   x=(xc1<xc2)?xc1:xc2;
   y=(x==xc1)?yc1:yc2;
  while((x<=xc2 && x>=xc1) || (x>=xc2 && x<=xc1))
   {
    glVertex2i(x,y);
    y+=1;
    x=x+1/m;
   }
}
  else if(m<=0 && m>-1)
  {
   x=(xc1>xc2)?xc1:xc2;
   y=(x==xc1)?yc1:yc2;
  while((x<=xc2 && x>=xc1) || (x>=xc2 && x<=xc1))
   {
    glVertex2i(x,y);
    x-=1;
    y=y-m;
   }
 }
  else if(m<-1)
 {
   y=(yc1>yc2)?yc1:yc2;
   x=(y==yc1)?xc1:xc2;
   while((x<=xc2 && x>=xc1) || (x>=xc2 && x<=xc1))
   {
    glVertex2i(x,y);
    y-=1;
    x=x-1/m;
   }
 }
  glEnd();
  glFlush();
}


void myinit()
{
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0,700,0,700);
}

void mouseClicks(int button, int state, int x, int y) {

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if(onMouse==0)
        {onMouse++;
         xc1=x;
         yc1=700-y;
         }
	else if(onMouse==1)
	{onMouse++;
         xc2=x;
         yc2=700-y;
	glutPostRedisplay();
        }
	else if(onMouse==2)
	{onMouse=0;
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glFlush();
        }

    }
    else
    {
   }
}


int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(700,700);
 glutInitWindowPosition(200,200);
 glutCreateWindow("DD Line");
 myinit();
 glutMouseFunc(mouseClicks);
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
*/
