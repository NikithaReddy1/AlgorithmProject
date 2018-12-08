#include "RandomSelectAlgo.h"

/*******************************************************************************
   Random Select Function
*******************************************************************************/
int RandomSelectAlgo :: randomised_Select(vector<int> array, int start, int end, int index_To_Find){
    if(start == end)
		return array[start];
    Partition p;
	int pivot_index = p.randomised_partition(array, start, end);
	int  pivot = pivot_index - start + 1;
	if(index_To_Find == pivot)
		return array[pivot_index];
	else if(index_To_Find < pivot)
		return randomised_Select(array, start, pivot_index-1,index_To_Find);
	else
		return randomised_Select(array, pivot_index+1, end, index_To_Find-pivot);
}
