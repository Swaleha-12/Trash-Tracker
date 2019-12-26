#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <cstdio>
#include <iostream>
#include "LTexture.hpp"
#include <list>

using namespace std;
enum MOTION
{
    RIGHT,
    LEFT
};
class Unit
{
protected:
    bool alive; // whether the object is alive or not
    int x;
    int y;
    int width; 
    int height;
    string type; // the type of the instance of the object
    int speedx; 
    LTexture *spriteSheetTexture;

public:
    Unit();
    Unit(LTexture *image, float x, float y);
    virtual ~Unit();
    void SetAlive(bool);
    bool GetAlive();
    int GetWidth();
    int GetHeight();
    string GetType();
    float GetX();
    float GetY();
    virtual bool check_collision(Unit *) = 0; //checks collision 
    virtual void Move(int direction); // for player
    virtual void Move(); // for other objects 
    virtual void Render(long int &frame, SDL_Renderer *gRenderer, bool debug) = 0;
};