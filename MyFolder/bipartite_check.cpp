#include<bits/stdc++.h>
using namespace std;

#define mpr make_pair
typedef long long int lli;

const int nmax = 1e5+10;

vector<int> adj[nmax];
int grp[nmax];


vector<int> seg[2];


bool bfs(int node){

    ///cout << "bfs: " << node << endl;
    queue<int> q;

    grp[node] = 1;
    q.push(node);

    while(q.size() > 0) {
        auto u = q.front();
        q.pop();

        seg[ grp[u] ].push_back(u);

        int expected = (grp[u] + 1) % 2;
        for(auto v : adj[u]) {

            if(grp[v] != -1) {
                if( grp[v] != expected ) return 0;
            }
            else{
                grp[v] = expected;
                ///cout << "pushed: " << v << endl;
                q.push(v);
            }
        }
    }
    return 1;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,m;

    cin >> n >> m;
    for(int i = 0;i<=n+2;i++) grp[i] = -1;

    int ui,vi;
    for(int i = 0;i<m;i++){
        cin >> ui >> vi;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }

    bool possible = 1;

    for(int i = 1;i<=n && possible==1;i++){
        if(grp[i]==-1) possible = (possible & bfs(i));
    }
    if(possible) {
        cout << seg[0].size() << endl;
        for(auto i : seg[0]) cout << i << " ";
        cout << endl;

        cout << seg[1].size() << endl;
        for(auto i : seg[1]) cout << i << " ";
        cout << endl;
    }
    else cout << -1 << endl;

}
