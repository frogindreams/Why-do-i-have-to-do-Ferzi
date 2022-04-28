#include <iostream>
#include "modules/theShortestWayToFerzi.h"

int main() {
    int TNOFFerzi;
    std::cout << "Your K: ";
    std::cin >> TNOFFerzi;
    std::cout << '\n';

    getTheShortestWayToFerzi(TNOFFerzi);
    return 0;
}
