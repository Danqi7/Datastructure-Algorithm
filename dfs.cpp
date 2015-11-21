#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> adjList;


class Graph
{
private:
	int n;
	adjList* graph;
	bool* visit;

public:
	Graph(int size)
	{
		n = size;
		graph = new adjList[size];
		visit = new bool[size];
	}

	void addEdge(int v, int v2)
	{
		graph[v-1].push_back(v2);
		graph[v2-1].push_back(v);
	}

	void dfsvisit(int node)
	{
		//cout << "aaaa!!!" << endl;
		visit[node] = true;
		cout << node + 1 << " ";
		for (int i = 0; i < graph[node].size(); i++)
		{
			if (visit[graph[node][i]-1] == false)
				dfsvisit(graph[node][i]-1);
		}
	}

	void dfs()
	{
		for (int i = 0; i < n; i++)
		{
			if (visit[i] == false)
			{
				//cout << "hi!" << endl;
				dfsvisit(i);
			}
		}

		cout << endl;
	}
	
};


int main()
{
	int size = 7;
	Graph g = Graph(size);
	
	g.addEdge(5, 7);
	g.addEdge(1, 4);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 6);

	g.dfs();


	return 0;
}