#include<reg51.h>
sbit LED1=P1^5;
char i = 100;
char t = 0;

void t1_init()
{
  TMOD = 0x01;		//定时器T0为方式1
	TH0 = 0xd8;			//设置定时器初值（1s）
	TL0 = 0xef;
	LED1 = 1;				//LED1熄灭
	ET0 = 1;				//允许定时器T0中断
	TR0 = 1;				//启动定时器T0
	EA = 1;					//开总中断
}

void main()
{
  t1_init();
	

  while(1);
}

void timer0() interrupt 1			//T0中断程序
{

	
			TH0 = 0xd8;
			TL0 = 0xef;
			i--;

			if(i<=0)
			{
					if(t==3){					//3s
						TR0 = 0;				//关闭定时器T0
						LED1 = ~LED1;		//LED灯状态取反
						t=0;
					}
						i = 100;
						t++;
			}
				TR0 = 1;				//重新启动定时器T0
} 





