# Trash Attack

## Game brief:

Keeping the environmental concerns in mind, this game is about picking up trash from Habib University's garden. The player not only has to
pick the trash but also classify the trash in proper categories, according to recycling principles.

The player will classify the trash by hitting with ball of colors specific to the type of trash. For instance; different keys will be pressed to hit a paper trash or a metal trash and so on. The player gains 10 points if they hit the trash with the right ball, loses 10 points if hit with the wrong ball. The speed of the game will increase after they have scored 100 points

Player wins when he scores more than 200 points and loses when his score goes in negative.

## Game controls:

Click on "New Game" to play the game.

Press "Left and Right keys" to move the player Left and Right respectively.

Press "M", "B" and "P" to hit metal, plastic and paper trash respectively.

## Team Members:

1) Swaleha Saleem (Team Lead)

2) Farah Naz Khan

3) Rabeea Atif

## Compilation Instruction

Apart from having SDL 2.0 licrary installed, the user should also have:

1) SDL_image 
2) SDL_TTF
3) SDL_mixer

## Game Technical Requirements

###### Polymorphism:

We implemented polymorphism by created a Unit* list names objectlist which would store instances of the classes inheriting form Unit like (metalBall, metal trash etc.)

###### Design Patterns:

Since we had relatively less number of  team members (3 out of 4 members in other groups) therefore we were allowed to scale down our game. We did that by using 3 design patterns instead of the 4 required patterns, which are as follows:

**1)Singleton:** The Player class is a singleton class so that we could create only one player instance.

**2)Factory:** We created a ballFactory that would create different ball instances according to the user input.

**3)Prototype:** We created a prototype class named Unit which had a string attribute named type. We created inherited different Game objects from that prototype class and ObjectFactory which instantiated different game objects and implemented them.

###### Menu with buttons

The start screen serves as menu with buttons of "Play" and "Exit". On click and hover, these button change their states. On clicking the "Play" the user is directed to the game scree. On pressing exit, the game closes.

###### File I/O

File I/O is implemented by saving the highest score ever and updating it if the current score is greater then the highest score.

###### Operator Overloading
 
Operator Overloading is done in Score class to increment the value of score.

###### Memory Management
Memory Management is done by creating and calling deconstructors.

## Game Thematic Requirements

###### Habib University's Context
Habib University's context is set in the game by picking up trash from Habib University's Garden.

###### Interactive
The game is interactive with the user, proceeds with user input. The game starts by clicking on the button, and the player moves and shoots the ball according to the keyboard input.

## Outside Resources
1) Stack Overflow
2) LazyFoo
3) Pacman Sample game.

## Youtube Playlist

[Click here](https://www.youtube.com/channel/UCZX4dih3083J8cT4Scl4MRQ?view_as=subscriber) to view this game's Youtube channel.

## Team Contribution

###### Swaleha Saleem (Team Lead)

1) Took care of logistics (taking care of important deadlines, a working demo etc) and video submission, creation, editing.
2) Designed all the sprites for all the buttons, start screen, winscreen, lose screen.
3) Worked on File I/O and the HighScore class.
4) brainstormed and created all the design patterns and creating required classes for it (ballFactory, ObjectFactory etc.)
5) Contributed on creating button class and screen class.
6) Contributed on integrating the code.

###### Rabeea Atif

1)Hpp and cpp files of all the screens. (Screen, startscreen, win screen, lose screen)

2)Hpp and cpp files of all the trash along  with their sprites rendering on the screen.

3)STL list to render sprites.

4)Initial UML classes implementation

5)Final UML diagram implementation

###### Farah Naz

1) Farah worked on the following classes: Unit, Player, Button, Collision, Score, ball and its children.

2) Also contributed to the development of screens

## No. Of Hours

The game collectively took almost 100-150 hours.

