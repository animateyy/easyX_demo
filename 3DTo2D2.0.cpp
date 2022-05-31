//﻿// 3DTo2D.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//




#include<graphics.h>      // 就是需要引用这个图形库

#include<conio.h>

#include<math.h>//因为函数中调用了sin,cos系统函数


#define R 75    
#define Z1 100
#define Z2 200
#define pi 3.1415926

//#define Point struct point

typedef struct Point
{
	int x;
	int y;
	int z;
}point;
	


Point vv[8] = { {R,R,0},{R,-R,0},{-R,-R,0},{-R,R,0},
				 {R,R,Z1},{R,-R,Z2},{-R,-R,Z2},
					 {-R,R,Z1} };


int  f[6][4] = { {0,1,5,4},{1,2,6,5},{2,3,7,6},
					 {3,0,4,7}, {4,5,6,7},{3,0,1,2} };

Point  v[8];

//float  p[8][3]; // used for temple storage


void rotate()
{
	int i;
	float t;
	for (i = 0;i < 8;i++)
	{
		t = cos(pi / 12)*vv[i].x - sin(pi / 12)*vv[i].y;
		v[i].x = (int)(t > 0 ? t + 0.5 : t - 0.5);
		t = sin(pi / 12)*vv[i].x + cos(pi / 12)*vv[i].y;
		v[i].y = (int)(t > 0 ? t + 0.5 : t - 0.5);
		v[i].z = vv[i].z;
	}
}

void translate()
{
	int i;
	float t;
	for (i = 0;i < 8;i++)
	{
		v[i].x =vv[i].x;
		
		t = cos(pi)*vv[i].y + sin(pi)*vv[i].z;
		v[i].y = (int)(t > 0 ? t + 0.5 : t - 0.5);
		//v[i].y=vv[i].y+vv[i].z;
		
		t = -sin(pi)*vv[i].y + cos(pi)*vv[i].z;
	    v[i].z = (int)(t > 0 ? t + 0.5 : t - 0.5);
		//v[i].z =vv[i].y+vv[i].z*(1+m);
	}
}


void scale(float d)
{
	int i;
	float t;
	for (i = 0;i < 8;i++)
	{
		v[i].x =d*vv[i].x;
		
		v[i].y =d*vv[i].y; 
		
		v[i].z =d*vv[i].z;
	}
}



void render()
{
	//将3D 投影到2D屏幕，计算出2D坐标
   //根据2D坐标，绘图
	setcolor(WHITE);

	int i, j;
	int a1, a2;
	setlinestyle(PS_SOLID, 2);
	for (i = 0;i < 6;i++)
	{
		for (j = 0;j < 4;j++)
		{
			a1 = f[i][j];
			a2 = f[i][(j + 1) % 4];
			line(vv[a1].x, vv[a1].z, vv[a2].x, vv[a2].z);
		}
		a1 = f[i][3];
		a2 = f[i][0];
		line(vv[a1].x, vv[a1].z, vv[a2].x, vv[a2].z);

	}

}

int main(int argc, char *argv[])
{


	initgraph(640, 480);
	setorigin(350, 350);
	setaspectratio(1, -1);

	setbkcolor(BLACK);//背景颜色
	cleardevice();//用背景颜色遮盖原始屏幕

	render();

	while(true){
		


   switch(getch())
	{
   case'a':
		cleardevice();
		rotate();break;
   case's':
		cleardevice();
		translate();break;
   case'd':
		cleardevice();
		scale(1.2);break;
   case'f':
		cleardevice();
		scale(0.8);break;
   }
		//计算对象旋转后的坐标点

		render();     // 将其绘制出来
		for (int i = 0;i < 8;i++)  // 用新8点值更新旧8点值，使下次旋转 
		{
		  vv[i].x = v[i].x;
		  vv[i].y = v[i].y;
		  vv[i].z = v[i].z;
		}
	}

   getch();
	closegraph();

	return 0;

}

	













//#include<Windows.h>
//#include<GL/glut.h>
//#include <iostream>
//
////#include<stdio.h>
//
//
//GLfloat vertices[][3] = {
//	{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
//	{1.0,1.0,-1.0}, {-1.0,1.0,-1.0},
//	{-1.0,-1.0,1.0}, {1.0,-1.0,1.0},
//	{1.0,1.0,1.0}, {-1.0,1.0,1.0}
//};
//
//GLfloat colors[][3] = {
//	{0.0,0.0,0.0},{1.0,0.0,0.0},
//	{1.0,1.0,0.0}, {0.0,1.0,0.0},
//	{0.0,0.0,1.0}, {1.0,0.0,1.0},
//	{1.0,1.0,1.0}, {0.0,1.0,1.0}
//};
//
//
//
//
//void quad(int a, int b, int c, int d, int face)
//{
//	glBegin(GL_QUADS);
//	glColor3fv(colors[a]);
//	glVertex3fv(vertices[a]);
//	glColor3fv(colors[b]);
//	glVertex3fv(vertices[b]);
//	glColor3fv(colors[c]);
//	glVertex3fv(vertices[c]);
//	glColor3fv(colors[d]);
//	glVertex3fv(vertices[d]);
//	glEnd();
//}
//
//void colorcube(void)
//{
//
//	quad(1, 0, 3, 2, 0);
//	quad(3, 7, 6, 2, 1);
//	quad(7, 3, 0, 4, 2);
//	quad(2, 6, 5, 1, 3);
//	quad(4, 5, 6, 7, 4);
//	quad(5, 4, 0, 1, 5);
//}
//
//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glLoadIdentity();
//	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
//	glMatrixMode(GL_MODELVIEW);
//
//	glRotatef(195, -30, -30, -30);
//	colorcube();
//	glFlush();
//}
//
//void main(int argc, char *argv[])
//{
	//glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_RGB);
	//glutInitWindowPosition(200, 200);
	//glutInitWindowSize(300, 300);
	//glutCreateWindow("第一个立方体");
