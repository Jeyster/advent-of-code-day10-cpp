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
        /*
        cout << "Iteration numero " << i << endl;
        cout << "Current sublist : " << endl;
        displayIntVector(currentSublist);
        cout << "Current list : " << endl;
        displayIntVector(initList);
        */
        /* !!!!!!!!!!!!! */

        currentPosition = (currentPosition + lengthSequence[i % lengthSequence.size()] + skipSize) % 256;
        ++skipSize;

        /* !!! DEBUG !!! */
        /*
        cout << "Length : " << lengthSequence[i % lengthSequence.size()] << " , position : " << currentPosition << " , skip : " << skipSize << endl << endl;
        */
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
            denseInt = denseInt ^ numbers[i*16+j];
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
        cout << numbers[i] << " ";
    }
    cout << endl;
}
