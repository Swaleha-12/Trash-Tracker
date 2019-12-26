#include "LoseScreen.hpp"

LoseScreen::LoseScreen(LTexture *bgImage, LTexture *buttonSprite) : Screen(bgImage)
{
    this->bgImage = bgImage;
}

void LoseScreen::Render(SDL_Renderer *gRenderer)
{
    bgImage->Render(0, 0, NULL, gRenderer);
}

LoseScreen::~LoseScreen()
{
    std::cout << "Lose Screen Destroyed" << std::endl;
}
