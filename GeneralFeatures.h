#pragma once
#ifndef GENERAL
#define GENERAL

#include <iostream>
#include <string>
#include <string.h>
#include "ConsoleCtrl.h"

using namespace std;

struct player
{
    string name;
    unsigned int score;
    unsigned short turn;
};

void createBox (char** &box)
{
    box = new char *[5];

    for (int i = 0; i < 5; i++)
        box[i] = new char[10];

    strcpy (box[0], " ------- ");
    strcpy (box[1], "|       |");
    strcpy (box[2], "|       |");
    strcpy (box[3], "|       |");
    strcpy (box[4], " ------- ");
}

void printBox (char** box, short x, short y)
{
    for (int i = 0; i < 5; i++)
    {
        goToXY (x, y+i);
        cout << box[i];
    }
}

void printBoard (short width, short height, char** node, char** box, player p)
{
    for (int i = 0; i < height; i++) //y
        for (int j = 0; j < width; j++) //x
        {
            goToXY (j*9, i*5);

            if (node[i][j] != 0)
            {
                printBox (box, j*9, i*5);
                goToXY (j*9 + 4, i*5 + 2);
                setColor (node[i][j] % 15 + 1);
                cout << node[i][j];
                setColor (7);
            }
        }
// Print info player
    setColor (3);
    goToXY (110, 13);
    cout << "Player's name: " << p.name;
    goToXY (110, 14);
    cout << "Turn left: " << p.turn;
    goToXY (110, 15);
    cout << "Score: " << p.score;
// Print tutorial
    setColor (2);
    goToXY (110, 23);
    cout << "Arrow key to move";
    goToXY (110, 24);
    cout << "Press Enter to select";
    goToXY (110, 25);
    cout << "Press ESC to quit";
    setColor (7);
}

void highlightBox (short x, short y, int color)
{
    // 0 black means unselected
    // 112 white means selected now
    // 33 yellow means previous selected
    // 40 green means correct
    // 70 red means wrong

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);

    goToXY (x*9 + 1, y*5 + 1);
    cout << "       ";
    goToXY (x*9 + 1, y*5 + 2);
    cout << " ";
    goToXY (x*9 + 7, y*5 + 2);
    cout << " ";
    goToXY (x*9 + 1, y*5 + 3);
    cout << "       ";
    
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 0);
}

void generateCharacters (char** &node, unsigned short height, unsigned short width)
{
    // Create matrix of characters
    node = new char*[height];
    
    for (int i = 0; i < height; i++)
        node[i] = new char[width];
    
    for (int i = 0; i < height; i++) // Set initial characters (0)
        for(int j = 0; j < width; j++)
            node[i][j] = 0;
    
    // Create characters
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            if (node[i][j] == 0) // If there is 0 character
            {
                node[i][j] = 65 + rand() % 26;

                while (true) // Create pairs of characters
                {
                    int h = 0 + rand() % height;
                    int k = 0 + rand() % width;

                    if (node[h][k] == 0)
                    {
                        node[h][k] = node[i][j];
                        break;
                    }               
                }
            }
        }
}

#endif;