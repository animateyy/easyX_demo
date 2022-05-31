#include <gl/glut.h>
#include <Windows.h>
#include <math.h>

void myinit()
{
    /* attributes */
    glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
    glColor3f(1.0, 0.0, 0.0); /* draw in red */
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 50.0, 0.0, 50.0);/* set up viewing 50.0 x 50.0 camera coordinate window with origin lower left */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void display()
{
    /* A triangle */
    GLfloat vertices[3][2] = { {0.0,0.0},{25.0,50.0},{50.0,0.0} };
    int j, k;
    int rand();       /* standard random number generator */
    GLfloat p[2] = { 7.5, 5.0 };  /* arbitrary initial point inside triangle */
    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */
    glBegin(GL_POINTS);
	glTranslatef(0.5f,0.0f,0.0f);
    glRotatef(70.0f,0.0f,0.0f,1.0f);

    /* compute and plot 5000 new points */

    for (k = 0; k < 5000; k++)
    {
		double OD=0;
        j = rand() % 3; /* pick a vertex at random */
         /* compute point halfway between selected vertex and old point */
        p[0] = (p[0] + vertices[j][0]) / 2.0;
        p[1] = (p[1] + vertices[j][1]) / 2.0;
		
	
		
		OD = sqrt(p[0]*p[0]+(p[1]*p[1]));//离圆心距离
		float twist=p[0]*OD;//成正比
		glRotatef(twist,0.0,0.0,1.0);//旋转后位置
        /* plot new point */
        glVertex2fv(p);
		glRotatef(-twist,0.0,0.0,1.0);//旋转后位置
    }
    glEnd();
	
    glFlush(); /* clear buffers */
}

int main(int argc, char** argv)
{
    /* standard GLUT initialization */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); /* default, not needed */
    glutInitWindowSize(500, 500); /* 500 x 500 pixel window */
    glutInitWindowPosition(0, 0); /* place window top left on display */
    glutCreateWindow("Sierpinski Gasket"); /* window title */
    glutDisplayFunc(display); /* display callback invoked when window opened */
    glutReshapeFunc(reshape);
    myinit(); /* set attributes */
    glutMainLoop(); /* enter event loop */
	return 0;
}
