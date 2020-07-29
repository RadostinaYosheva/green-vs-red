// ### This is a draft of the project
// ### There is nothing in addition to the task 
// ### task.cpp is not connected to the other files


#include <iostream>
#include <string>


// Check if the current cell is in the array
bool isValid (int width, int height, int cellX, int cellY){
    return (0 <= cellX) && (cellX < width) && (0 <= cellY) && (cellY < height);
}

// Check if the current cell is the target
bool isNotTarget (int targetX, int targetY, int cellX, int cellY){
    return (targetX != cellX) || (targetY != cellY);
}

// Check if the current cell is green (labeled '1')
bool isGreen(std::string *grid, int cellX, int cellY){
    return grid[cellY][cellX] == '1';
}

// Count all the neighbour cell that are green by iterating the array including the target and his neighbours
int greenNeighbours (std::string *grid, int width, int height, int targetX, int targetY){
    int counter = 0;

    for (int row = targetY - 1; row <= targetY + 1; row++){
        for (int column = targetX - 1; column <= targetX + 1; column++){
            if (isValid(width, height, column, row) && isNotTarget(targetX, targetY, column, row) && isGreen(grid, column, row)){
                counter++;
            }
        }
    }

    return counter;
}

// Check if the current cell should be green in the next generation acording to the rules
bool shouldBeGreen(std::string *grid, int width, int height, int cellX, int cellY){
    if (grid[cellY][cellX] == '0'){
        return greenNeighbours(grid, width, height, cellX, cellY) == 3 ||
                greenNeighbours(grid, width, height, cellX, cellY) == 6;

    } else {
        return greenNeighbours(grid, width, height, cellX, cellY) == 2 || 
                greenNeighbours(grid, width, height, cellX, cellY) == 3 ||
                greenNeighbours(grid, width, height, cellX, cellY) == 6;
    }
}

// Iterate through the grid to create the next generation by applying the rules
void applyRules(std::string *grid, int width, int height){
    std::string *nextGeneration = new std::string[height];

    for (int row = 0; row < height; row++){
        for (int column = 0; column < width; column++){
            if (shouldBeGreen(grid, width, height, column, row)){
                nextGeneration[row][column] = '1';
            } else {
                nextGeneration[row][column] = '0';
            }
        }
    }

    for (int row = 0; row < height; row++){
        for (int column = 0; column < width; column++){
            grid[row][column] = nextGeneration[row][column];
        }
    }

    delete[] nextGeneration;
}

int main()
{
    int width, height, targetX, targetY, N;
    int counter = 0;

    std::cout << "Enter width and height : ";
    std::cin >> width >> height;

    std::string *grid = new std::string[height];

    std::cout << "\nEnter the grid :" << std::endl;
    for (int i = 0; i < height; i++){
        std::cin >> grid[i];
    }

    std::cout << "\nEnter the coordinates of the target cell : ";
    std::cin >> targetX >> targetY;

    std::cout << "\nEnter the number N of generations: ";
    std::cin >> N;


    // Apply the rules for generations zero through N
    for (int i = 0; i <= N; i++){
        // Count the cell if it is green
        if (grid[targetY][targetX] == '1'){
            counter++;
        }
        
        applyRules(grid, width, height);
        
    }

    std::cout << "The target cell is green for " << counter << " generations." << std::endl;

    delete[] grid;

    return 0;
}