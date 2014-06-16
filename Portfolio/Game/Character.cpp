#include "Character.h"
#include "Map.h"

CHARACTER::CHARACTER()
 : update_dt(0), update_delay(3000)
{
	pos1p.pos.x = pos1p.pos.y = 0;
	pos2p.pos.x = pos2p.pos.y = 0;

	pos1p.dest = 0;
	pos2p.dest = 0;
}
CHARACTER::~CHARACTER()
{
}

void CHARACTER::Input(Point pt, int user)
{
	// 1p, 2p 유저 구분
	if (user == 1)
		pos1p.pos = pt;
	else 
		pos2p.pos = pt;

	// 캐릭터 최종 위치
	AniDepot["char1f"]->SetPosition(pos1p.pos);
	AniDepot["char2f"]->SetPosition(pos2p.pos);
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