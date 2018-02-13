#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> importInput(std::string const &filename);
void displayVector(std::vector<std::string> const &stringVector);
void displayIntVector(std::vector<int> const &intVector);
void displayIntVectorOfVector(std::vector<std::vector<int> > const &intVector);
std::vector<int> stringVectorConvertedToIntVector(std::vector<std::string> const &stringVector);
std::vector<int> initializeList(int listSize);
void knotTyingProcesses(std::vector<int> &initList, std::vector<int> const &lengthSequence, int const &numberOfProcesses);
std::vector<int> createSublistToReverse(std::vector<int> const &initList, int const &length, int const &currentPosition);
std::vector<int> importInputPart2(std::string const &filename);
void initializeLengthSequencePart2(std::vector<int> &input);
std::vector<int> createDenseHashXOR(std::vector<int> numbers);
void displayHashCode(std::vector<int> numbers);

/*
std::vector<std::string> convertIntArrayIntoBinaryStringArray(std::vector<int> intVector);
std::vector<std::vector<int> > changeStringToInt(std::vector<std::string> input);
std::vector<std::string> changeIntToString(std::vector<std::vector<int> > binaryIntegers);
std::vector<std::vector<int> > createDenseHashXOR(std::vector<std::vector<int> > binaryIntegers);
*/

#endif // TOOLS_H_INCLUDED
