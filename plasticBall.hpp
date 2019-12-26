#pragma once

#include "ball.hpp"

class plasticBall : public ball
{
public:
    plasticBall(LTexture *image, float x, float y);
    plasticBall();
    virtual ~plasticBall();
    void Move();
    virtual bool check_collision(Unit *);
    virtual void Render(long int &frame, SDL_Renderer *gRenderer, bool debug);
};