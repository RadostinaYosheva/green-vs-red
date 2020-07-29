
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

int Grid::getWidth() const {
    return width;
}

int Grid::getHeight() const {
    return height;
}