#include <iostream>
#include <vector>

using namespace std;

void merge(int a[], int low, int high, int mid)
{
	int i = low;
	int j = mid+1;

	vector<int> c;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			c.push_back(a[i]);
			i++;
		}
		else
		{
			c.push_back(a[j]);
			j++;
		}		
	}

	while (i <= mid)
	{
		c.push_back(a[i]);
		i++;
	}
	while (j <= high)
	{
		c.push_back(a[j]);
		j++;
	}


	int k = 0;
	for (int ii = low; ii <= high; ii++)
	{
		a[ii] = c[k];
		k++;
	}
}


void mergesortRecur(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low+high) / 2;
		mergesortRecur(a, low, mid);
		mergesortRecur(a, mid+1, high);
		merge(a, low, high, mid);
	}

}

void merge_sort(int a[], int size)
{
	mergesortRecur(a, 0, size-1);
}


int main()
{
	int a[10] = {2,7,3,10,4,9,73,1999,0,-1};

	merge_sort(a, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;

	return 0;
		
}