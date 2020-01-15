#include<GL/glut.h>
#include<stdio.h>
int x1 ,y2,r;



void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+x1 ,y+y2);
	glEnd();
}


void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}




















void midpoint()
{
	int x = 0;
	int y = r;
	float d = 5/4 - r;
	plot(x, y);

	while (y > x)
	{
		if (d < 0)
		{
			x++; 
			d += 2*x+1;
		}
		else
		{
			y--;
			x++;
			d += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}



void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	midpoint();

	glFlush ();
}



















void init(void)
{
glClearColor(0.7,0.7,0.7,0.7);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char ** argv){
 
printf("Enter the coordinates of the center");

	 printf("X-coordinate   : "); 
 	scanf("%f",&x1);
	printf("Y-coordinate : "); 
	scanf("%f",&y2);
	printf("Enter radius : "); 
	scanf("%f",&r);


 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA");
init();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}

















