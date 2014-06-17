#pragma once

#pragma comment(lib, "../GameDev/GameDev.lib")

#include "../GameDev/GameDev.h"

#include "Stage.h"

#include <windows.h>
#include <ctime>
#include <tchar.h>
#include <cstdlib>
#include <sstream>

class Game : public MainWindow<Game>
{
	typedef Game Me;
	typedef MainWindow<Game> Base;

public :
	Game();
	~Game();

	void Input(DWORD);
	void Update(DWORD);
	void Draw(DWORD);

	void InitEventMap();
	LRESULT OnSize(HWND,UINT,WPARAM,LPARAM);

protected :
	void Enter();
	void Leave();

private :
	bool start_chk;
	DWORD update_dt;
	DWORD update_delay;
	STAGE Stage;
};