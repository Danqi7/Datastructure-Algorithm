#include <iostream>

using namespace std;

int Partition(int a[], int pIndex, int start, int end)
{
	int pValue = a[pIndex];
	a[pIndex] = a[end];
	a[end] = pValue;

	int nextLeft = start;

	for (int i = start; i < end; i++)
	{
		if (a[i] < pValue)
		{
			int temp = a[nextLeft];
			a[nextLeft] = a[i];
			a[i] = temp;
			nextLeft++;
		}
	}	

	a[end] = a[nextLeft];
	a[nextLeft] = pValue;

	return nextLeft;
}


void QuicksortRecur(int a[], int start, int end)
{
	if (end > start)
	{
		int pIndex = (end+start) / 2;
		int newIndex = Partition(a, pIndex, start, end);
		QuicksortRecur(a, start, newIndex-1);
		QuicksortRecur(a, newIndex+1, end);
	}
}

void Quicksort(int a[], int size)
{
	//int size = sizeof(a) / sizeof(a[0]);
	QuicksortRecur(a, 0, size-1);
}

int main()
{
	int a[8] = {2,3,6,7,1,10,29,100};

	Quicksort(a, 8);

	for (int i = 0; i < 8; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;

	return 0;

}