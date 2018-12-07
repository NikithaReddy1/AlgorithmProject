#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <ctime>
#include <fstream>

using namespace std;
using namespace std::chrono;

/*******************************************************************************
	Display function to display the array
*******************************************************************************/
void display(vector<int> array, int start, int end){
   cout<<"The Elements of the array are : ";
   for(int i = start; i <= end; i++)
	   cout<<array[i]<<"   ";
   cout<<endl<<endl<<endl;
}

/*******************************************************************************
	Insertion Sort
*******************************************************************************/
void insertion_Sort(vector<int>& array, int start, int end){
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
   Median Function for Simplified QuickSort
*******************************************************************************/
int median(int first, int second, int third){
   vector<int> temp;
   temp.push_back(first);
   temp.push_back(second);
   temp.push_back(third);

   sort(temp.begin(), temp.end()+1);
   int start = 0;
   int end = temp.size()-1;
   return temp[start + ((end - start) / 2)];
}

/*******************************************************************************
	Finding the median of median using groups of 5
*******************************************************************************/
int median_Of_Medians(vector<int> array, int start, int end, int num_Groups){
	vector<int> temp_Array;
	int temp_End;
	 while(start +  num_Groups <= end){
		temp_End = start + num_Groups;
		//display(array, 0 , array.size()-1);
		insertion_Sort(array, start, temp_End);
		//display(array, 0 , array.size()-1);
		int median = array[start + ((temp_End - start)/2)];
		temp_Array.push_back(median);
		start = temp_End + 1;
	 }
	 if(start <= end){
		//display(array, start, end);
		insertion_Sort(array, start, end);
		//display(array, start, end);
		int median = array[start + ((end-start)/2)];
		temp_Array.push_back(median);
	 }
	 int start_Temp = 0;
	 int End_Temp = temp_Array.size()-1;
	 insertion_Sort(temp_Array, start_Temp, End_Temp);
	 //display(temp_Array, 0, temp_Array.size()-1);
	 return temp_Array[start_Temp + ((End_Temp - start_Temp)/2)];
}

/*******************************************************************************
           Partition function
*******************************************************************************/
int partition(vector<int>& array, int start, int end){
    int x = array[end];
    int i = start-1;
    for(int j = start; j < end; j++){
		if(array[j] <= x){
			i++;
			swap(array[i],array[j]);
		}
    }
    swap(array[i+1], array[end]);
    return i+1;
}

/*******************************************************************************
	modified partition function using median as pivot
*******************************************************************************/
int modified_Partition_SAlgo(vector<int>& array, int start, int end, int pivot){

	//block of code to find the index of the median
	int index;
	for(int i = start; i <= end; i++)
		if(array[i] == pivot)
		    index = i;
	//swap index and end
	swap(array[index], array[end]);
	return partition(array, start, end);
}

/*******************************************************************************
	select algorithm implementation using median to partition
*******************************************************************************/

int select_Algo(vector<int> array, int start, int end, int index_To_Find){
    if(start == end)
		return array[start];
	int pivot = median_Of_Medians(array, start, end, 6);
	int pivot_Index = modified_Partition_SAlgo(array, start, end, pivot);
	int calculated_Index = pivot_Index - start + 1;
	if(index_To_Find == calculated_Index)
		return pivot;
	else if(index_To_Find < calculated_Index)
		return select_Algo(array, start, pivot_Index - 1, index_To_Find);
	else
		return select_Algo(array, pivot_Index + 1, end, index_To_Find - calculated_Index);
}

/*******************************************************************************
	modified partition function for QuickSort using median as pivot
*******************************************************************************/
int modified_Partition_Quick(vector<int>& array, int start, int end){
    int median = median_Of_Medians(array, start, end, 6);
	//block of code to find the index of the median
	int index;
	for(int i = start; i <= end; i++)
		if(array[i] == median)
		    index = i;
	swap(array[end], array[index]);
	return partition(array, start, end);
}

/*******************************************************************************
   Function to generate random element
*******************************************************************************/
int randomElement(int start, int end){
	/*int element;
	do{
		element = (rand() % end) + start;
	}while(element < start || element > end);
	*/

    //Will be used to obtain a seed for the random number engine
	random_device rd;

	//Standard mersenne_twister_engine seeded with rd()
    mt19937 gen(rd());
    uniform_int_distribution<> dis(start, end);
    int element = dis(gen);
	return element;
}

/*******************************************************************************
   Randomised partition function
*******************************************************************************/
int randomised_partition(vector<int>& array,int start,int end){
     int i = randomElement(start, end);
     swap(array[end], array[i]);
     return partition(array, start, end);
}


/*******************************************************************************
   Select Function  using randomised partition
*******************************************************************************/
int randomised_Select(vector<int> array, int start, int end, int i){
    if(start == end)
		return array[start];
	int pivot = randomised_partition(array, start, end);
	int pivot_Index = pivot - start + 1;
	if(i == pivot_Index)
		return array[pivot];
	else if(i < pivot_Index)
		return randomised_Select(array, start, pivot-1,i);
	else
		return randomised_Select(array, pivot+1, end, i-pivot_Index);
}

/*******************************************************************************
   Randomised Quick Sort Function
*******************************************************************************/
void randomised_QuickSort(vector<int>& array,int start,int end){
    if(start < end){
		int pivot_Index = randomised_partition(array, start, end);
		randomised_QuickSort(array, start, pivot_Index-1);
		randomised_QuickSort(array, pivot_Index+1, end);
    }
}

/*******************************************************************************
   Normal Quick Sort Function
*******************************************************************************/
void Normal_QuickSort(vector<int>& array,int start,int end){
    if(start < end){
		int pivot_Index = partition(array, start, end);
		Normal_QuickSort(array, start, pivot_Index-1);
		Normal_QuickSort(array, pivot_Index+1, end);
    }
}

/*******************************************************************************
	QuickSort function using median as pivot
*******************************************************************************/
void quickSort_Median_As_Pivot(vector<int>& array, int start, int end){
    if(start < end){
		int pivot_Index = modified_Partition_Quick(array, start, end);
		quickSort_Median_As_Pivot(array, start , pivot_Index-1);
		quickSort_Median_As_Pivot(array, pivot_Index+1, end);
    }
}


/*******************************************************************************
   Simplified  Quick Sort Function
*******************************************************************************/
void Simplified_QuickSort(vector<int>& array,int start,int end){
	if((end - start + 1) > 7){
		if(start < end){
			int middle = (start  + end ) / 2;
			int pivot;
			if((end - start + 1) > 40){
				int length = (end - start + 1) / 8;
				int pivot1 = median(array[start], array[start + length], array[start + (2 * length)]);
				int pivot2 = median(array[end], array[end - length], array[end - (2 * length)]);
				int pivot3 = median(array[middle], array[middle - length], array[middle + length]);
				pivot = median(pivot1, pivot2, pivot3);
			}
			else{
				pivot = median(array[start], array[middle], array[end]);
			}
			int pivot_Index = modified_Partition_SAlgo(array, start, end, pivot);
			Simplified_QuickSort(array, start, pivot_Index-1);
			Simplified_QuickSort(array, pivot_Index+1, end);
		}
	}
	else{
		insertion_Sort(array, start, end);
	}
}

/*******************************************************************************
**************Begining Of Test Functions****************************************
*******************************************************************************/

/*******************************************************************************
       Test function for Median Of Median using different groups
*******************************************************************************/
void test_Function_For_Median_Finding(){
	int testCases;
    cout<<"Enter the number of test cases: ";
    cin>>testCases;

    int input_Size;
    cout<<"Enter Initial Input Size: ";
    cin>>input_Size;

    ofstream input_SizeFile;
	input_SizeFile.open("inputSize.txt");

    ofstream time_Of_Three;
    time_Of_Three.open("ThreeGroups.txt");

    ofstream time_Of_Five;
    time_Of_Five.open("FiveGroups.txt");

    ofstream time_Of_Seven;
    time_Of_Seven.open("SevenGroups.txt");

    while(testCases > 0){
		vector<int> array;
		for(int i = input_Size; i > 0; i--){
			array.push_back(i);
		}
		randomised_partition(array, 0, array.size()-1);
		randomised_partition(array, 0, array.size()-1);

		//Time test for Three gropus;
		auto start = high_resolution_clock::now();
		cout<<"Three: ";
		cout<<median_Of_Medians(array, 0, array.size()-1, 2)<<endl;
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);

		//writing execution time to file
		time_Of_Three<<duration.count()<<endl;

		//Time test for Five gropus;
		start = high_resolution_clock::now();
		cout<<"Five: ";
		cout<<median_Of_Medians(array, 0, array.size()-1, 4)<<endl;
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);

		//writing execution time to file
		time_Of_Five<<duration.count()<<endl;

		//Time test for Seven gropus;
		start = high_resolution_clock::now();
		cout<<"Seven: ";
		cout<<median_Of_Medians(array, 0, array.size()-1, 6)<<endl;
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);

		//writing execution time to file
		time_Of_Seven<<duration.count()<<endl;

		input_SizeFile<<input_Size<<endl;
	    input_Size += 1000;
	    testCases--;
	}
	time_Of_Three.close();
	time_Of_Five.close();
	time_Of_Seven.close();
    input_SizeFile.close();
}

