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
    
    int getWidth() const;
    int getHeight() const;
};

#endif