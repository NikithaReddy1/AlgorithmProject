#ifndef TESTFUNCTIONS_H
#define TESTFUNCTIONS_H

#include "Display.h"
#include "MedianOfMedians.h"
#include "Partition.h"
#include "RandomSelectAlgo.h"
#include "SelectAlgoMedianAsPivot.h"
#include "QuickSortAll.h"
#include <fstream>
#include <chrono>
using namespace std::chrono;

class TestFunctions
{
    public:
        void MedianOfMed();
        void Random_Select_Algo();
        void test_Func_Of_All_Quick_Sort();
};

#endif // TESTFUNCTIONS_H
