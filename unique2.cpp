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

	int index = 0;
    while(index < nums.size()-1)
    {
        if (nums[index] == nums[index+1])
        {   
            cout << nums[index] << endl;
            nums.erase(nums.begin()+index);
        }
            else
            {
                index++;
            }
        }

    for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";

    cout << "\n";
    cout <<  nums.size() << endl;

	return 0;
}