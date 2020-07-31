#ifndef _GRID_H
#define _GRID_H

#include <iostream>
#include <string>

class GameOfLife {
    private:
    int width, height;
    bool **grid;
    void allocateGrid();
    void copyGrid(const GameOfLife&);

    public:
    GameOfLife(int width, int height);
    GameOfLife(const GameOfLife&);
    ~GameOfLife();
    
    bool areNotValidCoordinates (int targetX, int targetY) const;
    bool isGreenCell(int cellX, int cellY) const;
    bool shouldBeGreen(int cellX, int cellY) const;
    bool isValidCell(int cellX, int cellY) const;
    bool isNotTarget(int targetX, int targetY, int cellX, int cellY) const;
    int getGreenNeighbours(int targetX, int targetY) const;
    void nextGeneration();

    friend std::istream& operator>>(std::istream&, const GameOfLife&);
};

#endif