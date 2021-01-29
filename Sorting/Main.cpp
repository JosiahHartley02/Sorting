#include <iostream>

///Create a function that will sort an array of integers using bubble sort
///Print the array before and after it's been sorted.

bool sortArray(int array[], int arrayLength)
{
	int swapped = 0;
	for (int i = 0; i < arrayLength; i++)
	{
		swapped = 0;
		for (int j = arrayLength - 1; j > i; j--)
		{
			swapped = 0;
			if (array[i] > array[j])
			{
				int int1 = array[i];
				int int2 = array[j];
				array[i] = int2;
				array[j] = int1;
				swapped = 1;
			}
			if (swapped == 1)
			{
				for (int i = 0; i < arrayLength; i++)
					std::cout << array[i];
				std::cout << " " << std::endl;
			}
		}
	};
	return swapped;
}


int main()
{
	int loop;
	int* loopPtr = &loop;
	//Create a new array
	int testArray[10] = { 3,5,1,2,6,8,9,0,7,4 };
	//Print array
	for (int i = 0; i < 10; i++)
		std::cout << testArray[i];
	std::cout << " " << std::endl;
	while (loop != 1)
	{
		//Sort Array
		*loopPtr = sortArray(testArray, 10) + 1;
	}
}