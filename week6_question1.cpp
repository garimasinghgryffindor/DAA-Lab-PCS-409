#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph{
    int V;
    vector <list <int> > graph;
    vector <bool> visited;
    int flag=0;

    public:
    Graph(int V);
    void addEdge(int s,int d);
    void dfs(int source,int destination);
    void dfsmain(int source,int destination);
};

Graph::Graph(int V)
{
    this->V = V;
    graph.resize(V);
    visited.resize(V,false);
}

void Graph::addEdge(int s,int d)
{
    graph[s].push_back(d);
}

void Graph::dfs(int source,int destination)
{

    dfsmain(source,destination);
    if(flag==0)
    {
        cout<<"No such path exits:\n";
    }
    else
        cout<<"Yes, Path exists\n";
    flag=0;
    
}

void Graph::dfsmain(int source,int destination)
{
    visited[source]=true;

    if(source==destination)
    {
        
        flag=1;
        return;
    }

    for(auto&it : graph[source])
    {
        if(!visited[it])
        {
            dfsmain(it,destination);
        }
    }
}

int main()
{
    int V,E,s,d,start,destination;

    cout<<"Enter the number of vertices:  ";
    cin>>V;

    Graph graph(V);

    cout<<"Enter the number of Edges:  ";
    cin>>E;

    for(int i=0 ; i<E ; i++)
    {
        cout<<"Enter the source node:  ";
        cin>>s;
        cout<<"Enter the destination node:  ";
        cin>>d;
        graph.addEdge(s,d);
    }

    cout<<"Enter the start node to search for path:  ";
    cin>>start;
    cout<<"Enter the destination node to search for path:  ";
    cin>>destination;

    graph.dfs(start,destination);
    
    return 0;
}