#include <bits/stdc++.h>
using namespace std;

const int nmax = 100000+10;
vector<int> adjlist[nmax];
bool visited[nmax];


void dfs(int u)
{
    cout << "dfs starting form vertex : " << u << endl;
    cout << "marked " << u << endl;
    visited[u] = true;
    for(auto v : adjlist[u])
    {
        if( visited[v]==0 ){
            cout << u << "'s adjacent vertex " << v << " not marked , so dfs " << v << endl;
            dfs(v);
        }
        else
            cout << u << "'s adjacent vertex " << v << " marked" << endl;
    }
}
///Time complexity: O(|V| + |E|)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin>>V>>E;
    for(int i = 0;i<E;i++)
    {
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back( v );
        adjlist[v].push_back( u );
    }
    for(int i = 1;i<=V;i++)
    {
        cout << i << " :";
        for(auto j : adjlist[i]) cout << " " << j;
        cout << endl;
    }
    cout << "========================================================================================" << endl;
    for(int i = 1;i<=V;i++)
    {
        if( visited[i]==0 ) dfs(i);
    }

}
