#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include <cstdio>
#include <iostream>
#include "Unit.hpp"
#include "LTexture.hpp"

using namespace std;

class Player : public Unit
{
private:
    enum ANIMATION_FRAMES
    {
        MOVING_FRAMES = 9
    };
    SDL_Rect spriteClips[MOVING_FRAMES];
    static Player *instance; // pointer to the player object
    static int instances; // number of instances of the player object
    Player(LTexture *image, float x, float y); // private constructor of the player
    Player();

public:
    virtual ~Player();
    virtual void Move(int direction);
    static Player *get_instance(LTexture *, float, float); // returns the new or the already existing instance of player
    bool check_collision(Unit *);
    void Render(long int &frame, SDL_Renderer *gRenderer, bool debug);
};
