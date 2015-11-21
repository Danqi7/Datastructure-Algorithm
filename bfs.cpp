#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int value;
	Node* next;
};

class GraphNode
{
private:
	Node* adjacent;
public:
	GraphNode()
	{
		//cout << "initialzied!" << endl;
		adjacent = NULL;
	}

	Node* getHead()
	{
		return adjacent;
	}
	//insert at the beginning
	void insertNode(int v)
	{
		
		Node* new_node = new Node;
		new_node->value = v;
		new_node->next = NULL;

		new_node->next = adjacent;
		//cout << "i am here!" << endl;
		adjacent = new_node;
	
	}

	void displayAdj()
	{
		Node* currnode = adjacent;
		while (currnode != NULL)
		{
			cout << currnode->value << " ";
			currnode = currnode->next;
		}

		cout << endl;
	}

	~GraphNode()
	{
		Node* currnode = adjacent;
		while (currnode != NULL)
		{
			Node* temp = currnode;
			currnode = currnode->next;
			delete temp;
		}
	}
};

class Graph
{
private:
	int n;
	bool* visit;
	GraphNode** graph;
	int cycle;

public:
	Graph(int size)
	{
		cycle = 0;
		n = size;
		visit = new bool[n];
		graph = new GraphNode*[size];
		//cout << "yoyoo" << endl;

		for (int i = 0; i < size; i++)
		{
			graph[i] = new GraphNode();
			visit[i] = false;
		}

	}

	vector<int> getNeighbors(int node)
	{
		vector<int> neighbors;
		Node* currnode = graph[node-1]->getHead();
		while (currnode != NULL)
		{
			neighbors.push_back(currnode->value);
			currnode = currnode->next;
		}

		return neighbors;
	}

	void addEdge(int v, int v2)
	{
		//cout << "hi";
		graph[v-1]->insertNode(v2);
		graph[v2-1]->insertNode(v);
	}

	void displayGraph()
	{
		for (int i = 0; i < n; i++)
		{
			cout << i+1 << " : ";
			graph[i]->displayAdj();
		}
	}

	void bfs(int start)
	{
		queue<int> Q;
		Q.push(start);
		visit[start-1] = true;
		while (!Q.empty())
		{
			int node = Q.front();
			cout << node << " ";
			Q.pop();
			vector<int> ns = getNeighbors(node);
			for (int i = 0; i < ns.size(); i++)
			{
				if (!visit[ns[i]-1])
				{
					visit[ns[i]-1] = true;
					Q.push(ns[i]);
				}
				else
				{
					cycle = 1;
				}
			}
		}

		cout << endl;

	}

	void has_cycle()
	{
		bfs(1);
		if (cycle)
			cout << "Yes! It has cycle!" << endl;
		else
			cout << "No cycle!" << endl;
	}

	~Graph()
	{
		for (int i = 0; i < n; i++)
			delete graph[i];
	}
};


int main()
{
	Graph* g = new Graph(5);
	g->addEdge(1,2);
	g->addEdge(2,3);
	g->addEdge(2,5);
	g->addEdge(2,4);
	g->addEdge(4,3);

	g->displayGraph();
	//g->bfs(4);
	g->has_cycle();

	
	return 0;

}