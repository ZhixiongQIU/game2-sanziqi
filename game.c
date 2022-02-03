#include "game.h"

//初始化棋盘-空格
void InitBoard(char arr[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisplayBoard(char arr[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			printf("---|---|---\n");
		}
	}
}

//玩家下棋
void Player(char arr[ROW][COL], int row, int col)
{
	printf("玩家走\n");
	int x, y;
	while (1)
	{
		printf("请输入坐标：\n");
		scanf("%d %d", &x, &y);
		if (x > row || y > col || arr[x - 1][y - 1] != ' ')
		{
			printf("输入错误，请重新输入：\n");
		}
		else
		{
			arr[x - 1][y - 1] = '*';
			break;
		}
	}
}

//电脑下棋
void Computer(char arr[ROW][COL], int row, int col)
{
	printf("电脑走\n");
	while (1)
	{
		int x = rand() % row;	//0~2
		int y = rand() % col;	//0~2
		if (arr[x][y] == ' ' && arr[x][y] != '*')
		{
			arr[x][y] = '#';
			break;
		}
	}
}

//判断平局
int IsFull(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;			//仍有空格，棋盘还没满，游戏继续
			}
		}
	}
	return 1;		//遍历棋盘后，没有空格，平局
}

//判断谁赢
char IsWin(char arr[ROW][COL], int row, int col)
{
	//判断三行
	for (int i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ' )
		{
			return arr[i][0];
		}
	}

	//判断三列
	for (int j = 0; j < col; j++)
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] !=  ' ')
		{
			return arr[0][j];
		}
	}

	//判断对角线
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] != ' ')
	{
		return arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] != ' ')
	{
		return arr[1][1];
	}

	//判断平局
	int temp = IsFull(arr,row,col);
	if (temp == 1)
	{
		return 'Q';		//平局
	}

	return 'C';		//游戏继续
	
}
