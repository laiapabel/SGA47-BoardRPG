#include "Character.h"
#include "Map.h"

CHARACTER::CHARACTER()
 : update_dt(0), update_delay(500)
 , move(0)
 , move_chk(true), turn_chk(true)
{
	pos1p.pos.x = pos1p.pos.y = 0;
	pos2p.pos.x = pos2p.pos.y = 0;

	pos1p.dest = 0;
	pos2p.dest = 0;
}
CHARACTER::~CHARACTER()
{
}

void CHARACTER::SetStart(Point pt)
{
	pos1p.pos = pt-55;
	pos2p.pos = pt-20;
	AniDepot["char1f"]->SetPosition(pos1p.pos);
	AniDepot["char2f"]->SetPosition(pos2p.pos);
}
void CHARACTER::Input(int user, int dest)
{

	if (move_chk)
	{
		move = 80;
		move_chk = false;
	}

	if (user == 1)
	{
		turn_chk = true;
		pos1p.dest = dest;
	}
	else
	{
		turn_chk = false;
		pos2p.dest = dest;
	}
}
void CHARACTER::Update(DWORD tick)
{
	AniDepot["char1b"]->Update(tick);
	AniDepot["char1f"]->Update(tick);
	AniDepot["char1l"]->Update(tick);
	AniDepot["char1r"]->Update(tick);
	AniDepot["char2b"]->Update(tick);
	AniDepot["char2f"]->Update(tick);
	AniDepot["char2l"]->Update(tick);
	AniDepot["char2r"]->Update(tick);

	if (update_dt > update_delay)
	{
		if (turn_chk)
		{
			if (pos1p.dest == 1)
			{
				pos1p.pos.y -= 5;
			}
			else if (pos1p.dest == 2)
			{
				pos1p.pos.y += 5;
			}
			else if (pos1p.dest == 3)
			{
				pos1p.pos.x -= 5;
			}
			else if (pos1p.dest == 4)
			{
				pos1p.pos.x += 5;
			}
		}
		else
		{
			if (pos2p.dest == 1)
			{
				pos2p.pos.y -= 5;
			}
			else if (pos2p.dest == 2)
			{
				pos2p.pos.y += 5;
			}
			else if (pos2p.dest == 3)
			{
				pos2p.pos.x -= 5;
			}
			else if (pos2p.dest == 4)
			{
				pos2p.pos.x += 5;
			}
		}
		
		update_dt %= update_delay;
	}
	else
	{
		move_chk = true;
		pos1p.dest = 0;
		pos2p.dest = 0;
	}
	update_dt += tick;

	std::wostringstream oss;
	std::wostringstream sss;
	oss << _T("Char1Pos : ") << AniDepot["char1f"]->GetPoint().x << _T(',') << AniDepot["char1f"]->GetPoint().y << _T("\n");
	sss << _T("Char2Pos : ") << AniDepot["char2f"]->GetPoint().x << _T(',') << AniDepot["char2f"]->GetPoint().y << _T("\n");

	::OutputDebugString(oss.str().c_str());
	::OutputDebugString(sss.str().c_str());
}
void CHARACTER::Draw(HDC hdc)
{
	if (pos1p.dest == 1)
	{
		AniDepot["char1b"]->SetPosition(pos1p.pos);
		AniDepot["char1b"]->Draw(hdc);
	}
	else if (pos1p.dest == 2)
	{
		AniDepot["char1f"]->SetPosition(pos1p.pos);
		AniDepot["char1f"]->Draw(hdc);
	}
	else if (pos1p.dest == 3)
	{
		AniDepot["char1l"]->SetPosition(pos1p.pos);
		AniDepot["char1l"]->Draw(hdc);
	}
	else if (pos1p.dest == 4)
	{
		AniDepot["char1r"]->SetPosition(pos1p.pos);
		AniDepot["char1r"]->Draw(hdc);
	}
	else
	{
		AniDepot["char1f"]->Draw(hdc);
	}

	if (pos2p.dest == 1)
	{
		AniDepot["char2b"]->SetPosition(pos2p.pos);
		AniDepot["char2b"]->Draw(hdc);
	}
	else if (pos2p.dest == 2)
	{
		AniDepot["char2f"]->SetPosition(pos2p.pos);
		AniDepot["char2f"]->Draw(hdc);
	}
	else if (pos2p.dest == 3)
	{
		AniDepot["char2l"]->SetPosition(pos2p.pos);
		AniDepot["char2l"]->Draw(hdc);
	}
	else if (pos2p.dest == 4)
	{
		AniDepot["char2r"]->SetPosition(pos2p.pos);
		AniDepot["char2r"]->Draw(hdc);
	}
	else
	{
		AniDepot["char2f"]->Draw(hdc);
	}

	if (move != 0)
		move-=5;
}