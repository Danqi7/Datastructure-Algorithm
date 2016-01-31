#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int l = 0;
        int r = nums.size()-1;
        int current = 0;

        while (current <= r)
        {
            if (nums[current] == 0)
            {
                swap(nums[l++], nums[current++]);
            }
            else if (nums[current] == 2)
            {
                swap(nums[r--], nums[current]);
            }
            else
                current++;
        }
        
    }
};

int main()
{
    
    int arr[] = {2,0};
    vector<int> nums (arr, arr+2);

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