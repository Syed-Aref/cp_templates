#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5+10;
vector<int> adj[nmax];
int depth[nmax];
int ancestor[nmax][20];     /// 2^20 > 10^6
/// ancestor[x][i] = 2^i-th ancestor of x

void dfs(int u, int par){
    for(int i = 0; i<20; i++)
        ancestor[u][i] = -1;

    if(par != -1){
        depth[u] = depth[par] + 1;
        ancestor[u][0] = par;
        for(int i = 1; i<20; i++){
            int v = ancestor[u][i-1];
            if(v == -1) break;
            ancestor[u][i] = ancestor[v][i-1];
        }
    }

    for(int v : adj[u]){
        if(v == par) continue;
        dfs(v, u);
    }
}

int getAncestor(int u, int k){
    for(int i = 0; i<20; i++){
        if((k & (1<<i)) != 0){
            u = ancestor[u][i];
            if(u == -1)
                return -1;
        }
    }
    return u;
}
/// log n

/// binary lifting

int LCA(int u, int v){
    if(depth[u] > depth[v]){
        u = getAncestor(u, depth[u] - depth[v]);
    }
    else if(depth[v] > depth[u]){
        v = getAncestor(v, depth[v] - depth[u]);
    }

    if(u == v) return u;

    for(int i = 19; i>=0; i--){
        if(ancestor[u][i] == ancestor[v][i]) continue;

        u = ancestor[u][i];
        v = ancestor[v][i];
    }

    return ancestor[u][0];
}

/// log n

/// lca if rooted at r
int genLCA(int r, int u, int v){
    int x = LCA(u, v);
    int y = LCA(u, r);
    int z = LCA(v, r);

    return x^y^z;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin>>n;
    cin>>q;

    for(int i = 2; i<=n; i++){
        int boss;
        cin>>boss;
        adj[boss].push_back(i);
    }

    dfs(1, -1);

//    for(int i = 1; i<=n; i++){
//        cout<<"ancestors of "<<i<<" = ";
//        for(int j = 0; j<3; j++){
//            cout<<ancestor[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    for(int i = 0; i<q; i++){
        int x, y;
        cin>>x>>y;

        cout<<LCA(x, y)<<"\n";
    }



    return 0;
}
