#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<gl/glut.h>
int m;
float v[][3]={{0,0,1},{0,1,0},{-1,-0.5,0},{1,-0.5,0}};
void init()
{

    glClearColor(0,0,0,0);
    glOrtho(-1,1,-1,1,-1,1);
    glEnable(GL_DEPTH_TEST);
}

void drawtetra(float *a,float *b,float *c)
{

    glBegin(GL_TRIANGLES);
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    glEnd();
    glFlush();
}

void tetra(float *p,float *q,float *r ,float *s)
{

    glColor3f(1,0,0);
    drawtetra(p,q,s);
     glColor3f(0,1,0);
    drawtetra(p,s,r);
     glColor3f(0,0,1);
    drawtetra(q,s,r);
     glColor3f(0,1,1);
    drawtetra(p,q,r);

}

void divide(float *x,float *y,float *z,float *h,int m)
{

    float p[6][6];
    if(m>0)
    {

        for(int i=0;i<3;i++)
        {

            p[0][i]=(x[i]+z[i])/2;
             p[1][i]=(y[i]+z[i])/2;
              p[2][i]=(x[i]+y[i])/2;
               p[3][i]=(x[i]+h[i])/2;
                p[4][i]=(y[i]+h[i])/2;
                 p[5][i]=(z[i]+h[i])/2;
        }
        divide(x,p[0],p[2],p[3],m-1);
          divide(p[0],z,p[1],p[5],m-1);
            divide(p[2],p[1],y,p[4],m-1);
              divide(p[3],p[5],p[4],h,m-1);


    }
    else{
        tetra(x,y,z,h);
    }
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    divide(v[0],v[1],v[2],v[3],m);
}
int main()
{

    glutInitWindowSize(600,600);
    glutInitDisplayMode(GLUT_SINGLE);
    glutCreateWindow("gdfghd");
    init();
    printf("division\n");
    scanf("%d",&m);
    glutDisplayFunc(display);
    glutMainLoop();
}
