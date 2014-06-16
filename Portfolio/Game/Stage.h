#pragma once

#include "Map.h"
#include "Character.h"
#include "Turn.h"

class STAGE
{
public :
	STAGE();
	~STAGE();

	void Input(DWORD);
	void Update(DWORD);
	void Draw(HDC);

	void Enter();

private :
	MAP Map;
	TURN Turn;
	CHARACTER Char;
	bool start_chk;
};