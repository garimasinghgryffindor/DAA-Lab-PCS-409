#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool bipartite(vector<vector<int> > graph , int V,int s)
{
    vector <int> vis(V,-1);
    queue <int> q;
    q.push(s);
    vis[s] = 0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i=0 ; i<V ; i++)
        {
            if(graph[v][i]==1 && vis[i]==-1)
            {
                vis[i] = 1 - vis[v];

                q.push(i);
            }
            else
            {
                if(graph[v][i]==1 && vis[i]==vis[v])
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int V,E,s,d,S;
    cout<<"Enter the number of vertices:  ";
    cin>>V;
    cout<<"Enter the number of edges:  ";
    cin>>E;
    vector<vector<int> > graph (V,vector<int>(V,INT_MAX));

    for(int i=0 ; i<E ; i++)
    {
        cout<<"Enter the source index:  ";
        cin>>s;
        cout<<"Enter the destination index:  ";
        cin>>d;
        graph[s][d] = 1;
        graph[d][s] = 1; 
    }

        //{{0, 1, 0, 1},
        // {1, 0, 1, 0},
        // {0, 1, 0, 1},
        // {1, 0, 1, 0}

    cout<<"Enter the starting index:  ";
    cin>>S;

    bool bip = bipartite(graph,V,S);
    
    if(bip==true)
    cout<<"Bipartite\n";
    else
    cout<<"NOt a bipartite\n";

    return 0;
}