#pragma once
#ifndef CONSOLECTRL
#define CONSOLECTRL

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define ENTER 13

#include <Windows.h>

void setColor (unsigned short color) // Change color for characters
{
    // 0	    BLACK
    // 1	    BLUE
    // 2	    GREEN
    // 3	    AQUA
    // 4	    RED
    // 5	    PURPLE
    // 6	    YELLOW
    // 7	    WHITE
    // 8	    GRAY
    // 9	    LIGHT BLUE
    // 10 ( A )	LIGHT GREEN
    // 11 ( B )	LIGHT AQUA
    // 12 ( C )	LIGHT RED
    // 13 ( D )	LIGHT PURPLE
    // 14 ( E )	LIGHT YELLOW
    // 15 ( F )	BRIGHT WHITE

	WORD wColor;
    HANDLE hStdOut = GetStdHandle (STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo (hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute (hStdOut, wColor);
    }
}

void goToXY(int x, int y) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(console, cursorPosition);
}

void setCursor(bool visible) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}

void resizeWindow(int x, int y) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, x, y, TRUE);
}

void hideScrollBar() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    GetConsoleScreenBufferInfo(console, &screenBufferInfo);

    COORD new_screen_buffer_size;

    new_screen_buffer_size.X = screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left + 1;
    new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top + 1;

    SetConsoleScreenBufferSize(console, new_screen_buffer_size);
}

void initWindow(int width, int length) {
    resizeWindow(width, length);
    hideScrollBar();
    setCursor(0);
}

#endif