#include "Player.hpp"

int Player::instances = 0;
Player *Player::instance = nullptr;

Player::Player()
{
}

Player::Player(LTexture *image, float x, float y) : Unit(image, x, y)
{
    spriteSheetTexture = image;

   //Frame 0
    spriteClips[0].x = 0;
    spriteClips[0].y = 0;
    spriteClips[0].w = 77;
    spriteClips[0].h = 80;

    //Frame 1
    spriteClips[1].x = 77;
    spriteClips[1].y = 0;
    spriteClips[1].w = 77;
    spriteClips[1].h = 80;

    //Frame 2
    spriteClips[2].x = 154;
    spriteClips[2].y = 0;
    spriteClips[2].w = 77;
    spriteClips[2].h = 80;
    //Frame 3
    spriteClips[3].x = 308;
    spriteClips[3].y = 0;
    spriteClips[3].w = 77;
    spriteClips[3].h = 80;
    //Frame 4
    spriteClips[4].x = 385;
    spriteClips[4].y = 0;
    spriteClips[4].w = 77;
    spriteClips[4].h = 80;
    //Frame 5
    spriteClips[5].x = 462;
    spriteClips[5].y = 0;
    spriteClips[5].w = 77;
    spriteClips[5].h = 80;
    //Frame 6
    spriteClips[6].x = 539;
    spriteClips[6].y = 0;
    spriteClips[6].w = 77;
    spriteClips[6].h = 80;
    //Frame 7
    spriteClips[7].x = 616;
    spriteClips[7].y = 0;
    spriteClips[7].w = 77;
    spriteClips[7].h = 80;
    //Frame 8
    spriteClips[8].x = 693;
    spriteClips[8].y = 0;
    spriteClips[8].w = 77;
    spriteClips[8].h = 80;
    this->width = spriteClips[0].w;
    this->height = spriteClips[0].h;
    type = "player";
    cout << "Player constructor called";
}
bool Player::check_collision(Unit *sprite)
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
Player *Player::get_instance(LTexture *image, float x, float y)
{
    if (instances < 1)
    {
        instance = new Player(image, x, y);
        instances++;
    }
    return instance;
}
Player::~Player()
{
    spriteSheetTexture = NULL;
    std::cout << "Player deallocated"
              << "\n";
}

void Player::Move(int direction)
{

    if (direction == LEFT)
    {
        x -= speedx;
        if (x <= 50)
        {
            x = 50;
        }
    }

    if (direction == RIGHT)
    {
        x += speedx;
        if (x > 1024 - 147)
        {
            x = 1024 - 147;
        }
    }
}

void Player::Render(long int &frame, SDL_Renderer *gRenderer, bool debug)
{
    spriteSheetTexture->Render(x - width / 2, y - height / 2, &spriteClips[frame % MOVING_FRAMES], gRenderer, 0.0, NULL, SDL_FLIP_NONE);
    if (debug == true)
    {
        SDL_Rect rect = {x - width / 2, y - height / 2, width, height};
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderDrawRect(gRenderer, &rect);
    }
}