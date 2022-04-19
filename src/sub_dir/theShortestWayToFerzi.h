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

    while (currentPosition != 1) {
        if (currentFloor == (length - 1)) { return true; } 

        success++;
        currentFloor++;
        currentPosition = board[currentFloor][position];
    }

    if (success == length) { return true; }
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
            if ( fullDown(allBoard, mysteryK, floor, posOfFeriz) ) {
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
