#include <gl/glut.h>
bool mousedown = false; // to mark if mouse is down
bool loopr = false;

int rx1 = 0, ry1 = 0;  //define the variable for teapot 1
int rx2 = 0, ry2 = 0;  // define the variable for teapot 2

GLfloat red;
GLfloat green;
GLfloat blue;

void timer(int p)
{
		glutPostRedisplay();
		glutTimerFunc(20, timer, 0);
}


void display()
{
	
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	//重置当前指定的矩阵为单位矩阵
	glLoadIdentity();

	render();

	//draw the first teapot
	glPushMatrix();
	glRotatef(ry1, 0, 1, 0); //1st parameter is the degree of rotation
	glRotatef(rx1 + 180, 1, 0, 0); //2nd ~4th parameters determine around which to rotate
	glTranslatef(0.5, 0, 0);
	glColor3f(red, green, blue);
	glutWireTeapot(0.3);
	glPopMatrix();

	//draw the second teapot
	glRotatef(ry2, 0, 1, 0);
	glRotatef(rx2 + 180, 1, 0, 0);
	glTranslatef(-0.5, 0, 0);
	glColor3f(red, green, blue);
	glutSolidTeapot(-0.3);

	//双缓冲模式
	glutSwapBuffers(); 

}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)       //left  button down
	{
		if (state == GLUT_DOWN)
		{
			mousedown = true;
			loopr = false;
		}
		else
			mousedown = false;
	}
	if (button == GLUT_RIGHT_BUTTON) //right  button down
		if (state == GLUT_DOWN)
		{
			loopr = true;
			glutTimerFunc(200, timer, 0);
		}
}

void motion(int x, int y) // deal with the event of mouse move
{
	if (mousedown == true)  // if the left button of the mouse is down
	{
		int mx = 0;
		int my = 0;
		ry1 += x - mx;
		rx1 += y - my;
		ry2 += x - mx;
		ry2 += y - my;
		my = y;   // update the  position 
		mx = x;   // update the  position 
		glutPostRedisplay();
	}
}

//void special(int key, int x, int y)
//{
//	switch (key)
//	{
//	case GLUT_KEY_F1:
//		red = 1;
//		break;
//	case GLUT_KEY_F2:
//		red = 0.0;
//		break;
//	case GLUT_KEY_F3:
//		red = 0.0;
//		break;
//	}
//}

void special(int key, int x, int y)  // special key event
{
	switch (key)
	{
	case GLUT_KEY_LEFT:  ry1 -= 10; break;
	case GLUT_KEY_RIGHT:  rx1 -= 10; break;
	case GLUT_KEY_UP:  rx2 += 10; break;
	case GLUT_KEY_DOWN:  ry2 -= 10; break;
	default: break;
	}
	glutPostRedisplay();
}


void mykey(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':  rx2 += 5; break;
	case '2':  ry1 -= 5; break;
	case '3':  rx1 += 5; break;
	case '4':  rx1 -= 5; break;
	default: break;
	}
	glutPostRedisplay();
}


void process_menu(int id)
{
	switch (id)
	{
	case 1:
		red = 1.0;
		green = 0.0;
		blue = 0.0;
		break;
	case 2:
		red = 0.0;
		green = 1.0;
		blue = 0.0;
		break;
	case 3:
		red = 0;
		green = 0;
		blue = 1;
		break;

	}
	glutPostRedisplay();
}



void main(int arge, char** argv)
{
	glutInit(&arge, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200, 100); // Init position window
	glutInitWindowSize(600, 600); //size of window
	glutCreateWindow("two teapot"); // name of window
	glutDisplayFunc(display);//object to display inside window
	glutMouseFunc(mouse);  //interaction by mouse
	glutMotionFunc(motion); // mouse movement
	glutSpecialFunc(special); //special key
	glutKeyboardFunc(mykey); //common key
	glutCreateMenu(process_menu); //create menu
	glutAddMenuEntry("Red", 1); //name,ID of 1st item
	glutAddMenuEntry("Blue", 2); //name,ID of 2nd item
	glutAddMenuEntry("Green", 3); // ……  of 3rd item
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	//click right button to
	// activate the Popup menu
	glutMainLoop();
}



