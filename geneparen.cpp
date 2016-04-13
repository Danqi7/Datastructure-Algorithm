#include <iostream>
#include <vector>
#include <string>

using namespace std;


void RecurParen(vector<string>& list, string s, int open, int close, int max)
{
	//cout << max;
	//cout << "----";
	if (s.length() == max * 2)
	{
		cout << s << endl;
		list.push_back(s);
		return;
	}

	if (open < max)
	{
		cout << "1" << endl;
		RecurParen(list, s + "(", open+1, close, max);
	}
	if (close < open)
	{
		cout << "2" << endl;
		RecurParen(list, s + ")", open, close+1, max);
	}

}

vector<string> generateParenthesis(int n)
{
	vector<string> result;
	RecurParen(result, "", 0, 0, n);
	return result;	
}


int main()
{
	vector<string> p = generateParenthesis(3);

	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i] << endl;
	}

	return 0;	
}