#include <iostream>
#include <cmath>
#include "MedianOfMedians.h"
#include "Partition.h"
#include "Display.h"
#include "RandomSelectAlgo.h"
#include "SelectAlgoMedianAsPivot.h"
using namespace std;

int main()
{
    vector<int> array = {1, 2,3,4,5};
    MedianOfMedians m;
    cout<<"Median Of Medians: "<<m.median_Of_Medians(array, 0, array.size()-1, 2)<<endl;
    Partition p;
    Display d;
    d.display(array, 0, array.size()-1);
    p.randomised_partition(array, 0, array.size()-1);
    d.display(array, 0, array.size()-1);
    cout<<10/2<<endl;
    RandomSelectAlgo r;
    cout<<"Median: "<<r.randomised_Select(array, 0, array.size()-1, 1)<<endl;

    SelectAlgoMedianAsPivot s;
    cout<<"Third Element: "<<s.select_Algo(array, 0, array.size()-1, 2)<<endl;

    return 0;
}
