#include <iostream>
#include <string>
  
using namespace std;

void reverse(char* str)
{
	int i = 0;
	int j = 0;
	char* cur = str;

	while(cur[j] != '\0')
	{
		j++;
	}
	
	j--;

	while (i != j)
	{
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
	}
}

int main()
{
	string s = "I love google";
	char* s1 = &s[0];
	reverse(s1);
    string reversed = "elgoog evol I";
    cout << s1 << endl; 
    if (s.compare(reversed) == 0)
	    cout << "Yes!" << endl;
    else
		cout << "No!" << endl;
	
	return 0;
}  