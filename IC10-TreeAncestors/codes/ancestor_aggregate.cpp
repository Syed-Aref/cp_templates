#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5+10;
vector<int> adj[nmax];
pair<int, int> ancestor[nmax][20];     /// 2^20 > 10^6
/// ancestor[x][i] = (2^i-th ancestor of x, sum of values from x upto but excluding 2^i-th ancestor)

int val[nmax];


/// n*log n
void dfs(int u, int par){
    for(int i = 0; i<20; i++)
        ancestor[u][i] = {-1, -1};

    if(par != -1){
        ancestor[u][0] = {par, val[u]};
        for(int i = 1; i<20; i++){
            int v = ancestor[u][i-1].first;
            int tmp = ancestor[u][i-1].second;
            if(v == -1) break;
            ancestor[u][i].first = ancestor[v][i-1].first;
            ancestor[u][i].second = ancestor[v][i-1].second + tmp;
        }
    }

    for(int v : adj[u]){
        if(v == par) continue;
        dfs(v, u);
    }
}

/// O(log n)
pair<int, int> getAncestor(int u, int k){   /// (kth ancestor, value upto kth ancestor (inclusive))
    int sum = 0;
    for(int i = 0; i<20; i++){
        if((k & (1<<i)) != 0){
            sum += ancestor[u][i].second;
            u = ancestor[u][i].first;
            if(u == -1)
                return {-1, -1};
        }
    }
    sum += val[u];
    return {u, sum};
}

/// binary lifting

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin>>n;
    cin>>q;

    for(int i = 1; i<=n; i++){
        cin>>val[i];
    }

    for(int i = 0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);



    return 0;
}

/*
18
1 2
1 3
2 4
2 8
4 5
5 6
4 7
8 9
8 10
9 11
3 13
3 14
14 15
14 17
15 16
17 18
17 12
*/


