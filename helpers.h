#ifndef _HELPERS_H
#define _HELPERS_H

// ##### DELETE #####
void test(int x, int y){
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
}

bool areValidGridBorders(int width, int height){            // rename
    return (0 < width) && (width <= height) && (height < 1000);
}

bool areValidCoordinates (int width, int height, int targetX, int targetY){
    return (0 <= targetX) && (targetX < width) 
        && (0 <= targetY) && (targetY < height);
}

void inputWidthAndHeight(int width, int height){
    // Message for input
    std::cout << "Enter width and height: ";
    std::cin >> width >> height;
    std::cout << std::endl;

    while (areValidGridBorders(width, height)){
        std::cout << "Error: Invalid values of width or/and height (0 < x <= y < 1000)\n" << std::endl;
        std::cout << "Enter width and height: ";
        std::cin >> width >> height;
        std::cout << std::endl;
    }
}

#endif
