#include <stdio.h>
#include<conio.h>
#include<time.h>
#include<conio.h>//按键
#include<graphics.h>//图形界面库
//播放音乐（头文件库文件）
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define  NUM   1000 
#define  SIZE  10   //一节蛇的宽度
#define  X     640
#define  Y     480
#define  SPEED 100  //速度
enum Ch { up = 72, down = 80, left = 75, right = 77 };
struct Coor  //坐标
{
	int x;
	int y;
};
struct Snack //蛇
{
	int length; //节数
	Ch ch;//蛇的方向
	Coor array[NUM]; //用来存蛇

};
struct Food
{
	//食物坐标
	int x;
	int y;
	bool iseat;//判断是否被吃
};
Snack snack;   //蛇实体
Food food;     //food结构体变量（食物）
void GameInit()
{
	srand((unsigned int)time(NULL));//使用随机
	//初始化蛇3节
	snack.length = 10;
	snack.ch = right;
	snack.array[0].x = 100;
	snack.array[0].y = 100;
	snack.array[1].x = 90;
	snack.array[1].y = 100;
	snack.array[2].x = 80;
	snack.array[2].y = 100;
	//初始化食物
	food.iseat = true;
}
void DrawGame()//游戏内容绘制
{
	cleardevice();
	//绘制食物
	setfillcolor(GREEN);
	fillroundrect(food.x, food.y, food.x + SIZE, food.y + SIZE, 5, 5);
	//绘制蛇 snake.n节
	setfillcolor(RED);//提供颜色
	fillrectangle(snack.array[0].x, snack.array[0].y,
		snack.array[0].x + SIZE, snack.array[0].y + SIZE);//填充蛇头
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
//蛇的移动
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
void ChangeCh()//"<-"和"->"控制左右 
{
	//按键 up down left right
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
void CreateFood()//增加食物
{
	if (food.iseat == true)
	{
		bool flag = false;    //食物和蛇是否重复
		if (food.iseat == true)
		{
			while (1)
			{
				flag = false;
				//食物位置
				food.x = rand() % (X / SIZE) * SIZE;
				food.y = rand() % (Y / SIZE) * SIZE;
				//食物不能在蛇的身体上
				for (int i = 0; i < snack.length; i++)
				{
					if (food.x == snack.array[i].x && food.y == snack.array[i].y)
					{
						flag = true;//重复
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
void EatFood()//吃食物
{
	if (snack.array[0].x == food.x && snack.array[0].y == food.y)
	{
		food.iseat = true;
		snack.length++;
	}
}
int GameOver()//结束游戏
{
	//跟墙碰撞
	if (snack.array[0].x < 0 || snack.array[0].x >= X || snack.array[0].y < 0 || snack.array[0].y >= Y)
	{
		return 1;
	}

	//跟自己身体碰撞
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
	//初始化一个窗口界面
	initgraph(X, Y);
	mciSendString(L"open ./贪吃蛇.mp3", 0, 0, 0);
	mciSendString(L"play ./贪吃蛇.mp3", 0, 0, 0);
	mciSendString(L"play ./贪吃蛇.mp3 repeat", 0, 0, 0);
	GameInit();//初始化游戏
	int n = 0;
	while (1)
	{
		while (!_kbhit())
		{
			SnackMove();
			DrawGame();
			CreateFood();
			EatFood();
			//结束
			n = GameOver();
			if (n)
				break;
			Sleep(SPEED);//蛇的速度
		}
		if (n)//结束
			break;
		ChangeCh();
	}
	return 0;
}
