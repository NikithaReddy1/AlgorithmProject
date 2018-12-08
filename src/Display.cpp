#include "Display.h"

/*******************************************************************************
	Display function to display the array
*******************************************************************************/
void Display:: display(vector<int> array, int start, int end){
   cout<<"The Elements of the array are : ";
   for(int i = start; i <= end; i++)
	   cout<<array[i]<<"   ";
   cout<<endl<<endl<<endl;
}
