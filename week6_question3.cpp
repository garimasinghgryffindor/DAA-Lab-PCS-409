//Whether cycle exists in the graph of not
//using DFS
//Undirected Graph

#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int> > &graph, int s, int d)
{
    graph[s].push_back(d);
}

bool dfs(vector<vector<int> >graph , vector<int> &visited , int s)
{
    visited[s] = true;

    for(auto &it : graph[s])
    {
        if(visited[it])
        {
            return false;
        }
        else
        {
            dfs(graph,visited,it);
        }
    }

    return true;
}

int main()
{
    int V,E,s,d,S;
    cout<<"Enter the number of vertices:  ";
    cin>>V;
    cout<<"Enter the number ofedges:  ";
    cin>>E;
    vector<vector<int> > graph(V);
    for(int i=0 ; i<E ; i++)
    {
        cout<<"Enter the source:  ";
        cin>>s;
        cout<<"Enter the destination:  ";
        cin>>d;
        addEdge(graph,s,d);
    }

    cout<<"Enter the start node:    ";
    cin>>S;

    vector <int> visited(V,false);

    bool cycle = dfs(graph,visited,S);
    
    if(cycle==false)
    cout<<"Contains a cycle"<<endl;
    else
    cout<<"Does NOT contains a cycle\n";

}

