#include "gameOfLife.h"
#include <algorithm>
#include <sstream>
#include "helpers.h"

bool** GameOfLife::allocateGrid(){
    bool ** newGrid = new bool*[height]; 
    for (int i = 0; i < height; i++){
        newGrid[i] = new bool[width];
    }

    return newGrid;
}

void GameOfLife::freeGrid(bool ** oldGrid){
    for (int i = 0; i < height; i++){
        delete[] oldGrid[i];
    }

    delete[] oldGrid;
}

void GameOfLife::copyGrid(const GameOfLife& other){
    this->height = other.height;
    this->width = other.width;
    grid = allocateGrid();

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            this->grid[i][j] = other.grid[i][j];
        }
    }
}

GameOfLife::GameOfLife(){
    width = 0;
    height = 0;
    grid = nullptr;
}

GameOfLife::GameOfLife(const GameOfLife& other){
    copyGrid(other);
}

GameOfLife::~GameOfLife(){
    for (int i = 0; i < height; i++){
        delete[] grid[i];
    }

    delete[] grid;
}

GameOfLife& GameOfLife::operator=(const GameOfLife& other){
    if(this != &other){
        copyGrid(other);
    }

    return *this;
}

bool GameOfLife::isGreenCell(int cellX, int cellY) const {
    return grid[cellY][cellX] == GREEN;
}

int GameOfLife::getGreenNeighboursCount(int targetX, int targetY) const {
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
    if (grid[cellY][cellX] == RED){
        return getGreenNeighboursCount(cellX, cellY) == 3 ||
               getGreenNeighboursCount(cellX, cellY) == 6; 
    } else {
        return getGreenNeighboursCount(cellX, cellY) == 2 ||
               getGreenNeighboursCount(cellX, cellY) == 3 ||
               getGreenNeighboursCount(cellX, cellY) == 6;
    }
}

bool GameOfLife::isValidCell (int cellX, int cellY) const {
    return (0 <= cellX) && (cellX < width) && (0 <= cellY) && (cellY < height);
}

bool GameOfLife::isNotTarget (int targetX, int targetY, int cellX, int cellY) const {
    return (targetX != cellX) || (targetY != cellY);
}

void GameOfLife::nextGeneration() {
    bool ** newGrid = allocateGrid();

    for (int row = 0; row < height; row++){
        for (int column = 0; column < width; column++){
            if (shouldBeGreen(column, row)){
                newGrid[row][column] = 1;
            } else {
                newGrid[row][column] = 0;
            }
        }
    }

    freeGrid(grid);

    grid = newGrid;
}

std::istream& operator>>(std::istream& in, GameOfLife& game){
    game.inputWidthAndHeight(in);
    game.grid = game.allocateGrid();
    
    game.inputGrid(in);
    
    return in;
}

void GameOfLife::inputGrid(std::istream& in){
    for (int i = 0; i < height; i++){
        std::string line;
        getline(in, line);
        for(int j = 0; j < line.size(); j++){
            grid[i][j] = (line[j] == '1');
        }
    }
}

void GameOfLife::inputWidthAndHeight(std::istream& in){
    std::string line;
    getline(in, line);
    std::stringstream ss = splitCommaSeparatedStr(line);
    
    ss >> width >> height;
}
