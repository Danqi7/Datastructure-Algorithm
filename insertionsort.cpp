#include <iostream>
#include <string>
#include <sstream>
#include <vector>


using namespace std;

void insert(vector<int>& numbers, int pos, int val)
{
	int i = 0;

	for (i = pos-1; i >= 0 && numbers[i] > val; i--)
	{
		numbers[i+1] = numbers[i];
	}

	numbers[i+1] = val;
}


void insertionsort(vector<int>& numbers)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		insert(numbers, i, numbers[i]);
	}
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

	insertionsort(numbers);

	for (int i = 0; i < numbers.size(); i++)
		cout << numbers[i] << " ";

	cout << "\n";
}