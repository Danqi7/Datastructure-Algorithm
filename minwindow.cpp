#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
string minWindow(string s, string t)
{
        vector<int> map(128,0);
        for(char c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end < s.size())
        {
            if(map[s[end++]]-->0) counter--; //in t

            while(counter==0)
            { //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }  
        }
        return  d == INT_MAX?  "":s.substr(head, d);
        }
};


int main()
{
    string a = "ADOBECODEBANC";
    string b = "ABC";

    string res;
    Solution* s = new Solution();
    res = s->minWindow(a,b);

    
    cout << res << endl;

    return 0;
}