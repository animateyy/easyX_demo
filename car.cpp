#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>

COLORREF c, body_color = RGB(25, 195, 61), bk = RGB(240, 240, 240);
int x = 320, y = 240, h = 40, b = 15, r = 20;
float pi = 3.1415926;
float d = 2 * pi * r / 48;
int i = 0;

void drawcar(int x)
{
	setcolor(body_color);
	moveto(x-h,y-h);
	lineto(x-h-b,y);
	lineto(x-2*h-b,y);
	lineto(x-2*h-b,y+h);
	lineto(x+2*h+b,y+h);
	lineto(x+2*h+b,y);
	lineto(x+h+b,y);
	lineto(x+h,y-h);
	lineto(x-h,y-h);
}

void wheel(int x)
{
	int c1xr = x - 1.5 * h +  d, c1yr = y + h;
	int c2xr= x + 1.5 * h +  d, c2yr = y + h;
	setfillstyle(BS_SOLID);
	setfillcolor(BLACK);
	fillcircle(c1xr, c1yr, r);
	fillcircle(c2xr, c2yr, r);
}

void fill(int x)
{
	setfillstyle(c, SOLID_FILL, NULL);
	int flag = 0;
	int a1, b1, a2, b2;
	for (int j = 0; j <= y + h; j++)
	{
		for (int i=x-2*h-b-h;i<x+2*h+b+h+1;i++)
		{
			c = getpixel(i, j);
			if (c == body_color&&flag == 0){
				a1 = i,b1 = j,flag = 1;
			}
			else if (c == body_color&&flag == 1){
				a2 = i,b2 = j;
				line(a1, b1, a2, b2);
				flag = 0;
			}
		}
		
	}
}

int main()
{
	initgraph(800, 480);
	setbkcolor(bk);
	cleardevice();

	while (_getch() != ' ')
	{
		x=x+10;
		int t;
		cleardevice();
		t = getch();

			if(t=='a')
			{
				drawcar(x);fill(x);wheel(x);
			}
	}
	return 0;
}