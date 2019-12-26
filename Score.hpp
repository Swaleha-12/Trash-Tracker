#pragma once
#include "LTexture.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <sstream>
class Score
{
private:
  SDL_Texture *mTexture; 
  SDL_Surface *TextSurface; //sdl surface for score
  TTF_Font *mFont; 
  std::string Text;
  SDL_Colour color;
  int score;
  int mx, my;

public:
  Score(int, int, TTF_Font *);
  ~Score();
  int get_score();
  void set_score(int);
  Score operator+(int); // for incrementing score
  Score operator-(int); // for decrementing score
  void set_position(int, int);
  void set_Text(std::string); // text to be rendered along with the score
  void Set_color(Uint8, Uint8, Uint8);
  void Render(SDL_Renderer *, bool);
};
