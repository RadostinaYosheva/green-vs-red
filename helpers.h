#pragma once

#include<iostream>

bool areNotValidCoordinates (int width, int height, int targetX, int targetY){
    return (targetX < 0) || (targetX > width) 
        || (targetY < 0) || (targetY > height);
}

void inputCoordinates(int width, int height, int& targetX, int& targetY){
    std::cout << "\nEnter target cell's coordinates : ";
    std::cin >> targetX >> targetY;

    while (areNotValidCoordinates(width, height, targetX, targetY)) {
        std::cout << "Error: Invalid coordinates.\n" << std::endl;
        std::cout << "Enter target cell's coordinates : ";
        std::cin >> targetX >> targetY;
        std::cout << std::endl;
    }
}

void inputNumberGenerations(int& n){
    std::cout << "\nEnter the number N of generations: ";
    std::cin >> n;
}
