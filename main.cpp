#include<windows.h>
#ifdef __APPLE__
#include<GLUT/glut.h>
#include<openGL/opengl.h>

#else
#include<GL/glut.h>
#endif

float x=1.0,y=1.0;
float x1=0.0,y1=0.0;
float x2=0.03,y2=0.0;
float x3=-0.03,y3=0.0;

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w,int h)
{
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(45,w/h,1,200);
}

void keyPressed(int k,int xX,int yY)
{
    if(k==GLUT_KEY_UP)
    {
        x+=0.05;
        y+=0.05;
    }
    if(k==GLUT_KEY_DOWN)
    {
        x-=0.05;
        y-=0.05;
    }
    glutPostRedisplay();
}

void update()
{
    x1+=0.005;
    y1+=0.005;
    if(x1>3.5)
    {
        x1=0.0;
        y1=0.0;
    }

    x2-=0.005;
    y2+=0.010;
    if(x2<-2.5)
    {
        x2=0.0;
        y2=0.0;
    }

    //x3+=0.005;
    y3+=0.005;
    if(y3>3.0)
    {
        //x1=0.0;
        y3=0.0;
    }
}

void makeBubbles()
{
    glColor3f(0.3,0.3,1.3);

    glPushMatrix();

    glTranslatef(x1,y1,-5.0);

    glutSolidSphere(0.1,20,20);

    glPopMatrix();

    glColor3f(1.,0.3,1.3);

    glPushMatrix();

    glTranslatef(x2+0.03,y2,-5.0);

    glutSolidSphere(0.1,20,20);

    glPopMatrix();

    glColor3f(1.0,1.0,0.0);

    glPushMatrix();

    glTranslatef(x3-0.03,y3,-5.0);

    glutSolidSphere(0.1,20,20);

    glPopMatrix();

    update();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glPushMatrix();

    glTranslatef(1.1,1.1,-5.0);
    glScalef(x,y,1.0);

    glBegin(GL_TRIANGLES);

        glColor3f(0.5,0.5,0.5);

        glVertex3f(-1.0,0.0,0.0);
        glVertex3f(1.0,0.0,0.0);
        glVertex3f(0.0,1.0,0.0);

    glEnd();

    glPopMatrix();

    makeBubbles();

    glutSwapBuffers();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(400,400);

    glutCreateWindow("Fountain Using OpenGL");

    initRendering();

    glutDisplayFunc(display);

    glutIdleFunc(display);

    glutReshapeFunc(reshape);

    glutSpecialFunc(keyPressed);

    glutMainLoop();

    return(0);
}
