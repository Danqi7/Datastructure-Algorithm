#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Matrix;

void ImageRotate(Matrix& matrix, int n)
{
	int counter = 0; // count the layer

	for (int i = n; i > 0; i = i - 2)
	{
		int counter2 = 0;
		//the outmost -> first
		//the edge -> last
		int first = 0 + counter;
		int last = first + i - 1;


		//only need to do length - 1 times
		for (int j = first; counter2 < i-1; counter2++)
		{

			//top->right
			//cout << matrix[0][1] << endl;
			int temp = matrix[j][last];
			matrix[j][last] = matrix[first][j];
			//cout << matrix[0][1] << endl;
			cout << "right" << matrix[j][last] << endl;
			//cout << "top" << matrix[first][j] << endl;

			//right->bottom
			int temp2 = matrix[last][last-j];
			matrix[last][last-j] = temp;
			cout << "bottom" << matrix[last][last-j] << endl;

			//bottom->left
			int temp3 = matrix[last-j][first];
			matrix[last-j][first] = temp2;

			//left->top
			matrix[first][j] = temp3;

			j++;
		}

		counter++;

		cout << "round" << endl;

	}


}



int main()
{
	Matrix matrix(2,vector<int>(2,0));

	matrix[0][0] = 1;
	matrix[0][1] = 2;
	//matrix[0][2] = 3;
	matrix[1][0] = 4;
	matrix[1][1] = 5;
	//matrix[1][2] = 6;
	//matrix[2][0] = 7;
	//matrix[2][1] = 8;
	//matrix[2][2] = 9;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}

	ImageRotate(matrix,2);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}



	return 0;
}