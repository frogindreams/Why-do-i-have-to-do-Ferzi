#include <iostream>
#include <vector>

using std::vector;

#ifndef THESHORTESTWAYTOFERZI_H
#define THESHORTESTWAYTOFERZI_H

int mysteryK;

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

    int success = currentFloor + 1;
    int currentPosition = board[currentFloor + 1][position];
    currentFloor++;

    while (!currentPosition) {
        if (currentFloor == (length - 1)) { return true; } 

        success++;
        currentFloor++;
        currentPosition = board[currentFloor][position];
    }

    if (success == length) { return true; }
    else { return false; }
}

bool fullUp(vector<vector<int>> board, int length, int currentFloor, int position) {
    if (!currentFloor) { return true; }

    int success = length - currentFloor;
    int currentPosition = board[currentFloor - 1][position];
    currentFloor--;

    while (!currentPosition) {
        if (!currentFloor) { return true; }

        success++;
        currentFloor--;
        currentPosition = board[currentFloor][position];
    }

    if (success == length) { return true; }
    else { return false; }
}

bool fullRight(vector<vector<int>> board, int length, int currentFloor, int position) {
    if (position == (length - 1)) { return true; }

    int success = position + 1;
    int currentPosition = board[currentFloor][position + 1];
    position++;

    while (!currentPosition) {
        if (position == (length - 1)) { return true; }

        success++;
        position++;
        currentPosition = board[currentFloor][position];
    }

    if (success == length) { return true; }
    else { return false; }
}

bool fullLeft(vector<vector<int>> board, int length, int currentFloor, int position) {
    if (!position) { return true; }

    int success = length - position;
    int currentPosition = board[currentFloor][position - 1];
    position--;

    while (!currentPosition) {
        if (!position) { return true; }

        success++;
        position--;
        currentPosition = board[currentFloor][position];
    }

    if (success == length) { return true; }
    else { return false; }
}

int _top_right(vector<vector<int>> board, int length, int currentFloor, int position) {
    if ( (position == (length - 1)) || (!currentFloor) ) { return 1; }

    int success = position + 1;
    int currentPosition = board[currentFloor - 1][position + 1];
    currentFloor--;
    position++;

    while (!currentPosition) {
        if ( (position == (length - 1)) || (!currentFloor) ) { return 1; }

        success++;
        currentFloor--;
        position++;
        currentPosition = board[currentFloor][position];
    }

    if (success == length) { return true; }
    else { return false; }
}

int _top_left(vector<vector<int>> board, int length, int currentFloor, int position) {
    if ( (!position) || (!currentFloor) ) { return 1; }

    int success = length - position;
    int currentPosition = board[currentFloor - 1][position - 1];
    currentFloor--;
    position--;

    while (!currentPosition) {
        if ( (!position) || (!currentFloor) ) { return 1; }

        success++;
        currentFloor--;
        position--;
        currentPosition = board[currentFloor][position];
    }

    if (success == length) { return true; }
    else { return false; }
}

int _bottom_right(vector<vector<int>> board, int length, int currentFloor, int position) {
    if ( (currentFloor == (length - 1)) || (position == (length - 1)) ) { return 1; }

    int success = position + 1;
    int currentPosition = board[currentFloor + 1][position + 1];
    currentFloor++;
    position++;

    while (!currentPosition) {
        if ( (currentFloor == (length - 1)) || (position == (length - 1)) ) { return 1; }

        success++;
        currentFloor++;
        position++;
        currentPosition = board[currentFloor][position];
    }

    if (success == length) { return true; }
    else { return false; }
}

int _bottom_left(vector<vector<int>> board, int length, int currentFloor, int position) {
    if ( (currentFloor == (length - 1)) || (!position) ) { return 1; }

    int success = length - position;
    int currentPosition = board[currentFloor + 1][position - 1];
    currentFloor++;
    position--;

    while (!currentPosition) {
        if ( (currentFloor == (length - 1)) || (!position) ) { return 1; }

        success++;
        currentFloor++;
        position--;
        currentPosition = board[currentFloor][position];
    }

    if (success == length) { return true; }
    else { return false; }
}

bool fullAcross(vector<vector<int>> board, int length, int currentFloor, int position) {
    int final_preps = 0;
    final_preps += _top_right(board, length, currentFloor, position);
    final_preps += _top_left(board, length, currentFloor, position);
    final_preps += _bottom_right(board, length, currentFloor, position);
    final_preps += _bottom_left(board, length, currentFloor, position);

    if (final_preps == 4) { return true; }
    else { return false; }
}

void getTheShortestWayToFerzi(int TNOFFerzi) {
    auto mysteryK = TNOFFerzi;
    int TNOFplacements = 0;
    vector<vector<int>> allBoard( mysteryK, vector<int> (mysteryK, 0) );

    for (int floor = 0; floor < mysteryK; ++floor) {
        allBoard[floor][0] = 1;
    }

    std::cout << "Variantions:" << '\n';

    for (int floor = 0; floor < mysteryK; ++floor) {
        for (int posOfFeriz = 0; posOfFeriz < mysteryK; ++posOfFeriz) {
            if ( fullDown(allBoard, mysteryK, floor, posOfFeriz) &&
                 fullUp(allBoard, mysteryK, floor, posOfFeriz) &&
                 fullRight(allBoard, mysteryK, floor, posOfFeriz) &&
                 fullLeft(allBoard, mysteryK, floor, posOfFeriz) &&
                 fullAcross(allBoard, mysteryK, floor, posOfFeriz)) {

                ++TNOFplacements;
                showMe(allBoard, mysteryK);
                std::cout << '\n';
            }

            allBoard = shift(allBoard, mysteryK, floor, posOfFeriz);
        }
    }

    std::cout << '\n' << "The number of placements: " << TNOFplacements << '\n';
}

#endif
