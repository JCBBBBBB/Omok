#include "Game.h"
#include <iostream>
#include <windows.h> 
#include <conio.h>
using namespace std;

#define MAX 15

int row = 0; // 행
int column = 0; // 열
int turn = 1;
string board[15][15] = {};

int temp = 224; // 방향키 arrow


void gotoxy(int x, int y) 
{ 
	COORD Cur = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur); 
}

void SetBoard()
{
	for (int i = 0; i < MAX; i++)
	{
		cout << "┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼" << endl;
	}
}

void ChangeTurn() // 흑돌, 백돌 턴 교체
{
	if ((turn % 2 == 1) && board[column][row].empty())
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			board[column][row] = "○";     //●
			cout << board[column][row];
			turn++;
		}
	}
	else if ((turn % 2 == 0) && board[column][row].empty())
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			board[column][row] = "●";     //●
			cout << board[column][row];
			turn++;
		}
	}

	gotoxy(column, row);
}

bool isGameOver() // row : 행   column : 열
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			// 가로
			if (board[i][j] == "○" && board[i + 1][j] == "○" && board[i + 2][j] == "○" && board[i + 3][j] == "○" && board[i + 4][j] == "○")
			{
				return true;
			}

			//세로
			if (board[i][j] == "○" && board[i][j + 1] == "○" && board[i][j + 2] == "○" && board[i][j + 3] == "○" && board[i][j + 4] == "○")
			{
				return true;
			}

			//왼 아래 대각
			if (board[i][j] == "○" && board[i - 1][j + 1] == "○" && board[i - 2][j + 2] == "○" && board[i - 3][j + 3] == "○" && board[i - 4][j + 4] == "○")
			{
				return true;
			}

			// 오른 아래 대각
			if (board[i][j] == "○" && board[i + 1][j + 1] == "○" && board[i + 2][j + 2] == "○" && board[i + 3][j + 3] == "○" && board[i + 4][j + 4] == "○")
			{
				return true;
			}

			// 왼 위 대각
			if (board[i][j] == "○" && board[i - 1][j - 1] == "○" && board[i - 2][j - 2] == "○" && board[i - 3][j - 3] == "○" && board[i - 4][j - 4] == "○")
			{
				return true;
			}

			//오른 위 대각
			if (board[i][j] == "○" && board[i + 1][j - 1] == "○" && board[i + 2][j - 2] == "○" && board[i + 3][j - 3] == "○" && board[i + 4][j - 4] == "○")
			{
				return true;
			}

			// 가로
			if (board[i][j] == "●" && board[i + 1][j] == "●" && board[i + 2][j] == "●" && board[i + 3][j] == "●" && board[i + 4][j] == "●")
			{
				return true;
			}

			//세로
			if (board[i][j] == "●" && board[i][j + 1] == "●" && board[i][j + 2] == "●" && board[i][j + 3] == "●" && board[i][j + 4] == "●")
			{
				return true;
			}

			//왼 아래 대각
			if (board[i][j] == "●" && board[i - 1][j + 1] == "●" && board[i - 2][j + 2] == "●" && board[i - 3][j + 3] == "●" && board[i - 4][j + 4] == "●")
			{
				return true;
			}

			// 오른 아래 대각
			if (board[i][j] == "●" && board[i + 1][j + 1] == "●" && board[i + 2][j + 2] == "●" && board[i + 3][j + 3] == "●" && board[i + 4][j + 4] == "●")
			{
				return true;
			}

			// 왼 위 대각
			if (board[i][j] == "●" && board[i - 1][j - 1] == "●" && board[i - 2][j - 2] == "●" && board[i - 3][j - 3] == "●" && board[i - 4][j - 4] == "●")
			{
				return true;
			}

			//오른 위 대각
			if (board[i][j] == "●" && board[i + 1][j - 1] == "●" && board[i + 2][j - 2] == "●" && board[i + 3][j - 3] == "●" && board[i + 4][j - 4] == "●")
			{
				return true;
			}
		}
	}

	return false;
	
}

int main()
{
	SetBoard();
	gotoxy(column, row);

	

	while (true && !isGameOver()) // false 되면 break
	{
		temp = _getch();


		if (temp == 224)
		{
			temp = _getch();


			switch (temp)
			{

			case 72: // 위
				row--;
				if (!board[column][row].empty() || column < 0 || row < 0 || column >= MAX || row >= MAX)
				{
					row++;
					continue;
				}
				break;

			case 80: // 아래
				row++;
				if (!board[column][row].empty() || column < 0 || row < 0 || column >= MAX || row >= MAX)
				{
					row--;
					continue;
				}
				break;

			case 75: // 왼쪽
				column--;
				if (!board[column][row].empty() || column < 0 || row < 0 || column >= MAX || row >= MAX)
				{
					column++;
					continue;
				}
				break;

			case 77: // 오른쪽
				column++;
				if (!board[column][row].empty() || column < 0 || row < 0 || column >= MAX || row >= MAX)
				{
					column--;
					continue;
				}
				break;
			}
			
		}

		gotoxy(column, row);
		ChangeTurn();

	}

	gotoxy(0, 20);
	system("pause");
	return 0;
}