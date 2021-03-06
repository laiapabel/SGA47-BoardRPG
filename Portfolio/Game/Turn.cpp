#include "Turn.h"

TURN::TURN()
 : update_dt(0), update_delay(3000)
 , turn_chk(false), turn(1)
 , dice_cnt(1), Dice(NULL)
{
	srand((unsigned)time(NULL));
}
TURN::~TURN()
{
	delete [] Dice;
	Dice = NULL;
}

void TURN::Input(int key)
{
	// 턴 종료 확인
	if (key == 46)
		turn_chk = !turn_chk;

	// 주사위 굴림
	if (key == 32)
	{
		if (Dice != NULL)
		{
			delete [] Dice;
			Dice = NULL;
		}

		dice_cnt = rand()%6+1;

		if (Dice == NULL)
			Dice = new DICE[dice_cnt];

		for (int i = 0; i < dice_cnt; i++)
		{
			Dice[i].Input(i);
		}
	}
	if (turn_chk)
	{
		if (turn == 1)
			turn = 2;
		else
			turn = 1;

		turn_chk = false;
	}
}
void TURN::Update(DWORD tick)
{
	if (Dice == NULL)
		Dice = new DICE[dice_cnt];

	for (int i = 0; i < dice_cnt; i++)
	{
		Dice[i].Update(tick);

		//Dice[i].GetDice();
	}
}
void TURN::Draw(HDC hdc)
{
	for (int i = 0; i < dice_cnt; i++)
	{
		Dice[i].Draw(hdc);
	}
}
int TURN::GetTurn()
{
	return turn;
}