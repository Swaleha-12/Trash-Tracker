#include "ball.hpp"

ball::ball()
{
}

ball::~ball()
{
    cout << "ball Destroyed" << endl;
}

ball::ball(LTexture *image, float x, float y) : Unit(image, x, y)
{
    spriteSheetTexture = image;
}

void ball::Move()
{
    y = y - 10;
    if (y < -100)
    {
        SetAlive(false);
    }
}

void ball::Render(long int &frame, SDL_Renderer *gRenderer, bool debug)
{
}
