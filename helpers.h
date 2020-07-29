#ifndef _HELPERS_H
#define _HELPERS_H

// ##### DELETE #####
void test(int x, int y){
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
}

bool areValidGridBorders(int width, int height){            // rename
    return (0 < width) && (width <= height) && (height < 1000);
}

bool areValidCoordinates (int width, int height, int targetX, int targetY){
    return (0 <= targetX) && (targetX < width) 
        && (0 <= targetY) && (targetY < height);
}

// Check if the current cell is in the array
bool isValidCell (int width, int height, int cellX, int cellY){
    return (0 <= cellX) && (cellX < width) && (0 <= cellY) && (cellY < height);
}

// Check if the current cell is the target
bool isNotTarget (int targetX, int targetY, int cellX, int cellY){
    return (targetX != cellX) || (targetY != cellY);
}

void inputWidthAndHeight(int width, int height){
    // Message for input
    std::cout << "Enter width and height : ";
    std::cin >> width >> height;
    std::cout << std::endl;

    while (!areValidGridBorders(width, height)){
        std::cout << "Error: Invalid values of width or/and height (0 < x <= y < 1000).\n" << std::endl;
        std::cout << "Enter width and height : ";
        std::cin >> width >> height;
        std::cout << std::endl;
    }
}

void inputCoordinates(int width, int height, int targetX, int targetY){
    // Message for input
    std::cout << "\nEnter target cell's coordinates : ";
    std::cin >> targetX >> targetY;

    while (!areValidCoordinates(width, height, targetX, targetY)) {
        std::cout << "Error: Invalid coordinates.\n" << std::endl;
        std::cout << "Enter target cell's coordinates : ";
        std::cin >> targetX >> targetY;
        std::cout << std::endl;
    }
}

void inputGrid(Grid grid){
    std::cout << "\nEnter the grid :" << std::endl;
    for (int i = 0; i < grid.getHeight(); i++){
        std::cin >> grid;
    }
}

void inputNumberGenerations(int N){
    std::cout << "\nEnter the number N of generations: ";
    std::cin >> N;
}

#endif
