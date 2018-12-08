#include "TestFunctions.h"

/*******************************************************************************
       Test function for Median Of Median using different groups
*******************************************************************************/
void TestFunctions :: MedianOfMed(){
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
		Partition p;//create object of Partition class
		p.randomised_partition(array, 0, array.size()-1);//randomize the array

		MedianOfMedians m;//create object of Median of Medians class
		auto start = high_resolution_clock::now();//Time test for Three gropus;
		cout<<"Three: ";
		cout<<m.median_Of_Medians(array, 0, array.size()-1, 2)<<"    ";
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		time_Of_Three<<duration.count()<<endl;//writing execution time to file

		start = high_resolution_clock::now();//Time test for Five gropus;
		cout<<"Five: ";
		cout<<m.median_Of_Medians(array, 0, array.size()-1, 4)<<"     ";
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		time_Of_Five<<duration.count()<<endl;//writing execution time to file

		start = high_resolution_clock::now();//Time test for Seven gropus;
		cout<<"Seven: ";
		cout<<m.median_Of_Medians(array, 0, array.size()-1, 6)<<endl;
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);

		time_Of_Seven<<duration.count()<<endl;//writing execution time to file
		input_SizeFile<<input_Size<<endl;//write input size to file
	    input_Size += 1000;
	    testCases--;
	}
	time_Of_Three.close();//close the files
	time_Of_Five.close();
	time_Of_Seven.close();
    input_SizeFile.close();
}

/*******************************************************************************
   Test function for Comparing Randomised select and Quick Select
*******************************************************************************/
void TestFunctions :: Random_Select_Algo(){
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
		Partition p;//object of partition class
		p.randomised_partition(array, 0, array.size()-1);//randomize the array
		auto start = high_resolution_clock::now();
		SelectAlgoMedianAsPivot s;
		cout<<s.select_Algo(array, 0, array.size()-1, array.size() / 2)<<"  ";
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		time_Of_Qselect<<duration.count()<<endl;

		start = high_resolution_clock::now();
		RandomSelectAlgo r;
		cout<<r.randomised_Select(array, 0, array.size()-1, array.size() / 2)<<endl;
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
void TestFunctions :: test_Func_Of_All_Quick_Sort(){
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
    ofstream time_Of_Quick_Rselect;
    time_Of_Quick_Rselect.open("QuickSortRandomSelect.txt");
    ofstream time_Of_Quick_selectAlgo;
    time_Of_Quick_selectAlgo.open("QuickSortQuickSelect.txt");
    ofstream SizeOfQuick;
    SizeOfQuick.open("SizeOfQuickSort.txt");
    while(testCases > 0){
        vector<int> array;
		for(int i = input_Size; i > 0; i--){
			array.push_back(i);
		}
		Partition p;
		p.randomised_partition(array, 0, array.size()-1);
		vector<int> array2 = array;
		vector<int> array3 = array;
		vector<int> array4 = array;
        QuickSortAll q;
		auto start = high_resolution_clock::now();
		q.quickSort(array, 0, array.size()-1, 'A');
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		time_Of_Nor_Quick<<duration.count()<<endl;

		start = high_resolution_clock::now();
		q.quickSort(array, 0, array.size()-1, 'B');
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		time_Of_Rand_Quick<<duration.count()<<endl;

		start = high_resolution_clock::now();
		q.quickSort(array, 0, array.size()-1, 'C');
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		time_Of_Quick_Rselect<<duration.count()<<endl;

		start = high_resolution_clock::now();
		q.quickSort(array, 0, array.size()-1, 'D');
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		time_Of_Quick_selectAlgo<<duration.count()<<endl;

		start = high_resolution_clock::now();
		q.quickSort(array, 0, array.size()-1, 'E');
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		time_Of_Quick_Med<<duration.count()<<endl;

		SizeOfQuick<<input_Size<<endl;
		cout<<testCases<<endl;
		testCases--;
		input_Size += 100;
    }
    time_Of_Nor_Quick.close();
    time_Of_Quick_Med.close();
    time_Of_Rand_Quick.close();
    time_Of_Quick_selectAlgo.close();
    time_Of_Quick_Rselect.close();
}
