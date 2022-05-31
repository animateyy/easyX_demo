#include <gl/glut.h>
#include<math.h>
#include<Windows.h>
int n=5;//分割五次

GLfloat* newPosition(GLfloat a[],GLfloat b[],int size,float f)
{
	float dis = sqrt(a[0] * a[0]+a[1] * a[1]);
	float theta =dis*f;
	b[0]=a[0]*cos(theta)-a[1]*sin(theta);
	b[1]=a[0]*sin(theta)+a[1]*cos(theta);
	
	return b;
}

void triangle(GLfloat *a,GLfloat *b,GLfloat *c,float f)
{
	GLfloat newA[2],newB[2],newC[2];
	
	GLfloat *newPointA =newPosition(a,newA,2,f);
	GLfloat *newPointB =newPosition(b,newB,2,f);
	GLfloat *newPointC =newPosition(c,newC,2,f);
	
	glVertex2fv(newPointA);
	glVertex2fv(newPointB);
	glVertex2fv(newPointC);
}

void devideTriangle(GLfloat *a,GLfloat *b,GLfloat *c,int n,float f)
{
	GLfloat midAB[2],midAC[2],midBC[2];
	if(n<1)
	{
		triangle(a,b,c,f);
	}
	else
	{
		for(int i=0;i<2;i++)
		{
			midAB[i]=(a[i]+b[i])/2;
			midBC[i]=(c[i]+b[i])/2;
			midAC[i]=(a[i]+c[i])/2;
		}
		n--;
		
		devideTriangle(midAB,midAC,a,n,f);
		devideTriangle(midBC,midAC,c,n,f);
		devideTriangle(midAB,midBC,b,n,f);
	}
}

void display()
{
	GLfloat points[3][2] ={{0.0,0.6},{-0.6,-0.6},{0.6,-0.6}};
	for(float f=0;f<15; f = f * 0.2)
	{
		glClearColor(1.0,1.0,1.0,0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glBegin(GL_TRIANGLES);
		glColor3f(1,0,1);
		
		//points[0]
		
		devideTriangle(points[0],points[1],points[2],n,f);
		glEnd();
		glFlush();
		Sleep(100);
	}
}

void main(int argc,char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Sierpinki");
	glutDisplayFunc(display);
	glutMainLoop();
}
	
		
		
			