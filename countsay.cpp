#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) 
    {
        string current = "1";
        
        while (n > 1)
        {
            current = readoff(current);
            n--;
        }
        
        return current;
        
    }
    
    string readoff(string prev)
    {
        string res;
        cout << "ha!" << endl;
        //cout << prev << endl;
        int count = 1;
        
        if (prev.length() == 1)
        {
            res = to_string(count) + prev;
            return res;
        }
        
        for (int i = 1; i < prev.length(); i++)
        {
            if (prev[i] == prev[i-1])
            {
                count++;
            }
            else
            {
                res = res + to_string(count) + prev.substr(i-1,1);
                count = 1;
            }
        }
        cout << "===="  << prev << endl ;
        res = res + to_string(count) + prev.substr(prev.length()-1,1);
        
        cout << res << endl;

        return res;
    }
};


int main()
{

    string res;
    Solution* s = new Solution();
    res = s->countAndSay(3);

    
    cout << res << endl;

    return 0;
}