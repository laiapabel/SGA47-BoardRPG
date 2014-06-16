#include "Dice.h"

DICE::DICE()
 : update_dt(0), update_delay(3000)
 , dice_stop(0)
 , play(false), stop(false)
 , dice_num(0)
{
}
DICE::~DICE()
{
}

void DICE::Input(int cnt)
{
	dice_num = cnt;
	
	dice_stop = rand()%6;

	if (!play)
	{
		play = true;
		stop = false;
	}
}
void DICE::Update(DWORD tick)
{
	if (play)
	{
		AniDepot["diceAni"]->Update(tick);

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
	if (play || stop)
	{
		if (stop)
		{
			ImgDepot["dice6"]->Move(Point(1000/2+260+dice_num*50,700/2));
			ImgDepot["dice6"]->SetSize(Rect(0 + 40*dice_stop,0, 40, 40));
			ImgDepot["dice6"]->Draw(hdc);
		}
		else
		{
			AniDepot["diceAni"]->SetPosition(Point(1000/2+dice_num*50,700/2));
			AniDepot["diceAni"]->Draw(hdc);
		}
	}
}

int DICE::GetDice()
{
	return dice_stop;
}
