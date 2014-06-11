#include "Character.h"
#include "Map.h"

CHARACTER::CHARACTER()
 : update_dt(0), update_delay(3000)
{
}
CHARACTER::~CHARACTER()
{
}

void CHARACTER::Input(Point pt, int user)
{
	if (user == 1)
		AniDepot["char1f"]->SetPosition(pt);
	else 
		AniDepot["char2f"]->SetPosition(pt);
}
void CHARACTER::Update(DWORD tick)
{
	AniDepot["char1f"]->Update(tick);
	AniDepot["char2f"]->Update(tick);
}
void CHARACTER::Draw(HDC hdc)
{
	AniDepot["char1f"]->Draw(hdc);
	AniDepot["char2f"]->Draw(hdc);
}