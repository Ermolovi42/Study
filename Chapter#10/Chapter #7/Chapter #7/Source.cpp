#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#define  NDEBUG

int binarySearch(int* array, int target, int min, int max)
{
	if (min > max)
		return -1;

	if (array[min + ((max - min) / 2)] == target)
		return min + ((max - min) / 2);

	if (array[min + ((max - min) / 2)] > target)
		return binarySearch(array, target, min, ( min + ((max - min) / 2) - 1) );

	if (array[min + ((max - min) / 2)] < target)
		return binarySearch(array, target, ( min + ((max - min) / 2) + 1), max);
}

int main()
{
	int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 };

	std::cout << "Enter a number: ";
	int x;
	std::cin >> x;

	int index = binarySearch(array, x, 0, 14);

	if (array[index] == x)
		std::cout << "Good! Your value " << x << " is on position " << index << " in array!\n";
	else
		std::cout << "Fail! Your value " << x << " isn't in array!\n";

	return 0;
}