#include <stdio.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>

void initialinterface(void);                   //初始界面函数
void playgame(void);                           //玩游戏函数
void randomdiamonds(void);                     //随机方块
void movediamonds(void);                       //移动方块
int downcondition(int a[4],int b[4]);          //下降条件函数
void refresh(void);                           // 刷新函数

int main(void)
{
	srand(time(NULL));                         //时间为随机数种子
	initialinterface() ;                       //初始界面
	playgame();                                //玩游戏
	getch();                                   //按任意键关闭
	closegraph();                              //释放空间
	return 0;
}


//初始界面函数
void initialinterface(void)
{
	int i,j,a,b;
	initgraph(940,700);                         //窗口绘制
	setlinecolor(RGB(50,50,50));                //线条颜色
	setlinestyle(PS_SOLID,6);                   //线条样式
	setfillcolor(RGB(0,0,0));                   //填充颜色
	fillrectangle(137,17,809,683);              //游戏窗口
	line(593,17,593,683);                       //画一条直线，分割窗口
	line(593,347,809,347);                      //再画一条
	setlinestyle(PS_SOLID);                     //线条样式
	for(i=140;i<590;i+=30)
	{
		for(j=20;j<680;j+=30)
		{
			fillrectangle(i,j,i+30,j+30);
		}
	};                                           //生成小格
    settextcolor(RGB(255,0,0));
	settextstyle(30, 0, _T("宋体"));
	TCHAR s2[] = _T("分数:");
    outtextxy(630, 250, s2 ); 
	char s[5];   a=1024;
    sprintf(s, "%4d", a);
    outtextxy(710, 250, s);	                     //分数记录
	TCHAR s1[] = _T("时间:");
    outtextxy(630, 90, s1);
	char m[5];   b=10;
    sprintf(m,"%2ds", b);
    outtextxy(710, 90,m);		                  //时间记录
	int pts[] = {635, 410,  643, 420,  638, 420,  638, 439,  632, 439,  632, 420,  627, 420};
	setfillcolor(RGB(0,255,0));
    fillpolygon((POINT*)pts, 7);                  //绘制箭头    up
	TCHAR s3[] = _T("旋转图形");                 
    outtextxy(650, 410, s3);                      //箭头解释
	int pts1[] = {620, 455,  630, 447,  630, 452,  650, 452,  650, 458,  630, 458,  630, 463};
	setfillcolor(RGB(0,255,0));
    fillpolygon((POINT*)pts1, 7);                 //绘制箭头    left
	TCHAR s4[] = _T("移动图形");                
    outtextxy(650, 440, s4);                      //箭头解释
	int pts2[] = {635, 499,  643, 490,  638, 490,  638, 470,  632, 470,  632, 490,  627, 490};
	setfillcolor(RGB(0,255,0));
    fillpolygon((POINT*)pts2, 7);                  //绘制箭头    down
	TCHAR s5[] = _T("旋转图形");                 
    outtextxy(650, 470, s5);                      //箭头解释
	int pts3[] = {650, 515,  640, 507,  640, 512,  620, 512,  620, 518,  640, 518,  640, 523};
	setfillcolor(RGB(0,255,0));
    fillpolygon((POINT*)pts3, 7);                     //绘制箭头    right
	TCHAR s6[] = _T("旋转图形");                 
    outtextxy(650, 500, s6);                          //箭头解释
	IMAGE imgup;
    getimage(&imgup, 620, 410, 30, 30);
    putimage(680, 575, &imgup);                       //投影up箭头 
    IMAGE imgleft;
    getimage(&imgleft, 620, 440, 30, 30);
    putimage(650, 605, &imgleft);                     //投影left箭头
	IMAGE imgdown;
    getimage(&imgdown, 620, 470, 30, 30);
    putimage(680, 605, &imgdown);                     //投影down箭头
	IMAGE imgright;
    getimage(&imgright, 620, 500, 30, 30);
    putimage(710, 605, &imgright);                    //投影right箭头
}


//玩游戏
void playgame(void) 
{
	while(1)
	{
		randomdiamonds();
	    movediamonds();
		refresh();
	}
}

