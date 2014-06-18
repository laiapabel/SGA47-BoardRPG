#pragma once

#include "Map.h"
#include "Character.h"
#include "Turn.h"

class STAGE
{
public :
	STAGE();
	~STAGE();

	void Input(int);
	void Update(DWORD);
	void Draw(HDC);
	void SetTurn();

	void Enter();

private :
	MAP Map;
	TURN Turn;
	CHARACTER Char;
	DWORD update_delay;
	DWORD update_dt;
	bool start_chk;
	bool turn_chk;
};