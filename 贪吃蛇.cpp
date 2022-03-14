#include <stdio.h>
#include<conio.h>
#include<time.h>
#include<conio.h>//����
#include<graphics.h>//ͼ�ν����
//�������֣�ͷ�ļ����ļ���
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define  NUM   1000 
#define  SIZE  10   //һ���ߵĿ��
#define  X     640
#define  Y     480
#define  SPEED 100  //�ٶ�
enum Ch { up = 72, down = 80, left = 75, right = 77 };
struct Coor  //����
{
	int x;
	int y;
};
struct Snack //��
{
	int length; //����
	Ch ch;//�ߵķ���
	Coor array[NUM]; //��������

};
struct Food
{
	//ʳ������
	int x;
	int y;
	bool iseat;//�ж��Ƿ񱻳�
};
Snack snack;   //��ʵ��
Food food;     //food�ṹ�������ʳ�
void GameInit()
{
	srand((unsigned int)time(NULL));//ʹ�����
	//��ʼ����3��
	snack.length = 10;
	snack.ch = right;
	snack.array[0].x = 100;
	snack.array[0].y = 100;
	snack.array[1].x = 90;
	snack.array[1].y = 100;
	snack.array[2].x = 80;
	snack.array[2].y = 100;
	//��ʼ��ʳ��
	food.iseat = true;
}
void DrawGame()//��Ϸ���ݻ���
{
	cleardevice();
	//����ʳ��
	setfillcolor(GREEN);
	fillroundrect(food.x, food.y, food.x + SIZE, food.y + SIZE, 5, 5);
	//������ snake.n��
	setfillcolor(RED);//�ṩ��ɫ
	fillrectangle(snack.array[0].x, snack.array[0].y,
		snack.array[0].x + SIZE, snack.array[0].y + SIZE);//�����ͷ
	for (int i = 1; i < snack.length; i++)
	{

		if (i % 2 == 1)
		{
			setfillcolor(YELLOW);
			fillrectangle(snack.array[i].x, snack.array[i].y, snack.array[i].x + SIZE, snack.array[i].y + SIZE);
		}
		else
		{
			rectangle(snack.array[i].x, snack.array[i].y, snack.array[i].x + SIZE, snack.array[i].y + SIZE);
		}
	}
}
//�ߵ��ƶ�
void SnackMove()
{
	for (int i = snack.length - 1; i > 0; i--)
	{
		snack.array[i].x = snack.array[i - 1].x;
		snack.array[i].y = snack.array[i - 1].y;
	}
	switch (snack.ch)
	{
	case up:
		snack.array[0].y -= SIZE;
		break;
	case down:
		snack.array[0].y += SIZE;
		break;
	case left:
		snack.array[0].x -= SIZE;
		break;
	case right:
		snack.array[0].x += SIZE;
		break;
	}
}
void ChangeCh()//"<-"��"->"�������� 
{
	//���� up down left right
	char key;
	key = _getch();
	switch (key)
	{
	case up:
		if (snack.ch != down)
			snack.ch = up;
		break;
	case down:
		if (snack.ch != up)
			snack.ch = down;
		break;
	case left:
		if (snack.ch != right)
			snack.ch = left;
		break;
	case right:
		if (snack.ch != left)
			snack.ch = right;
		break;
	}
}
void CreateFood()//����ʳ��
{
	if (food.iseat == true)
	{
		bool flag = false;    //ʳ������Ƿ��ظ�
		if (food.iseat == true)
		{
			while (1)
			{
				flag = false;
				//ʳ��λ��
				food.x = rand() % (X / SIZE) * SIZE;
				food.y = rand() % (Y / SIZE) * SIZE;
				//ʳ�ﲻ�����ߵ�������
				for (int i = 0; i < snack.length; i++)
				{
					if (food.x == snack.array[i].x && food.y == snack.array[i].y)
					{
						flag = true;//�ظ�
						break;
					}
				}
				if (!flag)
				{
					food.iseat = false;
					break;
				}
			}
		}
	}
}
void EatFood()//��ʳ��
{
	if (snack.array[0].x == food.x && snack.array[0].y == food.y)
	{
		food.iseat = true;
		snack.length++;
	}
}
int GameOver()//������Ϸ
{
	//��ǽ��ײ
	if (snack.array[0].x < 0 || snack.array[0].x >= X || snack.array[0].y < 0 || snack.array[0].y >= Y)
	{
		return 1;
	}

	//���Լ�������ײ
	for (int i = 1; i < snack.length - 1; i++)
	{
		if (snack.array[0].x == snack.array[i].x && snack.array[0].y == snack.array[i].y)
		{
			return 1;
		}
	}
	return 0;

}
int main()
{
	//��ʼ��һ�����ڽ���
	initgraph(X, Y);
	mciSendString(L"open ./̰����.mp3", 0, 0, 0);
	mciSendString(L"play ./̰����.mp3", 0, 0, 0);
	mciSendString(L"play ./̰����.mp3 repeat", 0, 0, 0);
	GameInit();//��ʼ����Ϸ
	int n = 0;
	while (1)
	{
		while (!_kbhit())
		{
			SnackMove();
			DrawGame();
			CreateFood();
			EatFood();
			//����
			n = GameOver();
			if (n)
				break;
			Sleep(SPEED);//�ߵ��ٶ�
		}
		if (n)//����
			break;
		ChangeCh();
	}
	return 0;
}
