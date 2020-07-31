#include <iostream>
#include "helpers.h"
#include "gameOfLife.h"

int main()
{
    int targetX, targetY, generations;
    
    GameOfLife game;

    std::cin >> game;

    inputCoordinatesAndGenerations(std::cin, targetX, targetY, generations);

    int counter = 0;
    for (int i = 0; i <= generations; i++){
        if (game.isGreenCell(targetX, targetY))
            counter++;

        game.nextGeneration();
    }

    std::cout << counter << std::endl;

    return 0;
}
