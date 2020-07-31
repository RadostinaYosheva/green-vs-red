#ifndef _HELPERS_H
#define _HELPERS_H

#include "grid.h"

bool areNotValidCoordinates (int width, int height, int targetX, int targetY){
    return (targetX < 0) || (targetX > width) 
        || (targetY < 0) || (targetY > height);
}

void inputWidthAndHeight(int& width, int& height){
    // Message for input
    std::cout << "Enter width and height : ";
    std::cin >> width >> height;
    std::cout << std::endl;
}

void inputCoordinates(int width, int height, int& targetX, int& targetY){
    // Message for input
    std::cout << "\nEnter target cell's coordinates : ";
    std::cin >> targetX >> targetY;

    while (areNotValidCoordinates(width, height, targetX, targetY)) {
        std::cout << "Error: Invalid coordinates.\n" << std::endl;
        std::cout << "Enter target cell's coordinates : ";
        std::cin >> targetX >> targetY;
        std::cout << std::endl;
    }
}

void inputGrid(GameOfLife& grid){
    std::cout << "\nEnter the grid :" << std::endl;
    std::cin >> grid;
}

void inputNumberGenerations(int& N){
    std::cout << "\nEnter the number N of generations: ";
    std::cin >> N;
}

#endif
