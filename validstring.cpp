#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) 
    {
       stack<char> st;
       for (int i = 0; i < s.length(); i++)
       {
       	   cout << s[i] << endl;
           if (s[i] == '(' || s[i] == '[' || s[i] == '{')
           {
               st.push(s[i]);
           }
           else
           {
               if (st.empty())
                  return false;
           }
           
           if (s[i] == ')')
           {
               if (st.top() != '(')
                   return false;
               st.pop();
           }
           
           if (s[i] == '}')
           {
               if (st.top() != '{')
                   return false;
               st.pop();
           }
           
           if (s[i] == ']')
           {
               if (st.top() != '[')
                   return false;
               st.pop();
           }
       }
       
       return st.empty();
    }

int main()
{
	string s = "()";
	//cin >> s;

	if (isValid(s))
	{
		cout << "valid!"<< endl;

	}
	else
		cout << "INVALID" << endl;
	//cout << isValid(s) << endl;
	return 0;
}