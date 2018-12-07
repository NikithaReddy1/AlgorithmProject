#include <iostream>
#include "MedianOfMedians.h"
using namespace std;

int main()
{
    vector<int> array = {1};
    MedianOfMedians m;
    cout<<"Median: "<<m.median_Of_Medians(array, 0, array.size()-1, 2)<<endl;


    return 0;
}
