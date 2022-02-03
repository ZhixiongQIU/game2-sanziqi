#include "game.h"

void menu()
{
	printf("***********************\n");
	printf("****** 1.��ʼ *********\n");
	printf("****** 0.�˳� *********\n");
	printf("***********************\n");
}

void game()
{
	char arr[ROW][COL];
	char result;	//�ж���Ϸ״̬
	//��ʼ������-�ո�
	InitBoard(arr, ROW, COL);
	//��ӡ����
	DisplayBoard(arr, ROW, COL);
	while (1)
	{
		//�������
		Player(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
		//�ж���Ӯ
		result = IsWin(arr, ROW, COL);
		if (result != 'C')
		{
			break;
		}

		//��������
		Computer(arr,ROW,COL);
		DisplayBoard(arr, ROW, COL);
		//�ж���Ӯ
		result = IsWin(arr, ROW, COL);
		if (result != 'C')
		{
			break;
		}
	}
	if (result == '*')
	{
		printf("���Ӯ�ˣ�\n");
	}
	else if (result == '#')
	{
		printf("����Ӯ�ˣ�\n");
	}
	else if (result == 'Q')
	{
		printf("ƽ�֣�\n");
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		printf("������ѡ�");
		scanf("%d", &input);
		if (input == 1)
		{
			printf("��ʼ��Ϸ\n");
			game();
		}
		else if(input == 0)
		{
			printf("�˳�\n");
			break;
		}
		else
		{
			printf("�����������������\n");
		}
	} while (input);
	return 0;
}