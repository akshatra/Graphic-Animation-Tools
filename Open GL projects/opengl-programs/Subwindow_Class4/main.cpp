#include <GL/freeglut.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
int winID=1,sub;
int r=50;
void display()
{
     gluOrtho2D(0,250,0,250);
    glClearColor(1.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	 float x,y,i;

	 glColor3f(1,1,1);

	 for(i=0;i<360;i=i+0.01)
	 {
        glColor3f(1,1,1);
        glBegin(GL_POINTS);
	 	x=r*cos(i);
	 	y=r*sin(i);
	 	glVertex2i(x,y);
	 		 glEnd();
	 }

}
void display2()
{
    gluOrtho2D(0,250,0,250);
    glClearColor(1.0,1,1,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	 float x,y,i;

	 glColor3f(1,1,0);

	 for(i=0;i<360;i=i+0.01)
	 {
        glColor3f(1,1,1);
        glBegin(GL_POINTS);
	 	x=r*cos(i);
	 	y=r*sin(i);
	 	glVertex2i(x,y);
	 		 glEnd();
	 }

}
void init()
{
      gluOrtho2D(-500,500,-500,500);
   glClearColor(0.5,1,0.5,1);
  glClear(GL_COLOR_BUFFER_BIT);

}
 int counter=0,A=0,B=0,C=0,D=0;
void mouse_event(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
       glutPostRedisplay();
    }


}
void mouse_event2(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
       glutPostRedisplay();
    }


}

/*using namespace std;

int mainWin, subWin1, subWin2;

/*void processKeyboardKeys(unsigned char key, int x, int y)
{
	switch(key)
	{
		case ''
		case 27:
			glutSetWindow(mainWin);
			exit(0);
		break;
	}
}
*/

int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(200,200);
 init();
 winID=glutCreateWindow("mainwindow");
 glutDisplayFunc(display);
 glutMouseFunc(mouse_event);
 sub=glutCreateSubWindow(winID,0,0,250,500);
 glutDisplayFunc(display2);
 glutMouseFunc(mouse_event2);
 glutSetWindow(sub);
// glutMouseFunc(mouse_event2);
 glutMainLoop();
 return 0;

}
