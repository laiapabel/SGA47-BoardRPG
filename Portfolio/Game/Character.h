#pragma once

#include "../GameDev/GameDev.h"

class CHARACTER
{
public :
	CHARACTER();
	~CHARACTER();

	void Input(Point, int);
	void Update(DWORD);
	void Draw(HDC);

private :
	DWORD update_dt;
	DWORD update_delay;
};