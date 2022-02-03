#include "game.h"

void menu()
{
	printf("***********************\n");
	printf("****** 1.开始 *********\n");
	printf("****** 0.退出 *********\n");
	printf("***********************\n");
}

void game()
{
	char arr[ROW][COL];
	char result;	//判断游戏状态
	//初始化棋盘-空格
	InitBoard(arr, ROW, COL);
	//打印棋盘
	DisplayBoard(arr, ROW, COL);
	while (1)
	{
		//玩家下棋
		Player(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
		//判断输赢
		result = IsWin(arr, ROW, COL);
		if (result != 'C')
		{
			break;
		}

		//电脑下棋
		Computer(arr,ROW,COL);
		DisplayBoard(arr, ROW, COL);
		//判断输赢
		result = IsWin(arr, ROW, COL);
		if (result != 'C')
		{
			break;
		}
	}
	if (result == '*')
	{
		printf("玩家赢了！\n");
	}
	else if (result == '#')
	{
		printf("电脑赢了！\n");
	}
	else if (result == 'Q')
	{
		printf("平局！\n");
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		printf("请输入选项：");
		scanf("%d", &input);
		if (input == 1)
		{
			printf("开始游戏\n");
			game();
		}
		else if(input == 0)
		{
			printf("退出\n");
			break;
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	} while (input);
	return 0;
}