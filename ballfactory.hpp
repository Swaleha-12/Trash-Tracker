#pragma once
#include "ball.hpp"
#include "metalBall.hpp"
#include "plasticBall.hpp"
#include "paperBall.hpp"
#include "LTexture.hpp"

enum
{
    metalball,
    paperball,
    plasticball
};

class BallFactory
{
private:
    ball *balls; // for creating the object of a type of ball
    LTexture *image;
    float x;
    float y;

public:
    BallFactory();
    ball *getBall(int type); // creates the required type of ball object
    void set_factory(LTexture *i, float xx, float yy); //sets the attributes
    ~BallFactory();
};
