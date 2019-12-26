#pragma once
#include <iostream>
#include "Trash.hpp"

class Paper : public Trash
{

public:
    Paper();
    Paper(LTexture *bodyImg, float x, float y);
    virtual ~Paper();
    virtual bool check_collision(Unit *);
    virtual void Render(long int &frame, SDL_Renderer *gRenderer, bool debug);
    virtual void Move();
};