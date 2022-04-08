/*
*	��Ŀ���ƣ�̰����
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<easyx.h> //ͼ�ο�
//��Ƶ
//#include<Windows.h>
//#include <mmsystem.h>
//#pragma comment(lib, "winmm.lib")

//�ߵ���󳤶�
#define SNAKE_MAX_NUM 500
//���ڴ�С
#define WINDOW_WIDTH 640
#define WINDOW_HIGHT 480
//��Ϸ�����С
#define GAME_WIDTH 640
#define GAME_HIGHT 480



enum DIR //��ʾ�ߵķ���
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};


//�ߵĽṹ
struct Snake 
{
	int size;  //ÿ���ߵĴ�С
	int length;//�ߵĽ���
	int dir;//�ߵķ���
	int speed;//�ߵ��ٶ�
	POINT coor[SNAKE_MAX_NUM];//����
}snake;

//ʳ��Ľṹ
struct Food 
{
	//ʳ�������
	int x;
	int y;
	int r;//ʳ��Ĵ�С
	bool flag;//ʳ���Ƿ񱻳�
	DWORD color;//ʳ�����ɫ
}food;


void SnakeInit() {
	//��ʼ����
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
	//��ʼʳ��
	food.r = snake.size / 2 + 8;
	srand(GetTickCount());//�������������Ϊϵͳ�������������������ĺ�����
	food.x = rand() % (GAME_WIDTH - food.r * 2) + food.r;
	food.y = rand() % (GAME_HIGHT - food.r * 2) + food.r;
	food.color = RED;
	food.flag = true;
}

//��ʼ��
void GameInit() {
	//init ��ʼ�� graph ͼ�δ���
	initgraph(WINDOW_WIDTH, WINDOW_HIGHT,EW_SHOWCONSOLE);
	//��ʼ����Ƶ
	/*mciSendString("open ./a.mp3", 0, 0, 0);
	int k = mciSendString("play ./a.mp3 repeat", 0, 0, 0);
	printf("%d", k);
	system("pause");*/
	//��ʼ����
	SnakeInit();
	//ʳ���ʼ��
	FoodInit();
}

//����
void GameDraw() {
	//˫�����ͼ
	BeginBatchDraw();

	//���ñ�����ɫ
	setbkcolor(RGB(132, 173, 234));
	cleardevice();
	//������
	for (int i = 0; i < snake.length; i++) {
		if(i==0)
			setfillcolor(RED);
		else 
			setfillcolor(YELLOW);
		solidcircle(snake.coor[i].x, snake.coor[i].y, snake.size/2);
	}
	//����ʳ��
	if (food.flag) {
		solidcircle(food.x, food.y, food.r);
	}
	EndBatchDraw();
}

//�ƶ���
void SnakeMove() {
	for (int i = snake.length; i > 0; i--) {
		snake.coor[i] = snake.coor[i - 1];
	}
	switch (snake.dir)
	{
	case UP:
		snake.coor[0].y-= snake.size;
		if (snake.coor[0].y <= 0)//��Խ��
			snake.coor[0].y = GAME_HIGHT - snake.size/2;
		break;
	case DOWN:
		snake.coor[0].y+= snake.size;
		if (snake.coor[0].y >= GAME_HIGHT)//��Խ��
			snake.coor[0].y = 0 + snake.size / 2;
		break;
	case LEFT:
		snake.coor[0].x-= snake.size;
		if (snake.coor[0].x <= 0)//��Խ�� 
			snake.coor[0].x = GAME_WIDTH - snake.size / 2;
		break;
	case RIGHT:
		snake.coor[0].x+= snake.size;
		if (snake.coor[0].x >= GAME_WIDTH)//��Խ��
			snake.coor[0].x = 0 + snake.size / 2;
		break;
	}
}


//ͨ�������ı��ߵķ���
void KeyControl() {
	//�ж��Ƿ��а���
	if (_kbhit()) {   //����0/1
		// 72 80 75 77 �������ҵļ�ֵ
		switch (_getch())
		{
		case 'w':
		case 'W':
		case 72:
			//��������
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


//��ʳ��
void EatFood(int& Score) {
	if (food.flag && snake.coor[0].x  >= food.x-food.r && snake.coor[0].x <= food.x + food.r &&
		snake.coor[0].y >= food.y - food.r && snake.coor[0].y <= food.y + food.r) {
		food.flag = false;
		snake.length++;
		Score++;
	}
	// �����µ�ʳ��
	if (!food.flag)
		FoodInit();
}

//�Ե��Լ�
void EatSelf(int& flag) {
	for (int i = 1; i < snake.length; i++) {
		if (snake.coor[0].x == snake.coor[i].x && snake.coor[0].y == snake.coor[i].y) {
			flag = 0;
			break;
		}
	}
}
//��Ϸ��ͣ
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
		printf("���ĵ÷֣�%d", Score);
		system("cls");
		Sleep(100);
	}
	printf("game over!\n");
	printf("���ĵ÷֣�%d\n", Score);
	system("pause");
	return 0;
}