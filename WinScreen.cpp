#include "WinScreen.hpp"

WinScreen::WinScreen(LTexture *bgImage, LTexture *buttonSprite) : Screen(bgImage)
{
    this->bgImage = bgImage;
}

void WinScreen::Render(SDL_Renderer *gRenderer)
{
    bgImage->Render(0, 0, NULL, gRenderer);
}

WinScreen::~WinScreen()
{
    std::cout << "Win Screen Destroyed" << std::endl;
}