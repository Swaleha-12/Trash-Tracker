#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include "LTexture.hpp"
#include "player.hpp"
#include "Unit.hpp"
#include "Trash.hpp"
#include "Metal.hpp"
#include "Paper.hpp"
#include "Plastic.hpp"
#include "paperBall.hpp"
#include "plasticBall.hpp"
#include "metalBall.hpp"
#include "Score.hpp"
#include "menuScreen.hpp"
#include "WinScreen.hpp"
#include "LoseScreen.hpp"
#include "Button.hpp"
#include "HighScore.hpp"
#include "ballfactory.hpp"
#include "ObjectFactory.hpp"
//Pre defined screen width and height
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 600;

bool init();

bool loadMedia();

void close();

SDL_Window *gWindow = NULL;

SDL_Renderer *gRenderer = NULL;

LTexture gSpriteSheetTexture;
LTexture gBGtexture;
LTexture gPaper;
LTexture gMetal;
LTexture gPlastic;
LTexture gballs;
LTexture gBGMenuScreen;
LTexture gMenuScreenButtons;
LTexture gBGWinScreen;
LTexture gBGLoseScreen;
TTF_Font *gFont;
Mix_Chunk *buttonClick = NULL;
int Trash::trashspeed = 2;

bool init();
bool loadMedia();
void close();
void removeall(std::list<Unit *> &); // empties the object list

