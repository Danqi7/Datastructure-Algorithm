#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, string> table;

    Solution()
    {
        table['2'] = "abc";
        table['3'] = "def";
        table['4'] = "ghi";
        table['5'] = "jkl";
        table['6'] = "mno";
        table['7'] = "pqrs";
        table['8'] = "tuv";
        table['9'] = "wxyz";
    }
    

    vector<string> letterCombinations(string digits) 
    {
        
        vector<string> result;
        if (digits.size() == 0)
            return result;
        cout << "fucking" << endl;
        char first = digits[0];
        for (int j = 0; j < table[first].length(); j++)
        {
            result.push_back(table[first].substr(j,1));
        }
        
        for (int i = 1; i < digits.size(); i++)
        {
            cout << "second loop << endl";
            combine(result, digits[i]);
        }
        
     
        return result;
        
    }
    
    void combine(vector<string>& res, char digit)
    {
        cout << "second loop << endl";
        string s = table[digit];
        for (int j = 0; j < res.size(); j++)
        {
            for (int i = 0; i < s.length(); i++)
            {
                res.push_back(res[j] + s.substr(i,1));
            }
        }
    }
};

int main()
{
    string name;
    cout << "Please, enter your full name: ";
    getline (cin,name);
    cout << "Hello, " << name << "!\n";
    cout << "haha" << endl;
    
    Solution* s = new Solution();
    vector<string>res;
    cout << "======haha";

    res = s->letterCombinations(name);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;

    return 0;
}


