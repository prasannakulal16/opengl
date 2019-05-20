
#include <windows.h>
#include<stdio.h>
#include<GL/glut.h>
float x=0.0;
float eye[3]={0,0,5};

float p[8][3]={{-1,-1,-1},{-1,1,-1},{1,-1,-1},{1,1,-1},{-1,-1,1},{-1,1,1},{1,-1,1},{1,1,1}};

float cl[8][3]={{-1,-1,-1},{-1,1,-1},{1,-1,-1},{1,1,-1},{-1,-1,1},{-1,1,1},{1,-1,1},{1,1,1}};
void init()
{
	glClearColor(1,1,1,1);
	glOrtho(-5,5,-5,5,-5,5);
	glEnable(GL_DEPTH_TEST);
}

void myReshape(int w,int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glFrustum(-2,2,-2*h/w,2*h/w,4,20);
	else
		glFrustum(-2*w/h,2*w/h,-2,2,4,20);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,w,h);
}


void square(int a,int b,int c,int d)
{
	glBegin(GL_QUADS);
	glColor3fv(cl[a]);
	glVertex3fv(p[a]);
	glColor3fv(cl[b]);
	glVertex3fv(p[b]);
	glColor3fv(cl[c]);
	glVertex3fv(p[c]);
	glColor3fv(cl[d]);
	glVertex3fv(p[d]);
	glEnd();
}

void cube()
{
	square(0,1,3,2);
	square(4,5,7,6);
	square(6,7,3,2);

	square(4,5,1,0);
	square(0,2,6,4);
    square(5,1,3,7);
}
/*void spin(void)
{
	if(x<360)
	{
		x=x+0.1;
	}
	else
		x=0.0;
	glutPostRedisplay();
}*/

void mykey(unsigned char key,int x,int y)
{
	if(key=='X')
	  eye[0]=eye[0]+0.1;
	if(key=='x')
		eye[0]=eye[0]-0.1;
	if(key=='Y')
		eye[1]=eye[1]+0.1;
	if(key=='y')
		eye[1]=eye[1]-0.1;
	if(key=='Z')
		eye[2]=eye[2]+0.1;
	if(key=='z')
		eye[2]=eye[2]-0.1;
	glutPostRedisplay();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(eye[0],eye[1],eye[2],0,0,0,0,1,0);
	cube();
	glFlush();
}

int main()
{

	glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH);
	glutInitWindowSize(500,500);

	glutInitWindowPosition(0,0);
	glutCreateWindow("cube");
	init();
	glutReshapeFunc(myReshape);
	//glutIdleFunc(spin);
	glutKeyboardFunc(mykey);
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}
