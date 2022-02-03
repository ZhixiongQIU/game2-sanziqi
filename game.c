#include "game.h"

//��ʼ������-�ո�
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

//��ӡ����
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

//�������
void Player(char arr[ROW][COL], int row, int col)
{
	printf("�����\n");
	int x, y;
	while (1)
	{
		printf("���������꣺\n");
		scanf("%d %d", &x, &y);
		if (x > row || y > col || arr[x - 1][y - 1] != ' ')
		{
			printf("����������������룺\n");
		}
		else
		{
			arr[x - 1][y - 1] = '*';
			break;
		}
	}
}

//��������
void Computer(char arr[ROW][COL], int row, int col)
{
	printf("������\n");
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

//�ж�ƽ��
int IsFull(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;			//���пո����̻�û������Ϸ����
			}
		}
	}
	return 1;		//�������̺�û�пո�ƽ��
}

//�ж�˭Ӯ
char IsWin(char arr[ROW][COL], int row, int col)
{
	//�ж�����
	for (int i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ' )
		{
			return arr[i][0];
		}
	}

	//�ж�����
	for (int j = 0; j < col; j++)
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] !=  ' ')
		{
			return arr[0][j];
		}
	}

	//�ж϶Խ���
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] != ' ')
	{
		return arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] != ' ')
	{
		return arr[1][1];
	}

	//�ж�ƽ��
	int temp = IsFull(arr,row,col);
	if (temp == 1)
	{
		return 'Q';		//ƽ��
	}

	return 'C';		//��Ϸ����
	
}
