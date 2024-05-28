#include "shape.h"

#include "Player.h"



void shape::printshape()const
{

	gotoxy(p1.getpointx(), p1.getpointy());
	cout << (char)219;
	gotoxy(p2.getpointx(), p2.getpointy());
	cout << (char)219;
	gotoxy(p3.getpointx(), p3.getpointy());
	cout << (char)219;
	gotoxy(p4.getpointx(), p4.getpointy());
	cout << (char)219;
}
void shape::deleteshape()const
{
	gotoxy(p1.getpointx(), p1.getpointy());
	cout << " ";
	gotoxy(p2.getpointx(), p2.getpointy());
	cout << " ";
	gotoxy(p3.getpointx(), p3.getpointy());
	cout << " ";
	gotoxy(p4.getpointx(), p4.getpointy());
	cout << " ";
}
void shape::movement(char input,Player& player,int p)
{

	Point p1cpy = p1;
	Point p2cpy = p2;
	Point p3cpy = p3;
	Point p4cpy = p4;

			Sleep(300);

			p1cpy.setpoint(p1.getpointx(), p1.getpointy() + 1);
			p2cpy.setpoint(p2.getpointx(), p2.getpointy() + 1);
			p3cpy.setpoint(p3.getpointx(), p3.getpointy() + 1);
			p4cpy.setpoint(p4.getpointx(), p4.getpointy() + 1);
			if (player.checkMovement(p1cpy, p2cpy, p3cpy, p4cpy, p) == 1)
			{
				deleteshape();
				p1 = p1cpy;
				p2 = p2cpy;
				p3 = p3cpy;
				p4 = p4cpy;
				printshape();

			}
			else
			{
				player.updateTaken(p1, p2, p3, p4, p);
				player.setNewShape();
				return;

			}


		if (((input == 'x' || input == 'X') && p == 1) || ((input == 'm' || input == 'M') && p == 2))
		{

			p1cpy.setpoint(p1.getpointx(), p1.getpointy() + 1);
			p2cpy.setpoint(p2.getpointx(), p2.getpointy() + 1);
			p3cpy.setpoint(p3.getpointx(), p3.getpointy() + 1);
			p4cpy.setpoint(p4.getpointx(), p4.getpointy() + 1);
			if (player.checkMovement(p1cpy, p2cpy, p3cpy, p4cpy, p) == 1)
			{
				deleteshape();
				p1 = p1cpy;
				p2 = p2cpy;
				p3 = p3cpy;
				p4 = p4cpy;
				printshape();


			}
			else
			{
				player.updateTaken(p1, p2, p3, p4, p);
				player.setNewShape();;
				return;


			}
		}
		if (((input == 'a' || input == 'A')&&p==1) || ((input == 'j' || input == 'J')&&p==2))
		{

			p1cpy.setpoint(p1.getpointx() - 1, p1.getpointy());
			p2cpy.setpoint(p2.getpointx() - 1, p2.getpointy());
			p3cpy.setpoint(p3.getpointx() - 1, p3.getpointy());
			p4cpy.setpoint(p4.getpointx() - 1, p4.getpointy());
			if (player.checkMovement(p1cpy, p2cpy, p3cpy, p4cpy, p) == 1)
			{
				deleteshape();
				p1 = p1cpy;
				p2 = p2cpy;
				p3 = p3cpy;
				p4 = p4cpy;
				printshape();


			}
			else
			{
				player.updateTaken(p1, p2, p3, p4, p);
				player.setNewShape();;
				return;

			}
		}
		if (((input == 'd' || input == 'D') && p == 1) || ((input == 'l' || input == 'L') && p == 2))
		{
			p1cpy.setpoint(p1.getpointx() + 1, p1.getpointy());
			p2cpy.setpoint(p2.getpointx() + 1, p2.getpointy());
			p3cpy.setpoint(p3.getpointx() + 1, p3.getpointy());
			p4cpy.setpoint(p4.getpointx() + 1, p4.getpointy());
			if (player.checkMovement(p1cpy, p2cpy, p3cpy, p4cpy, p) == 1)
			{
				deleteshape();
				p1 = p1cpy;
				p2 = p2cpy;
				p3 = p3cpy;
				p4 = p4cpy;
				printshape();

			}
			else
			{
				player.updateTaken(p1, p2, p3, p4, p);
				player.setNewShape();;
				return;

			}
		}
		if (input == 's' || input == 'S' || input == 'k' || input == 'K')
		{
			

			rotateS(90,player,p);
			
		}
		if (input == 'w' || input == 'W' || input == 'i' || input == 'I')
		{
			
			rotateS(-90, player, p);
		}
	
	
}

