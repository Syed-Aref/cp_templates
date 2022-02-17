
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
pair<int,lli> ancestor[nmax+10][20];
lli val[nmax+10];


void dfs(int u,int par) {
    for(int j = 0;j<20;j++)
        ancestor[u][j] = {-1,0};
    if(par != -1){
        ancestor[u][0] = {par, val[u] };
        for(int i = 1; i<20; i++){
            int v = ancestor[u][i-1].first;
            int tmp = ancestor[u][i-1].second;
            if(v == -1) break;
            ancestor[u][i].first = ancestor[v][i-1].first;
            ancestor[u][i].second = ancestor[v][i-1].second + tmp;
        }
    }

    for(auto v : adj[u]){
        if(v==par) continue;
        dfs(v,u);
    }
}


pair<int,lli> get_ancestor(int u,int n){
    lli sum = 0;
    for(int i = 0; i<20; i++){
        if((n & (1<<i)) != 0){
            sum += ancestor[u][i].second;
            u = ancestor[u][i].first;

            if(u == -1)
                return mpr(-1,0);
        }
    }

    sum += val[u];
    /**
    If the weight is on edge we
    do not add on sum
    **/

    return mpr(u,sum);
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
        ///cin >> x;
        /**
        for(int i = 0;i<=n+2;i++) {
            adj[i].clear();
            for(int j = 0;j<20;j++) {
                ances[i][j] = -1;
            }
        }
        **/
        int u,v;lli w;
        for(int i = 2;i<=n;i++) {
            cin >> u >> v;
            adj[v].pbk( u );
            adj[u].pbk( v );
        }
        for(int i = 1;i<=n;i++) cin >> val[i];
        dfs(1,-1);

    }
}
