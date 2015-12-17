#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Matrix;

void SetZero(Matrix& matrix)
{
	int numrow = matrix.size();
	int numcol = matrix[0].size();
	int row = -1;
	int col = -1;


	for (int i = 0; i < numrow; i++)
	{
		for (int j = 0; j < numcol; j++)
		{
			//set the bench row and col
			if (matrix[i][j] == 0 && row == -1)
			{
				row = i;
				col = j;

			}
			else
			{
				if (matrix[i][j] == 0)
				{
					matrix[row][j] = 0;
					matrix[i][col] = 0;
				}
			}


		}
	}

	if (row == -1)
	{
		//no zero at all
		return;
	}


	//cout << row << " " << col << endl;

	//for row that needed to be set to 0
	for (int r = 0; r < numrow; r++)
	{
		if (matrix[r][col] == 0 && r != row)
		{
			//set this row to 0
			for (int index = 0; index < numcol; index++)
			{
				matrix[r][index] = 0;
			}
		}
	}

	for (int c = 0; c < numcol; c++)
	{
		if (matrix[row][c] == 0)
		{
			for (int index = 0; index < numrow; index++)
			{
				matrix[index][c] = 0;
			}
		}
	}

	for (int index = 0; index < numcol; index++)
	{
		matrix[row][index] = 0;
	}
}




int main()
{
	Matrix matrix(3,vector<int>(3,0));

	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 3;
	matrix[1][0] = 4;
	matrix[1][1] = 5;
	matrix[1][2] = 0;
	matrix[2][0] = 7;
	matrix[2][1] = 8;
	matrix[2][2] = 9;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}

	SetZero(matrix);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}

	


	return 0;
}