#include "grid.h"
#include "helpers.h"

void Grid::copyGrid(const Grid& other){
    this->width = other.width;
    this->height = other.height;
    for (int i = 0; i < height; i++){
        this->cells[i] = other.cells[i];
    }
}

Grid::Grid(){
    cells = new std::string[height]; 
}

Grid::Grid(int width, int height){
    this->width = width;
    this->height = height;
    cells = new std::string[height];
}

Grid::Grid(const Grid& other){
    copyGrid(other);
}

Grid::~Grid(){
    delete[] cells;
}

Grid& Grid::operator=(const Grid& other){
    if (this != &other){
        copyGrid(other);
    }
    return *this;
}

// Check if the current cell is green (labeled '1')
bool Grid::isGreenCell(int cellX, int cellY) const{
    return cells[cellY][cellX] == '1';
}

int Grid::getWidth() const {
    return width;
}

int Grid::getHeight() const {
    return height;
}

int Grid::getGreenNeighbours(int targetX, int targetY){
    int counter = 0;

    for (int row = targetY - 1; row <= targetY + 1; row++){
        for (int column = targetX - 1; column <= targetX + 1; column++){
            if (isValidCell(width, height, column, row) && isNotTarget(targetX, targetY, column, row) && isGreenCell(column, row)){
                counter++;
            }
        }
    }

    return counter;
}

std::istream& operator>>(std::istream& in, const Grid& grid){
    for (int i = 0; i < grid.getHeight(); i++){
        in >> grid.cells[i];
    }
        return in;
}
