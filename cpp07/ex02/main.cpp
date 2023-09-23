#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
	std::cout << "==================== Example Test =======================" << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	std::cout << "==================== Additional Test =======================" << std::endl;
	Array<int> arr1;
	Array<int> arr2(5);
	for (int i = 0; i < 5; i++)
		arr2[i] = i;
	Array<int> arr3(arr2);
	for (int i = 0; i < 5; i++)
		arr2[i] = 4 - i;
	Array<int> arr4 = arr3;
	for (int i = 0; i < 5; i++)
		arr3[i] = 5 + i;
	arr1 = arr4;
	for (int i = 0; i < 5; i++)
		arr4[i] = 9 - i;
	std::cout << "array 1: " << arr1.size() << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << arr1[i] << " ";
	std::cout << std::endl;
	std::cout << "array 2: " << arr2.size() << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;
	std::cout << "array 3: " << arr3.size() << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << arr3[i] << " ";
	std::cout << std::endl;
	std::cout << "array 4: " << arr4.size() << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << arr4[i] << " ";
	std::cout << std::endl;
	return 0;
}
