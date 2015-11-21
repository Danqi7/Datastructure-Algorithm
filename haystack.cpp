#include <iostream>
#include <string>

using namespace std;

int main()
{
	string haystack;
	string needle;

	cin >> haystack;
	cin >> needle;

	if (haystack == needle)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < haystack.length(); i++)
	{
		for (int j = 0; j < needle.length() && i+j < haystack.length(); j++)
		{
			if (haystack[i+j] != needle[j])
				break;

			
			if (j == needle.length()-1)
			{
				cout << i << endl;
				return 0;
			}

		}

	}

	cout << -1 << endl;

	return 0;

}