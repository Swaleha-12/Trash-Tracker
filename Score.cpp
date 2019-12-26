#include "Score.hpp"

Score::Score(int _x, int _y, TTF_Font *font)
{
  mTexture = NULL;
  TextSurface = NULL;
  score = 0;
  mFont = font;
  mx = _x;
  my = _y;
  Text = "Score: ";
  color = {0, 0, 0, 255};
}

Score Score::operator+(int _score)
{
  score += _score;
  return *this;
}
void Score::Set_color(Uint8 R, Uint8 B, Uint8 G)
{
  color = {R, B, G, 255};
}
Score Score::operator-(int _score)
{
  score -= _score;
  return *this;
}
void Score::Render(SDL_Renderer *gRenderer, bool debug)
{
  std::stringstream ss;
  ss << Text << std::to_string(score);
  TextSurface = TTF_RenderText_Solid(mFont, ss.str().c_str(), color);
  if (TextSurface != NULL)
  {
    mTexture = SDL_CreateTextureFromSurface(gRenderer, TextSurface);
    SDL_Rect destRect = {mx, my, TextSurface->w, TextSurface->h};
    SDL_RenderCopy(gRenderer, mTexture, NULL, &destRect);
  }
}
int Score::get_score()
{
  return score;
}
void Score::set_score(int _score)
{
  score = _score;
}
void Score::set_position(int x, int y)
{
  mx = x;
  my = y;
}

void Score::set_Text(std::string _text)
{
  Text = _text;
}
Score::~Score()
{
  SDL_FreeSurface(TextSurface);
  TextSurface = NULL;
  SDL_DestroyTexture(mTexture);
  std::cout << "Score has been destructed"
            << "\n";
}
