#include "CApp.h"

bool CApp::OnInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) { 
		return false;
	}

	if ((Surf_Display = SDL_SetVideoMode(600,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) { 
		return false;
	}

/*
	if ((Surf_Grid = CSurface::OnLoad("./gfx/grid.png")) == NULL) {
		return false;
	}
*/

	Reset();

    return true;
}


