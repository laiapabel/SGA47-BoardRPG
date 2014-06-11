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

protected :
	void Init();

private :
	DWORD update_dt;
	DWORD update_delay;
	int dice_quantity;
	int dice_type;
	int dice_stop;
	bool play;
	bool stop;
};