/*******************************************************************************
   Test function for Comparing Randomised select and Quick Select
*******************************************************************************/
void test_Func_Random_Select_Algo(){
	int testCases;
    cout<<"Enter the number of test cases:";
    cin>>testCases;

    int input_Size;
    cout<<"Enter Initial Input Size: ";
    cin>>input_Size;

    ofstream time_Of_Qselect;
    time_Of_Qselect.open("QuickSelectTime.txt");
    ofstream time_Of_Rselect;
    time_Of_Rselect.open("RandomSelectTime.txt");
    ofstream Size;
    Size.open("SizeOfRandQuickSelect.txt");

    while(testCases > 0){
        vector<int> array;
		for(int i = input_Size; i > 0; i--){
			array.push_back(i);
		}
		//randomised_partition(array, 0, array.size()-1);
		//randomised_partition(array, 0, array.size()-1);

		auto start = high_resolution_clock::now();
		cout<<select_Algo(array, 0, array.size()-1, 0 + (((array.size()-1) - 0) / 2))<<" ";
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		time_Of_Qselect<<duration.count()<<endl;

		start = high_resolution_clock::now();
		cout<<randomised_Select(array, 0, array.size()-1, 0 + (((array.size()-1) - 0) / 2))<<endl;
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		time_Of_Rselect<<duration.count()<<endl;

		Size<<input_Size<<endl;

		input_Size += 100;
		cout<<"TestCase: "<<testCases<<endl;
		testCases--;
    }
    time_Of_Qselect.close();
    time_Of_Rselect.close();
}

