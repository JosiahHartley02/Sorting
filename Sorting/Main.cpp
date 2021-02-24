#include <iostream>
#include "DynamicArray.h"
#include "List.h"

///Create a function that will sort an array of integers using bubble sort
///Print the array before and after it's been sorted.
int main()
{
	//DynamicArray<int> intArr = DynamicArray<int>();
	//intArr.addItem(5);
	//intArr.addItem(3);
	//intArr.addItem(3);
	//intArr.addItem(2);
	//intArr.addItem(2);
	//intArr.addItem(4);
	//intArr.removeItem(3);
	//intArr.sortItems();
	//intArr.print();
	
	List<int> intArr = List<int>();
	intArr.pushFront(1);
	intArr.print();
	intArr.pushFront(2);
	intArr.print();
	intArr.pushFront(3);
	intArr.print();
	intArr.pushFront(4);
	intArr.print();
	intArr.pushFront(5);
	intArr.print();
	intArr.pushFront(6);
	intArr.print();
	intArr.sort();
	intArr.print();
	intArr.sort();
	intArr.print();
	intArr.insert(7, 3);
	intArr.print();
	intArr.sort();
	intArr.print();
	if (!intArr.contains(8))
		intArr.pushBack(8);
	intArr.print();
	intArr.~List();
	intArr.print();
	intArr.pushFront(2);
	intArr.print();	
	intArr.pushBack(1);
	intArr.print();
	intArr.pushBack(3);
	intArr.print();
	system("pause");
}