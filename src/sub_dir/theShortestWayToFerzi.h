#include <iostream>
#include <vector>

using std::vector;

#ifndef THESHORTESTWAYTOFERZI_H
#define THESHORTESTWAYTOFERZI_H

int mysteryK;
int TNOFplacements = 0;

void showMe(vector<vector<int>> board, int length) {
    for (int iterV = 0; iterV < length; ++iterV) {
        for (int iterH = 0; iterH < length; ++iterH) {
            std::cout << board[iterV][iterH] << " ";
        } std::cout << '\n';
    }
}

vector<vector<int>> shift(vector<vector<int>> allBoard, int mysteryK, int floor, int posOfFeriz) {
    allBoard[floor][posOfFeriz] = 0;
    if ((posOfFeriz + 1) != mysteryK) { allBoard[floor][posOfFeriz + 1] = 1; }
    else { allBoard[floor][0] = 1; }

    return allBoard;
}

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

void flashy_dance(vector<vector<int>> allBoard, int mysteryK, int sub_floor) {
    for (int posOfFeriz = 0; posOfFeriz < mysteryK; ++posOfFeriz) {
        if (true /* fullDown(allBoard, mysteryK, sub_floor, posOfFeriz) &&
            fullUp(allBoard, mysteryK, sub_floor, posOfFeriz) &&
            fullAcross(allBoard, mysteryK, sub_floor, posOfFeriz) */) {

            if (!attempts) { return 0; }

            ++TNOFplacements;
            --attempts;
            showMe(allBoard, mysteryK);
            std::cout << '\n';
        }

        allBoard = shift(allBoard, mysteryK, sub_floor, posOfFeriz);
    }
}

int _factorial(int floor) {
    return (floor == 1 || floor == 0) ? 1 : _factorial(floor - 1) * floor;
}

void fireworks(vector<vector<int>> allBoard, int mysteryK, int sub_floor) {
    if (!attempts) { return 0; }

    for (int posOfFeriz = 0; posOfFeriz < mysteryK; ++posOfFeriz) {
        allBoard = shift(allBoard, mysteryK, sub_floor, posOfFeriz);
            
        flashy_dance(allBoard, mysteryK, 0);

        if (sub_floor > 0) {
            fireworks(allBoard, mysteryK, sub_floor - 1);
        }
    }
}

void getTheShortestWayToFerzi(int TNOFFerzi) {
    auto mysteryK = TNOFFerzi;
    int floor = 0;
    vector<vector<int>> allBoard( mysteryK, vector<int> (mysteryK, 0) );

    for (int floor = 0; floor < mysteryK; ++floor) {
        allBoard[floor][0] = 1;
    }

    std::cout << "Variantions:" << '\n';

    flashy_dance(allBoard, mysteryK, floor);

    ++floor;
    while (floor < mysteryK) {
        fireworks(allBoard, mysteryK, floor);
        ++floor;
    }

    std::cout << '\n' << "The number of placements: " << TNOFplacements << '\n';
}

#endif