/*******************************************************************************
   Test function for Comparing All Quick Sort
*******************************************************************************/
void test_Func_Of_All_Quick_Sort(){
	int testCases;
    cout<<"Enter the number of test cases:";
    cin>>testCases;

    int input_Size;
    cout<<"Enter Initial Input Size: ";
    cin>>input_Size;

    ofstream time_Of_Nor_Quick;
    time_Of_Nor_Quick.open("NormalQuickSort.txt");

    ofstream time_Of_Rand_Quick;
    time_Of_Rand_Quick.open("RandQuickSort.txt");

    ofstream time_Of_Quick_Med;
    time_Of_Quick_Med.open("QuickSortMedian.txt");

    ofstream time_Of_Simp_Quick;
    time_Of_Simp_Quick.open("SimplifiedQuick.txt");

    ofstream SizeOfQuick;
    SizeOfQuick.open("SizeOfQuickSort.txt");

    while(testCases > 0){
        vector<int> array;
		for(int i = input_Size; i > 0; i--){
			array.push_back(i);
		}
		randomised_partition(array, 0, array.size()-1);
		randomised_partition(array, 0, array.size()-1);

		vector<int> array2 = array;
		vector<int> array3 = array;
		vector<int> array4 = array;

		auto start = high_resolution_clock::now();
		Normal_QuickSort(array, 0, array.size()-1);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		time_Of_Nor_Quick<<duration.count()<<endl;

		start = high_resolution_clock::now();
		randomised_QuickSort(array2, 0, array.size()-1);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		time_Of_Rand_Quick<<duration.count()<<endl;

		start = high_resolution_clock::now();
		quickSort_Median_As_Pivot(array3, 0, array.size()-1);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		time_Of_Quick_Med<<duration.count()<<endl;

		start = high_resolution_clock::now();
		Simplified_QuickSort(array4, 0, array.size()-1);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		time_Of_Simp_Quick<<duration.count()<<endl;

		SizeOfQuick<<input_Size<<endl;
		cout<<testCases<<endl;
		testCases--;
		input_Size += 100;
    }
    time_Of_Nor_Quick.close();
    time_Of_Quick_Med.close();
    time_Of_Simp_Quick.close();
    time_Of_Rand_Quick.close();
}
int main()
{
	int choice;
	do{
        cout<<"Select any options below to perform test"<<endl;
	    cout<<"Enter 1--> to compare all quicksort"<<endl;
	    cout<<"Enter 2-->to compare Median of Median And Random Median"<<endl;
	    cout<<"Enter 3--> to compare Three types of median of medians"<<endl;
	    cout<<"Enter 0--> to quit"<<endl;
	    cout<<"Enter Your Choice: ";
	    cin>>choice;
	    switch(choice){
	       case 1: test_Func_Of_All_Quick_Sort();
	               break;
		   case 2: test_Func_Random_Select_Algo();
		           break;
		   case 3: test_Function_For_Median_Finding();
		           break;
	    }
	}while(choice != 0);
    return 0;
}

