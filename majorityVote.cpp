#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
#include "majority.h"

using namespace std;

int main()
{
	long long size = GetN();

	//get the potential candidate that > size/2
	long long majority = GetVote(0);
	long long ctr = 1;
	for (long long i = 1; i < size; i++)
	{
		long long current = GetVote(i);
		if (current == majority)
			ctr++;
		else
			ctr--;

		if (ctr == 0)
			majority = current;
	}
	ctr = 0;
	//check whether the potential candidate > size/2
	for (long long i = 0; i < size; i++)
	{
		if (GetVote(i) == majority)
			ctr++;
	}

	if (ctr > ceil(size/2))
		cout << majority;
	else
		cout << "NO WINNER";

	cout << endl;

	return 0;
}