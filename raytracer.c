// ----- INCLUDES ----- //
#include <stdio.h>
#include <stdint.h>
#include <math.h>
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

void writePixel(uint8_t x, uint8_t y, uint8_t luminance)
{
    if (x < 0 || x >= SCREEN_COLS || y < 0 || y >= SCREEN_ROWS)
    {
        printf("writePixel: x,y out of bounds!\n");
        return;
    }

    char writeChar;

    switch (luminance)
    {
        case 0:
            writeChar = ' ';
            break;
        case 1:
            writeChar = 'O';
            break;
        default:
            printf("writePixel: undefined luminance\n");
            writeChar = 'X';
            break;
    }

    displayBuffer[getOffset(1 + x, 1 + y)] = writeChar;
}

void showScreen(void)
{
    printf("%s\n", displayBuffer);
}

//------------------------------------------------------------// 
//                    VECTOR MATH FUNCTIONS                   //
//------------------------------------------------------------// 

void vec4_scalar(vec4_t v, float scalar)
{
    v[0] *= scalar;
    v[1] *= scalar;
    v[2] *= scalar;
    v[3] *= scalar;
}

void vec4_add(vec4_t a, vec4_t b)
{
    a[0] += b[0];
    a[1] += b[1];
    a[2] += b[2];
    a[3] += b[3];
}

void vec4_sub(vec4_t a, vec4_t b)
{
    a[0] -= b[0];
    a[1] -= b[1];
    a[2] -= b[2];
    a[3] -= b[3];
}

float vec4_dot(vec4_t a, vec4_t b)
{
    float dotProduct;
    dotProduct = a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
    return dotProduct;
}

float vec4_mag(vec4_t a)
{
    float magnitude;
    magnitude = sqrtf(a[0] * a[0] + a[1] * a[1] + a[2] * a[2] + 
        a[3] * a[3]);
    return magnitude;
}

int main(int argc, char **argv)
{
    // Screen setup
    formatScreen();

    // Render frame
    for (uint8_t y = 0; y < SCREEN_ROWS; y++)
    {
        for (uint8_t x = 0; x < SCREEN_COLS; x++)
        {
        }
    }
    showScreen();

    return 0;
}
