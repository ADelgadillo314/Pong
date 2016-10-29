#ifndef GLOBALS_INCLUDED
#define GLOBALS_INCLUDED

#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream> 
#include <string> 
#include <vector>
using namespace std;

#include "Game.h"
#include "Paddles.h"


const int GAME_WINDOW_X = 1000;
const int GAME_WINDOW_Y = 600;

const int LEFT_OFFSET = -50;
const int RIGHT_OFFSET = 50;
const int PADDLE_LENGTH = 150;

const int PADDLE_START_Y = 275;
const int lPADDLE_START_X = 75;
const int rPADDLE_START_X = 925;

const int BALL_X = 500;
const int BALL_Y = 300;
const int BALL_W = 50; 

const double BALL_V = 3;

const int MOVE_SPEED = 5; 






#endif //GLOBALS_INCLUDED