#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> result;
        if (nums.size() == 0)
            return result;
            
        int start = nums[0];
        int end = start;
        string s;
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == (end+1))
            {
                end++;
            }
            else
            {
                s = to_string(start) + "->" + to_string(end);
                cout << s << endl;
                result.push_back(s);
                
                start = nums[i];
                end = nums[i];
            }
        }
        
        s = to_string(start) + "->" + to_string(end);
        result.push_back(s);
        
        return result;
    }


int main()
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	

	vector<string> result = summaryRanges(nums);

	for (int i = 0; i < nums.size(); i++)
	{
		cout << result[i];
	}

	cout << endl;

	return 0;
}