int main(int argc, char *args[])
{
    //Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load media
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {

            bool quit = false; //Main loop flag
            list<Unit *> objectlist;

            //list<ball*> ballList;
            SDL_Event e;             //Event handler
            long int trashframe = 0; //for trash appearing frequency
            long int delaytrash = 0;
            long int frame = 0;      //Current animation frame of player
            int ballDelay = 0;       // delay between shooting balls
            int animationRate = 20;  // for player sprite animation
            int animationLength = 8; // frames of the player
            int startTime = SDL_GetTicks();
            int scrollingOffset = 0; // for gameplay background
            int trashrand = 0;       //random picking of trash
            bool gameOver = false;
            bool ismenuscreen = true;
            bool gamePlay = false;
            bool pauseScreen = false;
            bool speedincreased = false; // whether trash and background's speed has already increased
            bool win = false;
            int bgspeed = 2; // game play backgroud speed
            int x, y;        // to get mouse state
            bool mouseClicked = false;
            Button *buttons = NULL;                                                        // for array of buttons on the menu screen
            HighScore HIGHSCORE;                                                           // the saved highscore
            Score GameScore(10, 10, gFont);                                                // the overall score of the game
            Score displayhighscore(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 + 100, gFont); // to dsplayhighscore

            /* initialize random seed: */
            srand(time(NULL));

            /* generate secret number between 1 and 10: */
            int random = 0;
            // player instance
            Unit *player = Player::get_instance(&gSpriteSheetTexture, (float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT - 50);

            // trash and ball instance
            Trash *trash = NULL;
            ball *balls = NULL;

            // ball factory instance
            BallFactory factory;

            //screen objects
            menuScreen menu_screen(&gBGMenuScreen, &gMenuScreenButtons);
            WinScreen win_screen(&gBGWinScreen, NULL);
            LoseScreen lose_screen(&gBGLoseScreen, NULL);

            while (!quit) //While application is running
            {
                trashrand = rand() % 3; // Generate trash randomly
                if (delaytrash % 100 == 0 && gamePlay)
                {
                    random = rand() % (SCREEN_WIDTH - 100 - 100) + 100;
                    if (trashrand == 0)
                    {
                        trash = new Paper(&gPaper, random, -100);
                    }
                    else if (trashrand == 1)
                    {
                        trash = new Metal(&gMetal, random, -100);
                    }
                    else if (trashrand == 2)
                    {
                        trash = new Plastic(&gPlastic, random, -100);
                    }
                    objectlist.push_back(trash);
                }
                while (SDL_PollEvent(&e) != 0) //Handle events on queue
                {
                    //User requests quit
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    SDL_GetMouseState(&x, &y);
                    if (e.type == SDL_MOUSEBUTTONDOWN && ismenuscreen)
                    {
                        if (e.button.button == SDL_BUTTON_LEFT)
                            mouseClicked = true;
                    }
                    if (e.type == SDL_MOUSEMOTION && ismenuscreen) //to handle all mouse motion events for all screens
                    {
                        menu_screen.mouseMotionEvents(x, y);
                    }
                    if (e.type == SDL_MOUSEBUTTONUP && mouseClicked && ismenuscreen) //to handle all mouse click events for all screens
                    {
                        menu_screen.mouseClickEvents(x, y, buttonClick);
                        mouseClicked = false;
                    }
                    if (ismenuscreen)
                    {
                        gamePlay = false;
                        buttons = menu_screen.getButtons();
                        if (buttons[0].get_clicked())
                        {
                            gamePlay = true;
                            ismenuscreen = false;
                        }
                        if (buttons[1].get_clicked())
                        {
                            quit = true;
                        }
                    }
                }
                const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);

                if (currentKeyStates[SDL_SCANCODE_RIGHT] && gamePlay)
                {

                    player->Move(RIGHT);
                }

                if (currentKeyStates[SDL_SCANCODE_LEFT] && gamePlay)
                {

                    player->Move(LEFT);
                }
                // for shooting balls
                if (currentKeyStates[SDL_SCANCODE_M] && gamePlay)
                {
                    if (ballDelay > 30)
                    {
                        factory.set_factory(&gballs, player->GetX(), player->GetY() - player->GetHeight() / 2);
                        balls = factory.getBall(0);
                        objectlist.push_back(balls);
                        ballDelay = 0;
                    }
                }
                if (currentKeyStates[SDL_SCANCODE_P] && gamePlay)
                {
                    if (ballDelay > 30)
                    {
                        factory.set_factory(&gballs, player->GetX(), player->GetY() - player->GetHeight() / 2);
                        balls = factory.getBall(1);
                        objectlist.push_back(balls);
                        ballDelay = 0;
                    }
                }
                if (currentKeyStates[SDL_SCANCODE_B] && gamePlay)
                {
                    if (ballDelay > 30 && gamePlay)
                    {
                        factory.set_factory(&gballs, player->GetX(), player->GetY() - player->GetHeight() / 2);
                        balls = factory.getBall(2);
                        objectlist.push_back(balls);
                        ballDelay = 0;
                    }
                }

                if (gamePlay)
                {
                    ObjectFactory obj;
                    obj.run(objectlist, GameScore);
                    obj.Clean(objectlist);
                    if (GameScore.get_score() < 0)
                    {
                        gameOver = true;
                        win = false;
                    }
                    if (GameScore.get_score() >= 200)
                    {
                        gameOver = true;
                        win = true;
                    }
                    if (GameScore.get_score() >= 100)
                    {
                        if (!speedincreased)
                        {
                            bgspeed = 3;
                            trash->set_speed(3);
                            speedincreased = true;
                        }
                    }
                    for (std::list<Unit *>::iterator it = objectlist.begin(); it != objectlist.end(); ++it)
                    {
                        if ((*it)->GetType() == "metal" || (*it)->GetType() == "paper" || (*it)->GetType() == "plastic")
                        {
                            if (player->check_collision((*it)))
                            {
                                gameOver = true;
                            }
                        }
                    }
                }

                //clear screen
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF); //Clear screen
                SDL_RenderClear(gRenderer);
                if (gamePlay)
                {
                    // scrolling effect of the background
                    scrollingOffset = scrollingOffset + bgspeed;
                    if (scrollingOffset > gBGtexture.GetHeight())
                    {
                        scrollingOffset = 0;
                    }
                    // rendering background
                    gBGtexture.Render(0, scrollingOffset, NULL, gRenderer, 0.0, NULL, SDL_FLIP_NONE, 0);
                    gBGtexture.Render(0, scrollingOffset - gBGtexture.GetHeight(), NULL, gRenderer, 0.0, NULL, SDL_FLIP_NONE, 0);
                    // rendering player and score
                    player->Render(frame, gRenderer, false);
                    GameScore.Render(gRenderer, false);
                    //rendering ball and trash
                    for (std::list<Unit *>::iterator it = objectlist.begin(); it != objectlist.end(); ++it)
                    {
                        (*it)->Render(trashframe, gRenderer, false);
                        (*it)->Move();
                    }
                    SDL_RenderPresent(gRenderer);
                    frame = ((SDL_GetTicks() - startTime) * animationRate / 1000) % animationLength;
                    ++delaytrash;
                    ++ballDelay;
                }
                if (ismenuscreen)
                {
                    scrollingOffset = 0;
                    GameScore.set_score(0);
                    delaytrash = 0;
                    frame = 0;
                    trashframe = 0;
                    ballDelay = 0;
                    menu_screen.Render(gRenderer);
                    SDL_RenderPresent(gRenderer);
                }
                if (gameOver)
                {
                    ismenuscreen = false;
                    gamePlay = false;
                    removeall(objectlist);
                    if (win)
                    {
                        win_screen.Render(gRenderer);
                    }
                    else
                    {
                        lose_screen.Render(gRenderer);
                        displayhighscore.set_Text("High Score: ");
                        displayhighscore.set_score(HIGHSCORE.get_score());
                        displayhighscore.Render(gRenderer, false);
                    }
                    GameScore.set_position(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 + 50);
                    GameScore.Render(gRenderer, false);
                    SDL_RenderPresent(gRenderer);
                }
            }
            if (gameOver) // compare score with high score after the game is over
            {
                HIGHSCORE.set_score(GameScore.get_score());
            }
            delete player;
            delete trash;
            delete balls;
            removeall(objectlist);
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError());
                    success = false;
                }
                // iniatialize TTF
                if (TTF_Init() == -1)
                {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
                // initializer Mixer
                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
                {
                    printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;
    // load font
    gFont = TTF_OpenFont("Aerovias Brasil NF.ttf", 32);
    if (gFont == NULL)
    {
        printf("Failed to load TTF font!\n");
        success = false;
    }

    //Load sprite sheet texture
    if (!gSpriteSheetTexture.LoadFromFile("Sprite1-01.png", gRenderer))
    {
        printf("Failed to load sprite sheet texture!\n");
        success = false;
    }
    if (!gBGtexture.LoadFromFile("dg.png", gRenderer))
    {
        printf("Failed to load background texture!\n");
        success = false;
    }
    if (!gPaper.LoadFromFile("paper1.png", gRenderer))
    {
        printf("Failed to load paper texture!\n");
        success = false;
    }
    if (!gMetal.LoadFromFile("tincan.png", gRenderer))
    {
        printf("Failed to load paper texture!\n");
        success = false;
    }
    if (!gPlastic.LoadFromFile("pb1.png", gRenderer))
    {
        printf("Failed to load paper texture!\n");
        success = false;
    }
    if (!gballs.LoadFromFile("balls.png", gRenderer))
    {
        printf("Failed to load paper texture!\n");
        success = false;
    }

    if (!gBGMenuScreen.LoadFromFile("bgmenuscreen.png", gRenderer))
    {
        printf("Failed to load menu screen background texture!\n");
        success = false;
    }
    if (!gBGWinScreen.LoadFromFile("gBGWinScreen.png", gRenderer))
    {
        printf("Failed to load menu screen background texture!\n");
        success = false;
    }
    if (!gBGLoseScreen.LoadFromFile("gBGLoseScreen.png", gRenderer))
    {
        printf("Failed to load menu screen background texture!\n");
        success = false;
    }
    if (!gMenuScreenButtons.LoadFromFile("start_buttons.png", gRenderer))
    {
        printf("Failed to load start screen button texture!\n");
        success = false;
    }
    // load sound
    buttonClick = Mix_LoadWAV("button_click.wav");
    if (buttonClick == NULL)
    {
        printf("Failed to load buttonClick sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    return success;
}
void removeall(list<Unit *> &objectlist)
{
    for (std::list<Unit *>::iterator it = objectlist.begin(); it != objectlist.end(); ++it)
    {
        delete (*it);
    }
    objectlist.clear();
}
void close()
{
    //Free loaded images
    gSpriteSheetTexture.Free();
    gPaper.Free();
    gBGtexture.Free();
    gMetal.Free();
    gPlastic.Free();
    gballs.Free();
    gBGMenuScreen.Free();
    gMenuScreenButtons.Free();
    gBGWinScreen.Free();
    gBGLoseScreen.Free();
    // free sound
    Mix_FreeChunk(buttonClick);
    buttonClick = NULL;
    //closing Font
    TTF_CloseFont(gFont);
    gFont = NULL;
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();
}
