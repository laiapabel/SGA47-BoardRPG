#include "Stage.h"

STAGE::STAGE()
	: update_dt(0), update_delay(200)
	, start_chk(true), turn_chk(true)
{
}

STAGE::~STAGE()
{
	Map.DelImage();
}

void STAGE::Input(int key)
{
	Turn.Input(key);
	Char.Input(Turn.GetTurn(), key);
}

void STAGE::Update(DWORD tick)
{
	Map.Update(tick);
	Turn.Update(tick);

	if (update_dt > update_delay)
	{
		update_dt %= update_delay;
		Char.Update(tick);
	}
	update_dt += tick;
}

void STAGE::Draw(HDC hdc)
{
	Map.Draw(hdc);

	if (start_chk)
	{
		Point start_pos = Map.GetStart();

		Char.SetStart(start_pos);

		start_chk = false;
	}

	Char.Draw(hdc);

	Turn.Draw(hdc);
}

void STAGE::Enter()
{
	Map.SetImage();
}

void STAGE::SetTurn()
{
	turn_chk = !turn_chk;
}
