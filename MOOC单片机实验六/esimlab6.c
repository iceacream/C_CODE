#include<reg51.h>
sbit LED1=P1^5;
char i = 100;
char t = 0;

void t1_init()
{
  TMOD = 0x01;		//��ʱ��T0Ϊ��ʽ1
	TH0 = 0xd8;			//���ö�ʱ����ֵ��1s��
	TL0 = 0xef;
	LED1 = 1;				//LED1Ϩ��
	ET0 = 1;				//����ʱ��T0�ж�
	TR0 = 1;				//������ʱ��T0
	EA = 1;					//�����ж�
}

void main()
{
  t1_init();
	

  while(1);
}

void timer0() interrupt 1			//T0�жϳ���
{

	
			TH0 = 0xd8;
			TL0 = 0xef;
			i--;

			if(i<=0)
			{
					if(t==3){					//3s
						TR0 = 0;				//�رն�ʱ��T0
						LED1 = ~LED1;		//LED��״̬ȡ��
						t=0;
					}
						i = 100;
						t++;
			}
				TR0 = 1;				//����������ʱ��T0
} 





