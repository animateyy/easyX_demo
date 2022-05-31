#include <graphics.h>
#include <windows.h>
#include <random>
#include <stdio.h>
int main1() {
    void erasemoon(int, int, int);
    void putmoon(int x, int y, int r);
    void putstar();
    //void wink();
    initgraph(1024,500,SHOWCONSOLE);//初始化图像,第三个参s数填写地址
    setbkcolor(LIGHTBLUE);//设置背景颜色
    cleardevice();//要设置背景颜色这一步非常重要
    int x,y;
    x = getmaxx();//获取最大的宽度值
    y = getmaxy();//
    setfillcolor(RGB(43, 87, 154));
    bar(0, 350, x, y);
    setcolor(RGB(43, 87, 154));
    line(0, 350, x, 350);//绘制一条线
   /* setlinecolor(WHITE);*/
    int x0 = 0;                              
    putstar();
    while (x0<x-50) {
       putmoon(x0, 50, 50);
       Sleep(50);
       erasemoon(x0,50, 50);//月亮消失
      
       x0 = x0 + 2;//x+2
    }
   
    Sleep(2000);
    //closegraph ( ) ; // 关闭图形环境 
   

    return 0;

}

//绘制月亮

//月亮消失函数
void erasemoon(int x,int y,int r)
{
    setfillcolor(LIGHTBLUE);
    solidcircle(x , y, r );
}

void putmoon(int x, int y, int r)
{
    setfillcolor(RGB(255, 238, 98));// 设置当前填充样式 ,黄色
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

//让星星闪,还未成功
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