//随机方块
void randomdiamonds(void)
{
	int i,j,k,m,n,index,minus,a[4],b[4];
	long color[4]={RGB(200,0,0),RGB(200,200,0),RGB(200,0,200),RGB(0,200,0)};
	a[0]=350;    b[0]=110;
	i=rand()%4; 
	for(j=i;j==i;)
	{
		j=rand()%4;
	}
	switch(i)
	{
	case 0:  a[1]=a[0];  b[1]=b[0]-30;    break;
	case 1:  a[1]=a[0];  b[1]=b[0]+30;    break;
	case 2:  a[1]=a[0]-30;  b[1]=b[0];    break;
	case 3:  a[1]=a[0]+30;  b[1]=b[0];    break;
	}
	switch(j)
	{
	case 0:  a[2]=a[0];  b[2]=b[0]-30;    break;
	case 1:  a[2]=a[0];  b[2]=b[0]+30;    break;
	case 2:  a[2]=a[0]-30;  b[2]=b[0];    break;
	case 3:  a[2]=a[0]+30;  b[2]=b[0];    break;
	}
	k=rand()%3;
	for(m=1;m==1;)
	{
	    index=rand()%4;
        switch(index)
		{
	    case 0:     a[3]=a[k];    b[3]=b[k]-30;
			        if((a[3]==a[0])&&(b[3]==b[0]))
					    break      	;
					else if((a[3]==a[1])&&(b[3]==b[1]))
						break       ;
		           	else if((a[3]==a[2])&&(b[3]==b[2]))
						break       ;
					else
					{	m=0;    break;  }    
	    case 1:     a[3]=a[k];    b[3]=b[k]+30;
		            if((a[3]==a[0])&&(b[3]==b[0]))
					    break      	;
					else if((a[3]==a[1])&&(b[3]==b[1]))
						break       ;
		           	else if((a[3]==a[2])&&(b[3]==b[2]))
						break       ;
					else
					{	m=0;    break;  }
    	case 2:     a[3]=a[k]-30;    b[3]=b[k];
		            if((a[3]==a[0])&&(b[3]==b[0]))
					    break      	;
					else if((a[3]==a[1])&&(b[3]==b[1]))
						break       ;
		           	else if((a[3]==a[2])&&(b[3]==b[2]))
						break       ;
					else
					{	m=0;    break;  }                
    	case 3:     a[3]=a[k]+30;    b[3]=b[k];
		            if((a[3]==a[0])&&(b[3]==b[0]))
					    break      	;
					else if((a[3]==a[1])&&(b[3]==b[1]))
						break       ;
		           	else if((a[3]==a[2])&&(b[3]==b[2]))
						break       ;
					else
					{	m=0;    break;  }
		}
	}
	setfillcolor(color[rand()%4]);                   //填充颜色
	for(i=0;i<4;i++)
		for(j=3;j>i;j--)
			if(b[i]>=b[j])
			{ 
				m=b[i];  b[i]=b[j];  b[j]=m ;m=a[i];  a[i]=a[j];  a[j]=m ;
			}                                        //排序
    minus=b[0]-20;
	for(i=0;i<4;i++)
		b[i]=b[i]-minus;
	for(n=0;n<4;n++)
	{
     	fillrectangle(a[n],b[n],a[n]+30,b[n]+30);
	}
}



//移动方块
void movediamonds(void)
{
	int i,j,ch,re,k=0,a[4],b[4];
	long color,colors;
	for(i=35;i<=125;i+=30)	  
		for(j=305;j<=425;j+=30)
		{
			color=getpixel(j, i);
		    if(color!=RGB(0,0,0))
			{
				a[k]=j;
				b[k]=i;
			    k++;
				colors=color;
			} 
		}                                       //获取方块坐标
		re=downcondition(a,b);

		while(re)
		{
			ch=80;
			if(kbhit())                     //当按下按键的时候  头文件conio.h
			{
                 ch=getch();
                 if (ch==72)
				 {
                      ch=72;
				 }
				 else if (ch==77)
				 {
                    ch= 77;
				 }
				 else if (ch==75)
				 {
						 ch=75;
				 }
			     else
				 {
                      ch=80;
				 }
			} 
			 switch(ch)
			{
	           case 72:                                            break;
	           case 80:     	 setfillcolor(RGB(0,0,0));                   //填充颜色
                                 for(k=0;k<4;k++)
								 {
				                     fillrectangle(a[k]-15,b[k]-15,a[k]+15,b[k]+15);
								 }
					             for(i=0;i<4;i++) 
								 { 
					             b[i]=b[i]+30;
								 }
					             setfillcolor(colors);
                                 for(k=0;k<4;k++)
								 {
			           	             fillrectangle(a[k]-15,b[k]-15,a[k]+15,b[k]+15);
								 }                     Sleep(200);            break;
	           case 75:          setfillcolor(RGB(0,0,0));                   //填充颜色
                                 for(k=0;k<4;k++)
								 {
				                     fillrectangle(a[k]-15,b[k]-15,a[k]+15,b[k]+15);
								 }
					             for(i=0;i<4;i++) 
								 { 
					             a[i]=a[i]-30;
								 }
					             setfillcolor(colors);
                                 for(k=0;k<4;k++)
								 {
			           	             fillrectangle(a[k]-15,b[k]-15,a[k]+15,b[k]+15);
								 }                     Sleep(200);            break;
	           case 77:          setfillcolor(RGB(0,0,0));                   //填充颜色
                                 for(k=0;k<4;k++)
								 {
				                     fillrectangle(a[k]-15,b[k]-15,a[k]+15,b[k]+15);
								 }
					             for(i=0;i<4;i++) 
								 { 
					             a[i]=a[i]+30;
								 }
					             setfillcolor(colors);
                                 for(k=0;k<4;k++)
								 {
			           	             fillrectangle(a[k]-15,b[k]-15,a[k]+15,b[k]+15);
								 }                     Sleep(200);            break;
			}
			re=downcondition(a,b);
		}
}                                                                       //移动方块

