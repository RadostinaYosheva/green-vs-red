#pragma once

#include <iostream>
#include <string>

class GameOfLife {
    private:
    int width, height;
    bool **grid;

    void allocateGrid();
    void copyGrid(const GameOfLife&);
    
    void inputGrid(std::istream& in);
    void inputWidthAndHeight(std::istream& in);
    
    //operator= should be private
    GameOfLife(const GameOfLife&);

    public:
    GameOfLife();
    GameOfLife(int width, int height);
    ~GameOfLife();

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    
    bool isGreenCell(int cellX, int cellY) const;
    bool shouldBeGreen(int cellX, int cellY) const;
    bool isValidCell(int cellX, int cellY) const;
    bool isNotTarget(int targetX, int targetY, int cellX, int cellY) const;
    int getGreenNeighbours(int targetX, int targetY) const;
    void nextGeneration();

    friend std::istream& operator>>(std::istream&, GameOfLife&);
};
