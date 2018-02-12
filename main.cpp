#include "tools.h"

using namespace std;

int main()
{
    /* PART 1 */
    vector<string> input(importInput("input.txt"));
    vector<int> lengthSequence(stringVectorConvertedToIntVector(input));
    vector<int> initList(initializeList(256));
    knotTyingProcesses(initList, lengthSequence, 1);
    cout << "Resultat partie 1 : " << initList[0] * initList[1] << endl << endl;;

    /* PART 2 */
    vector<int> lengthSequence2(importInputPart2("input.txt"));
    initializeLengthSequencePart2(lengthSequence2);
    vector<int> initList2(initializeList(256));
    knotTyingProcesses(initList, lengthSequence, 64);
    displayIntVector(initList);

    return 0;
}
