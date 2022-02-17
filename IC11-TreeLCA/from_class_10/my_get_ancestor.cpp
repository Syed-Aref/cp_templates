
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 200000;
vector<int> adj[nmax+10];
int ances[nmax+10][20];



void dfs(int s,int par) {
    for(int j = 0;j<20;j++)
        ances[s][j] = -1;
    if(par != -1){
        ances[s][0] = par;
        for(int i = 1; i<20; i++){
            int v = ances[s][i-1];
            if(v == -1) break;
            ances[s][i] = ances[v][i-1];
        }
    }

    for(auto v : adj[s]){
        if(v==par) continue;
        dfs(v,s);
    }
}

int get_ancestor(int u,int n){
    for(int i = 0; i<20; i++){
        if((n & (1<<i)) != 0){
            u = ances[u][i];
            if(u == -1)
                return -1;
        }
    }
    return u;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    ///cin >> t;
    while(t-->0) {
        int n;
        cin >> n;
        int x;
        cin >> x;
        /**
        for(int i = 0;i<=n+2;i++) {
            adj[i].clear();
            for(int j = 0;j<20;j++) {
                ances[i][j] = -1;
            }
        }
        **/
        int u,v;
        for(int i = 2;i<=n;i++) {
            u = i;
            cin >> v;
            adj[v].pbk(u);
            adj[u].pbk(v);
        }
        dfs(1,-1);
        for(int i = 0;i<x;i++) {
            int node,k;
            cin >> node >> k;
            cout << get_ancestor(node,k) << endl;
        }
    }
}

