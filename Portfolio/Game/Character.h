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

	void Input(int, int);
	void Update(DWORD);
	void Draw(HDC);
	void SetStart(Point);

private :
	int move;
	Pos pos1p;
	Pos pos2p;
	bool move_chk;
	bool turn_chk;
	DWORD update_dt;
	DWORD update_delay;
};