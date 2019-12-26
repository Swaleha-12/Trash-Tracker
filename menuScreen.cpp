#include "menuScreen.hpp"

menuScreen::menuScreen(LTexture *bgImage, LTexture *buttonSprite) : Screen(bgImage)
{
    this->bgImage = bgImage;
    float posX = (float)width / 2;
    float posY = ((float)height / 2);
    ButtonCount = 2;
    buttons = new Button[2];
    int y = 0; // for sprite sheet
    for (int i = 0; i < 2; i++)
    {
        buttons[i] = Button(buttonSprite, posX, posY + 50);
        posY += 150;
        buttons[i].set_sprite(0, 0, y, 200, 100);
        y += 100;
        buttons[i].set_sprite(1, 0, y, 200, 100);
        y += 100;
    }
}

void menuScreen::Render(SDL_Renderer *gRenderer) //rendering menu screen with buttons
{
    bgImage->Render(0, 0, NULL, gRenderer);
    for (int i = 0; i < ButtonCount; i++)
    {
        buttons[i].Render(gRenderer);
    }
}

menuScreen::~menuScreen()
{
    std::cout << "Menu Screen Destroyed" << std::endl;
}
