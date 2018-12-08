#ifndef QUICKSORTALL_H
#define QUICKSORTALL_H

#include "Partition.h"
#include "RandomSelectAlgo.h"
#include "SelectAlgoMedianAsPivot.h"
#include "MedianOfMedians.h"
#include <vector>
using namespace std;
class QuickSortAll
{
    public:
        int modified_Partition_Quick(vector<int>&, int, int, int);
        void quickSort(vector<int>&, int, int, char);
};

#endif // QUICKSORTALL_H
