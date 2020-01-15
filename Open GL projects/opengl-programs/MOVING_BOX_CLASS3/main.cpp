#include<GL/freeglut.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
int counter=200;
int r=50,x1=0,y3=0;
void init()
{

   glClearColor(0.5,1,0.5,1);
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-500,500,-500,500);

}
void display()
{
    glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	 float x,y,i;

	 glColor3f(1,1,1);

	 for(i=0;i<360;i=i+0.01)
	 {
	   glBegin(GL_POINTS);
	   glColor3f(0,1,1);
	 	x=r*cos(i)+x1;
	 	y=r*sin(i)+y3;
	 	glVertex2i(x,y);
	 		 glEnd();
	 }



glFlush();
}


void MyKeyboardFunc(unsigned char key, int x, int y)
{

if(key=='w')
        {
        y3=y3+30;
        glutPostRedisplay();
        }
else if(key=='a')
        {
        x1=x1-30;
        glutPostRedisplay();
        }
else if(key=='e')
        {
         x1=x1+30;
         y3=y3+30;

        glutPostRedisplay();
        }
else if(key=='q')
        {
         x1=x1-30;
         y3=y3+30;

        glutPostRedisplay();
        }
else if(key=='c')
        {
         x1=x1+30;
         y3=y3-30;

        glutPostRedisplay();
        }
else if(key=='z')
        {
         x1=x1-30;
         y3=y3-30;

        glutPostRedisplay();
        }
else if(key=='s')
        {
        y3=y3-30;
        glutPostRedisplay();
        }
else if(key=='d')
         {
        x1=x1+30;
        glutPostRedisplay();
        }
else if(key==27) exit(1);
else
std::cout<<"\n wrong input";

}
int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(200,200);
 glutCreateWindow("Multi-Color changing Triangle");
 init();
 glutDisplayFunc(display);

 glutKeyboardFunc(MyKeyboardFunc);
 glutMainLoop();
 return 0;
}

