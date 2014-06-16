#pragma once

#include "../GameDev/GameDev.h"
#include "Dice.h"

class TURN
{
public :
	TURN();
	~TURN();

	void Input(int);
	void Update(DWORD);
	void Draw(HDC);
	int GetTurn();

private :
	int turn;
	int dice_cnt;
	bool turn_chk;
	DICE* Dice;
	DWORD update_dt;
	DWORD update_delay;
};