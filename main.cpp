#include "tools.h"

using namespace std;

int main()
{
    vector<string> input(importInput("input.txt"));
    vector<int> lengthSequence(stringVectorConvertedToIntVector(input));
    vector<int> initList(initializeList(256));
    cout << "Resultat partie 1 : " << part1Result(initList, lengthSequence) << endl << endl;;

    vector<int> input2(importInputPart2("input.txt"));
    displayIntVector(input2);
    cout << "taille : " << input2.size() << endl;

    return 0;
}
