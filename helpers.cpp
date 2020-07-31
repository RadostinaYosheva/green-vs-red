#include "helpers.h"

void inputCoordinatesAndGenerations(std::istream& in, int& targetX, int& targetY, int& generations){
    std::string line;
    getline(in, line);
    std::stringstream ss = splitCommaSeparatedStr(line);

    inputCoordinates(ss, targetX, targetY);
    inputGenerations(ss, generations);
}

void inputCoordinates(std::istream& in, int& targetX, int& targetY){
    in >> targetX >> targetY;
}

void inputGenerations(std::istream& in, int& n){
    in >> n;
}
   
std::stringstream splitCommaSeparatedStr(std::string source){
    char delimiter = ',';

    source.erase(std::remove(source.begin(), source.end(), delimiter), source.end());
    std::stringstream ss(source);

    return ss;
}