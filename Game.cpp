#include "globals.h"

Game::Game()
	:m_over(false)
{

}

Game:: ~Game()
{

}


bool Game:: over() const
{
	return m_over;
}

void Game:: housekeepingEvents(SDL_Event& event)
{
	if((event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE) ||
		event.type == SDL_QUIT )
		m_over = true;

}


void Game:: display() const
{
	glClear(GL_COLOR_BUFFER_BIT);


}

void Game:: endGame() const
{

}

void Game:: play()
{
	Paddle left  (lPADDLE_START_X,PADDLE_START_Y,LEFT);
	Paddle right (rPADDLE_START_X,PADDLE_START_Y,RIGHT);
	Ball ball;
	int pause = 0;


	while( ! over() )
	{

		SDL_Event event;

		while( SDL_PollEvent(&event) )
		{
			housekeepingEvents(event);
			left.move(event);
			right.move(event);

		}

		if( left.up() )
			left.move_up();
		if(left.down()  )
			left.move_down();

		left.edgecheck();

		if(right.up() )
			right.move_up();
		if(right.down() )
			right.move_down();

		right.edgecheck();




		ball.vel_X();

		if( checkCol(ball.x() ,ball.y(), BALL_W, BALL_W, left.x(), left.y(), 0,PADDLE_LENGTH) )
		{
			ball.changeX();
			ball.incr();

		}
		if( checkCol(ball.x(),ball.y(), BALL_W, BALL_W,right.x(),right.y(),RIGHT_OFFSET,PADDLE_LENGTH) )
		{
			ball.changeX();
			ball.incr();
		}
		ball.vel_Y();

		ball.edgecheck();



		//Render ALL. 

		display();

		left.draw (PADDLE_LENGTH, LEFT_OFFSET );
		right.draw(PADDLE_LENGTH, RIGHT_OFFSET);
		ball.draw();

		SDL_Delay(10);
		SDL_GL_SwapBuffers();
	}

}



bool Game:: checkCol(double Ax, double Ay, double Aw, double Ah, double Bx, double By, double Bw, double Bh)
{
	//check if it is in the four states.. if not it is a collison

	if( Ay + Ah < By) return false;
	if( Ay > By + Bh) return false;
	if( Ax + Aw < Bx) return false;
	if( Ax > Bx + Bw) return false;

	return true;
}

