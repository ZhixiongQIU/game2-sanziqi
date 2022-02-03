#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//��ʼ������-�ո�
void InitBoard(char arr[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char arr[ROW][COL], int row, int col);

//�������
void Player(char arr[ROW][COL], int row, int col);

//��������
void Computer(char arr[ROW][COL], int row, int col);

//�ж�˭Ӯ
char IsWin(char arr[ROW][COL], int row, int col);