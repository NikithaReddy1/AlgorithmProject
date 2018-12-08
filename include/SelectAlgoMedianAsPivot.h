#ifndef SELECTALGOMEDIANASPIVOT_H
#define SELECTALGOMEDIANASPIVOT_H

#include "Partition.h"
#include "MedianOfMedians.h"
class SelectAlgoMedianAsPivot
{
    public:
        int modified_Partition_SAlgo(vector<int>&, int, int, int);
        int select_Algo(vector<int>, int, int, int);
};

#endif // SELECTALGOMEDIANASPIVOT_H
