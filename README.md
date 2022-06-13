# ProjektWDP 
## Libraries & how to compile
This program uses standard libraries:
- <stdio.h>
- <stdlib.h>
- <time.h>
- <string.h>

as well as

- [<raylib.h>](raylib.com)
To compile it you need to:
-install gcc compiler
-install raylib
-put [this](https://github.com/raysan5/raylib/blob/master/projects/VSCode/Makefile) file into the project folder
-open terminal in the folder
-type mingw32-make RAYLIB_PATH=C:/raylib/raylib and press enter
## Game description and how to play
This game is inspired by [this](https://moreorless.io/game/country-size) one. Two countries' names show up on screen. One on the left has it's territory shown below. Your task is to guess whether the country on the right is bigger(press arrow up) or smaller(press arrow down). If your answer is right the country on the right will slide to the left guaranteening an endless game. The game ends if your answer is wrong. You'll be able to see the stats compared and earned points on game over screen
