#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> importInput(std::string const &filename);
void displayVector(std::vector<std::string> const &stringVector);
void displayIntVector(std::vector<int> const &intVector);
std::vector<int> stringVectorConvertedToIntVector(std::vector<std::string> const &stringVector);
std::vector<int> initializeList(int listSize);
int part1Result(std::vector<int> initList, std::vector<int> const &lengthSequence);
std::vector<int> createSublistToReverse(std::vector<int> const &initList, int const &length, int const &currentPosition);
std::vector<int> importInputPart2(std::string const &filename);

#endif // TOOLS_H_INCLUDED
