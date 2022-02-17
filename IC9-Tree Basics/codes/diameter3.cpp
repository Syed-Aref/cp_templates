#include <bits/stdc++.h>
using namespace std;


const int nmax = 1e5+10;

vector<int> adj[nmax];      /// adj[i] = adjacency list of node i

pair<int, int> farthest[nmax][3];

void dfs1(int u, int par){
    for(int i = 0; i<3; i++) farthest[u][i] = {0, u};

    for(int v : adj[u]){
        if(v == par)
            continue;

        dfs1(v, u);

        farthest[u][0] = {farthest[v][2].first+1, farthest[v][2].second};
        sort(farthest[u], farthest[u]+3);
    }
}

void dfs2(int u, int par){
    if(par != -1){
        if(farthest[u][2].second == farthest[par][2].second){
            farthest[u][0] = {farthest[par][1].first+1, farthest[par][1].second};   /// second farthest
        }
        else{
            farthest[u][0] = {farthest[par][2].first+1, farthest[par][2].second};   /// farthest
        }
        sort(farthest[u], farthest[u]+3);
    }

    for(int v : adj[u]){
        if(v == par) continue;

        dfs2(v, u);
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

    dfs1(1, -1);
    dfs2(1, -1);

    for(int i = 1; i<=n; i++){
        cout << "#" << i << " :" << endl;
        cout<<i<<" -> "<<farthest[i][2].second<<" "<<farthest[i][2].first<<endl;
        cout<<i<<" -> "<<farthest[i][1].second<<" "<<farthest[i][1].first<<endl;
        ///if( farthest[i][2].second==farthest[i][1].second ) cout << "Both have same distance" << endl;
    }
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



