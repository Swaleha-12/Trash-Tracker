#include "ballfactory.hpp"

BallFactory::BallFactory()
{

    balls = NULL;
}
ball *BallFactory::getBall(int type) //creates the required type of ball object
{
    if (type == 0)
    {
        balls = new metalBall(image, x, y);
    }
    else if (type == 1)
    {
        balls = new paperBall(image, x, y);
    }
    else if (type == 2)
    {
        balls = new plasticBall(image, x, y);
    }
    return balls;
}
void BallFactory::set_factory(LTexture *i, float xx, float yy)
{
    image = i;
    x = xx;
    y = yy;
}
BallFactory::~BallFactory()
{
    delete balls;
    image = NULL;
    std::cout << "ballfactory destroyed"
              << "\n";
}
