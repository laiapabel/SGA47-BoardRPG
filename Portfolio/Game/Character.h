#pragma once

#include "../GameDev/GameDev.h"

struct Pos
{
	Point pos;
	int dest;
};

class CHARACTER
{
public :
	CHARACTER();
	~CHARACTER();

	void Input(Point, int);
	void Update(DWORD);
	void Draw(HDC);

private :
	Pos pos1p;
	Pos pos2p;
	DWORD update_dt;
	DWORD update_delay;
};