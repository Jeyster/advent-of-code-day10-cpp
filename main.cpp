#include "tools.h"
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    /* PART 1 */
    /*
    vector<string> input(importInput("input.txt"));
    vector<int> lengthSequence(stringVectorConvertedToIntVector(input));
    vector<int> initList(initializeList(256));
    knotTyingProcesses(initList, lengthSequence, 1);
    cout << "Resultat partie 1 : " << initList[0] * initList[1] << endl << endl;;
    */

    /* PART 2 */

    vector<int> lengthSequence2(importInputPart2("test.txt"));
    initializeLengthSequencePart2(lengthSequence2);
    displayIntVector(lengthSequence2);
    vector<int> initList2(initializeList(256));
    knotTyingProcesses(initList2, lengthSequence2, 2);
    displayIntVector(initList2);

    vector<int> denseHash(createDenseHashXOR(initList2));
    displayIntVector(denseHash);
    displayHashCode(denseHash);
    /*
    vector<string> binariesStr(changeIntToString(denseHash));
    displayVector(binariesStr);
    calculateSolutionPart2(binariesStr);
    */

    /*
    vector<int> initList3 {65, 27, 9, 1, 4, 3, 40, 50, 91, 7, 6, 0, 2, 5, 68, 22};
    cout << setbase(10);
    vector<int> denseHash(createDenseHashXOR(initList3));
    displayIntVector(denseHash);
    */

    return 0;
}
