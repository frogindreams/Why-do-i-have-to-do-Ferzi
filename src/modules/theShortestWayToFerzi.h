#include <iostream>
#include <vector>
#include "checker_modules/checkerModules.h"

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

void fullCheckOut(vector<vector<int>> allBoard, int mysteryK) {
    int status = 0;

    for (int floor = 0; floor < mysteryK; ++floor) {
        for (int posOfFeriz = 0; posOfFeriz < mysteryK; ++posOfFeriz) {
            if (allBoard[floor][posOfFeriz]) {
                if (fullAcross(allBoard, mysteryK, floor, posOfFeriz) &&
                    fullUp(allBoard, mysteryK, floor, posOfFeriz) &&
                    fullDown(allBoard, mysteryK, floor, posOfFeriz)) {

                    ++status;
                }
            }
        }
    }

    if (status == mysteryK) {
        showMe(allBoard, mysteryK);
        std::cout << '\n';
        ++TNOFplacements;
    }
} 

void showTime(vector<vector<int>> allBoard, int floor, int mysteryK) {
    if (!floor) {
        for (int posOfFeriz = 0; posOfFeriz < mysteryK; ++posOfFeriz) {
            if (fullAcross(allBoard, mysteryK, floor, posOfFeriz) &&
                fullUp(allBoard, mysteryK, floor, posOfFeriz) &&
                fullDown(allBoard, mysteryK, floor, posOfFeriz)) {

                fullCheckOut(allBoard, mysteryK);
            }

            allBoard = shift(allBoard, mysteryK, floor, posOfFeriz);
        }
    } else {
        for (int posOfFeriz = 0; posOfFeriz < mysteryK; ++posOfFeriz) {
            if (fullAcross(allBoard, mysteryK, floor, posOfFeriz) &&
                fullUp(allBoard, mysteryK, floor, posOfFeriz) &&
                fullDown(allBoard, mysteryK, floor, posOfFeriz)) {

                fullCheckOut(allBoard, mysteryK);
            }

            allBoard = shift(allBoard, mysteryK, floor, posOfFeriz);
            showTime(allBoard, floor - 1, mysteryK);
        }
    }
}

void getTheShortestWayToFerzi(int TNOFFerzi) {
    auto mysteryK = TNOFFerzi;
    vector<vector<int>> allBoard( mysteryK, vector<int> (mysteryK, 0) );

    for (int floor = 0; floor < mysteryK; ++floor) {
        allBoard[floor][0] = 1;
    }

    std::cout << "Variantions:" << '\n';

    for (int floor = 0; floor < mysteryK; ++floor) {
        showTime(allBoard, floor, mysteryK);
    }

    std::cout << '\n' << "The number of placements: " << TNOFplacements << '\n';
}

#endif
