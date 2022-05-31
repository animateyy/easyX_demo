#include <windows.h>
#include <gl/glut.h>
void display(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);  //set the background color        
	glClear(GL_COLOR_BUFFER_BIT);//buffer the color 
	
	glColor3f(0, 0, 1.0);  // teapot-1	 
	glTranslatef(0, -0.5, 0); // move , make a space for the other teapot	 
	//glutWireTeapot(0.5);
	glutWireCube(0.5);

	glTranslatef(0, 1, 0);  // teapot-2£¬do not overlapping with teapot-1
	glRotatef(100, 0, 1.0, 0.2);
	glColor3f(1.0, 0, 0);
	glutWireTeapot(0.4);

	//glFlush();				//set them to the screen
	glutSwapBuffers(); //
}

void s_display(void)
{
	glClearColor(1, 1, 1, 1); //draw the first teapot
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0.5, 0, 0);
	glColor3f(0, 0, 1);
	glutWireTeapot(0.3);

	glPopMatrix(); //draw the second teapot	  
	glTranslatef(-0.5, 0, 0);
	glColor3f(1, 0, 0);
	glutSolidTeapot(-0.3);
	glFlush();
}



void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluOrtho2D(0, 0, 0, (GLfloat)h / (GLfloat)w);
	else
		gluOrtho2D(0, (GLfloat)w / (GLfloat)h, 0, 0);

}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);		//initialization
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set the display mode

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);//Ë«»º³åÄ£Ê½

	glutInitWindowPosition(300, 100); //define window position

	glutInitWindowSize(600, 600); //define the size of window

	glutCreateWindow("my first teapot-by Yiyun Xu");   //create a window£¬naming the title
	glutReshapeFunc(reshape);//the first solution
	glutDisplayFunc(display);		//draw image
	glutMainLoop();			//execute it
}

