#include "tools.h"
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;

vector<string> importInput(string const &filename)
{
    ifstream myStream(filename.c_str());
    if(!myStream)
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        //exit(0);
    }
    string inputLine;
    getline(myStream, inputLine);

    stringstream ss(inputLine);
    vector<string> result;

    while( ss.good() )
    {
        string substring;
        getline( ss, substring, ',' );
        result.push_back( substring );
    }
    return result;
}

void displayVector(vector<string> const &stringVector)
{
    for(int i(0); i != stringVector.size(); ++i)
    {
        cout << stringVector[i] << endl;
    }
    cout << endl;
}

void displayIntVector(vector<int> const &intVector)
{
    for(int i(0); i != intVector.size(); ++i)
    {
        cout << intVector[i] << endl;
    }
    cout << endl;
}

void displayIntVectorOfVector(vector<vector<int> > const &intVector)
{
    for(int i(0); i != intVector.size(); ++i)
    {
        for(int j(0); j != intVector[i].size(); ++j)
        {
            cout << intVector[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> stringVectorConvertedToIntVector(vector<string> const &stringVector)
{
    vector<int> intVector;
    for(int i(0); i != stringVector.size(); ++i)
    {
        int number(atoi(stringVector[i].c_str()));
        intVector.push_back(number);
    }

    return intVector;
}

vector<int> initializeList(int listSize)
{
    vector<int> initList;
    for(int i(0); i != listSize; ++i)
    {
        initList.push_back(i);
    }

    return initList;
}

void knotTyingProcesses(vector<int> &initList, vector<int> const &lengthSequence, int const &numberOfProcesses)
{
    int currentPosition(0);
    int skipSize(0);

    for(int i(0); i != (lengthSequence.size() * numberOfProcesses); ++i)
    {
        vector<int> currentSublist(createSublistToReverse(initList, lengthSequence[i % lengthSequence.size()], currentPosition));
        reverse(currentSublist.begin(), currentSublist.end());
        for(int j(0); j != currentSublist.size(); ++j)
        {
            initList[(j+currentPosition) % 256] = currentSublist[j];
        }

        /* !!! DEBUG !!! */
        cout << "Iteration numero " << i << endl;
        cout << "Current sublist : " << endl;
        displayIntVector(currentSublist);
        cout << "Current list : " << endl;
        displayIntVector(initList);
        /* !!!!!!!!!!!!! */

        currentPosition = (currentPosition + lengthSequence[i % lengthSequence.size()] + skipSize) % 256;
        ++skipSize;

        /* !!! DEBUG !!! */
        cout << "Length : " << lengthSequence[i % lengthSequence.size()] << " , position : " << currentPosition << " , skip : " << skipSize << endl;
        /* !!!!!!!!!!!!! */
    }
}

vector<int> createSublistToReverse(vector<int> const &initList, int const &length, int const &currentPosition)
{
    vector<int> sublist;
    for(int i(0); i != length; ++i)
    {
        sublist.push_back(initList[(i+currentPosition) % 256]);
    }
    return sublist;
}

vector<int> importInputPart2(string const &filename)
{
    vector<int> input;

    ifstream myStream(filename.c_str());
    if(!myStream)
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        //exit(0);
    }

    char a;
    while(myStream.get(a))
    {
        input.push_back(a);
    }

    return input;
}

void initializeLengthSequencePart2(vector<int> &input)
{
    input.push_back(17);
    input.push_back(31);
    input.push_back(73);
    input.push_back(47);
    input.push_back(23);
}

vector<int> createDenseHashXOR(vector<int> numbers)
{
    vector<int> denseHash;
    for(int i(0); i != numbers.size()/16; ++i)
    {
        int denseInt(numbers[i*16]);
        for(int j(1); j != numbers.size()/16; ++j)
        {
            denseInt = denseInt ^ numbers[j];
        }
        denseHash.push_back(denseInt);
    }
    return denseHash;
}

void displayHashCode(vector<int> numbers)
{
    for(int i(0); i != numbers.size(); ++i)
    {
        cout << setbase(16);
        cout << numbers[i];
    }
    cout << endl;
}

/*
vector<string> convertIntArrayIntoBinaryStringArray(vector<int> intVector)
{
    vector<string> binaryStrVector;
    for(int i(0); i != intVector.size(); ++i)
    {
        binaryStrVector.push_back(bitset<8>(intVector[i]).to_string());
    }
    return binaryStrVector;
}

vector<vector<int> > changeStringToInt(vector<string> input)
{
    vector<vector<int> > inputNumbers;

    for(int i(0); i != input.size(); ++i)
    {
        istringstream stream(input[i]);
        char a;
        vector<int> number;
        while(stream.get(a))
        {
            number.push_back(atoi(&a));
        }
        inputNumbers.push_back(number);
    }

    return inputNumbers;
}

vector<string> changeIntToString(vector<vector<int> > binaryIntegers)
{
    vector<string> binaries;
    for(int i(0); i != binaryIntegers.size(); ++i)
    {
        vector<int> currentBinaryInteger(binaryIntegers[i]);
        string currentStr("");
        ostringstream oss;
        for(int j(0); j != currentBinaryInteger.size(); ++j)
        {
            oss << currentBinaryInteger[j];
        }
        currentStr = oss.str();
        binaries.push_back(currentStr);
    }
    return binaries;
}

vector<vector<int> > createDenseHashXOR(vector<vector<int> > binaryIntegers)
{
    vector<vector<int> > denseHash;
    for(int i(0); i != binaryIntegers.size()/16; ++i)
    {
        vector<int> denseBinary(binaryIntegers[i*16]);
        for(int j(1); j != binaryIntegers.size()/16; ++j)
        {
            for(int k(0); k != binaryIntegers[i*16+j].size(); ++k)
            {
                denseBinary[k] = denseBinary[k] ^ binaryIntegers[i*16+j][k];
            }
        }
        denseHash.push_back(denseBinary);
    }
    return denseHash;
}
*/


