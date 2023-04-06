#include "Initiation.h"

using namespace std;

int main ()
{
    unsigned short height, width;
    char** node, **box;
    player p;

    initWindow (0, 0);
    inigame (width, height, box, node, p);

    system ("pause");

    return 0;
}