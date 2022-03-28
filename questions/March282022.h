#include <iostream>
#include <cmath>

//Locker Toggling
/*
* The question is asking how many lockers will be open after 100 iterations of toggling them. Each locker will only
* get toggled on iterations that evenly divide the locker number, for example, locker number 10 will only get toggled on
* iterations 1, 2, 5 and 10. Since all of the lockers start in the closed position, only numbers that have an odd
* number of divisors will remain open. The only way for a number to have an odd number of divisors, is if the number has
* a square root (this is because divisors always come in pairs, other than a square root which multiplies against itself
* to reach the goal). Since there are only 100 lockers, therefore, there will only be sqrt(100) = 10 lockers that remain open:
* 1, 4, 9, 16, 25, 36, 49, 64, 81 and 100. It goes to follow that the answer to the problem is 10.
*
* To test this theory I also wrote a brute force algorithm and confirmed that it gave 10 as well. The square root method
* is far superior in this case, not requiring any loops or anything. The square root method would also work even if N
* itself isn't a perfect square. For example, if there were 115 lockers then there should be sqrt(115) ~= 10.72 lockers
* open, however, we can't have a fraction of a locker open. C++ will automatically discard any decimals after casting the
* double to an integer so the function will still return 10. In fact, 10 will be the number of lockers open until we hit our
* 121st locker, then there will be 11 open.
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
