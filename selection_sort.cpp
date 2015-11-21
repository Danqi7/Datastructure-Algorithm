#include <iostream>
#include <string>
#include <sstream>
#include <vector>


using namespace std;

int findMin(vector<int> arr, int start)
{
	int index = start;

	for (int i = start + 1; i < arr.size(); i++)
	{
		if (arr[i] < arr[index])
			index = i;
	}

	return index;
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

	for (int i = 0; i < numbers.size(); i++)
	{
		int temp = numbers[i];
		int index = findMin(numbers, i);
		numbers[i] = numbers[index];
		numbers[index] = temp;
	}


	for (int i = 0; i < numbers.size(); i++)
		cout << numbers[i] << " ";

	cout << "\n";
}