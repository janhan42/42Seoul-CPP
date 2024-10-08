#include <iostream>
#include <cstdlib>
#include "Array.hpp"


#define MAX_VAL 20
int main(int, char**)
{
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
		for (unsigned int i = 0; i < MAX_VAL; ++i)
		{
			std::cout << "tmp, numbers:\t\t" << tmp[i] << ",\t" << numbers[i] << std::endl;
		}
		Array<int> test(tmp);
		for (unsigned int i = 0; i < MAX_VAL; ++i)
		{
			std::cout << "tmp, test:\t\t" << tmp[i] << ",\t" << test[i] << std::endl;
		}
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	/* 잘못된 인덱스 범위 */
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
	/*  */

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}
