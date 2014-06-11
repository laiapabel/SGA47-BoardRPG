#include "Stage.h"

STAGE::STAGE()
	: first_chk(true)
{
}

STAGE::~STAGE()
{
	Map.DelImage();
}

void STAGE::Input(DWORD)
{
}

void STAGE::Update(DWORD tick)
{
	Char.Update(tick);
	Map.Update(tick);
}

void STAGE::Draw(HDC hdc)
{
	Map.Draw(hdc);

	Point pos = Map.GetStart();

	Char.Input(pos, 1);
	Char.Input(pos, 2);

	Char.Draw(hdc);
}

void STAGE::Enter()
{
	Map.SetImage();
}
