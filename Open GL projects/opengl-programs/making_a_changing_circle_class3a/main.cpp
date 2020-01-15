#include<GL/freeglut.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
int counter=200;
 int r=200;
void init()
{

   glClearColor(0.5,1,0.5,1);
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-500,500,-500,500);

}
void display()
{
    glClearColor(1.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	 float x,y,i;

	 glColor3f(1,1,1);

	 for(i=0;i<360;i=i+0.01)
	 {
        glColor3f(1,0,0);
        glBegin(GL_POINTS);
	 	x=r*cos(i);
	 	y=r*sin(i);
	 	glVertex2i(x,y);
	 		 glEnd();
	 }



glFlush();
}
void mouse_event(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(r<900)
        r=r+20;
        glutPostRedisplay();

    }
     if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
     {

         r=r-20;
        glutPostRedisplay();
     }

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
 glutMouseFunc(mouse_event);
 glutMainLoop();
 return 0;
}

