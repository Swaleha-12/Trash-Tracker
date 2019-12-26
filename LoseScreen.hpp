#pragma once
#include "Screen.hpp"

class LoseScreen : public Screen
{
public:
    LoseScreen(LTexture *, LTexture *);
    virtual void Render(SDL_Renderer *);
    virtual ~LoseScreen();
};