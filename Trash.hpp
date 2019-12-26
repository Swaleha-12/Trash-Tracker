#pragma once
#include "Unit.hpp"
#include "LTexture.hpp"

class Trash : public Unit
{
protected:
    enum ANIMATION_FRAMES
    {
        MOVING_FRAMES = 1
    };
    SDL_Rect spriteClips[MOVING_FRAMES]; 
    static int trashspeed; // speed of the moving trash

public:
    Trash();
    Trash(LTexture *bodyImg, float x, float y);
    virtual ~Trash();
    static void set_speed(int); //sets the speed
    virtual bool check_collision(Unit *) = 0;
    virtual void Move();
    virtual void Render(long int &frame, SDL_Renderer *gRenderer, bool debug);
};
