#include "QuickSortAll.h"

/*******************************************************************************
	modified partition function for QuickSort using median as pivot
*******************************************************************************/
int QuickSortAll :: modified_Partition_Quick(vector<int>& array, int start, int end, int median){
	//block of code to find the index of the median
	int index;
	for(int i = start; i <= end; i++)
		if(array[i] == median)
		    index = i;
	swap(array[end], array[index]);
	Partition p;
	return p.partition(array, start, end);
}

/*******************************************************************************
	All QuickSort Functions combined
*******************************************************************************/
void QuickSortAll :: quickSort(vector<int>& array, int start, int end, char choice){
    if(start < end){
        int pivot_index;
        int median;
        switch(choice){
            case 'A' : Partition p;
                       pivot_index = p.partition(array, start, end);
                       break;
            case 'B' : Partition p2;
                       pivot_index = p2.randomised_partition(array, start, end);
                       break;
            case 'C' : RandomSelectAlgo r;
                       median = r.randomised_Select(array, start, end, (end - start + 1) / 2);
                       pivot_index = modified_Partition_Quick(array, start, end, median);
                       break;
            case 'D' : SelectAlgoMedianAsPivot s;
                       median = s.select_Algo(array, start, end, (end - start + 1) / 2);
                       pivot_index = modified_Partition_Quick(array, start, end, median);
                       break;
            case 'E' : MedianOfMedians m;
                       median = m.median_Of_Medians(array, start, end, (end - start + 1) / 2);
                       pivot_index = modified_Partition_Quick(array, start, end, median);
                       break;
        }
        quickSort(array, start, pivot_index - 1, choice);
        quickSort(array, pivot_index + 1, end, choice);
    }
}
