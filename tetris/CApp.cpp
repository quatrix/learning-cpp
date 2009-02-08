#include "CApp.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::runtime_error;

#define BOARD_SIZE_X 10;
#define BOARD_SIZE_Y 10;

CApp::CApp() {
	Surf_Display	= NULL;
	Surf_Board	= NULL;
	Surf_Brick	= NULL;

	Running		= true;
	current_shape.board_x 	= BOARD_SIZE_X;
	current_shape.board_x 	= BOARD_SIZE_Y;

}

void CApp::DrawShape() { 

	int y = 100;

	for (vector<vector<int> >::const_iterator i = current_shape.shape.begin(); i != current_shape.shape.end(); i++) { 
		int x = 100;
		for (vector<int>::const_iterator j = (*i).begin(); j != (*i).end(); j++) {
			if ((*j) != 0)  
				CSurface::OnDraw(Surf_Display,Surf_Brick,x,y);
			
			x += 30;
		}
		y += 30;
	}
}

int CApp::OnExecute() {
	try { 
		OnInit();
	}
	catch(runtime_error e) { 
		cout << "OnInit failed with: " << e.what() << endl;
		return -1;
	}

	SDL_Event Event;

	while(Running) { 
		while(SDL_PollEvent(&Event)) { 
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

    return 0;
}

int main(int argc, char* argv[]) {
    CApp theApp;

    return theApp.OnExecute();
}

