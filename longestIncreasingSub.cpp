#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> longestIncreasingSubarray(vector<int> numbers)
{
	if (numbers.size() == 0)
		return vector<int>();

	vector<int> table(numbers.size(), 1);

	//base case
	table[0] = 1;

	for (int i = 1; i < numbers.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (numbers[j] < numbers[i])
				table[i] = max(table[j] + 1);
		}
	}

	int longest = 0;
	int index = 0;

	for (int i = 0; i < table.size(); i++)
	{
		if (longest < table[i])
		{
			index = i;
			longest = table[i];
		}
	}

	vector<int> res;
	int last = numbers[index];

	for (int i = index-1; i >= 0; i--)
	{
		if (last > numbers[i])
		{
			res.push_back(numbers[i])
			last = numbers[i];
		}
	}


}

int main()
{
	vector<int> numbers;
	string input;
	string buf;
	getline(cin, input);

	stringstream s1(input);

	while (s1 >> buf)
		numbers.push_back(stoi(buf));
	
	
	return 0;
}
