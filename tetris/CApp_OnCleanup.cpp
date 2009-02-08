#include "CApp.h"

void CApp::OnCleanup() {
	SDL_FreeSurface(Surf_Display);
	SDL_FreeSurface(Surf_Board);
	SDL_FreeSurface(Surf_Brick);
	SDL_Quit();
}
