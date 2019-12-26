#pragma once

#include "Unit.hpp"
// extends metalball, paperball, plasticball
class ball : public Unit
{
protected:
  enum
  {
    BALL_FRAMES = 1 
  }; 
  SDL_Rect spriteClips[BALL_FRAMES];

public:
  ball(LTexture *image, float x, float y);
  ball();
  virtual ~ball();
  virtual bool check_collision(Unit *) = 0;
  virtual void Move() = 0;
  virtual void Render(long int &frame, SDL_Renderer *gRenderer, bool debug);
};