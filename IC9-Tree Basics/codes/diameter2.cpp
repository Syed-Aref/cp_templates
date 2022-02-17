#include <bits/stdc++.h>
using namespace std;


const int nmax = 1e5+10;

vector<int> adj[nmax];      /// adj[i] = adjacency list of node i

int height[nmax];
int maxlen[nmax];

void dfs(int u, int par){
    height[u] = 0;

    int h[3] = {0, 0, 0};

    for(int v : adj[u]){
        if(v == par)
            continue;

        dfs(v, u);
        height[u] = max(height[u], height[v]+1);

        h[0] = height[v]+1;
        sort(h, h+3);
    }

    maxlen[u] = max(h[1] + h[2], height[u]);
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

    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans = max(ans, maxlen[i]);
    }

    cout<<ans<<endl;
}

/*
9
1 2
2 3
3 4
3 5
5 6
2 7
3 8
7 9
*/


