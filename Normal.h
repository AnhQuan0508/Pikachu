#include "Initiation.h"
#include "Check.h"
#include "GeneralFeatures.h"

using namespace std;

void moveNor (char **node, unsigned short width, unsigned short height, unsigned short &mode, short &px, short &py, short &x0, short &y0, short &x, short &y, short &enterPress, char **box, player &p)
{
    // px, py : previous x0/1, y0/1
    // x0, y0 : location of first selected box
    // x, y : location of selected box now

    int key;

    switch (key = getch())
    {
        case ESC:
            mode = 3;
            return;

        case ENTER:
            enterPress++ ;

            if (enterPress == 2)
            {
                if (allcheck (node, y0, x0, y, x, height, width) && (x != x0 || y != y0))
                {
                    highlightBox (x0, y0, 70);
                    highlightBox (x, y, 70);
                    Sleep (500);
                    node[y0][x0] = 0;
                    node[y][x] = 0;
                    system ("cls");
                    printBoard (width, height, node, box, p);
                } else {
                    highlightBox (x0, y0, 70);
                    highlightBox (x, y, 70);
                    Sleep (500);
                    highlightBox (x0, y0, 0);
                    highlightBox (x, y, 0);
                }

                enterPress = 0;
            } else {
                x0 = x;
                y0 = y;
            }

        case UP:
            for (int i = x; i < width; i++) {
                for (int j = y - 1; j >= 0; j--) {
                    if (node[j][i] != 0) {
                        px = x;
                        py = y;
                        x = i;
                        y = j;
                        return;
                    }
                }
            }

            for (int i = x - 1; i >= 0; i--) {
                for (int j = y - 1; j >= 0; j--) {
                    if (node[j][i] != 0) {
                        px = x;
                        py = y;
                        x = i;
                        y = j;
                        return;
                    }
                }
            }

            for (int i = x; i < width; i++) {
                for (int j = height - 1; j > y; j--) {
                    if (node[j][i] != 0) {
                        px = x;
                        py = y;
                        x = i;
                        y = j;
                        return;
                    }
                }
            }

            for (int i = x; i >= 0; i--) {
                for (int j = height - 1; j > y; j--) {
                    if (node[j][i] != 0) {
                        px = x;
                        py = y;
                        x = i;
                        y = j;
                        return;
                    }
                }
            }

            break;
        case DOWN:
            for (int i = x; i < width; i++) {
                for (int j = y + 1; j < height; j++) {
                    if (node[j][i] != 0) {
                        px = x;
                        py = y;
                        x = i;
                        y = j;
                        return;
                    }
                }
            }

            for (int i = x - 1; i >= 0; i--) {
                for (int j = y + 1; j < height; j++) {
                    if (node[j][i] != 0) {
                        px = x;
                        py = y;
                        x = i;
                        y = j;
                        return;
                    }
                }
            }

            for (int i = x; i < width; i++) {
                for (int j = 0; j < y; j++) {
                    if (node[j][i] != 0) {
                        px = x;
                        py = y;
                        x = i;
                        y = j;
                        return;
                    }
                }
            }

            for (int i = x - 1; i >= 0; i--) {
                for (int j = 0; j < y; j++) {
                    if (node[j][i] != 0) {
                        px = x;
                        py = y;
                        x = i;
                        y = j;
                        return;
                    }
                }
            }
            break;
        case LEFT:
            for (int i = y; i >= 0; i--) {
                for (int j = x - 1; j >= 0; j--) {
                    if (node[i][j] != 0) {
                        px = x;
                        py = y;
                        x = j;
                        y = i;
                        return;
                    }
                }
            }

            for (int i = y + 1; i < height; i++) {
                for (int j = x - 1; j >= 0; j--) {
                    if (node[i][j] != 0) {
                        px = x;
                        py = y;
                        x = j;
                        y = i;
                        return;
                    }
                }
            }

            for (int i = y; i >= 0; i--) {
                for (int j = width - 1; j > x; j--) {
                    if (node[i][j] != 0) {
                        px = x;
                        py = y;
                        x = j;
                        y = i;
                        return;
                    }
                }
            }

            for (int i = y + 1; i < height; i++) {
                for (int j = width - 1; j > x; j--) {
                    if (node[i][j] != 0) {
                        px = x;
                        py = y;
                        x = j;
                        y = i;
                        return;
                    }
                }
            }
            break;
        case RIGHT:
            for (int i = y; i >= 0; i--) {
                for (int j = x + 1; j < width; j++) {
                    if (node[i][j] != 0) {
                        px = x;
                        py = y;
                        x = j;
                        y = i;
                        return;
                    }
                }
            }

            for (int i = y + 1; i < height; i++) {
                for (int j = x + 1; j < width; j++) {
                    if (node[i][j] != 0) {
                        px = x;
                        py = y;
                        x = j;
                        y = i;
                        return;
                    }
                }
            }

            for (int i = y; i >= 0; i--) {
                for (int j = 0; j < x; j++) {
                    if (node[i][j] != 0) {
                        px = x;
                        py = y;
                        x = j;
                        y = i;
                        return;
                    }
                }
            }

            for (int i = y + 1; i < height; i++) {
                for (int j = 0; j < x; j++) {
                    if (node[i][j] != 0) {
                        px = x;
                        py = y;
                        x = j;
                        y = i;
                        return;
                    }
                }
            }
        default:
            break;
    }
}

void NormalGame (unsigned short &width, unsigned short &height, char **box, char** &node, player &p, unsigned short &mode)
{
    short   px, py, // previous x0/1, y0/1
            x0, y0, // first selected box
            x = 0, y = 0, // second selected box
            enterPress = 0; // Enter times

    char c;
    
    width = height = 0;

    while (width <= 3 || width > 14 || height <= 3 || height > 7 || (width * height) % 2 != 0)
    {
        // Let players choose size of board
        cout << "\n4 <= height <= 7\n4 <= width <= 14\nand (Heigh x Width) % 2 = 0\nOnly who plays 7x14 games has name on Leaderboard.\n" << endl;
        cout << "Enter height: ";
        cin >> height;
        cout << "Enter width: ";
        cin >> width;
    }

    generateCharacters (node, height, width);
    system ("cls");
    printBoard (width, height, node, box, p);
    highlightBox (0, 0, 112);
    
    while (checkValidPairs (node, height, width))
    {
        moveNor (node, width, height, mode, px, py, x0, y0, x, y, enterPress, box, p);

        if (mode == 3)
        {
            system ("cls");
            goToXY (50, 20);
            setColor (3);
            cout << "Are you sure to stop, your progress will be lost (Y/N): ";
            setColor (7);
            cin >> c;
            cin.ignore ();

            if (c == 'y' || c == 'Y')
            {
                system ("cls");
                return;
            }
        }

        highlightBox (px, py, 0);

        if (enterPress == 0)      
            highlightBox (x, y, 112);
        else {
            highlightBox (x0, y0, 70);
            highlightBox (x, y, 112);
        }
    }
}