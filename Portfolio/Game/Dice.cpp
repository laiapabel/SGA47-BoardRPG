#include "Dice.h"

DICE::DICE()
 : update_dt(0), update_delay(3000), dice_type(0), dice_stop(0)
 , play(false), stop(false)
{
	srand((unsigned)time(NULL));
}
DICE::~DICE()
{
}

void DICE::Input(int type)
{
	if (!play)
	{
		dice_type = type;
		play = true;
		stop = false;

		dice_stop = rand()%dice_type+1;

		AniDepot["dice4"]->SetPosition(Point(1000/2-100,700/2));
		AniDepot["dice6"]->SetPosition(Point(1000/2+50,700/2));
		ImgDepot["dice4"]->SetRect(Rect(1000/2,700/2));
		ImgDepot["dice6"]->SetRect(Rect(1000/2,700/2));
	}
}
void DICE::Update(DWORD tick)
{
	if (dice_type != 0 && play)
	{
		if (dice_type == 4)
			AniDepot["dice4"]->Update(tick);
		else if (dice_type == 6)
			AniDepot["dice6"]->Update(tick);

		if (update_dt >= 3000)
		{
			play = false;
			stop = true;

			update_dt %= update_delay;
		}

		update_dt += tick;
	}
}
void DICE::Draw(HDC hdc)
{
	if (dice_type != 0 && (play || stop))
	{
		if (dice_type == 4)
		{
			if (stop)
			{
				ImgDepot["dice4"]->SetSize(Rect(50*dice_stop-50,0, 50, 50));
				ImgDepot["dice4"]->Draw(hdc);
			}
			else
			{
				AniDepot["dice4"]->Draw(hdc);
			}
		}
		else if (dice_type == 6)
		{
			if (stop)
			{
				ImgDepot["dice6"]->SetSize(Rect(50*dice_stop-50,0, 50, 50));
				ImgDepot["dice6"]->Draw(hdc);
			}
			else
			{
				AniDepot["dice6"]->Draw(hdc);
			}
		}
	}
}

void DICE::Init()
{
}
