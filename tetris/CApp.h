#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include "CSurface.h"
#include "CEvent.h"
#include "Shape.hpp"

class CApp : public CEvent {
	private:
	        bool    	Running;
		int 		CurrentPlayer;
		int		Winner;

		SDL_Surface*	Surf_Display;
		SDL_Surface*	Surf_Board;
		SDL_Surface*	Surf_Brick;
		Shape		current_shape;

	private:
//		SDL_Surface*	Surf_Grid;

	private:

	public: 
		void DrawShape();

	public:
		CApp();
	public:

		int OnExecute();

		bool OnInit();

		void OnEvent(SDL_Event* Event);
//			void OnLButtonDown(int mX, int mY);
			void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
			void OnExit();

		void OnLoop();

		void OnRender();

		void OnCleanup();
};


#endif

