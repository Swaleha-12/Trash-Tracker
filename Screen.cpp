#include "Screen.hpp"

Screen::Screen(LTexture *Image)
{
    bgImage = Image;
}
Screen::~Screen()
{
    //deallocating pointer
    if (buttons != NULL)
    {
        delete[] buttons;
        buttons = NULL;
    }
    std::cout << "Screen destructed" << std::endl;
}
Button *Screen::getButtons() //returns array of buttons
{
    return buttons;
}
int Screen::getButtonCount() //return the no. of buttons rendered
{
    return ButtonCount;
}
void Screen::mouseMotionEvents(int x, int y)
{
    for (int i = 0; i < ButtonCount; i++)
    {
        buttons[i].set_hover(x, y);
    }
}
void Screen::mouseClickEvents(int x, int y, Mix_Chunk *buttonClick)
{
    for (int i = 0; i < ButtonCount; i++) //loop going through each button index
    {
        buttons[i].set_clicked(x, y, buttonClick);
    }
}
