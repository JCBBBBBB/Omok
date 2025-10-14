#include "Game.h"
#include <iostream>
#include <windows.h> 
#include <conio.h>
using namespace std;

int row = 0; // 행
int column = 0; // 열
string board[15][15] = {};


enum class Direction
{
	UP = VK_UP,
	DOWN = VK_DOWN,
	LEFT = VK_LEFT,
	RIGHT = VK_RIGHT,
};

void gotoxy(int x, int y) 
{ 
	COORD Cur = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur); 
}

void SetBoard()
{
	for (int i = 0; i < 15; i++)
	{
		cout << "┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼" << endl;
	}
}



int main()
{
	SetBoard();
	gotoxy(column, row);

	int temp = 224;

	while (true)
	{
		temp = _getch();

		if (temp == 224)
		{
			temp = _getch();

			switch (temp)
			{
			case 72:
				row--;
				break;
			case 80:
				row++;
				break;
			case 75:
				column--;
				break;
			case 77:
				column++;
				break;
			}
		}

		gotoxy(column, row);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			board[column][row] = "○";     //●
			cout << board[column][row];
		}

	}

	return 0;
}