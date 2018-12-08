#include <iostream>
#include "TestFunctions.h"
using namespace std;

int main()
{
    int choice;
    TestFunctions t;
	do{
        cout<<"Select any options below to perform test"<<endl;
	    cout<<"Enter 1--> to compare all quicksort"<<endl;
	    cout<<"Enter 2-->to compare Random Select And Quick Select"<<endl;
	    cout<<"Enter 3--> to compare Three types of median of medians"<<endl;
	    cout<<"Enter 0--> to quit"<<endl;
	    cout<<"Enter Your Choice: ";
	    cin>>choice;
	    switch(choice){
	       case 1: t.test_Func_Of_All_Quick_Sort();
	               break;
		   case 2: t.Random_Select_Algo();
		           break;
		   case 3: t.MedianOfMed();
		           break;
	    }
	}while(choice != 0);
    return 0;
}
