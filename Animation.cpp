#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
   int gdriver= DETECT, gmode,i,j,x,y;
   initgraph(&gdriver,&gmode, NULL);
   
   
   
   for(i=0;i<getmaxx()-95;i++)
   {
   cleardevice();
   setcolor(BROWN);
   line(0,450,getmaxx(),450);//road
   
   setcolor(YELLOW);
   rectangle(20+i,320,70+i,420);//man
   
   setcolor(WHITE);
   circle(45+i,300,20);//head
   
   setcolor(WHITE);
   line(25+i,420,65+i,450);//legs
   line(65+i,420,25+i,450);
   line(45+i,330,95+i,380);//hands
   line(70+i,355,95+i,330);
   
   setcolor(MAGENTA);
   line(95+i,330,95+i,250);//vertical umbrella stick
   line(20+i,250,170+i,250);//horizontal umbrella stick
   
   setcolor(MAGENTA);
   arc(95+i,250,180,360,75);//umbrella top
   for(j=0;j<100;j++)
   {
   x=rand()%getmaxx();
   y=rand()%getmaxy();
   setcolor(CYAN);
   line(x,y,x+4,y+4);
   }
   delay(30);
   }
   delay(10000);
   closegraph();
}
