#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include <vector>

struct student 
{
	std::string Name;
	int     Grade;
};

void Sort—hoos(std::vector<student>array, int lenArray)
{
	for (int startIndex = 0; startIndex < lenArray; startIndex++)
	{
		int smallestIndex = startIndex;
		for (int curret = startIndex; curret < lenArray; curret++)
		{
			if (array[smallestIndex].Name > array[startIndex].Name)
				smallestIndex = curret;
		}
		std::swap(array[smallestIndex], array[startIndex]);
	}
}

int main()
{
	int quantityStudent{ 0 };
	std::cout << "How many people : ";
	std::cin >> quantityStudent;

	std::vector<student> array(quantityStudent);

	for (int i = 0; i < quantityStudent; i++)
	{
		std::cout << "Enter the name a student #" << i + 1 << " :";
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::getline(std::cin, array[i].Name);
		std::cout << "Enter the grade a student # " << i + 1 << " :";
		std::cin >> array[i].Grade;

	}
	Sort—hoos(array, quantityStudent);
	
	for (int i = 0; i < quantityStudent; i++)
	{
		std::cout << array[i].Name << ' ' << array[i].Grade << std::endl;
	}
	return 0;   
}