//下降条件函数
int downcondition(int a[4],int b[4])
{
	int re;
    if(b[0]==b[3])
		 {
		     if(((getpixel(a[3],b[3]+16)==RGB(0,0,0))&&(getpixel(a[2],b[2]+16)==RGB(0,0,0)))&&((getpixel(a[1],b[1]+16)==RGB(0,0,0))&&(getpixel(a[0],b[0]+16)==RGB(0,0,0))))
			 {
			      re=1;
			 }
			 else
				 re=0;
		 }
     	if((b[1]==b[3])&&(b[0]!=b[3]))
		{
		    if(((getpixel(a[3],b[3]+16)==RGB(0,0,0))&&(getpixel(a[2],b[2]+16)==RGB(0,0,0)))&&((getpixel(a[1],b[1]+16)==RGB(0,0,0))&&(getpixel(a[3],b[3]+16)==RGB(0,0,0))))
			{
			    re=1;
			}
			else
				re=0;
		}
		if((b[2]==b[3])&&(b[1]!=b[3]))
		{
			if(b[0]==b[1])
			{
				if(a[1]==a[2])
				{
					if((getpixel(a[0],b[0]+16)==RGB(0,0,0))&&((getpixel(a[3],b[3]+16)==RGB(0,0,0))&&(getpixel(a[2],b[2]+16)==RGB(0,0,0))))
					{
			            re=1;
					}
			        else
				        re=0;
				}
				else if(a[0]==a[2])
				{
					if(((getpixel(a[3],b[3]+16)==RGB(0,0,0))&&(getpixel(a[2],b[2]+16)==RGB(0,0,0))))
					{
			            re=1;
					}
			        else
				        re=0;
				}
				else
				{
					if((getpixel(a[1],b[1]+16)==RGB(0,0,0))&&((getpixel(a[3],b[3]+16)==RGB(0,0,0))&&(getpixel(a[2],b[2]+16)==RGB(0,0,0))))
					{
			            re=1;
					}
			        else
				        re=0;
				}
			}
			else
			{
		         if((getpixel(a[3],b[3]+16)==RGB(0,0,0))&&(getpixel(a[2],b[2]+16)==RGB(0,0,0)))
				 {
			         re=1;
				 }
			     else
				     re=0;
			}
			
		}
		if((b[3]==b[3])&&(b[2]!=b[3]))
		{
			if(b[0]==b[2])
			{
				if(a[2]==a[3])
				{
					if((getpixel(a[3],b[3]+16)==RGB(0,0,0))&&(getpixel(a[0],b[0]+16)==RGB(0,0,0))&&(getpixel(a[1],b[1]+16)==RGB(0,0,0)))
						{
			                re=1;
						}
		           	else
				            re=0;
				}
				else
				{
					if((getpixel(a[3],b[3]+16)==RGB(0,0,0))&&(getpixel(a[0],b[0]+16)==RGB(0,0,0))&&(getpixel(a[2],b[2]+16)==RGB(0,0,0)))
						{
			                re=1;
						}
		           	else
				            re=0;
				}
			}
			else if((b[1]==b[2])&&(b[0]!=b[1]))
			{
				if(a[1]==a[3])
				{
					if((getpixel(a[3],b[3]+16)==RGB(0,0,0))&&(getpixel(a[2],b[2]+16)==RGB(0,0,0)))
					{
			             re=1;
					}
		           	else
				         re=0;
				}
				else
				{
					if((getpixel(a[3],b[3]+16)==RGB(0,0,0))&&(getpixel(a[1],b[1]+16)==RGB(0,0,0)))
					{
			             re=1;
					}
		            else
				         re=0;
				}
			}
		else if(b[0]==b[1])
				{
					if(a[0]==a[2])
					{	
						if((getpixel(a[3],b[3]+16)==RGB(0,0,0))&&(getpixel(a[1],b[1]+16)==RGB(0,0,0)))
						{
			                re=1;
						}
		             	else
				            re=0;
					}
				    else
					{
						 if((getpixel(a[3],b[3]+16)==RGB(0,0,0))&&(getpixel(a[0],b[0]+16)==RGB(0,0,0)))
						 {
			                   re=1;
						 }
		             	 else
				               re=0;		 
					}
				}
		   else
		   {
		        if(getpixel(a[3],b[3]+16)==RGB(0,0,0))
				{
			        re=1;
				}
		        else
				    re=0;
		   }
		}
	return re;
}  


//刷新函数
void refresh(void)
{
	int i=665,j=155,k=0,m=0,index[4];
	for(i=665,k=0;i>=35;i=i-30)
	{
    	for(j=155;j<=575;j=j+30)
		{
			if(getpixel(j,i)!=RGB(0,0,0))
				k++;
		}
		while(k==15)
		{
			index[m]=i;
			m++;
		}
	}
	setfillcolor(RGB(0,0,0)); 
	for(m=0;m<4;m++)
	{
        fillrectangle(140,index[m]-15,590,index[m]+15);
	}  
}
