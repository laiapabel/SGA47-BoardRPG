#include "Game.h"

INT WINAPI _tWinMain(HINSTANCE hInst,
					 HINSTANCE,
					 LPTSTR,
					 INT)
{
	Game app;

	app.Setup(hInst);

	return app.Run();
}