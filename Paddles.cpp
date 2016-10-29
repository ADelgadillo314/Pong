#include "globals.h"



Paddle:: Paddle(int topx, int topy, Side s)
	:m_x(topx), m_y(topy), m_s(s),m_down(false), m_up(false)
{}


Paddle:: ~Paddle()
{}


double Paddle:: x()
{return m_x;}

double Paddle:: y()
{return m_y;}

Side Paddle:: s()
{ return m_s; }

bool Paddle:: up()
{return m_up;}

bool Paddle:: down()
{return m_down;}

void Paddle:: move_up()
{
	m_y -= MOVE_SPEED;
}
void Paddle:: move_down()
{
	m_y += MOVE_SPEED;
}

void Paddle:: draw(int length, int offset)
{
	glPushMatrix();
	{
		glOrtho(0,GAME_WINDOW_X,GAME_WINDOW_Y,0,-1,1);


		glBegin(GL_QUADS);
		{
			glColor4ub(0,150,0,255);

			glVertex2d(m_x , m_y);
			glVertex2d(m_x + offset , m_y);
			glVertex2d(m_x + offset , m_y + length );
			glVertex2d(m_x , m_y + length);

		}
		glEnd();

		glBegin(GL_LINE_LOOP);
		{
			glColor4ub(0,0,0,255);

			glVertex2d(m_x , m_y);
			glVertex2d(m_x + offset , m_y);
			glVertex2d(m_x + offset , m_y + length );
			glVertex2d(m_x , m_y + length);

		}
		glEnd();
	}
	glPopMatrix();
}

void Paddle:: move(SDL_Event event)
{
	if( s() == RIGHT)
	{

		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN && y() + PADDLE_LENGTH  + MOVE_SPEED <= GAME_WINDOW_Y )
		{
			cout << " Y COORD   " << m_y << endl;
			if(y() + PADDLE_LENGTH  + MOVE_SPEED <= GAME_WINDOW_Y)
				m_down = true;

		}

		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP )
		{
			cout << " Y COORD   " << m_y << endl;
			m_up = true;
		}

		if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_DOWN )
		{
			m_down = false;
		}

		if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_UP )
		{
			m_up = false;
		}

	}

	if( s() == LEFT)
	{
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_z )
		{
			cout << "  left Y COORD   " << m_y << endl;
			m_down = true;
		}

		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_a )
		{
			cout << "  left Y COORD   " << m_y << endl;
			m_up = true;
		}

		if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_z )
		{
			m_down = false;
		}

		if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_a )
		{
			m_up = false;
		}



	}


}


void Paddle:: edgecheck()
{
	if( y() < 0)
		m_y = 0;

	if( y() + PADDLE_LENGTH > GAME_WINDOW_Y)
		m_y = GAME_WINDOW_Y - PADDLE_LENGTH;

}



Ball:: Ball()
	:m_x(500), m_y(100), velY(BALL_V),velX(BALL_V)
{}

Ball:: ~Ball()
{}

void Ball:: draw()
{

	glPushMatrix();
	{
		glOrtho(0,GAME_WINDOW_X,GAME_WINDOW_Y,0,-1,1);

		glBegin(GL_QUADS);
		{
			glColor4ub(255,255,255,255);

			glVertex2d(m_x,m_y);
			glVertex2d(m_x + BALL_W, m_y);
			glVertex2d(m_x + BALL_W, m_y + BALL_W);
			glVertex2d(m_x, m_y + BALL_W);
		}
		glEnd();
	}
	glPopMatrix();

}

void Ball:: vel_Y()
{
	m_y += velY;

}

void Ball:: vel_X()
{
	m_x += velX;
}

int Ball:: x()
{ return m_x; }

int Ball:: y()
{ return m_y; }

void Ball:: changeY()
{ velY = -velY;}

void Ball:: changeX()
{ velX = -velX; }

void Ball:: edgecheck()
{
	if( x() > 0 || x() < GAME_WINDOW_X)
	{
		if( m_y < 0 )
			changeY();
		if( m_y + BALL_W >= GAME_WINDOW_Y)
		{
			cout << "changed";
			changeY();
		}
	}
	else
	{
		velY = 0;
		velX = 0;
	}

}

void Ball:: incr()
{
	if( velX < 0 ) 
		velX += -.5;
	else 
		velX += .5;

	if(velY < 0)
		velY += -.5;
	else
		velY += .5;

	cout << " VelY    " << velY << "    velX  " << velX << endl;
}