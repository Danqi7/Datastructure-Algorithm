#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string itoa(int num)
{
	stringstream ss;
	ss << num;

	return ss.str();
}

int countsize(string s)
{
	int numcount = 1;
	char last = s[0];
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] != last)
		{
			numcount++;
			last = s[i];
		}
	}

	return (2*numcount);
}

string compress(string s)
{
	int size = countsize(s);

	//cout << size;

	char* result = new char[size];


	if (size > s.length())
	{
		return s;
	}

	int j = 0;
	result[j] = s[0];
	char last = s[0];
	int count = 1;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == last)
		{
			count++;
		}
		else
		{
			j++;
			result[j] = '0' + count;
			j++;
			count = 1;
			result[j] = s[i];
			last = s[i];
		}
	}

	j++;
	//cout << count;
	//cout << s[j] << endl;
	result[j] = '0' + count;
	//cout << j << endl;
	//cout << s[j] << endl;

	//cout << count << endl;

	return result;

}





int main()
{
	string s = "abcdd";

	cout << compress(s) << endl;

	return 0;
}
