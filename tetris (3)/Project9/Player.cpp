
#include "Player.h"
#include"game.h"




void Player::printBoard(int p)
{
	gotoxy(40, 3);
	cout << "press escape to pause the game";
	gotoxy(42, 6);
	cout << "  V       V   SSSSSS   " << endl;
	gotoxy(42, 7);
	cout << "   V     V   S        " << endl;
	gotoxy(42, 8);
	cout << "    V   V     SSSSS   " << endl;
	gotoxy(42, 9);
	cout << "     V V            S  " << endl;
	gotoxy(42, 10);
	cout << "      V       S      S " << endl;
	gotoxy(42, 11);
	cout << "      V        SSSSS   " << endl;



	if (p == 1)
	{
		for (int col = MIN_X; col < GAME_WIDTH + MIN_X; col++)
		{

			for (int i = 0; i < GAME_HEIGHT; i++)
			{
				board[i][col - 10].setpoint(col, i + MIN_Y);



			}

			gotoxy(col, MIN_Y - 1);
			cout << "-";

			gotoxy(col, GAME_HEIGHT + MIN_Y);
			cout << "-";
		}

		for (int row = MIN_Y - 1; row <= GAME_HEIGHT + MIN_Y; row++)
		{
			gotoxy(MIN_X - 1, row);
			cout << "|";

			gotoxy(GAME_WIDTH + MIN_X, row);
			cout << "|";
		}
	}
	if (p == 2)
	{

		for (int col = MIN_X + 70; col < GAME_WIDTH + MIN_X + 70; col++)
		{

			for (int i = 0; i < GAME_HEIGHT; i++)
			{
				board[i][col - 80].setpoint(col, i + MIN_Y);

			}

			gotoxy(col, MIN_Y - 1);
			cout << "-";


			gotoxy(col, GAME_HEIGHT + MIN_Y);
			cout << "-";

		}


		for (int row = MIN_Y - 1; row <= GAME_HEIGHT + MIN_Y; row++)
		{
			gotoxy(MIN_X + 70 - 1, row);
			cout << "|";

			gotoxy(GAME_WIDTH + MIN_X + 70, row);
			cout << "|";
		}
	}

	for (int i = 0; i < 20; i++)
		board[i][12].updatePointstatus();



}

int Player::checkMovement(const Point& p1, const Point& p2, const Point& p3, const Point& p4, int player)
{
	int x=10;

	if (player == 2)
		x += 70;

	if (board[(int)p1.getpointx() - x][(int)p1.getpointy()-3].getisTaken() != 0)
		return 0;
	if (board[(int)p2.getpointx()-x][(int)p2.getpointy()-3].getisTaken() != 0)
		return 0;
	if (board[(int)p3.getpointx()-x][(int)p3.getpointy()-3].getisTaken() != 0)
		return 0;
	if (board[(int)p4.getpointx()-x][(int)p4.getpointy()-3].getisTaken() != 0)
		return 0;

	return 1;
	
	
}

void Player::updateTaken(const Point& p1, const Point& p2, const Point& p3, const Point& p4,int player)
{
	int x=0;
	if (player == 1)
		x = 10;
	if (player == 2)
		x = 80;
	board[(int)p1.getpointx() - x][(int)p1.getpointy() - 3].updatePointstatus();
	board[(int)p2.getpointx() - x][(int)p2.getpointy() - 3].updatePointstatus();
	board[(int)p3.getpointx() - x][(int)p3.getpointy() - 3].updatePointstatus();
	board[(int)p4.getpointx() - x][(int)p4.getpointy() - 3].updatePointstatus();
	setscore();
	


}

void Player::printLastBoard(int p)
{

	gotoxy(40, 3);
	cout << "press escape to pause the game";
	gotoxy(42, 6);
	cout << "  V       V   SSSSSS   " << endl;
	gotoxy(42, 7);
	cout << "   V     V   S        " << endl;
	gotoxy(42, 8);
	cout << "    V   V     SSSSS   " << endl;
	gotoxy(42, 9);
	cout << "     V V            S  " << endl;
	gotoxy(42, 10);
	cout << "      V       S      S " << endl;
	gotoxy(42, 11);
	cout << "      V        SSSSS   " << endl;


	if (p == 1)
	{
		for (int col = MIN_X; col < GAME_WIDTH + MIN_X; col++)
		{


			gotoxy(col, MIN_Y - 1);
			cout << "-";

			gotoxy(col, GAME_HEIGHT + MIN_Y);
			cout << "-";
		}

		for (int row = MIN_Y - 1; row <= GAME_HEIGHT + MIN_Y; row++)
		{
			gotoxy(MIN_X - 1, row);
			cout << "|";

			gotoxy(GAME_WIDTH + MIN_X, row);
			cout << "|";
		}
	}
	if (p == 2)
	{

		for (int col = MIN_X + 70; col < GAME_WIDTH + MIN_X + 70; col++)
		{

			gotoxy(col, MIN_Y - 1);
			cout << "-";


			gotoxy(col, GAME_HEIGHT + MIN_Y);
			cout << "-";

		}


		for (int row = MIN_Y - 1; row <= GAME_HEIGHT + MIN_Y; row++)
		{
			gotoxy(MIN_X + 70 - 1, row);
			cout << "|";

			gotoxy(GAME_WIDTH + MIN_X + 70, row);
			cout << "|";
		}
	}

	for (int row =0 ; row < 20; row++)
	{

		for (int col = 0; col < 12; col++)
		{
			if (board[row][col].getisTaken() == 1)
			{
				if (p == 1)
				{
					gotoxy(row + 10, col + 3);
					

				}
				if (p == 2)
				{
					gotoxy(row + 80, col + 3);
				}

				cout << (char)219;

			}


		}

	}

	
}
void Player::setBoard()
{

	for (int i = 0; i < 14; i++)
		this->board[i][12].updatePointstatus();

}
void Player:: setNewShape()
{
	if (newshape == 0)
		newshape = 1;
	else
		newshape = 0;
}
int Player::getNewShape()const
{
	return newshape;
}
void Player::setfirstpoint(int p)
{
	if (p == 1)
		firstpoint.setpoint(P1_FIRST_POINT_X, P1_FIRST_POINT_Y);

	if (p == 2)
		firstpoint.setpoint(P2_FIRST_POINT_X, P2_FIRST_POINT_Y);

}
int Player::checkGameOver()const
{
	for (int i = 0; i < 20; i++)
	{
		if (board[i][1].getisTaken() == 1)
			return 1;
	}
	return 0;

}
Point Player:: getpoint()const
{
	return firstpoint;


}
void Player::set(const Point& p)
{
	indextobegin = p;
}

void Player::resetBoard()
{
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 14; j++)
			if (board[i][j].getisTaken() == 1)
				board[i][j].updatePointstatus();


}