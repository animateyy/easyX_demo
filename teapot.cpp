#include <windows.h>
#include <glut.h>
void display(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);  //set the background color        
	glClear(GL_COLOR_BUFFER_BIT);//buffer the color 

	glColor3f(0, 0, 1.0);  // teapot-1	 
	glTranslatef(0, -0.5, 0); // move , make a space for the other teapot	 
	glutWireTeapot(0.5);

	glTranslatef(0, 1, 0);  // teapot-2£¬do not overlapping with teapot-1
	glRotatef(100, 0, 1.0, 0.2);
	glColor3f(1.0, 0, 0);
	glutWireTeapot(0.4);

	glFlush();				//set them to the screen
}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);		//initialization
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set the display mode

	glutInitWindowPosition(300, 100); //define window position

	glutInitWindowSize(600, 600); //define the size of window

	glutCreateWindow("my first teapot-by Xiafen Zhang");   //create a window£¬titled¡°my first¡­."
	glutDisplayFunc(display);		//draw image
	glutMainLoop();			//execute it
}

