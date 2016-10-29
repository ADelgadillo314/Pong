#ifndef PADDLES_INCLUDED
#define PADDLES_INCLUDED

#include "globals.h"


enum Side { LEFT , RIGHT };

class Paddle
{
public: 
	Paddle(int topx, int topy, Side s);

	double x();
	double y();
	Side s();
	bool up(); 
	bool down();
	void move_up();
	void move_down();
	void edgecheck();

	//where offset is the width to left or right. 

	void draw( int length, int offset);
	void move(SDL_Event event);

	~Paddle();


private: 
	double m_x;
	double m_y;
	Side m_s;
	bool m_up; 
	bool m_down;


};


class Ball
{
public:
	Ball();
	~Ball();

	void draw();
	void vel_Y();
	void vel_X();
	void changeY();
	void changeX();
	int x();
	int y();
	void incr(); 
	void edgecheck();

private:
	int m_x;
	int m_y;
	double velY;	
	double velX;


};


#endif //PADDLES_INCLUDED