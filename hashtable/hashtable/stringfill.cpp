#include <iostream>
#include <string>

using namespace std;

void stringfill(string &s)
{
	int j = s.length()-1;
	int firstchar = 0;

	for (int i = s.length()-1; i >= 0; i--)
	{
		if (s[i] != ' ')
		{
			firstchar = 1;
		}

		if (firstchar)
		{
			if (s[i] != ' ')
			{
				s[j] = s[i];
				j--;
			}
			else
			{
				s[j] = '0';
				s[j-1] = '2';
				s[j-2] = '%';

				j = j - 3;
			}
		}
	} 
}

int main()
{
	string s = "Mr John Smith like      ";

	stringfill(s);

	cout << s << endl;

	return 0;
}