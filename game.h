#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//初始化棋盘-空格
void InitBoard(char arr[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char arr[ROW][COL], int row, int col);

//玩家下棋
void Player(char arr[ROW][COL], int row, int col);

//电脑下棋
void Computer(char arr[ROW][COL], int row, int col);

//判断谁赢
char IsWin(char arr[ROW][COL], int row, int col);