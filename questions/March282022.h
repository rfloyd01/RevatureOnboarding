#include <iostream>
#include <cmath>

//Locker Toggling
/*
* The question is asking how many lockers will be open after 100 iterations of toggling them. Each locker will only
* get toggled on iterations that evenly divide the locker number, for example, locker number 10 will only get toggled on
* iterations 1, 2, 5 and 10. Since all of the lockers start in the closed position, only numbers that have an odd
* number of divisors will remain open. The only way for a number to have an odd number of divisors, is if the number has
* a square root (this is because divisors always come in pairs, other than a square root which multiplies against itself
* to reach the goal). Since there are only 100 lockers, therefore, there will only sqrt(100) = 10 lockers that remain open:
* 1, 4, 9, 16, 25, 36, 49, 64, 81 and 100. It goes to follow that the answer to the problem is 10.
*
* To test this theory I'll write a brute force algorithm and make sure that it spits out the same answer as the square root
* of N.
*/

int lockers(int N)
{
	return sqrt(N);
}

int lockersBruteForce(int N)
{
	int totalOpen = 1; //start with 1 because we skip the first iteration
	bool *lockers = new bool[N](); //0 will represent an open locker

	//we start on the second iteration because on the first iteration every
	//locker goes from closed to open. We initialized the locker array to be all open.
	for (int i = 1; i < N; i++)
	{
		totalOpen += lockers[i]; //once we hit iteration i, that locker won't be altered again
		for (int j = i; j < N; j += (i + 1)) lockers[j] = !lockers[j];
	}

	delete[] lockers;
	return totalOpen;
}