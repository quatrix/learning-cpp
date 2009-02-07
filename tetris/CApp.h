#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include "CSurface.h"
#include "CEvent.h"

class CApp : public CEvent {
	private:
	        bool    	Running;
		int 		CurrentPlayer;
		int		Winner;

		SDL_Surface*	Surf_Display;

	private:
//		SDL_Surface*	Surf_Grid;

	private:

	public:
		CApp();

	public:
	public:

		int OnExecute();

		bool OnInit();

		void OnEvent(SDL_Event* Event);
//			void OnLButtonDown(int mX, int mY);
			void OnExit();

		void OnLoop();

		void OnRender();

		void OnCleanup();
};


#endif

