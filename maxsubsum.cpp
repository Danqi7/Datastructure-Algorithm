#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int maxSubsum(vector<int> numbers)
{
	//check if all negative
	int maxn = numbers[0];

	for (int i = 1; i < numbers.size(); i++)
	{
		maxn = max(maxn, numbers[i]);
	}

	if (maxn <= 0)
		return maxn;


	//there is positive number
	int res = 0;
	int max_ending = 0;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (max_ending + numbers[i] > 0)
		{
			max_ending = max_ending + numbers[i];
			res = max(max_ending, res);
		}
		else
			max_ending = 0;
	}

	return res;

}


int main()
{	
	//get the input number
	vector<int> numbers;
	string input;
	string buf;
	getline(cin, input);

	stringstream s1(input);

	while (s1 >> buf)
		numbers.push_back(stoi(buf));

	cout <<	maxSubsum(numbers);

	cout << "\n";
}