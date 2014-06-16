#include "Stage.h"

STAGE::STAGE()
	: start_chk(true)
{
}

STAGE::~STAGE()
{
	Map.DelImage();
}

void STAGE::Input(DWORD tick)
{
	if (Turn.GetTurn() == 1)
		Turn.Input(1);
	else
		Turn.Input(2);
}

void STAGE::Update(DWORD tick)
{
	Char.Update(tick);
	Map.Update(tick);
	Turn.Update(tick);
}

void STAGE::Draw(HDC hdc)
{
	Map.Draw(hdc);

	if (start_chk)
	{
		Point start_pos = Map.GetStart();

		Char.Input(start_pos, 1);
		Char.Input(start_pos, 2);

		start_chk = false;
	}

	Char.Draw(hdc);

	Turn.Draw(hdc);
}

void STAGE::Enter()
{
	Map.SetImage();
}
