//determines whether a string has all unique chars

#include <iostream>
#include <string>

using namespace std;

bool is_unique(string s)
{
    if (s.length() > 128)
        return false;
    
    bool singlechars[128];
    
    for (int i = 0; i < 128; i++)
        singlechars[i] = true;
    
    int j = 0;
    
    while (s[j])
    {
        int value = s[j];
        if (singlechars[value] == false)
            return false;
        else
        {
            singlechars[value] = false;
        }
        j++;
    }
    
    
    return true;
}


int main()
{
    string s;
    getline(cin, s);
    
    cout << is_unique(s);
    
    return 0;
}
