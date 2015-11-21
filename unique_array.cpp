#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	vector<int> nums;
	int input;

	string s1;
	getline(cin, s1);
	stringstream s2(s1);

	while (s2 >> input)
	{
		nums.push_back(input);
	}

	
	for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];
            for (int j = i+1; j < nums.size(); j++)
            {
                if (temp == nums[j])
                {
                    nums.erase(nums.begin()+j);
                    j--;
                }
            }
        }

    for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";

    cout << "\n";
    cout <<  nums.size() << endl;

	return 0;
}