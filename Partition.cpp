#include "Partition.h"

/*******************************************************************************
           Partition function
*******************************************************************************/
int Partition :: partition(vector<int>& array, int start, int end){
    int x = array[end];
    int pivot_index = start-1;
    for(int j = start; j < end; j++){
		if(array[j] <= x){
			pivot_index++;
			swap(array[pivot_index], array[j]);
		}
    }
    swap(array[pivot_index+1], array[end]);
    return pivot_index+1;
}

/*******************************************************************************
      Function to generate random element
*******************************************************************************/
int Partition :: randomElement(int start, int end){
	random_device rd;//Will be used to obtain a seed for the random number engine
    mt19937 gen(rd());//Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(start, end);
    int index = dis(gen);
	return index;
}

/*******************************************************************************
       Randomised partition function
*******************************************************************************/
int Partition :: randomised_partition(vector<int>& array,int start,int end){
     int index = randomElement(start, end);
     swap(array[end], array[index]);
     return partition(array, start, end);
}
