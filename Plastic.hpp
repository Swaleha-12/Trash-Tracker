#pragma once
#include <iostream>
#include "Trash.hpp"

class Plastic : public Trash
{
public:
    Plastic();
    Plastic(LTexture *bodyImg, float x, float y);
    virtual ~Plastic();
    virtual bool check_collision(Unit *);
    virtual void Render(long int &frame, SDL_Renderer *gRenderer, bool debug);
    virtual void Move();
};