#include "CApp.h"

void CApp::OnRender() {
	CSurface::OnDraw(Surf_Display,Surf_Board,0,0);
	DrawShape();


	SDL_Flip(Surf_Display);
}

