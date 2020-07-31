#pragma once

#include <iostream>
#include <string>

#define RED 0
#define GREEN 1

class GameOfLife {
    private:
    int width, height;
    bool **grid;

    bool** allocateGrid();
    void freeGrid(bool ** grid);
    void copyGrid(const GameOfLife&);

    bool shouldBeGreen(int cellX, int cellY) const;
    bool isValidCell(int cellX, int cellY) const;
    bool isNotTarget(int targetX, int targetY, int cellX, int cellY) const;
    int getGreenNeighbours(int targetX, int targetY) const;
    
    void inputGrid(std::istream& in);
    void inputWidthAndHeight(std::istream& in);
    
    public:
    GameOfLife();
    GameOfLife(const GameOfLife&);
    ~GameOfLife();
    GameOfLife& operator=(const GameOfLife& other);

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    
    bool isGreenCell(int cellX, int cellY) const;
    void nextGeneration();

    friend std::istream& operator>>(std::istream&, GameOfLife&);
};
