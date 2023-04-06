#pragma once
#ifndef INITIATION
#define INITIATION

#include <iostream>
#include <conio.h>
#include <fstream>
#include <limits>
#include "ConsoleCtrl.h"
#include "GeneralFeatures.h"
#include "Normal.h"

using namespace std;

int mainMenu ()
{
    int choice[4] = {0, 0, 0, 0}, temp, key, curChoice = 0;

    goToXY (35, 2);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
    cout << " ______    __   __  ___      ___       ______  __    __   __    __";
    goToXY (35, 3);
    cout << "|   _  \\  |  | |  |/  /     /   \\     /      ||  |  |  | |  |  |  |";
    goToXY (35, 4);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 3);
    cout << "|  |_)  | |  | |  '  /     /  ^  \\   |  ,----'|  |__|  | |  |  |  |";
    goToXY (35, 5);
    cout << "|   ___/  |  | |    <     /  /_\\  \\  |  |     |   __   | |  |  |  |";
    goToXY (35, 6);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
    cout << "|  |      |  | |  .  \\   /  _____  \\ |  `----.|  |  |  | |  `--'  |";
    goToXY (35, 7);
    cout << "| _|      |__| |__|\\__\\ /__/     \\__\\ \\______||__|  |__|  \\______/";
    goToXY (38, 9);
    cout << "Pikachu Onet Connect - Remake by HVK & VAQ - 22CLC03 - HCMUS\n";

    while (1)
    {
        choice[curChoice] = 1;

        if (choice[0])
        {
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++)
            {
                goToXY (60, 11 + i);
                cout << "             ";
            }

            goToXY (64, 12);
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 112 + 3);
            cout << "NORMAL";
        }
        else
        {
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++)
            {
                goToXY (60, 11 + i);
                cout << "             ";
            }

            goToXY (64, 12);
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 3);
            cout << "NORMAL";
        }

        if (choice[1])
        {
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++)
            {
                goToXY (60, 14 + i);
                cout << "             ";
            }

            goToXY (62, 15);
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 112 + 4);
            cout << "DIFFICULT";
        }
        else
        {
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++)
            {
                goToXY (60, 14 + i);
                cout << "             ";
            }

            goToXY (62, 15);
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
            cout << "DIFFICULT";
        }

        if (choice[2])
        {
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++)
            {
                goToXY (60, 17 + i);
                cout << "             ";
            }

            goToXY (61, 18);
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 112 + 2);
            cout << "LEADERBOARD";
        }
        else
        {
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);

            for (int i = 0; i < 3; i++)
            {
                goToXY (60, 17 + i);
                cout << "             ";
            }

            goToXY (61, 18);
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
            cout << "LEADERBOARD";
        }

        if (choice[3])
        {
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 112);

            for (int i = 0; i < 3; i++)
            {
                goToXY (60, 20 + i);
                cout << "             ";
            }

            goToXY (64, 21);
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 112 + 6);
            cout << "EXIT";
        }
        else
        {
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
            for (int i = 0; i < 3; i++)
            {
                goToXY (60, 20 + i);
                cout << "             ";
            }

            goToXY (64, 21);
            SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
            cout << "EXIT";
        }

        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);

        if (temp = _getch ())
        {
            if (temp != 224 && temp)
            {
                if (temp == ENTER)
                {
                    system ("cls");
                    return curChoice;
                }
            }
            else
            {
                key = _getch ();
                switch (key)
                {
                case UP:
                    choice[curChoice] = 0;
                    if (curChoice > 0)
                        curChoice--;
                    else
                        curChoice = 3;
                    break;
                case DOWN:
                    choice[curChoice] = 0;
                    if (curChoice < 3)
                        curChoice++;
                    else
                        curChoice = 0;
                default:
                    break;
                }
            }
        }
    }
}

void getInfoPlayers (player &p)
{
    setColor (4);
    cout << "!!! Too much characters can cause an error !!!";
    setColor (7);
    cout << "\nEnter your name (maximum 10 characters): ";
    cin >> p.name;
    cin.ignore ();

    p.turn = 3;
    p.score = 0;
}

// void getBackground (char bg[][41])
// {
//     ifstream fin ("pika.txt");

//     if (fin) {
//         for (int i = 0; i < 20; i++)
//         {
//             for (int j = 0; j < 41; j++)
//                 bg[i][j] = fin.get();

//             fin.ignore();
//         }

//         fin.close();
//     } else memset(bg, ' ', sizeof(bg));
// }

// void displayBackground (char bg[][41], int x, int y)
// {
//     SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);

//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < 11; j++)
//         {
//             goToXY ((x + 1) * 10 + j, (y + 1) * 4 + i);
//             cout << bg[y * 4 + i][x * 10 + j];
//         }
//     }

//     SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 7);
// }

void inigame (unsigned short &width, unsigned short &height, char **&box, char **&node, player &p)
{
    unsigned short mode;

    system ("cls");
    setColor (6);
    cout << "Open fullscreen for best performance\n"
         << endl;
    setColor (7);

    system ("pause");
    system ("cls");

    createBox(box);

    while ((mode = mainMenu ()) != 3)
        switch (mode)
        {
        case 0:
            getInfoPlayers (p);
            NormalGame (width, height, box, node, p, mode);
            break;
        case 1:
            getInfoPlayers (p);
            break;
        case 2:
            break;
        default:
            break;
        }
}

#endif