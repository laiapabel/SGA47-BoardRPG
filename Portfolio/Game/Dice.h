#pragma once

#include "../GameDev/GameDev.h"
#include <cstdlib>
#include <ctime>

class DICE
{
public :
	DICE();
	~DICE();

	void Input(int);
	void Update(DWORD);
	void Draw(HDC);
	int GetDice();

private :
	DWORD update_dt;
	DWORD update_delay;
	int dice_quantity;
	int dice_stop;
	int dice_num;
	bool play;
	bool stop;
};