#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event) {
	CEvent::OnEvent(Event);
}

/*
void CApp::OnLButtonDown(int mX, int mY) {
	int ID = mX / 200;
	ID += ((mY / 200) * 3);

	if (Winner != GRID_TYPE_NONE) { 
		// if someone won, reseting...
		CurrentPlayer = Winner;
		Reset();
		return;
	}

	if (Grid[ID] != GRID_TYPE_NONE) { 
		return;
	}

	if (CurrentPlayer == GRID_TYPE_X) {
		SetCell(ID,GRID_TYPE_X);
		CurrentPlayer = GRID_TYPE_O;
	}
	else {
		SetCell(ID,GRID_TYPE_O);
		CurrentPlayer = GRID_TYPE_X;
	}


}
*/

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) { 
		case SDLK_ESCAPE: 
			Running = 0;
			break;
/*
		case SDLK_LEFT:
			ClearShape();
			Tris.Left();
			DrawShape();
			break;
		case SDLK_RIGHT:
			ClearShape();
			Tris.Right();
			DrawShape();
			break;
		case SDLK_DOWN:
			ClearShape();
			Tris.Down();
			DrawShape();
			break;
*/
		case SDLK_UP:
			current_shape.Rotate();
			current_shape.Display();
			break;

	}
}

void CApp::OnExit() { 
	Running = false;
}


