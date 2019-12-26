#include "Button.hpp"

Button::Button()
{
    hover = false;
    clicked = false;
    mx = 0, my = 0;
}

Button::~Button()
{
    Buttonspritesheet = NULL;
    std::cout << "Button destroyed"
              << "\n";
}
Button::Button(LTexture *gTexture, float x, float y)
{
    Buttonspritesheet = gTexture;
    this->mx = x;
    this->my = y;
    this->hover = false;
    this->clicked = false;
    //frame 0
    ButtonspriteClips[0].x = 0;
    ButtonspriteClips[0].y = 0;
    ButtonspriteClips[0].h = 100;
    ButtonspriteClips[0].w = 200;
    //frame 1
    ButtonspriteClips[1].x = 0;
    ButtonspriteClips[1].y = 100;
    ButtonspriteClips[1].h = 100;
    ButtonspriteClips[1].w = 200;

    this->height = ButtonspriteClips[0].h;
    this->width = ButtonspriteClips[0].w;
}

void Button::set_sprite(int indx, int x, int y, int w, int h)
{
    ButtonspriteClips[indx].x = x;
    ButtonspriteClips[indx].y = y;
    ButtonspriteClips[indx].w = w;
    ButtonspriteClips[indx].h = h;
}

void Button::Render(SDL_Renderer *gRenderer)
{

    if (hover)
    {
        Buttonspritesheet->Render(mx - width / 2, my - height / 2, &ButtonspriteClips[1], gRenderer);
        std::cout << "button render"
                  << "\n";
    }
    else
    {

        Buttonspritesheet->Render(mx - width / 2, my - height / 2, &ButtonspriteClips[0], gRenderer);
        std::cout << "button render2"
                  << "\n";
    }
}

void Button::set_hover(int x, int y)
{
    if ((x <= mx + width / 2 && x >= mx - width / 2) && (y <= my + height / 2 && y >= my - height / 2))
    {
        hover = true;
    }
    else
        hover = false;
}
void Button::set_clicked(int x, int y, Mix_Chunk *buttonClicked)
{
    if ((x <= mx + width / 2 && x >= mx - width / 2) && (y <= my + height / 2 && y >= my - height / 2))
    {
        Mix_PlayChannel(-1, buttonClicked, 0);
        clicked = true;
    }
    else
        clicked = false;
}
bool Button::get_hover()
{
    return hover;
}
bool Button::get_clicked()
{
    return clicked;
}