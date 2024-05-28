#include "game.h"

using namespace std;


void printInstructions()
{
	system("cls");

	
	cout << "Welcome to Two-Player Tetris!" << endl << endl;

	cout << "Player 1 Controls:" << endl;
	cout << "  Move Left:  A or a" << endl;
	cout << "  Move Right: D or d" << endl;
	cout << "  ROTATE clockwise:     S or s" << endl;
	cout << "  ROTATE counterclockwise:     W or w" << endl; 
	cout << "  Drop:       X or x" << endl << endl;
	
	cout << "Player 2 Controls:" << endl;
	cout << "  Move Left:  J or j" << endl;
	cout << "  Move Right: L or l" << endl;
	cout << "  ROTATE clockwise:     K or k" << endl;
	cout << "  ROTATE counterclockwise:     I or i" << endl;
	cout << "  Drop:       M or m" << endl << endl;
	
	cout << "Game Rules:" << endl;
	cout << "  - The goal is to complete horizontal lines with falling Tetriminos." << endl;
	cout << "  - Each completed line scores points." << endl;
	cout << "  - The game ends if the Tetriminos reach the top of the playfield." << endl;
	cout << "  - the player with the highest score wins." << endl << endl;
	

	cout << "Press any key to start/continue the game" << endl;
	
	_getch();
	system("cls");
}
void printMenu()
{
	
	
	cout << "choose option" << endl;

	cout << "(1) Start a new game" << endl;
	
	cout << "(2) Continue a paused game" << endl;
	
	cout << "(3) ADD COLOR" << endl;
	cout << "(4) REMOVE COLOR" << endl;
	cout << "(8) Present instructions and keys" << endl;
	
	cout << "(9) EXIT" << endl;
	

}
void startGame()
{
	int check = 0;
	menu(check);
	if (check == 2)
		return;
	srand(static_cast<unsigned int>(time(nullptr)));

	Player p1, p2;

	p1.setfirstpoint(1);
	p2.setfirstpoint(2);
	p1.printBoard(1);
	p2.printBoard(2);



	shape square1, square2;


	int randomNum = rand() % 7 + 1;
	square2.set(p2.getpoint(), randomNum);

	randomNum = rand() % 7 + 1;
	square1.set(p1.getpoint(), randomNum);
	char pressed = 0;
	while (true)
	{




		if (_kbhit())
		{
			pressed = _getch();	

		}
		if (pressed == 27)
		{
			system("cls");
			menu(check);
			if (check == 2)
				break;
			if (check == 3)
			{
				p1.resetBoard();
				p2.resetBoard();
				
				p1.printBoard(1);
				p2.printBoard(2);
				randomNum = rand() % 7 + 1;
				square2.set(p2.getpoint(), randomNum);

				randomNum = rand() % 7 + 1;
				square1.set(p1.getpoint(), randomNum);
				check = 0;
			}
			if (check == 4)
			{
				p1.printLastBoard(1);
				p2.printLastBoard(2);
				check = 0;
			}
			
			

		}
			if (isPlayer(pressed) == 1)
				square1.movement(pressed, p1, 1);
			else if (isPlayer(pressed) == 2)
				square2.movement(pressed, p2, 2);
			else 
			{
				pressed = 0;
				square1.movement(pressed, p1, 1);
				square2.movement(pressed, p2, 2);
			}

			

			pressed = 0;
			if (p1.getNewShape() == 1)
			{
				randomNum = rand() % 7 + 1;
				square1.set(p1.getpoint(), randomNum);

				p1.setNewShape();
			}
			if (p2.getNewShape() == 1)
			{
				randomNum = rand() % 7 + 1;
				square2.set(p2.getpoint(), randomNum);
				
				p2.setNewShape();
			}

			if (p1.checkGameOver() == 1 || p2.checkGameOver() == 1)
			{
				system("cls");
				cout << "Game Over"<<endl;
				cout <<"p1 score is:"<< p1.getscore()<<endl;
				cout << "p2 score is:"<<p2.getscore()<<endl;
				if (p1.getscore() > p2.getscore())
				{
					cout << "p1 wins";
				}
				else if (p1.getscore() < p2.getscore())
				{
					cout << "p2 wins";
				}
				else
				{
					cout << "tie";
				}

				break;
		}
	}



}

void menu(int& check)
{
	printMenu();
	int flag = 1;

	while (flag)
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		int randomcolor = rand() % 4 + 1;
		if (_kbhit())
		{

			char pressed = _getch();
			

			switch (pressed) {
			case '1':
				system("cls");
				check = 3;
				return;
				break;

			case '2':
				system("cls");
				check = 4;
				return;


				break;
			case '3':
				system("cls");
				switch (randomcolor)
				{
				case 1:
					cout << YELLOW_COLOR;
					break;
				case 2:
					cout << GREEN_COLOR;
					break;
				case 3:
					cout << BLUE_COLOR;
					break;
				case 4:
					cout << RED_COLOR;
					break;
				default:
					break;
				}
				printMenu();
				break;

			case '4':
				system("cls");
				cout << RESET_COLOR;
				printMenu();
				break;

			case '8':
				printInstructions();
				check = 4;
				return;


			case '9':

				system("cls");
				check = 2;
				cout << "finito la comedia";
				flag = 0;
				break;

			default:

				break;
			}


		}
	}

}


void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

int searchPointInBoard(Player player,Point point)
{
	int x = point.getpointx();
	int y= point.getpointy();
	int row = 15 - x;
	int col=10- y;
	return 1;
}

int isPlayer(char pressed)
{
	if (pressed == 'x' || pressed == 'X' || pressed == 'a' || pressed == 'A' || pressed == 'd' ||
		pressed == 'D' || pressed == 's' || pressed == 'S' || pressed == 'w' || pressed == 'W')
		return 1;
	else if (pressed == 'j' || pressed == 'J' || pressed == 'i' || pressed == 'I' || pressed == 'l' ||
		pressed == 'L' || pressed == 'k' || pressed == 'K' || pressed == 'm' || pressed == 'M')
		return 2;
	else return 3;
}