void shape::set(const Point& p, int ind)
{

	switch (ind)
	{
	case 1: //square
		this->p1 = p;
		this->p2.setpoint(p.getpointx() + 1, p.getpointy());
		this->p3.setpoint(p.getpointx(), p.getpointy() + 1);
		this->p4.setpoint(p.getpointx() + 1, p.getpointy() + 1);
		break;


	case 2: //right L
		this->p1 = p;
		this->p2.setpoint(p.getpointx(), p.getpointy() + 1);
		this->p3.setpoint(p.getpointx(), p.getpointy() + 2);
		this->p4.setpoint(p.getpointx() + 1, p.getpointy() + 2);
		break;
	case 3: // Left L
		this->p1 = p;
		this->p2.setpoint(p.getpointx(), p.getpointy() + 1);
		this->p3.setpoint(p.getpointx(), p.getpointy() + 2);
		this->p4.setpoint(p.getpointx() -1, p.getpointy() + 2);
		break;


	case 4:

		this->p1 = p;
		this->p2.setpoint(p.getpointx() + 1, p.getpointy());
		this->p3.setpoint(p.getpointx() + 1, p.getpointy() + 1);
		this->p4.setpoint(p.getpointx() + 2, p.getpointy() + 1);
		break;
	case 5:

		this->p1 = p;
		this->p2.setpoint(p.getpointx() + 1, p.getpointy());
		this->p3.setpoint(p.getpointx() + 1, p.getpointy() +1);
		this->p4.setpoint(p.getpointx() + 2, p.getpointy() + 1);
		break;
	case 6:
		this->p1 = p;
		this->p2.setpoint(p.getpointx() + 1, p.getpointy());
		this->p3.setpoint(p.getpointx() + 2, p.getpointy());
		this->p4.setpoint(p.getpointx() + 1, p.getpointy() + 1);
		break;

	case 7:
		this->p1 = p;
		this->p2.setpoint(p.getpointx() , p.getpointy()+1);
		this->p3.setpoint(p.getpointx() , p.getpointy()+2);
		this->p4.setpoint(p.getpointx() , p.getpointy() +3);
		break;;
	}
	

	

}

void shape::rotateS(float angleInDegrees,Player& player,int p)
{
	Point p1cpy = p1;
	Point p2cpy = p2;
	Point p3cpy = p3;
	Point p4cpy = p4;

	// Save the current state of the shape
	float centerX = (p1.getpointx() + p2.getpointx() + p3.getpointx() + p4.getpointx()) / 4.0;
	float centerY = (p1.getpointy() + p2.getpointy() + p3.getpointy() + p4.getpointy()) / 4.0;

	float angleInRadians = angleInDegrees * M_PI / 180.0;
	float cosTheta = cos(angleInRadians);
	float sinTheta = sin(angleInRadians);

	// Rotate each point of the shape around its center
	p1cpy.setpoint((p1.getpointx() - centerX) * cosTheta - (p1.getpointy() - centerY) * sinTheta + centerX,
		(p1.getpointx() - centerX) * sinTheta + (p1.getpointy() - centerY) * cosTheta + centerY);

	p2cpy.setpoint((p2.getpointx() - centerX) * cosTheta - (p2.getpointy() - centerY) * sinTheta + centerX,
		(p2.getpointx() - centerX) * sinTheta + (p2.getpointy() - centerY) * cosTheta + centerY);

	p3cpy.setpoint((p3.getpointx() - centerX) * cosTheta - (p3.getpointy() - centerY) * sinTheta + centerX,
		(p3.getpointx() - centerX) * sinTheta + (p3.getpointy() - centerY) * cosTheta + centerY);

	p4cpy.setpoint((p4.getpointx() - centerX) * cosTheta - (p4.getpointy() - centerY) * sinTheta + centerX,
		(p4.getpointx() - centerX) * sinTheta + (p4.getpointy() - centerY) * cosTheta + centerY);

	if (player.checkMovement(p1cpy, p2cpy, p3cpy, p4cpy, p) == 1)
	{

		deleteshape();
		p1 = p1cpy;
		p2 = p2cpy;
		p3 = p3cpy;
		p4 = p4cpy;
		printshape();


	}
	else
	{
		player.updateTaken(p1, p2, p3, p4, p);
		player.setNewShape();
		return;

	}

}
