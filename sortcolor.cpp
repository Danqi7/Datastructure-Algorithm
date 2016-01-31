#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int p = 0;
        int c = 0;
        
        while (c < 3 && p <= nums.size()-1)
        {
            cout << "p" << p << endl;
            while (nums[p] == c)
                p++;
            for (int i = p+1; i < nums.size() && p < nums.size(); i++)
            {
                if (nums[i] == c)
                {
                    cout << "swap";
                    //swap
                    nums[i] = nums[p];
                    nums[p] = c;
                    p++;
                    while (nums[p] == c)
                        p++;
                }
            }

             for (int i = 0; i < nums.size(); i++)
            {
                cout << nums[i] << " ";
            }
            cout << endl;
            cout << "---" << c << endl;
            c++;
        }
        
    }
};

int main()
{
    
    int arr[] = {1,2,1};
    vector<int> nums (arr, arr+3);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;

    Solution* s = new Solution();
    s->sortColors(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    
    cout << endl;

    return 0;
}