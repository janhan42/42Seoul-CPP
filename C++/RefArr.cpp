#include <iostream>

int& function(int& a)
{
	a = 5;
	return (a);
}

int main(void)
{
	int b = 2;
	int c = function(b);
	return (0);
}