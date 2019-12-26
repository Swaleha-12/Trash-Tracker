#pragma once
#include "Screen.hpp"

class WinScreen : public Screen
{
private:
public:
    WinScreen(LTexture *, LTexture *);
    virtual void Render(SDL_Renderer *);
    virtual ~WinScreen();
};