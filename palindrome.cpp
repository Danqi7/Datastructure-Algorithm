#include <iostream>
#include <string>

using namespace std;

bool palindrome(string s)
{
	int i = 0;
    int j = s.length()-1;

    while (i <= j)
    {
    	while (!isalnum(s[i]) && i < j)
    		i++;
    	while (!isalnum(s[j]) && i < j)
    		j--;

    	if (toupper(s[i]) != toupper(s[j]))
    		return false;
    	else
    	{
    		i++;
    		j--;
    	}
    }

        
    return true;	
}

int main()
{
	string s = "   rat , tar   ";

	//palindrome(s);
	cout << palindrome(s) << endl;

	return 0;


}