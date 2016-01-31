#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INF = 2147483647;

class Solution {
public:
    
    void wallsAndGates(vector< vector<int> >& rooms) 
    {
        vector< vector<int> > cache( rooms.size(), vector<int>(rooms[0].size(), -2) );
        vector< vector<int> > visited( rooms.size(), vector<int>(rooms[0].size(), 0) );
        
        for (int i = 0; i < rooms.size(); i++)
        {
            for (int j = 0; j < rooms[0].size(); j++)
            {
                if (rooms[i][j] == INF)
                {
                    rooms[i][j] = findGate(rooms, i, j, cache, visited);
                    for (int ii = 0; ii < visited.size(); ii++)
                    {
                        for (int jj = 0; jj < visited[0].size(); jj++)
                        {
                            visited[ii][jj] = 0;
                        }
                    }
                }
            }
        }
        
        
    }
    
    int findGate(vector< vector<int> >& rooms, int row, int col, vector< vector<int> >& cache, vector< vector<int> >& visited)
    {
        int dmin = INF;
        int res;

        visited[row][col] = 1;
        
        if (cache[row][col] != -2)
        {
            return cache[row][col];
        }
        
        if (rooms[row][col] == 0)
        {
            cache[row][col] = 0;
            return 0;    
        }
        
        if (rooms[row][col] == -1)
        {
            cache[row][col] = INF;
            return INF;
        }

        //up
        if (row-1 >= 0)
        {
            if (visited[row-1][col] == 0)
            {  
                res = findGate(rooms, row-1, col, cache, visited);
                if (res != INF)
                    dmin = min(dmin, 1 + res);
            }
        }
        
        
        //down
        if (row+1 < rooms.size())
        {
            if (visited[row+1][col] == 0)
            {  
                res = findGate(rooms, row+1, col, cache, visited);
                if (res != INF)
                    dmin = min(dmin, 1 + res);
            }
        }

        //
        if (col-1 >= 0)
        {
            if (visited[row][col-1] == 0)
            {  
                res = findGate(rooms, row, col-1, cache, visited);
                if (res != INF)
                    dmin = min(dmin, 1 + res);
            }
        }
        
        //right
        if (col+1 < rooms[0].size())
        {
            if (visited[row][col+1] == 0)
            {  
                res = findGate(rooms, row, col+1, cache, visited);
                if (res != INF)
                    dmin = min(dmin, 1 + res);
            }
        }
        
        cache[row][col] = dmin;
        return dmin;
    }
};

int main()
{
    static const int arr1[] = {2147483647,-1};
    static const int arr2[] = {2147483647,-1};
    static const int arr3[] = {0,2147483647};
    vector<int> v1;
    v1.push_back(2147483647);
    v1.push_back(-1);

    vector<int> v2;
    v2.push_back(2147483647);
    v2.push_back(-1);

    vector<int> v3;
    v3.push_back(0);
    v3.push_back(2147483647);

    vector< vector<int> > rooms;
    rooms.push_back(v1);
    rooms.push_back(v2);
    rooms.push_back(v3);


    for (int i = 0; i < rooms.size(); i++)
    {
            for (int j = 0; j < rooms[0].size(); j++)
            {
                cout << rooms[i][j] << " ";
            }

            cout << endl;
    }

    Solution* s = new Solution();
    s->wallsAndGates(rooms);



    for (int i = 0; i < rooms.size(); i++)
    {
            for (int j = 0; j < rooms[0].size(); j++)
            {
                cout << rooms[i][j] << " ";
            }

            cout << endl;
    }
    

    return 0;
}