// ----- INCLUDES ----- //
#include <stdio.h>
#include <stdint.h>
#include "raytracer.h"

int getOffset(uint8_t x, uint8_t y)
{
    return (SCREEN_COLS + 2 + 2) * y + x;
}

void formatScreen(void)
{
    for (int stepY = 0; stepY < SCREEN_ROWS; stepY++)
    {
        for (int stepX = 0; stepX < SCREEN_COLS; stepX++)
        {
            displayBuffer[getOffset(1 + stepX, 1 + stepY)] = ' ';
        }
    }

    // Row lines
    for (int step = 0; step < SCREEN_COLS; step++)
    {
        displayBuffer[getOffset(1 + step, 0)] = '-';
        displayBuffer[getOffset(1 + step, SCREEN_ROWS + 1)] = '-';
    }

    // Column lines
    for (int step = 0; step < SCREEN_ROWS; step++)
    {
        displayBuffer[getOffset(0, 1 + step)] = '|';
        displayBuffer[getOffset(SCREEN_COLS + 1, 1 + step)] = '|';
    }

    for (int step = 0; step < (SCREEN_ROWS + 1); step++)
    {
        displayBuffer[getOffset(SCREEN_COLS + 2, step)] = '\x0D';
        displayBuffer[getOffset(SCREEN_COLS + 3, step)] = '\x0A';
    }

    // Corners
    displayBuffer[getOffset(0, 0)] = '+';
    displayBuffer[getOffset(0, SCREEN_ROWS + 1)] = '+';
    displayBuffer[getOffset(SCREEN_COLS + 1, 0)] = '+';
    displayBuffer[getOffset(SCREEN_COLS + 1, SCREEN_ROWS + 1)] = '+';
    displayBuffer[getOffset(SCREEN_COLS + 2, SCREEN_ROWS + 1)] = '\0';
}

void showScreen(void)
{
    printf("%s\n", displayBuffer);
}

int main(int argc, char **argv)
{
    formatScreen();

    printf("'%c'\n", displayBuffer[0]);
    printf("Test\n");
    showScreen();

    return 0;
}
