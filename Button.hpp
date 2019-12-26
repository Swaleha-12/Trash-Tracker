#pragma once
#include "LTexture.hpp"
#include <SDL_mixer.h>

class Button
{

    int width;                     //width of the button
    int height;                    //height of the Button
    int mx, my;                    //position of the button
    SDL_Rect ButtonspriteClips[2]; //sprite clips for each state of the button
    LTexture *Buttonspritesheet;   //Texture of image consisting of Buttons
    bool hover; //whether the button hovered or not
    bool clicked; //whether the button is clicked or not

public:
    Button();
    ~Button();
    Button(LTexture *, float, float);
    void set_sprite(int, int, int, int, int); //setting the spritesheet coordinates for the spriteclips
    void set_hover(int, int); //setting hover using mouse motion events
    void set_clicked(int, int, Mix_Chunk *); //setting hover using mouse clicked events
    bool get_clicked();
    bool get_hover();
    void Render(SDL_Renderer *);
};