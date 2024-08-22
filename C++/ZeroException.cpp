#include <exception>
#include <iostream>

int main(void)
{
	int	number1 = 0;
	int number2 = 0;

	std::cin >> number1 >> number2;

	try
	{
		int result = number1 / number2;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
