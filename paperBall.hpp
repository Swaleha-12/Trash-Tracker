#pragma once

#include "ball.hpp"

class paperBall : public ball
{
public:
    paperBall(LTexture *image, float x, float y);
    paperBall();
    virtual ~paperBall();
    void Move();
    virtual bool check_collision(Unit *);
    virtual void Render(long int &frame, SDL_Renderer *gRenderer, bool debug);
};