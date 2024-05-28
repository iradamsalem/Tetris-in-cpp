#pragma once
class Point
{
private:
	float x, y;
	int istaken = 0;
public:
	void setpoint(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	float getpointx()const
	{
		return x;
	
	}
	float getpointy()const
	{
		return y;

	}
	int getisTaken()const
	{
		

			return istaken;
		

	}
	void updatePointstatus()
	{

		if (this->istaken == 0)
		{
			this->istaken = 1;

		}
		else
		{
			this->istaken = 0;

		}


	}


};

