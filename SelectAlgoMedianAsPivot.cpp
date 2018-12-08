#include "SelectAlgoMedianAsPivot.h"

/*******************************************************************************
	modified partition function using median as pivot
*******************************************************************************/
int SelectAlgoMedianAsPivot :: modified_Partition_SAlgo(vector<int>& array, int start, int end, int median){

	//block of code to find the index of the median
	int index;
	for(int i = start; i <= end; i++)
		if(array[i] == median)
		    index = i;
	//swap index and end
	swap(array[index], array[end]);
	Partition p;
	return p.partition(array, start, end);
}

/*******************************************************************************
	select algorithm implementation using median to partition
*******************************************************************************/
int SelectAlgoMedianAsPivot :: select_Algo(vector<int> array, int start, int end, int index_To_Find){
    if(start == end)
		return array[start];
    MedianOfMedians m;
	int median = m.median_Of_Medians(array, start, end, 6);
	int pivot_Index = modified_Partition_SAlgo(array, start, end, median);
	int pivot = pivot_Index - start + 1;
	if(index_To_Find == pivot)
		return median;
	else if(index_To_Find < pivot)
		return select_Algo(array, start, pivot_Index - 1, index_To_Find);
	else
		return select_Algo(array, pivot_Index + 1, end, index_To_Find - pivot);
}
