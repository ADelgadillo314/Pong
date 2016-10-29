#include "globals.h"



bool initRender();

int main(int argc, char**)
{
	//initialize everything 
	if(! initRender() )
		return 1;


	Game example;

	example.play();

	


	SDL_Quit();
	return 0;

}


bool initRender()
{
	//initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);


	
	//Set opengl memory usage
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,    8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,  8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,   8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,  8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,  16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

	//Caption of the window 
	SDL_WM_SetCaption("Pong",NULL);

	//Size of the window 
	SDL_SetVideoMode(GAME_WINDOW_X,GAME_WINDOW_Y,32,SDL_OPENGL);

	//Specify the clear color (white) 
	glClearColor(0,0,0,1); //Red,Green, Blue, Alpha
	
	//Portion of screen displayed 
	glViewport(0,0,GAME_WINDOW_X,GAME_WINDOW_Y);



	//Shading Fixer
	glShadeModel(GL_SMOOTH);

	//promise to 2d render + save
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//disable depth checking
	glDisable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT);

	
	return true;
}
