#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int hidestat(int position, int *pointer2) // funkcja zwraca przezroczystosc statystyki danego panstwa
{
    if (position == *pointer2)
        return 255;
    else
        return 0;
};

int main()
{

    // struktura do której wczytujemy panstwa i terytorium z plikow
    typedef struct country
    {

        char name[35];
        double territory;
    } country;

    country tablica[200];
    // otwieranie plikow
    FILE *countries = fopen("countries.txt", "r");
    FILE *area = fopen("area.txt", "r");
    for (int x = 0; x < 200; ++x)
    {

        char buff[35];
        if (fgets(buff, 35, countries) == NULL) // jesli koniec pliku to koniec wczytywania
        {
            break;
        }
        strncpy(tablica[x].name, buff, 35);         // kopiuje stringa z nazwa z bufora do tablicy, z ograniczeniem do 35
        fscanf(area, "%lf", &tablica[x].territory); // wczytuje terytorium(float) z pliku do tablicy
    };

    fclose(countries); // zamyka pliki
    fclose(area);

    const int screenWidth = 1200; // szerokość i wysokość okna
    const int screenHeight = 800;
    float posy = screenHeight / 2.5;  // pozycja tekstu na osi oy
    int fontsize1 = 30;               // wielkość czcionki dużej
    int fontsize2 = fontsize1 * 0.75; // wielkość czcionki małej
    int score = 0;                    // wynik
    int rectWidth = screenWidth / 2;  // szerokość prostokąta

    srand(time(NULL));
    // rgb dla tła
    float col11 = rand();
    float col12 = rand();
    float col13 = rand();
    float col21 = rand();
    float col22 = rand();
    float col23 = rand();
    float col31 = rand();
    float col32 = rand();
    float col33 = rand();
    // przesunięcie danych segmentów
    float move1 = 0;
    float move2 = 0;
    float move3 = 0;
    int go = 0; // czy powinno sie przesuwac

    // pozycja startowa danych segmentów
    int rect1pos = 0;
    int rect3pos = screenWidth / 2;
    int rect2pos = screenWidth - 1;

    int panstwo1 = rand() % 197; // losuje liczbe od 1 do 197
    int panstwo2 = rand() % 197;
    while (panstwo2 == panstwo1)
    {
        panstwo2 = rand();
    }

    int panstwo3 = rand() % 197;
    while (panstwo3 == panstwo2)
    {
        panstwo3 = rand();
    }
    Image icon = LoadImage("icon.png");
    InitWindow(screenWidth, screenHeight, "Projekt"); // inicjalizacja okna, docelowe FPS

    SetWindowIcon(icon);
    SetTargetFPS(100);

    int *pointer = &panstwo2;
    int *pointer2 = &panstwo1;

    int lost = 0;

    score = 0;
    lost = 0;
    go = 0;
    col11 = rand();
    col12 = rand();
    col13 = rand();
    col21 = rand();
    col22 = rand();
    col23 = rand();
    col31 = rand();
    col32 = rand();
    col33 = rand();

    move1 = 0;
    move2 = 0;
    move3 = 0;
    rect1pos = 0 - 1;
    rect3pos = screenWidth / 2 - 1;
    rect2pos = screenWidth - 1;
    panstwo1 = rand() % 197;
    panstwo2 = rand() % 197;
    while (panstwo2 == panstwo1)
    {
        panstwo2 = rand();
    }

    panstwo3 = rand() % 197;
    while (panstwo3 == panstwo2 || panstwo3 == panstwo1)
    {
        panstwo3 = rand();
    }
    pointer = &panstwo2;
    pointer2 = &panstwo1;

    while (!WindowShouldClose()) // co klatkę podczas gdy okno jest otwarte wykonujemy
    {
        if (lost == 0)
        {

            if (IsKeyPressed(KEY_UP))
            {
                if (go == 0)
                {
                    if (tablica[*pointer].territory > tablica[*pointer2].territory)
                    {
                        go = 1;
                        ++score;
                    }
                    else
                    {
                        lost = 1;
                    }
                }
            }
            if (IsKeyPressed(KEY_DOWN))
            {
                if (go == 0)
                {
                    if (tablica[*pointer].territory < tablica[*pointer2].territory)
                    {
                        go = 1;
                        ++score;
                    }
                    else
                    {
                        lost = 1;
                    }
                }
            }
            if (go == 1)
            {
                move1 -= GetFrameTime() * 450; // przesuwanie segmentów
                move2 -= GetFrameTime() * 450;
                move3 -= GetFrameTime() * 450;
            }
            if (rect1pos + move1 <= -rectWidth)
            {
                rect1pos = screenWidth + 1;
                move1 = 0;
                col11 = rand();
                col12 = rand();
                col13 = rand();
                go = 0;

                panstwo1 = rand() % 197;
                while (panstwo1 == panstwo3)
                {
                    panstwo1 = rand();
                }
                pointer = &panstwo2;
                pointer2 = &panstwo3;
            }
            if (rect2pos + move2 <= -rectWidth)
            {
                rect2pos = screenWidth + 1;
                move2 = 0;
                col21 = rand();
                col22 = rand();
                col23 = rand();
                go = 0;

                panstwo2 = rand() % 197;
                while (panstwo2 == panstwo1)
                {
                    panstwo2 = rand();
                }
                pointer = &panstwo3;
                pointer2 = &panstwo1;
            }
            if (rect3pos + move3 <= -rectWidth)
            {
                rect3pos = screenWidth + 1;
                move3 = 0;
                col31 = rand();
                col32 = rand();
                col33 = rand();
                go = 0;
                panstwo3 = rand() % 197;
                while (panstwo3 == panstwo1)
                {
                    panstwo3 = rand();
                }
                pointer = &panstwo1;
                pointer2 = &panstwo2;
            }

            BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawRectangle(rect1pos + move1, 0, rectWidth, screenHeight, CLITERAL(Color){col11, col12, col13, 255});
            DrawRectangle(rect2pos + move2, 0, rectWidth, screenHeight, CLITERAL(Color){col21, col22, col23, 255});
            DrawRectangle(rect3pos + move3, 0, rectWidth, screenHeight, CLITERAL(Color){col31, col32, col33, 255});
            DrawText(tablica[panstwo1].name, rect1pos + move1 + rectWidth * 0.10, posy, fontsize1, BLACK);
            DrawText(TextFormat("%.2lf", tablica[panstwo1].territory), rect1pos + move1 + rectWidth * 0.20, posy + 30, fontsize2, CLITERAL(Color){0, 0, 0, hidestat(panstwo1, pointer2)}); // 2 cyfry po kropce
            DrawText(tablica[panstwo2].name, rect2pos + move2 + rectWidth * 0.10, posy, fontsize1, BLACK);
            DrawText(TextFormat("%.2lf", tablica[panstwo2].territory), rect2pos + move2 + rectWidth * 0.20, posy + 30, fontsize2, CLITERAL(Color){0, 0, 0, hidestat(panstwo2, pointer2)});
            DrawText(tablica[panstwo3].name, rect3pos + move3 + rectWidth * 0.10, posy, fontsize1, BLACK);
            DrawText(TextFormat("%.2lf", tablica[panstwo3].territory), rect3pos + move3 + rectWidth * 0.20, posy + 30, fontsize2, CLITERAL(Color){0, 0, 0, hidestat(panstwo3, pointer2)});

            DrawText(TextFormat("%d", score), screenWidth * 0.1, screenHeight * 0.1, (screenHeight + screenWidth) / 2 * 0.1, LIGHTGRAY);
            EndDrawing();
        }
        else
        {
            BeginDrawing();
            DrawRectangle(0, 0, screenWidth, screenHeight, RED);
            DrawText(TextFormat("%d", score), screenWidth * 0.40, screenHeight * 0.4, (screenHeight + screenWidth) / 2 * 0.1, LIGHTGRAY);
            DrawText("Game Over", screenWidth * 0.20, screenHeight * 0.2, (screenHeight + screenWidth) / 2 * 0.1, LIGHTGRAY);
            DrawText(tablica[panstwo1].name, rect1pos + move1 + rectWidth * 0.10, posy, fontsize1, BLACK);
            DrawText(TextFormat("%.2lf", tablica[panstwo1].territory), rect1pos + move1 + rectWidth * 0.20, posy + 30, fontsize2, BLACK);
            DrawText(tablica[panstwo2].name, rect2pos + move2 + rectWidth * 0.10, posy, fontsize1, BLACK);
            DrawText(TextFormat("%.2lf", tablica[panstwo2].territory), rect2pos + move2 + rectWidth * 0.20, posy + 30, fontsize2, BLACK);
            DrawText(tablica[panstwo3].name, rect3pos + move3 + rectWidth * 0.10, posy, fontsize1, BLACK);
            DrawText(TextFormat("%.2lf", tablica[panstwo3].territory), rect3pos + move3 + rectWidth * 0.20, posy + 30, fontsize2, BLACK);

            EndDrawing();
            if (IsKeyPressed(KEY_ENTER))
            {
                score = 0;
                lost = 0;
                go = 0;
                col11 = rand();
                col12 = rand();
                col13 = rand();
                col21 = rand();
                col22 = rand();
                col23 = rand();
                col31 = rand();
                col32 = rand();
                col33 = rand();

                move1 = 0;
                move2 = 0;
                move3 = 0;
                rect1pos = 0 - 1;
                rect3pos = screenWidth / 2 - 1;
                rect2pos = screenWidth - 1;
                panstwo1 = rand() % 197;
                panstwo2 = rand() % 197;
                while (panstwo2 == panstwo1)
                {
                    panstwo2 = rand();
                }

                panstwo3 = rand() % 197;
                while (panstwo3 == panstwo2 || panstwo3 == panstwo1)
                {
                    panstwo3 = rand();
                }
                pointer = &panstwo2;
                pointer2 = &panstwo1;
            }
        }
    }

    CloseWindow();

    return 0;
}
