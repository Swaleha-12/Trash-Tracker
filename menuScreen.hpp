#pragma once
#include "Screen.hpp"

class menuScreen : public Screen
{
public:
    menuScreen(LTexture *, LTexture *);
    virtual void Render(SDL_Renderer *); // renders screen along with buttons
    virtual ~menuScreen();
};
