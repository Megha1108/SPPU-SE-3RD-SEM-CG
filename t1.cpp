#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

float res[3][3];
float coord[3][3];

void mm(float m1[3][3],float m2[3][3])
{
       int i,j,k;
       cout<<"multiplication of the matrix :";
       
       for(i=0;i<3;i++)
       {
              for(j=0;j<3;j++)
              {
                     res[i][j]=0;
                     for(k=0;k<3;k++)
                     {
                            res[i][j]+=m1[i][k]*m2[k][j];
                     }
              }
       }
       
       line(res[0][0],res[0][1],res[1][0],res[1][1]);
       line(res[1][0],res[1][1],res[2][0],res[2][1]);
       line(res[2][0],res[2][1],res[0][0],res[0][1]);
       delay(5000);
}

//transformation
void transformation(float coord[3][3])
{
       float tx,ty;
       cout<<"enter tx and ty= ";
       cin>>tx>>ty;
       
       float t[3][3]={{1,0,0},{0,1,0},{tx,ty,1}};
       mm(coord,t);
       delay(5000);
}

//scaling
void scaling(float coord[3][3])
{
       float sx,sy;
       cout<<"enter sx and sy= ";
       cin>>sx>>sy;
       
       float s[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};
       mm(coord,s);
       delay(5000);
}

//anticlk
void anticlk(float coord[3][3])
{
       float rad,theta;
       cout<<"enter theta=  ";
       cin>>theta;
       rad=(3.14/180)*theta;
       float ac[3][3]={{cos(rad),sin(rad),0},{-sin(rad),cos(rad),0},{0,0,1}};
       mm(coord,ac);
       delay(5000);
}


//clk
void clk(float coord[3][3])
{
       float rad,theta;
       cout<<"enter theta=  ";
       cin>>theta;
       rad=(3.14/180)*theta;
       float c[3][3]={{cos(rad),-sin(rad),0},{sin(rad),cos(rad),0},{0,0,1}};
       mm(coord,c);
       delay(5000);
}

int main()
{
       
       float x1,y1,x2,y2,x3,y3;
       
       cout<<"enter x1 and y1= ";
       cin>>x1>>y1;
       cout<<"enter x2 and y2= ";
       cin>>x2>>y2;
       cout<<"enter x3 and y3= ";
       cin>>x3>>y3;

       int gdriver=DETECT,gmode;
       initgraph(&gdriver,&gmode,NULL);

       float coord[3][3]={{x1,y1,1},{x2,y2,1},{x3,y3,1}};
       
       line(x1,y1,x2,y2);
       line(x2,y2,x3,y3);
       line(x3,y3,x1,y1);

       delay(10000);


       int ch;
       cout<<"1.translation,2.scaling,3.anticlockwise rotation,4.clockwise rotation = ";
       cin>>ch;
       switch(ch){
              case 1:
                     transformation(coord);
                     break;
              case 2:
                     scaling(coord);
                     break;
              case 3:
                     anticlk(coord);
                     break;
              case 4:
                     clk(coord);
                     break;
              default:
                     cout<<"invalid input";
                     break;
       }
       closegraph();
       return 0;
}
