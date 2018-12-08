#include "MedianOfMedians.h"

/*******************************************************************************
	                  Insertion Sort
*******************************************************************************/
void MedianOfMedians :: insertion_Sort(vector<int>& array, int start, int end){
    if(start < end){
       for(int j = start + 1; j <= end; j++){
          int key = array[j];
          int i = j - 1;
          while(i >= start && array[i] > key){
              array[i + 1] = array[i];
              i = i - 1;
          }
          array[i + 1] = key;
       }
   }
}

/*******************************************************************************
       Median of Medians of specified group
*******************************************************************************/
int MedianOfMedians :: median_Of_Medians(vector<int> array, int start, int end, int num_Groups){
	vector<int> temp_Array;
	int temp_End;
    while(start +  num_Groups <= end){
       temp_End = start + num_Groups;
       insertion_Sort(array, start, temp_End);
       int median = array[start + ((temp_End - start)/2)];
       temp_Array.push_back(median);
       start = temp_End + 1;
    }
    if(start <= end){
       insertion_Sort(array, start, end);
       int median = array[start + ((end-start)/2)];
       temp_Array.push_back(median);

    }
    int start_Temp = 0;
    int End_Temp = temp_Array.size()-1;
    insertion_Sort(temp_Array, start_Temp, End_Temp);
    return temp_Array[start_Temp + ((End_Temp - start_Temp)/2)];
}
