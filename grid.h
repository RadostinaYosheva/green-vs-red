#ifndef _GRID_H
#define _GRID_H

#include <iostream>
#include <string>

class Grid {
    private:
    int width, height;
    std::string *cells;

    void copyGrid(const Grid&);

    public:
    Grid();
    Grid(int width, int height);
    Grid(const Grid&);
    ~Grid();
    Grid& operator=(const Grid&);
    
    bool isGreenCell(int cellX, int cellY) const;
    int getWidth() const;
    int getHeight() const;
    int getGreenNeighbours(int targetX, int targetY);

    friend std::istream& operator>>(std::istream&, const Grid&);
};

#endif