//	glutDisplayFunc(&myDisplay);
//	glutMainLoop();
//}
//



//#include<graphics.h>
//#include<conio.h>
//#include<math.h>
//
//#include<iostream>
//#include<math.h>
//using namespace std;
//
////因为函数中调用了sin,cos系统函数
//#define R 75
////3D物体的边长
//#define Z1 100
////3D物体矮边高度
//#define Z2 200
////3D物体高边的高度
//#define pi 3.1415926
////因为键盘输入不了π
////struct point   {    int x;    int y;    int z;  };
////#define Point struct point
////不愿每次都在程序中写 struct point ，而是直接写Point，让程序转换
//double p[][4]={{R,R,0,1},{R,-R,0,1},{-R,-R,0,1},{-R,R,0,1},
//		{R,R,Z1,1},{R,-R,Z2,1},{-R,-R,Z2,1},{-R,R,Z1,1}};
// //用户给出的8个顶点
////Point p[8],s[8];
// //数组new_v[]用来保存旋转后新位置的点点，p[]用来保存3D投影到2D后的数据，用来画图
//int  surface[6][2]={ {0,1},{1,2},{2,3},{3,0},
//							{4,5},{3,0} };
////6个面，给出哪4个点组成一个面
////三维坐标转换为右手坐标系的二维坐标
//void transfer(double P[][4], int n, POINT S[])
//{
//	int i,j;
//	for(i=0;i<n;i++)
//	{
//		for(j=0;j<3;j++)
//		{
//			S[i].x=P[i][1]+sqrt(2)/3.0*(-P[i][0]);
//			S[i].y=P[i][2]+sqrt(2)/3.0*(-P[i][0]);
//		}
//	}
//}
//int ring1[]={0,1,2,3,4,5,6,7
//};
//int ring2[]={0,1,5,4};
//int ring3[]={0,4,7,3};
//int ring4[]={1,2,6,5};
//int ring5[]={0,3,7,4};


//int main()
//{
//	initgraph(800,550);
//	setorigin(220,350);
//	setaspectratio(1,-1);
//
//	line(0,0,600,0);
//	line(0,0,0,520);
//	line(0,0,-550,-550);
//	int i,j,index,k;
//	POINT points[20];
//	POINT points1[10];
//	setcolor(RED);
//	transfer(p,20,points);
////画三维立体图
//for(i=0;i<12;i++){
//	k=0;
//	for(j=surface[i][0];j<=surface[i][1];j++)
//	{
//		index=ring1[j];
//		points1[k].x=points[index].x;
//		points1[k].y=points[index].y;
//		k++;
//	}
//	polygon(points1,k);
//}
//for(i=0;i<12;i++){
//	k=0;
//	for(j=surface[i][0];j<=surface[i][1];j++)
//	{
//		index=ring2[j];
//		points1[k].x=points[index].x;
//		points1[k].y=points[index].y;
//		k++;
//	}
//	polygon(points1,k);
//}
//for(i=0;i<12;i++){
//	k=0;
//	for(j=surface[i][0];j<=surface[i][1];j++)
//	{
//		index=ring3[j];
//		points1[k].x=points[index].x;
//		points1[k].y=points[index].y;
//		k++;
//	}
//	polygon(points1,k);
//}
//for(i=0;i<12;i++){
//	k=0;
//	for(j=surface[i][0];j<=surface[i][1];j++)
//	{
//		index=ring4[j];
//		points1[k].x=points[index].x;
//		points1[k].y=points[index].y;
//		k++;
//	}
//	polygon(points1,k);
//}
//for(i=0;i<12;i++){
//	k=0;
//	for(j=surface[i][0];j<=surface[i][1];j++)
//	{
//		index=ring5[j];
//		points1[k].x=points[index].x;
//		points1[k].y=points[index].y;
//		k++;
//	}
//	polygon(points1,k);
//}
//
//setcolor(YELLOW);
//
//
//	_getch();
//	closegraph();
//	return 0;
//}








