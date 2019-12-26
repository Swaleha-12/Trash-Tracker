
#include "Unit.hpp"

Unit::Unit()
{
}
Unit::~Unit()
{
    spriteSheetTexture = NULL;
    std::cout << "Unit destructed"
              << "\n";
}
Unit::Unit(LTexture *image, float x, float y)
{
    spriteSheetTexture = image;

    this->x = x;
    this->y = y;
    alive = true;
    type = "";
    speedx = 10;
}

void Unit::SetAlive(bool alive)
{
    this->alive = alive;
}

bool Unit::GetAlive()
{
    return alive;
}

void Unit::Move()
{
}
void Unit::Move(int direction)
{
}
int Unit::GetWidth()
{
    return width;
}

int Unit::GetHeight()
{
    return height;
}
string Unit::GetType()
{
    return type;
}

float Unit::GetX()
{
    return x;
}
float Unit::GetY()
{
    return y;
}
