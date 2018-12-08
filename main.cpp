#include <iostream>
#include <cmath>
#include <algorithm>
#include "MedianOfMedians.h"
#include "Partition.h"
#include "Display.h"
#include "RandomSelectAlgo.h"
#include "SelectAlgoMedianAsPivot.h"
#include "QuickSortAll.h"
using namespace std;

int main()
{

    int testCases;
    cout<<"Enter the number of test cases:";
    cin>>testCases;

    int input_Size;
    cout<<"Enter Initial Input Size: ";
    cin>>input_Size;
    while(testCases > 0){
        vector<int> array;
		for(int i = input_Size; i > 0; i--){
			array.push_back(i);
		}

		QuickSortAll q;
		q.quickSort(array, 0, array.size()-1, 'E');
		if(is_sorted(begin(array), end(array)))
		    cout<<"Ok"<<endl;
        else{
            cout<<"Failed"<<endl;
            return -1;
        }
        input_Size += 100;
        testCases--;
    }
   /* vector<int> array = {8, 7, 6, 5, 4, 3, 2, 1,9, 10};
    Display d;
    QuickSortAll q;

    d.display(array, 0, array.size()-1);

    q.quickSort(array, 0, array.size()-1, 'D');
    d.display(array, 0, array.size()-1);
    MedianOfMedians m;
    cout<<"Median Of Medians: "<<m.median_Of_Medians(array, 0, array.size()-1, 2)<<endl;
    Partition p;

    p.randomised_partition(array, 0, array.size()-1);
    d.display(array, 0, array.size()-1);
    cout<<10/2<<endl;
    RandomSelectAlgo r;
    cout<<"Median: "<<r.randomised_Select(array, 0, array.size()-1, 1)<<endl;

    SelectAlgoMedianAsPivot s;
    cout<<"Third Element: "<<s.select_Algo(array, 0, array.size()-1, 2)<<endl;
  */
    return 0;
}
