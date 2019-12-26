#include <iostream>
#include "Metal.hpp"

Metal::Metal()
{
}

Metal::~Metal()
{
  cout << "Metal Deallocated" << endl;
}
Metal::Metal(LTexture *image, float x, float y) : Trash(image, x, y)
{

  spriteSheetTexture = image;

  //Frame 0
  spriteClips[0].x = 0;
  spriteClips[0].y = 0;
  spriteClips[0].w = 50;
  spriteClips[0].h = 50;

  this->width = spriteClips[0].w;
  this->height = spriteClips[0].h;
  type = "metal";
}

void Metal::Move()
{
  y = y + trashspeed; //speedy;
  if (y > 700)
  {
    SetAlive(false);
  }
}
bool Metal::check_collision(Unit *sprite)
{
  if ((this->GetX() >= sprite->GetX() && this->GetX() <= (sprite->GetX() + sprite->GetWidth())) ||
      ((this->GetX() + this->GetWidth()) >= sprite->GetX() && (this->GetX() + this->GetWidth()) <= (sprite->GetX() + sprite->GetWidth())))
  {
    //Now we look at the y axis:
    if ((this->GetY() >= sprite->GetY() && this->GetY() <= (sprite->GetY() + sprite->GetHeight())) ||
        ((this->GetY() + this->GetHeight()) >= sprite->GetY() && (this->GetY() + this->GetHeight()) <= (sprite->GetY() + sprite->GetHeight())))
    {
      //The sprites appear to overlap.
      return true;
    }
  }
  return false;
}
void Metal::Render(long int &frame, SDL_Renderer *gRenderer, bool debug)
{
  spriteSheetTexture->Render(x - width / 2, y - height / 2, &spriteClips[frame % MOVING_FRAMES], gRenderer, 0.0, NULL, SDL_FLIP_VERTICAL);
  if (debug == true)
  {
    SDL_Rect rect = {x - width / 2, y - height / 2, width, height};
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderDrawRect(gRenderer, &rect);
  }
}