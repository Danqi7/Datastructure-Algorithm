#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        if (citations.size() == 0)
            return 0;
            
        int count = citations.size();
        if (count <= citations[0])
            return count;
        
        int h = 0;
        int r = citations.size()-1;
        int l = 1;
        
        while (l < r)
        {
            count = (l+r)/2;
            cout << count << "--";
            
            if (count >= citations[citations.size()-count-1] && count <= citations[citations.size()-count])
            {
                cout << "found it!" << endl;

                h = max(h, count);
                l = count+1;
            }
            else
            {
                r = count-1;
            }
        }
        
        return h;
        
        
    }
};

int main()
{
    int arr[] = {2,3,7,8,11,200};

    vector<int> citations(&arr[0], &arr[0]+6);

    int res;
    Solution* s = new Solution();
    res = s->hIndex(citations);

    
    cout << res << endl;

    return 0;
}