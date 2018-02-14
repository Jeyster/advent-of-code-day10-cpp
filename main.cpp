#include "tools.h"
#include <iomanip>
#include <cmath>

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
    //displayIntVector(lengthSequence2);
    vector<int> initList2(initializeList(256));
    knotTyingProcesses(initList2, lengthSequence2, 64);
    //displayIntVector(initList2);

    vector<int> denseHash(createDenseHashXOR(initList2));
    //displayIntVector(denseHash);
    cout << "Resultat partie 2 : ";
    displayHashCode(denseHash);
    cout << endl;

    return 0;
}
