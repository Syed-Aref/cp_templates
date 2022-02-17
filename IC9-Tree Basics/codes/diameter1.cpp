#include <bits/stdc++.h>
using namespace std;


const int nmax = 1e5+10;

vector<int> adj[nmax];      /// adj[i] = adjacency list of node i

int depth[nmax];    /// depth[i] = depth of node i

int bfs(int u, int n){
    queue<int> q;

    for(int i = 1; i<=n; i++){
        depth[i] = -1;
    }

    q.push(u);
    depth[u] = 0;

    while(!q.empty()){
//        cout<<u<<endl;

        u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(depth[v] == -1){
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }

    return u;       /// farthest node
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

    int f = bfs(1, n);
    int e = bfs(f, n);

    cout<<depth[e]<<endl;

    cout<<f<<" "<<e<<endl;
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

