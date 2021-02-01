#include <iostream>
#include "DynamicArray.h"

///Create a function that will sort an array of integers using bubble sort
///Print the array before and after it's been sorted.

//bool sortArray(int array[], int arrayLength)
//{
//	int swapped = 0;
//	for (int i = 0; i < arrayLength; i++)
//	{
//		swapped = 0;
//		for (int j = arrayLength - 1; j > i; j--)
//		{
//			swapped = 0;
//			if (array[i] > array[j])
//			{
//				int int1 = array[i];
//				int int2 = array[j];
//				array[i] = int2;
//				array[j] = int1;
//				swapped = 1;
//			}
//			if (swapped == 1)
//			{
//				for (int i = 0; i < arrayLength; i++)
//					std::cout << array[i];
//				std::cout << " " << std::endl;
//			}
//		}
//	};
//	return swapped;
//}


int main()
{
	DynamicArray<int> intArr = DynamicArray<int>();
	intArr.addItem(5);
	intArr.addItem(3);
	intArr.addItem(3);
	intArr.addItem(2);
	intArr.addItem(2);
	intArr.addItem(4);
	intArr.removeItem(3);
	intArr.sortItems();
	intArr.print();
}