#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include "sandwich.h"

using namespace std;

int main()
{
	long long maxt = LLONG_MIN;
	long long total = 0;
	long long size = GetN();

	long long max_ending = 0;
	long long res = 0;

	//negate the number and find the max subarray sum
	for (long long i = 0; i < size; i++)
	{
		long long temp = GetTaste(i);
		total += temp;
		temp = -temp;
		maxt = max(maxt,temp);
		
		if (max_ending + temp > 0)
		{
			max_ending = max_ending + temp;
			res = max(res,max_ending);
		}
		else
			max_ending = 0;
	}

	if (maxt <= 0)
		res = 0;

	cout << (total + res) << endl;

	return 0;	
}