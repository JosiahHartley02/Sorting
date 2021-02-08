#include <iostream>
#include "DynamicArray.h"

///Create a function that will sort an array of integers using bubble sort
///Print the array before and after it's been sorted.
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