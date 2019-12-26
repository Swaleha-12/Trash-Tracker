#pragma once
#include "LTexture.hpp"
#include "Button.hpp"
#include <SDL_mixer.h>
class Screen
{
protected:
    LTexture *bgImage;      //background image of the screen
    int ButtonCount = 0;    //no. of Buttons to be rendered
    Button *buttons = NULL; //pointer of Button class(either kept null or used to create dynamic array of buttons)
    const int width = 1024; 
    const int height = 600;

public:
    virtual void Render(SDL_Renderer *) = 0; //Render the Screen
    Screen(LTexture *bgImage);
    virtual ~Screen();
    Button *getButtons();                                        //returns array of buttons
    int getButtonCount();                                        //return the no. of buttons to be rendered                           //changes the state of Button on the index
    void mouseMotionEvents(int x, int y);                        //used to handle mouse motion events on a screen
    void mouseClickEvents(int x, int y, Mix_Chunk *buttonClick); //used to handle mouse click events on a screen
};
