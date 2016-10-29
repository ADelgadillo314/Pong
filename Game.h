#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "globals.h"

class Game
{
public:

	Game();

	void display() const;
	void endGame() const;
	bool over() const ;
	void housekeepingEvents(SDL_Event& event);
	void play();
	bool checkCol(double Ax, double Ay, double Aw, double Ah, double Bx, double By, double Bw, double Bh);

	~Game();

private:
	bool m_over;

};








#endif //GAME_INCLUDED