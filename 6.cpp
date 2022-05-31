#include<graphics.h>
#include<math.h>  
#include <tchar.h>
#include<conio.h>  //调用sin,cos系统函数
#define R 80  //3D物体的边长
#define Z1 300  //3D物体矮边高度
#define Z2 300  //3D物体高边的高度
#define pi 3.1415926  //π




struct point {
	int x;
	int y;
	int z;
};

#define Point struct point //定义宏Point结构体
int  f[6][4] = { 0,1,5,4,1,2,6,5,2,3,7,6,3,0,4,7,4,5,6,7,3,2,1,0 };
float  p[8][3];
Point vv[8] = { {R,R,0},{R,-R,0},{-R,-R,0},{-R,R,0},{R,R,Z1},{R,-R,Z2},{-R,-R,Z2},{-R,R,Z1} };
Point v[8] = { {R,R,0},{R,-R,0},{-R,-R,0},{-R,R,0},{R,R,Z1},{R,-R,Z2},{-R,-R,Z2},{-R,R,Z1} };
Point vector[6] = { {R,0,0},{0,-R,0},{-R,0,0},{0,R,0},{0,0,R},{0,0,-R} };//六个面的法向量
Point pv[8];
Point normal[6];
Point eye = { int(0.2 * R),R,0 };

void cal()

{
	int i; int a, b, c;
	for (i = 0; i < 6; i++)
	{
		a = (pv[f[i][0]].y - pv[f[i][1]].y) * (pv[f[i][0]].z - pv[f[i][2]].z) - (pv[f[i][0]].z - pv[f[i][1]].z) * (pv[f[i][0]].y - pv[f[i][2]].y);
		b = (pv[f[i][0]].z - pv[f[i][1]].z) * (pv[f[i][0]].x - pv[f[i][2]].x) - (pv[f[i][0]].x - pv[f[i][1]].x) * (pv[f[i][0]].z - pv[f[i][2]].z);
		c = (pv[f[i][0]].x - pv[f[i][1]].x) * (pv[f[i][0]].y - pv[f[i][2]].y) - (pv[f[i][0]].y - pv[f[i][1]].y) * (pv[f[i][0]].x - pv[f[i][2]].x);
		normal[i].x = a;
		normal[i].y = b;
		normal[i].z = c;
	}
}

void rotate(Point vv[8], Point v[8])//选择
{
	int i;
	double t;
	for (i = 0; i < 8; i++)
	{
		t = cos(pi / 12) * vv[i].x - sin(pi / 12) * vv[i].y;
		v[i].x = (int)(t > 0 ? t + 0.5 : t - 0.5);
		t = sin(pi / 12) * vv[i].x + cos(pi / 12) * vv[i].y;
		v[i].y = (int)(t > 0 ? t + 0.5 : t - 0.5);
		v[i].z = vv[i].z;
	}
}


void scalebig(Point vv[8], Point v[8])//放大
{
	int i;
	double t;
	for (i = 0; i < 8; i++)
	{
		t = vv[i].x * 1.2;
		v[i].x = (int)(t > 0 ? t + 0.5 : t - 0.5);
		t = vv[i].y * 1.2;
		v[i].y = (int)(t > 0 ? t + 0.5 : t - 0.5);
		t = vv[i].z * 1.2;
		v[i].z = (int)(t > 0 ? t + 0.5 : t - 0.5);
	}

}


void scalesmall(Point vv[8], Point v[8])//缩小
{
	int i;
	double t;
	for (i = 0; i < 8; i++)
	{
		t = vv[i].x * 0.8;
		v[i].x = (int)(t > 0 ? t + 0.5 : t - 0.5);
		t = vv[i].y * 0.8;
		v[i].y = (int)(t > 0 ? t + 0.5 : t - 0.5);
		t = vv[i].z * 0.8;
		v[i].z = (int)(t > 0 ? t + 0.5 : t - 0.5);
	}

}

void translate(Point vv[8], Point v[8])//平移
{
	int i;
	int t;
	for (i = 0; i < 8; i++)
	{
		t = vv[i].x - 10;
		v[i].x = t;
		t = vv[i].z - 10;
		v[i].z = t;
		v[i].y = vv[i].y;
	}
}


