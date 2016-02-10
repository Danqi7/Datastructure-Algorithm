#include <iostream>
#include <string>
#include <vector>
#include <utility>


using namespace std;
typedef vector<int> adjList;
    
class MyGraph
{
public:
        int n;
        adjList* graph;
        bool* visited;
        bool cyc;
        

        MyGraph(int num)
        {
            n = num;
            cyc = false;
            graph = new adjList[num];
            visited = new bool[num];
        }
        
        void addEdge(pair<int, int> edge)
        {
            int node1 = edge.first;
            int node2 = edge.second;
            
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        
        void dfsvisit(int node, int parent)
        {
            visited[node] = true;

            for (int i = 0; i < graph[node].size(); i++)
            {
                if (visited[graph[node][i]] && graph[node][i] != parent)
                {
                    cyc = true;
                    return;
                }
                else if (!visited[graph[node][i]])
                {
                    dfsvisit(graph[node][i], node);
                }
            }
            return;
        }
};

class Solution {
public:
    bool validTree(int n, vector< pair<int, int> >& edges) 
    {
        MyGraph* g = new MyGraph(n);
         
        for (int i = 0; i < edges.size(); i++)
        {
            g->addEdge(edges[i]);
        }
        
        g->dfsvisit(0,-1);
        
        if (g->cyc == true)
        {
            cout << "wtf";
            return false;
        }
            
        
        for (int i = 0; i < n; i++)
        {
            if (!g->visited[i])
            {
                cout << "ummm" << endl;
                return false;
            }

        }
        
        return true;
    }
};
int main()
{
    pair<int, int> e1(0,1);
    pair<int, int> e2(0,2);
    pair<int, int> e3(2,3);
    pair<int, int> e4(2,4);

    vector< pair<int, int> > edges;
    edges.push_back(e1);
    edges.push_back(e2);
    edges.push_back(e3);
    edges.push_back(e4);

    bool res;
    Solution* s = new Solution();
    res = s->validTree(5, edges);

    if (res)
        cout << "yes" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
