#pragma once
#ifndef CHECK
#define CHECK




bool nextcheck(char** board, int p1, int p2, int q1, int q2) {
    if ((p1 == q1 + 1 || p1 == q1 - 1) && (p2 == q2)) {
        if (board[p1][p2] == board[q1][q2])
            return true;
    }
    if ((p2 == q2 + 1 || p2 == q2 - 1) && (p1 == q1)) {
        if (board[p1][p2] == board[q1][q2])
            return true;
    }
    return false;
}

bool linecheck(char** board, int p1, int p2, int q1, int q2) {
    if (p1 == q1) {
        int y, x, dem = 0;
        if (p2 > q2) {
            x = q2;
            y = p2;
        }
        else {
            x = p2;
            y = q2;
        }
        for (int i = x; i <= y; i++) {
            if (board[p1][i] != 0) {
                dem++;
                if (dem == 2) return false;
            }
        }
        if ((dem == 1) && ((!board[p1][p2] != 0 && board[q1][q2] != 0) || (board[p1][p2] != 0 && !board[q1][q2] != 0))) {//sai
            return true;
        }
        else if (dem == 0) {
            return true;
        }
        return false;
    }
    if (p2 == q2) {
        int x, y, dem = 0;
        if (p1 > q1) {
            x = q1;
            y = p1;
        }
        else {
            x = p1;
            y = q1;
        }
        for (int i = x; i <= y; i++) {
            if (board[i][p2] != 0) {
                dem++;
                if (dem == 2) return false;
            }
        }
        if ((dem == 1) && ((!board[p1][p2] != 0 && board[q1][q2] != 0) || (board[p1][p2] != 0 && !board[q1][q2] != 0))) {//sai
            return true;
        }
        else if (dem == 0) {
            return true;
        }
        return false;
    }
    return false;
}

bool Icheck_1(char** board, int p1, int p2, int q1, int q2) {
    if (p1 == q1) {
        int y, x, dem = 0;
        if (p2 > q2) {
            x = q2;
            y = p2;
        }
        else {
            x = p2;
            y = q2;
        }
        for (int i = x + 1; i < y; i++) {
            if (board[p1][i] != 0) {
                return false;
            }
        }
        return true;
    }
    if (p2 == q2) {
        int x, y, dem = 0;
        if (p1 > q1) {
            x = q1;
            y = p1;
        }
        else {
            x = p1;
            y = q1;
        }
        for (int i = x + 1; i < y; i++) {
            if (board[i][p2] != 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Lcheck(char** board, int p1, int p2, int q1, int q2) {
    if (p1 == q1 || p2 == q2) {
        return false;
    }
    bool c1, c2;
    if (!board[p1][q2] != 0) {
        c1 = linecheck(board, p1, p2, p1, q2);
        c2 = linecheck(board, q1, q2, p1, q2);
        if (c1 && c2) {
            return true;
        }
    }
    if (!board[q1][p2] != 0) {
        c1 = linecheck(board, p1, p2, q1, p2);
        c2 = linecheck(board, q1, q2, q1, p2);
        if (c1 && c2) {
            return true;
        }
    }
    return false;
}

bool Zcheck(char** board, int p1, int p2, int q1, int q2) {
    if (p1 == q1 || p2 == q2) {
        return false;
    }
    bool c1, c2, c3;
    int x, y;
    if (q2 < p2) {
        x = q2;
        y = p2;
    }
    else {
        x = p2;
        y = q2;
    }
    for (int i = x + 1; i < y; i++) {
        c3 = linecheck(board, p1, i, q1, i);
        if (c3) {
            c1 = linecheck(board, p1, p2, p1, i);
            c2 = linecheck(board, q1, q2, q1, i);
            if (c1 && c2)
                return true;
        }
    }
    if (q1 < p1) {
        x = q1;
        y = p1;
    }
    else {
        x = p1;
        y = q1;
    }
    for (int i = x + 1; i < y; i++) {
        c3 = linecheck(board, i, p2, i, q2);
        if (c3) {
            c1 = linecheck(board, p1, p2, i, p2);
            c2 = linecheck(board, q1, q2, i, q2);
            if (c1 && c2)
                return true;
        }
    }
    return false;
}

bool Ucheck(char** board, int p1, int p2, int q1, int q2, unsigned short height, unsigned short width) {
    if (((p1 == q1) && (p1 == 0 || p1 == height - 1) || ((p2 == q2) && (p2 == 0 || q2 == width - 1)))) {
        return true;
    }
    bool c1, c2, c3;
    int x, y;
    if (q2 < p2) {
        x = q2;
        y = p2;
    }
    else {
        x = p2;
        y = q2;
    }
    for (int i = 0; i < width; i++) {
        if (i <= x || i >= y) {
            c3 = linecheck(board, p1, i, q1, i);
            if (c3) {
                c1 = linecheck(board, p1, p2, p1, i);
                c2 = linecheck(board, q1, q2, q1, i);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 0 || i == (width - 1)) {
                c1 = linecheck(board, p1, p2, p1, i);
                c2 = linecheck(board, q1, q2, q1, i);
                if ((c1 && c2) || (c1 && q2 == i) || (p2 == i && c2)) {
                    return true;
                }
            }
        }
    }

    if (q1 < p1) {
        x = q1;
        y = p1;
    }
    else {
        x = p1;
        y = q1;
    }
    for (int i = 0; i < height; i++) {
        if (i <= x || i >= y) {
            c3 = linecheck(board, i, p2, i, q2);
            if (c3) {
                c1 = linecheck(board, p1, p2, i, p2);
                c2 = linecheck(board, q1, q2, i, q2);
                if (c1 && c2) {
                    return true;
                }
            }
            else if (i == 0 || i == (height - 1)) {
                c1 = linecheck(board, p1, p2, i, p2);
                c2 = linecheck(board, q1, q2, i, q2);
                if ((c1 && c2) || (c1 && q1 == i) || (p1 == i && c2)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool allcheck(char** board, int p1, int p2, int q1, int q2, unsigned short height, unsigned short width) {
    if (nextcheck(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (Icheck_1(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (Lcheck(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (Zcheck(board, p1, p2, q1, q2)) {
        return true;
    }
    else if (Ucheck(board, p1, p2, q1, q2, height, width)) {
        return true;
    }
    return false;
}

bool checkValidPairs(char** board, unsigned short height, unsigned short width) {
    char check = 'A';
    while (check >= 'A' && check <= 'Z') {
        int cnt = 0;
        int* pos = new int[height * width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == check && board[i][j] != 0) {
                    pos[cnt++] = i;
                    pos[cnt++] = j;
                }
            }
        }
        for (int i = 0; i < cnt - 2; i += 2) {
            for (int j = i + 2; j < cnt; j += 2) {
                if (allcheck(board, pos[i], pos[i + 1], pos[j], pos[j + 1], height, width)) {
                    delete[] pos;
                    return true;
                }
            }
        }
        check++;
        delete[] pos;
    }
    return false;
}


#endif
