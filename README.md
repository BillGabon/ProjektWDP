# ProjektWDP 
## Libraries & how to compile
This program uses standard libraries:
- <stdio.h>
- <stdlib.h>
- <time.h>
- <string.h>

as well as

- [<raylib.h>](https://www.raylib.com/)

To compile it you need to:
- install gcc compiler
- install raylib
- put [this](https://github.com/raysan5/raylib/blob/master/projects/VSCode/Makefile) file into the project folder
- open terminal in the folder
- type mingw32-make RAYLIB_PATH=C:/raylib/raylib and press enter
## Game description and how to play
This game is inspired by [this](https://moreorless.io/game/country-size) one. Two countries' names show up on screen. One on the left has it's territory shown below. Your task is to guess whether the country on the right is bigger(press arrow up) or smaller(press arrow down). If your answer is right the country on the right will slide to the left guaranteening an endless game. The game ends if your answer is wrong. You'll be able to see the stats compared and earned points on game over screen. Pressing enter results in restarting the game.
 # PL
 ##
 # ProjektWDP
## Biblioteki i sposób kompilacji
Ten program korzysta ze standardowych bibliotek:
- <stdio.h>
- <stdlib.h>
- <time.h>
- <string.h>

jak również

- [<raylib.h>](https://www.raylib.com/)

Aby go skompilować:
- zainstaluj kompilator gcc
- zainstaluj raylib
- umieść plik [ten](https://github.com/raysan5/raylib/blob/master/projects/VSCode/Makefile) do folderu projektu
- otwórz terminal w folderze
- wpisz mingw32-make RAYLIB_PATH=C:/raylib/raylib i naciśnij enter
## Opis gry i jak grać
Ta gra jest inspirowana [tą](https://moreorless.io/game/country-size). Na ekranie pojawiają się nazwy dwóch krajów. Jeden po lewej ma swoje terytorium pokazane poniżej. Twoim zadaniem jest odgadnąć, czy kraj po prawej jest większy (naciśnij strzałkę w górę) czy mniejszy (naciśnij strzałkę w dół). Jeśli Twoja odpowiedź jest prawidłowa, kraj po prawej stronie przesunie się w lewo, gwarantując niekończącą się grę. Gra kończy się, jeśli twoja odpowiedź jest błędna. Będziesz mógł zobaczyć porównanie statystyk i zdobyte punkty w grze na ekranie. Naciśnięcie enter powoduje ponowne uruchomienie gry.
