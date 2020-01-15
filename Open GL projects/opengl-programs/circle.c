#include <GL/freeglut.h>
#include <GL/gl.h>
 
void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255, 0.0, 0.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
     glBegin(GL_TRIANGLE_FAN) ;
 
 	glVertex2f(0.5, -0.5);
 
 for angle60 = 0 to 360 step 5
 
 glVertex2f(0.5 + sind(angle60) * radius5, -0.5 + cosd(angle60) * radius5)
 
 next
 
 glEnd()
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("first square program");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}

