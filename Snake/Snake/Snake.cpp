/*
*	项目名称：贪吃蛇
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<easyx.h> //图形库
//音频
//#include<Windows.h>
//#include <mmsystem.h>
//#pragma comment(lib, "winmm.lib")

//蛇的最大长度
#define SNAKE_MAX_NUM 500
//窗口大小
#define WINDOW_WIDTH 640
#define WINDOW_HIGHT 480
//游戏区域大小
#define GAME_WIDTH 640
#define GAME_HIGHT 480



enum DIR //表示蛇的方向
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};


//蛇的结构
struct Snake 
{
	int size;  //每节蛇的大小
	int length;//蛇的节数
	int dir;//蛇的方向
	int speed;//蛇的速度
	POINT coor[SNAKE_MAX_NUM];//坐标
}snake;

//食物的结构
struct Food 
{
	//食物的坐标
	int x;
	int y;
	int r;//食物的大小
	bool flag;//食物是否被吃
	DWORD color;//食物的颜色
}food;


void SnakeInit() {
	//初始化蛇
	snake.size = 20;
	snake.length = 3;
	snake.speed = 1;
	snake.dir = RIGHT;
	for (int i = 0; i < snake.length; i++) {
		snake.coor[i].x = 40 - snake.size * i;
		snake.coor[i].y = snake.size;
	}
}
void FoodInit() {
	//初始食物
	food.r = snake.size / 2 + 8;
	srand(GetTickCount());//设置随机数种子为系统开机，到现在所进过的毫秒数
	food.x = rand() % (GAME_WIDTH - food.r * 2) + food.r;
	food.y = rand() % (GAME_HIGHT - food.r * 2) + food.r;
	food.color = RED;
	food.flag = true;
}

//初始化
void GameInit() {
	//init 初始化 graph 图形窗口
	initgraph(WINDOW_WIDTH, WINDOW_HIGHT,EW_SHOWCONSOLE);
	//初始化音频
	/*mciSendString("open ./a.mp3", 0, 0, 0);
	int k = mciSendString("play ./a.mp3 repeat", 0, 0, 0);
	printf("%d", k);
	system("pause");*/
	//初始化蛇
	SnakeInit();
	//食物初始化
	FoodInit();
}

//绘制
void GameDraw() {
	//双缓冲绘图
	BeginBatchDraw();

	//设置背景颜色
	setbkcolor(RGB(132, 173, 234));
	cleardevice();
	//绘制蛇
	for (int i = 0; i < snake.length; i++) {
		if(i==0)
			setfillcolor(RED);
		else 
			setfillcolor(YELLOW);
		solidcircle(snake.coor[i].x, snake.coor[i].y, snake.size/2);
	}
	//绘制食物
	if (food.flag) {
		solidcircle(food.x, food.y, food.r);
	}
	EndBatchDraw();
}

//移动蛇
void SnakeMove() {
	for (int i = snake.length; i > 0; i--) {
		snake.coor[i] = snake.coor[i - 1];
	}
	switch (snake.dir)
	{
	case UP:
		snake.coor[0].y-= snake.size;
		if (snake.coor[0].y <= 0)//上越界
			snake.coor[0].y = GAME_HIGHT - snake.size/2;
		break;
	case DOWN:
		snake.coor[0].y+= snake.size;
		if (snake.coor[0].y >= GAME_HIGHT)//下越界
			snake.coor[0].y = 0 + snake.size / 2;
		break;
	case LEFT:
		snake.coor[0].x-= snake.size;
		if (snake.coor[0].x <= 0)//左越界 
			snake.coor[0].x = GAME_WIDTH - snake.size / 2;
		break;
	case RIGHT:
		snake.coor[0].x+= snake.size;
		if (snake.coor[0].x >= GAME_WIDTH)//右越界
			snake.coor[0].x = 0 + snake.size / 2;
		break;
	}
}


//通过按键改变蛇的方向
void KeyControl() {
	//判断是否有按键
	if (_kbhit()) {   //返回0/1
		// 72 80 75 77 上下左右的键值
		switch (_getch())
		{
		case 'w':
		case 'W':
		case 72:
			//不允许反向
			if(snake.dir != DOWN)
				snake.dir = UP;
			break;
		case 's':
		case 'S':
		case 80:
			if (snake.dir != UP)
				snake.dir = DOWN;
			break;
		case 'a':
		case 'A':
		case 75:
			if (snake.dir != RIGHT)
				snake.dir = LEFT;
			break;
		case 'd':
		case 'D':
		case 77:
			if (snake.dir != LEFT)
				snake.dir = RIGHT;
			break;
		case 27:
			while (1) {
				if (_getch() == 27)
					return;
			}	
			break;
		}
	}
}


//吃食物
void EatFood(int& Score) {
	if (food.flag && snake.coor[0].x  >= food.x-food.r && snake.coor[0].x <= food.x + food.r &&
		snake.coor[0].y >= food.y - food.r && snake.coor[0].y <= food.y + food.r) {
		food.flag = false;
		snake.length++;
		Score++;
	}
	// 产生新的食物
	if (!food.flag)
		FoodInit();
}

//吃到自己
void EatSelf(int& flag) {
	for (int i = 1; i < snake.length; i++) {
		if (snake.coor[0].x == snake.coor[i].x && snake.coor[0].y == snake.coor[i].y) {
			flag = 0;
			break;
		}
	}
}
//游戏暂停
void stop() {
	if (_kbhit()) {
		if (_getch() == 27) {

		}
	}
}


int main() {

	GameInit();
	int Score = 0;
	int Flag = 1;
	while (Flag) {
		SnakeMove();
		GameDraw();
		KeyControl();
		EatFood(Score);
		EatSelf(Flag);
		//stop();
		printf("您的得分：%d", Score);
		system("cls");
		Sleep(100);
	}
	printf("game over!\n");
	printf("您的得分：%d\n", Score);
	system("pause");
	return 0;
}