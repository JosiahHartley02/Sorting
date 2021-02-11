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
	if (intArr.isEmpty())
		std::cout << "This List Empty" << std::endl;
	intArr.pushBack(4);
	std::cout << "pushed a 4 to the back" << std::endl;
	intArr.pushBack(1);
	std::cout << "pushed a 1 to the back" << std::endl;
	intArr.pushFront(3);
	std::cout << "pushed a 3 to the front" << std::endl;
	intArr.pushFront(2);
	std::cout << "pushed a 2 to the front" << std::endl;
	intArr.insert(5, 3);
	std::cout << "inserted a 5 at the index of 3" << std::endl;
	intArr.insert(6, 4);
	std::cout << "inserted a 6 at the index of 4" << std::endl;
	if (intArr.contains(7))
	{
		std::cout << "this list contains a 7" << std::endl;
		intArr.print();
	}
	else
	{
		std::cout << "this list does not contain a 7" << std::endl;
	}
	intArr.remove(1);
	std::cout << "removed a 1" << std::endl;
	intArr.remove(3);
	std::cout << "removed a 3" << std::endl;
	intArr.sort();
	std::cout << "list sorted" << std::endl;
}