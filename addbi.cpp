#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) 
    {
        int i;
        int j;
        string res (max(a.length(), b.length())+1, '8');
        
        //return res;

        int k = res.length()-1;
        int carry = 0;
        
        for (i = a.length()-1, j = b.length()-1; i >= 0 && j >= 0; i--, j--)
        {
            if ((a[i]-'0') + (b[j]-'0') + carry < 2)
            {
                 res[k] = '0' + (a[i]-'0') + (b[j]-'0') + carry;
                 carry = 0;
            }
            else
            {
                res[k] = '0' + (a[i]-'0') + (b[j] - '0') + carry - 2;
                carry = 1;
            }
            k--;
        }
        cout << res << endl;
        cout << carry << endl;

        cout << i << endl;
        
        while (i >= 0)
        {
            cout << "loop";
            if (a[i]-'0' + carry < 2)
            {
                res[k] = a[i]-'0' + carry + '0';
                carry = 0;
            }
            else
            {
                res[k] = a[i]-'0' + carry - 2 + '0';
                carry = 1;
            }
            k--;
            i--;
        }
        
        while (j >= 0)
        {
            if (b[j]-'0' + carry < 2)
            {
                res[k] = b[j]-'0' + carry + '0';
                carry = 0;
            }
            else
            {
                res[k] = b[j]-'0' + carry - 2 + '0';
                carry = 1;
            }
            k--;
            j--;
        }
        cout << "k is " << k << endl;
        if (carry == 1)
        {
            res[k] = '1';
        }
        else
        {
          res = res.substr(1,max(a.length(), b.length()));
        }
        cout << "Carry is " << carry << endl;
        cout << res << endl;
        return res;
        
        
        
        
    }
};

int main()
{
    string a = "1";
    string b = "111";

    string res;
    Solution* s = new Solution();
    res = s->addBinary(a,b);

    
    cout << res << endl;

    return 0;
}