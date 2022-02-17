#include <bits/stdc++.h>
using namespace std;


const int nmax = 1e5+10;

vector<int> adj[nmax];      /// adj[i] = adjacency list of node i

int subtree[nmax];  /// subtree[i] = subtree size of node i
int height[nmax];   /// height[i] = height of node i
int depth[nmax];    /// depth[i] = depth of node i

void dfs(int u, int par){
    subtree[u] = 1;

    if(par == -1)
        depth[u] = 0;
    else
        depth[u] = depth[par]+1;

    height[u] = 0;

    for(int v : adj[u]){
        if(v == par) continue;

        dfs(v, u);
        subtree[u] += subtree[v];
        height[u] = max(height[u], height[v]+1);
    }
}


int main(){
    int n;
    cin>>n;

    /// tree -> e = v-1

    for(int i = 0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    for(int i = 1; i<=n; i++){
        cout<<i<<" "<<height[i]<<endl;
    }
}

/*
7
1 2
1 3
3 4
3 5
2 6
6 7
*/