void render(Point v[8], Point pv[8])//绘制立体图形
{
	int i;
	double t;
	for (int i = 0; i < 8; i++)
	{
		t = 0.7071 * v[i].x - 0.7071 * (-v[i].y);
		pv[i].x = (int)(t > 0 ? t + 0.5 : t - 0.5) + 150;
		t = (-0.40577) * v[i].x - 0.40577 * (-v[i].y) + 0.819 * (-v[i].z);
		pv[i].z = (int)(t > 0 ? t + 0.5 : t - 0.5) + 150;
		pv[i].y = v[i].y;
	}
	cal();
	setcolor(WHITE);
	for (i = 0; i < 6; i++)
	{
		if (eye.x * normal[i].x + eye.y * normal[i].y + eye.z * normal[i].z <= 0)
		{
			setlinecolor(RED);
			setlinestyle(PS_DASHDOT);
		} //用虚线	
		else
		{
			setlinecolor(RED); 
			setlinestyle(PS_SOLID, 3, NULL, 0);
		}//用实线
		for (int j = 0; j < 4; j++) //画一个面
		{
			//注意下4点点首尾相连，最后一个顶点，与第一个定点连线
			int a1 = f[i][j];
			int a2 = f[i][(j + 1) % 4];
			line(pv[a1].x, pv[a1].z, pv[a2].x, pv[a2].z);
		}
	}

	TCHAR c[]= _T("1");
	   for ( i=0;i<8;i++)
	   {
	   	outtextxy(pv[i].x+3,pv[i].z+3,c);//在屏幕上指定位置输出字符串
	   	c[0]++;
	   }




}

int main(int argc, char* argv[])
{

	initgraph(1024, 768);
	setorigin(400, 400);
	setbkcolor(BLACK);
	cal();
	cleardevice();//用背景颜色遮盖原始屏幕
	render(v, pv);
	

	while (true)
	{
		while (_getch() == 'R')
		{
			cleardevice();
			rotate(vv, v);  //计算对象旋转后的坐标点
			render(v, pv);     // 将其绘制出来
			for (int i = 0; i < 8; i++) {  // 用新8点值更新旧8点值，使下次旋转               
				vv[i].x = v[i].x;       //在本次已有的基础上接着旋转
				vv[i].y = v[i].y;
				vv[i].z = v[i].z;
			}
			for (int i = 0; i < 6; i++)//更新6个面的法向量。
			{
				vector[i].x = pv[i].x;
				vector[i].y = pv[i].y;
				vector[i].z = pv[i].z;
			}
		}
		while (_getch() == 'B')
		{
			cleardevice();
			scalebig(vv, v); //计算对象旋转后的坐标点
			render(v, pv);     // 将其绘制出来
			for (int i = 0; i < 8; i++) {  // 用新8点值更新旧8点值               
				vv[i].x = v[i].x;
				vv[i].y = v[i].y;
				vv[i].z = v[i].z;
			}
			for (int i = 0; i < 6; i++)//更新6个面的法向量。
			{
				vector[i].x = pv[i].x;
				vector[i].y = pv[i].y;
				vector[i].z = pv[i].z;
			}

		}
		while (_getch() == 'S')
		{
			cleardevice();
			scalesmall(vv, v); //计算对象旋转后的坐标点
			render(v, pv);     // 将其绘制出来
			for (int i = 0; i < 8; i++) {  // 用新8点值更新旧8点值               
				vv[i].x = v[i].x;
				vv[i].y = v[i].y;
				vv[i].z = v[i].z;
			}
			for (int i = 0; i < 6; i++)//更新6个面的法向量。
			{
				vector[i].x = pv[i].x;
				vector[i].y = pv[i].y;
				vector[i].z = pv[i].z;
			}

		}
		while (_getch() == 'T')//平移
		{
			cleardevice();
			translate(vv, v); //计算对象旋转后的坐标点
			render(v, pv);     // 将其绘制出来
			for (int i = 0; i < 8; i++) {  // 用新8点值更新旧8点值               
				vv[i].x = v[i].x;
				vv[i].y = v[i].y;
				vv[i].z = v[i].z;
			}
			for (int i = 0; i < 6; i++)//更新6个面的法向量。
			{
				vector[i].x = pv[i].x;
				vector[i].y = pv[i].y;
				vector[i].z = pv[i].z;
			}

		}
	}
	closegraph();
	return 0;
}
