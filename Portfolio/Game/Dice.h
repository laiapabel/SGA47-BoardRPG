#pragma once

#include "../GameDev/GameDev.h"
#include <cstdlib>
#include <ctime>

class DICE : public Object
{
public :
	DICE();
	~DICE();

	void Input(DWORD);
	void Update(DWORD);
	void Draw(HDC);
	int GetDice();

private :
	DWORD update_dt;
	DWORD update_delay;
	int dice_quantity;
	int dice_stop;
	bool play;
	bool stop;
};