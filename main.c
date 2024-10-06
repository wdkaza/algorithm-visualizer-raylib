#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define SHUFFLE_LEN 5


void shuffle(int array[], int length);


int main(void)
{


    const int screenWidth = 1920;
    const int screenHeight = 1080;

    int posX = 20;
    int width = 20;
    int max = SHUFFLE_LEN;

    int array[SHUFFLE_LEN];
    for(int i = 0; i < SHUFFLE_LEN; i++) {
        array[i] = i + 1;
    }

    shuffle(array, SHUFFLE_LEN);

    InitWindow(screenWidth, screenHeight, "woah a window!");

    SetTargetFPS(60); 

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            
            for(int i = 0; i < SHUFFLE_LEN; i++){
                DrawRectangle(posX + (i * 10),100, width, 300, GREEN);
            }
            DrawRectangle(20, 500 - 300, width, 1000, GREEN);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();

    return 0;
}

void shuffle(int array[], int length){
    srand(time(NULL));

    for(int i = 0; i <length; i++){
        int swap_index = rand() % length;
        int temp = array[i];
        array[i] = array[swap_index];
        array[swap_index] = temp;
    }
}