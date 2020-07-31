#include <iostream>
#include "gameOfLife.h"
#include "helpers.h"

int main()
{
    // int width, height, targetX, targetY, N;
    // int counter = 0;

    // inputWidthAndHeight(width, height);

    // GameOfLife currentGeneration(width, height);

    // inputGrid(currentGeneration);
    // inputCoordinates(width, height, targetX, targetY);
    // inputNumberGenerations(N);

    int targetX, targetY, n;
    
    GameOfLife game;

    std::cin >> game;

    inputCoordinates(game.getWidth(),
                     game.getHeight(), 
                     targetX, 
                     targetY);

    inputNumberGenerations(n);

    int counter = 0;
    for (int i = 0; i <= n; i++){
        if (game.isGreenCell(targetX, targetY))
            counter++;

        game.nextGeneration();
    }

    std::cout << counter << std::endl;

    return 0;
}
