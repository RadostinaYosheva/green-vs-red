#pragma once

#include<iostream>
#include<sstream>
#include<algorithm>

void inputCoordinatesAndGenerations(std::istream& in, int& targetX, int& targetY, int& generations);
void inputCoordinates(std::istream& in, int& targetX, int& targetY);
void inputGenerations(std::istream& in, int& n);
std::stringstream splitCommaSeparatedStr(std::string source);
