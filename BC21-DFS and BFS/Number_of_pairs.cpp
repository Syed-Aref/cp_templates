#include <bits/stdc++.h>
using namespace std;

const int nmax = 100000;

vector<int> adjlist[nmax+5];
bool visited[nmax+5];
vector<pair<int,int>> vp; /// (last,first)
int par[nmax+5];

void dfs(int u,int parent)
{
    visited[u] = 1;
    par[u] = parent;
    for(auto v : adjlist[u])
    {
        if( v==par[u] ) continue;
        if( visited[v]==1 ) vp.push_back( make_pair(u,v) );
        else dfs( v,u );
    }

}

void clear_(int n){
    for(int i = 0;i<=n+2;i++){
        adjlist[i].clear();
        visited[i] = 0;
        par[i] = 0;
    }
    vp.clear();

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        int n;
        cin >> n;

        clear_(n);

        for(int u = 1;u<=n;u++){
            for(int v = u+1;v<=n;v++){
                adjlist[u].push_back(v);
                adjlist[v].push_back(u);
            }
        }

        dfs(1,0);
        cout << vp.size() << endl;
        /// Maximum number of cycle in a graph: 2*|E|
    }

}
