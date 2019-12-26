#pragma once
#include <iostream>
#include "Trash.hpp"

class Metal : public Trash
{
private:
    string Text;

public:
    Metal();
    Metal(LTexture *bodyImg, float x, float y);
    virtual ~Metal();
    virtual void Render(long int &frame, SDL_Renderer *gRenderer, bool debug);
    virtual void Move();
    virtual bool check_collision(Unit *);
};