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

void CApp::OnExit() { 
	Running = false;
}


