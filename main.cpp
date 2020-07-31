#include <iostream>
#include "helpers.h"

int main()
{
    int width, height, targetX, targetY, N;
    int counter = 0;

    inputWidthAndHeight(width, height);

    GameOfLife currentGeneration(width, height);

    inputGrid(currentGeneration);
    inputCoordinates(width, height, targetX, targetY);
    inputNumberGenerations(N);

    for (int i = 0; i <= N; i++){
        if (currentGeneration.isGreenCell(targetX, targetY))
            counter++;

        currentGeneration.nextGeneration();
    }

    std::cout << counter << std::endl;

    return 0;
}
