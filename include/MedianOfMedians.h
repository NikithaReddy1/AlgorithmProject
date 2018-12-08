#ifndef MEDIANOFMEDIANS_H
#define MEDIANOFMEDIANS_H
#include <vector>
using namespace std;

class MedianOfMedians
{
    public:
        void insertion_Sort(vector<int>&, int , int);//function to sort array
        int median_Of_Medians(vector<int>, int, int, int);//median of medians function
};

#endif // MEDIANOFMEDIANS_H
