#pragma once

#include "Map.h"
#include "Character.h"

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
	CHARACTER Char;
	bool first_chk;
};