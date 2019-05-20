#include<windows.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
void init()
{

    glClearColor(0.0,0.0,0.0,1.0);
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_PROJECTION);
}
void display()
{
 int i; float x;
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,1,0);
  glBegin(GL_POINT);
 for(i=0;i<360;i++)
 {
x=(i*3.142)/180;
 glVertex2f(250+150*cos(x),250+150*sin(x));
 }

 /*for(i=240;i<300;i++)
 {
 glBegin(GL_POLYGON);
 x=cos((2*i*3.14)/360) * .3;
 y=sin((2*i*3.14)/360) * .3;
 glVertex2f(x,y);
 glEnd();
 }
 glPointSize(10.0);
 glBegin(GL_POLYGON);
 glVertex2f(-.25,.2);
 glVertex2f(.25,.2);*/
 glEnd();

 glFlush();
}

int main()
{
 init();
 glutInitWindowSize(550,550);
 glutInitWindowPosition(0,0);
 glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
 glutCreateWindow("simple");
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
