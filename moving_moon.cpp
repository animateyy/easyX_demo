#include <graphics.h>
#include <windows.h>
#include <random>
#include <stdio.h>
int main1() {
    void erasemoon(int, int, int);
    void putmoon(int x, int y, int r);
    void putstar();
    //void wink();
    initgraph(1024,500,SHOWCONSOLE);//��ʼ��ͼ��,��������s����д��ַ
    setbkcolor(LIGHTBLUE);//���ñ�����ɫ
    cleardevice();//Ҫ���ñ�����ɫ��һ���ǳ���Ҫ
    int x,y;
    x = getmaxx();//��ȡ���Ŀ��ֵ
    y = getmaxy();//
    setfillcolor(RGB(43, 87, 154));
    bar(0, 350, x, y);
    setcolor(RGB(43, 87, 154));
    line(0, 350, x, 350);//����һ����
   /* setlinecolor(WHITE);*/
    int x0 = 0;                              
    putstar();
    while (x0<x-50) {
       putmoon(x0, 50, 50);
       Sleep(50);
       erasemoon(x0,50, 50);//������ʧ
      
       x0 = x0 + 2;//x+2
    }
   
    Sleep(2000);
    //closegraph ( ) ; // �ر�ͼ�λ��� 
   

    return 0;

}

//��������

//������ʧ����
void erasemoon(int x,int y,int r)
{
    setfillcolor(LIGHTBLUE);
    solidcircle(x , y, r );
}

void putmoon(int x, int y, int r)
{
    setfillcolor(RGB(255, 238, 98));// ���õ�ǰ�����ʽ ,��ɫ
    solidcircle(x, y, r);
    setfillcolor(LIGHTBLUE);
    solidcircle(x + 30, y+10, r-5);
};

void putstar()            /*put star*/
{
    int dotx,doty, w, h;
    w = getmaxx();
    h = getmaxy()-150;
    for (int i = 0; i < 100; i++)
    {
        dotx = rand()%w;
        doty = rand()%h;
        //t = rand()%3;
        setfillcolor(WHITE);
        fillellipse(dotx, doty, dotx+3, doty+3);    /*star*/
    }  

}

//��������,��δ�ɹ�
void wink()
{
    int w, h;
    w = getmaxx();
    h = getmaxy();

    for (int i=0; i < h; i + 10) {
        setfillcolor(LIGHTBLUE);
        bar(0, i, w, i+10);
        Sleep(20);
    }

}

