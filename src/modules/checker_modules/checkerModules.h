#include <iostream>
#include <vector>

using std::vector;

#ifndef CHECKERMODULES_H
#define CHECKERMODULES_H

bool fullDown(vector<vector<int>> board, int length, int currentFloor, int position) {
    if (currentFloor == (length - 1)) { return true; }

    int currentPosition = board[currentFloor + 1][position];
    currentFloor++;

    while (!currentPosition) {
        if (currentFloor == (length - 1)) { return true; } 

        currentFloor++;
        currentPosition = board[currentFloor][position];
    }

    return false;
}

bool fullUp(vector<vector<int>> board, int length, int currentFloor, int position) {
    if (!currentFloor) { return true; }

    int currentPosition = board[currentFloor - 1][position];
    currentFloor--;

    while (!currentPosition) {
        if (!currentFloor) { return true; }

        currentFloor--;
        currentPosition = board[currentFloor][position];
    }

    return false;
}

bool _top_right(vector<vector<int>> board, int length, int currentFloor, int position) {
    if ( (position == (length - 1)) || (!currentFloor) ) { return true; }

    int currentPosition = board[currentFloor - 1][position + 1];
    currentFloor--;
    position++;

    while (!currentPosition) {
        if ( (position == (length - 1)) || (!currentFloor) ) { return true; }

        currentFloor--;
        position++;
        currentPosition = board[currentFloor][position];
    }

    return false;
}

bool _top_left(vector<vector<int>> board, int length, int currentFloor, int position) {
    if ( (!position) || (!currentFloor) ) { return true; }

    int currentPosition = board[currentFloor - 1][position - 1];
    currentFloor--;
    position--;

    while (!currentPosition) {
        if ( (!position) || (!currentFloor) ) { return true; }

        currentFloor--;
        position--;
        currentPosition = board[currentFloor][position];
    }

    return false;
}

bool _bottom_right(vector<vector<int>> board, int length, int currentFloor, int position) {
    if ( (currentFloor == (length - 1)) || (position == (length - 1)) ) { return true; }

    int currentPosition = board[currentFloor + 1][position + 1];
    currentFloor++;
    position++;

    while (!currentPosition) {
        if ( (currentFloor == (length - 1)) || (position == (length - 1)) ) { return true; }

        currentFloor++;
        position++;
        currentPosition = board[currentFloor][position];
    }

    return false;
}

bool _bottom_left(vector<vector<int>> board, int length, int currentFloor, int position) {
    if ( (currentFloor == (length - 1)) || (!position) ) { return true; }

    int currentPosition = board[currentFloor + 1][position - 1];
    currentFloor++;
    position--;

    while (!currentPosition) {
        if ( (currentFloor == (length - 1)) || (!position) ) { return true; }

        currentFloor++;
        position--;
        currentPosition = board[currentFloor][position];
    }

    return false;
}

bool fullAcross(vector<vector<int>> board, int length, int currentFloor, int position) {
    bool _top_right_access = _top_right(board, length, currentFloor, position);
    bool _top_left_access = _top_left(board, length, currentFloor, position);
    bool _bottom_right_access = _bottom_right(board, length, currentFloor, position);
    bool _bottom_left_access = _bottom_left(board, length, currentFloor, position);

    if ( _top_right_access && _top_left_access && _bottom_right_access && _bottom_left_access) { return true; }
    else { return false; }
}

#endif
