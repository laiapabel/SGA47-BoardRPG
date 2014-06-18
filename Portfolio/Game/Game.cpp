#include "Game.h"

Game::Game()
	: update_dt(0), update_delay(100)
	, start_chk(false)
{
	SetWindowTitle(_T("Board RPG"));
	SetWindowStyle(WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX);
}
Game::~Game()
{
}

void Game::Input(DWORD tick)
{
	if (InputDevice.OnClick(VK_RETURN))
		start_chk = true;
	else if (InputDevice.OnClick(VK_SPACE))
		Stage.Input(VK_SPACE);
	else if (InputDevice.OnClick(VK_DELETE))
		Stage.Input(VK_DELETE);
	
	if (InputDevice.IsPressed(VK_LEFT))
		Stage.Input(3);
	else if (InputDevice.IsPressed(VK_RIGHT))
		Stage.Input(4);
	else if (InputDevice.IsPressed(VK_UP))
		Stage.Input(1);
	else if (InputDevice.IsPressed(VK_DOWN))
		Stage.Input(2);
}
void Game::Update(DWORD tick)
{
	Stage.Update(tick);
}
void Game::Draw(DWORD)
{
	backbuffer << RGB(0,0,0);

	if (start_chk)
		Stage.Draw(backbuffer);
	else
		ImgDepot["Title"]->Draw(backbuffer);

	backbuffer.Draw();
}

void Game::Enter()
{
	ImgLoader();
	AniLoader();
	Stage.Enter();
}

void Game::Leave()
{
}

void Game::InitEventMap()
{
	Base::InitEventMap();

	SetEventHandler(WM_SIZE, &Me::OnSize);
}
LRESULT Game::OnSize(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	DWORD dwStyle = WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX;
	Rect rc(0,0,1000,700);

	::AdjustWindowRect(&rc, dwStyle, FALSE);

	::SetWindowPos(hWnd, NULL, 0, 0,
		rc.width(), rc.height(), 
		SWP_NOZORDER | SWP_NOMOVE);

	ChangeClientRect();

	return 0;
}
