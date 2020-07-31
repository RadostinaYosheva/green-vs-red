#include "grid.h"

void GameOfLife::allocateGrid(){
    grid = new bool*[height]; 
    for (int i = 0; i < height; i++){
        grid[i] = new bool[width];
    }
}

void GameOfLife::copyGrid(const GameOfLife& other){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            this->grid[i][j] = other.grid[i][j];
        }
    }
}

GameOfLife::GameOfLife(int width, int height){
    this->width = width;
    this->height = height;
    allocateGrid();
}

GameOfLife::GameOfLife(const GameOfLife& other){
    this->height = other.height;
    this->width = other.width;
    allocateGrid();
    copyGrid(other);
}

GameOfLife::~GameOfLife(){
    // for(int i = 0; i < height; i++){
    //     std::cout << " " << grid[i] << std::endl;
    // }

    for (int i = 0; i < height; i++){
        delete[] grid[i];
    }

    delete[] grid;
}

// Check if the current cell is green (labeled 1)
bool GameOfLife::isGreenCell(int cellX, int cellY) const{
    return grid[cellY][cellX] == 1;
}

int GameOfLife::getGreenNeighbours(int targetX, int targetY) const{
    int counter = 0;

    for (int row = targetY - 1; row <= targetY + 1; row++){
        for (int column = targetX - 1; column <= targetX + 1; column++){
            if (isValidCell(column, row) && isNotTarget(targetX, targetY, column, row) && isGreenCell(column, row)){
                counter++;
            }
        }
    }

    return counter;
}

bool GameOfLife::shouldBeGreen(int cellX, int cellY) const {
    if (grid[cellY][cellX] == 0){
        return getGreenNeighbours(cellX, cellY) == 3 ||
               getGreenNeighbours(cellX, cellY) == 6; 
    } else {
        return getGreenNeighbours(cellX, cellY) == 2 ||
               getGreenNeighbours(cellX, cellY) == 3 ||
               getGreenNeighbours(cellX, cellY) == 6;
    }
}

// Check if the current cell is in the array
bool GameOfLife::isValidCell (int cellX, int cellY) const{
    return (0 <= cellX) && (cellX < width) && (0 <= cellY) && (cellY < height);
}

// Check if the current cell is the target
bool GameOfLife::isNotTarget (int targetX, int targetY, int cellX, int cellY) const{
    return (targetX != cellX) || (targetY != cellY);
}

void GameOfLife::nextGeneration() {
    bool ** newGrid = new bool*[height]; 
    for (int i = 0; i < height; i++){
        newGrid[i] = new bool[width];
    }

    //seed new
    for (int row = 0; row < height; row++){
        for (int column = 0; column < width; column++){
            if (shouldBeGreen(column, row)){
                newGrid[row][column] = 1;
            } else {
                newGrid[row][column] = 0;
            }
        }
    }

    //delete old
    for (int i = 0; i < height; i++){
        delete[] grid[i];
    }

    delete[] grid;

    grid = newGrid;
}

std::istream& operator>>(std::istream& in, const GameOfLife& generation){
    for (int i = 0; i < generation.height; i++){
        for (int j = 0; j < generation.width; j++){
            in >> generation.grid[i][j];
        }
    }

    return in;
}
