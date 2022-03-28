#include <iostream>
#include <questions/March282022.h>

int main()
{
	std::cout << "The brute force answer is " << lockersBruteForce(100) << std::endl;
	std::cout << "The fast answer is " << lockers(100) << std::endl;
	return 0;
}