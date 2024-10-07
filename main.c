#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SHUFFLE_LEN 63
#define DELAY 10


void shuffle(int array[], int length);
void swap(int* array, int i, int j);
void bubbleSort(int array[], int n);
void drawArray(int array[], int length, int posX, int width);


int main(void)
{


    const int screenWidth = 1920;
    const int screenHeight = 1080;

    int posX = 20;
    int width = 20;
    int height;


    int array[SHUFFLE_LEN];
    for(int i = 0; i < SHUFFLE_LEN; i++) {
        array[i] = i + 1;
    }
    int n = sizeof(array) / sizeof(array[0]);

    shuffle(array, SHUFFLE_LEN);

    InitWindow(screenWidth, screenHeight, "nice");

    SetTargetFPS(60); 

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------

        if (IsKeyPressed(KEY_SPACE)){
            bubbleSort(array, n);
        }

        for(int i = 0; i < SHUFFLE_LEN; i++){
            DrawRectangle(posX + (i * 30),25, width, (array[i] * 30) / 3, GREEN);
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            DrawText("Press space to sort",500,500,20,YELLOW);

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

void bubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1])
                swap(array, j, j + 1);

                BeginDrawing();
                    ClearBackground(BLACK);
                    drawArray(array, SHUFFLE_LEN, 20, 20);
                EndDrawing(); // i dont know a better way to do this because im dumb as rock so dont question this
        }
    }
}

void swap(int* array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void drawArray(int array[], int length, int posX, int width) {
    for (int i = 0; i < length; i++) {
        DrawRectangle(posX + (i * 30), 25, width, (array[i] * 30) / 3, GREEN);
    }
}
