#include "Game.h"
#include <iostream>
#include <windows.h> 
#include <conio.h>
using namespace std;

#define MAX 15

int row = 0; // 행
int column = 0; // 열
int turn = 1; // 턴 세는 정수
int winNum = 0; // 백돌이 이기면 1, 흑돌이 이기면 2
int temp = 224; // 방향키 arrow

string board[15][15] = {}; // 돌 정보를 넣는 2차원 배열


// 커서 이동
void gotoxy(int x, int y)
{ 
	COORD Cur = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur); 
}

// 오목판 깔기
void SetBoard()
{
	for (int i = 0; i < MAX; i++)
	{
		cout << "┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼" << endl;
	}
}

// 흑돌, 백돌 턴 교체
void ChangeTurn()
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

// 5개 돌 이어졌나 확인
bool IsGameOver() // row : 행   column : 열
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
		
			// 백돌 가로
			if (board[i][j] == "○" && board[i + 1][j] == "○" && board[i + 2][j] == "○" && board[i + 3][j] == "○" && board[i + 4][j] == "○")
			{

				if (i == 0 || i + 4 == MAX)
				{
					winNum = 1;
					return true;
				}

				if ((board[i - 1][j] != "○") || (board[i + 5][j] != "○"))
				{
					winNum = 1;
					return true;
				}
				
			}


			// 백돌 세로
			if (board[i][j] == "○" && board[i][j + 1] == "○" && board[i][j + 2] == "○" && board[i][j + 3] == "○" && board[i][j + 4] == "○")
			{
				if (j == 0 || j + 4 == MAX)
				{
					winNum = 1;
					return true;
				}

				if ((board[i][j - 1] != "○") || (board[i][j + 5] != "○"))
				{
					winNum = 1;
					return true;
				}
			}

			// 백돌 ↗
			if (board[i][j] == "○" && board[i - 1][j + 1] == "○" && board[i - 2][j + 2] == "○" && board[i - 3][j + 3] == "○" && board[i - 4][j + 4] == "○")
			{
				if (i == 0 && j == MAX  || i-4 == MAX && j + 4 == 0)
				{
					winNum = 1;
					return true;
				}

				if (board[i + 1][j - 1] != "○" && board[i - 5][j + 5] != "○")
				{
					winNum = 1;
					return true;
				}
			}

			// 백돌 ↖
			if (board[i][j] == "○" && board[i + 1][j + 1] == "○" && board[i + 2][j + 2] == "○" && board[i + 3][j + 3] == "○" && board[i + 4][j + 4] == "○")
			{
				if (i == 0 && j == 0 || i + 4 == MAX && j + 4 == MAX)
				{
					winNum = 1;
					return true;
				}

				if (board[i-1][j - 1] != "○" && board[i+5][j + 5] != "○")
				{
					winNum = 1;
					return true;
				}
			}


			// 가로
			if (board[i][j] == "●" && board[i + 1][j] == "●" && board[i + 2][j] == "●" && board[i + 3][j] == "●" && board[i + 4][j] == "●")
			{
				if (i == 0 || i + 4 == MAX)
				{
					winNum = 2;
					return true;
				}

				if ((board[i - 1][j] != "●") || (board[i + 5][j] != "●"))
				{
					winNum = 2;
					return true;
				}
			}

			//세로
			if (board[i][j] == "●" && board[i][j + 1] == "●" && board[i][j + 2] == "●" && board[i][j + 3] == "●" && board[i][j + 4] == "●")
			{
				if (j == 0 || j + 4 == MAX)
				{
					winNum = 2;
					return true;
				}

				if ((board[i][j - 1] != "●") || (board[i][j + 5] != "●"))
				{
					winNum = 2;
					return true;
				}
			}

			//흑돌 ↗
			if (board[i][j] == "●" && board[i - 1][j + 1] == "●" && board[i - 2][j + 2] == "●" && board[i - 3][j + 3] == "●" && board[i - 4][j + 4] == "●")
			{
				if (i == 0 && j == MAX || i - 4 == MAX && j + 4 == 0)
				{
					winNum = 2;
					return true;
				}

				if (board[i + 1][j - 1] != "●" && board[i - 5][j + 5] != "●")
				{
					winNum = 2;
					return true;
				}
			}

			//  흑돌 ↖
			if (board[i][j] == "●" && board[i + 1][j + 1] == "●" && board[i + 2][j + 2] == "●" && board[i + 3][j + 3] == "●" && board[i + 4][j + 4] == "●")
			{
				if (i == 0 && j == 0 || i + 4 == MAX && j + 4 == MAX)
				{
					winNum = 2;
					return true;
				}

				if (board[i - 1][j - 1] != "●" && board[i + 5][j + 5] != "●")
				{
					winNum = 2;
					return true;
				}
			}

		}
	}

	return false;
	
} // 5개 

// 바둑돌 차례 출력
void PrintTurn()
{
	gotoxy(20, 0);
	if (turn % 2 == 1)
	{
		cout << "흑돌 차례" << endl;
	}
	else
	{
		cout << "백돌 차례" << endl;
	}
	gotoxy(column, row);
}

// 바둑돌 차례 지우기
void EraseTurn()
{
	gotoxy(20, 0);
	cout << "        " << endl;
}

// 바둑돌 승자 출력
void PrintWinner()
{
	gotoxy(0, 18);

	if (winNum == 1)
	{
		cout << "흑돌이 이겼습니다!" << endl;
	}

	else if (winNum == 2)
	{
		cout << "백돌이 이겼습니다!" << endl;
	}
}





int main()
{
	SetBoard();
	gotoxy(column, row);

	// IsGameOver가 true 되면 while문이 false가 되어 루프 나간다.
	while (!IsGameOver())
	{
		PrintTurn();

		temp = _getch();


		if (temp == 224)
		{
			temp = _getch();


			switch (temp)
			{

			case 72: // 위
				row--;
				if (column < 0 || row < 0 || column >= MAX || row >= MAX)
				{
					row++;
					continue;
				}
				break;

			case 80: // 아래
				row++;
				if (column < 0 || row < 0 || column >= MAX || row >= MAX)
				{
					row--;
					continue;
				}
				break;

			case 75: // 왼쪽
				column--;
				if (column < 0 || row < 0 || column >= MAX || row >= MAX)
				{
					column++;
					continue;
				}
				break;

			case 77: // 오른쪽
				column++;
				if (column < 0 || row < 0 || column >= MAX || row >= MAX)
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

	EraseTurn();
	PrintWinner();
	
	system("pause");
	
	return 0;
}