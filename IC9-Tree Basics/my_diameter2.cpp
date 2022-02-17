#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"


const int nmax = 1e5;

vector<int> adj[nmax+10];
int height[nmax+10];
int maxlen[nmax+10];

void dfs(int u,int par){
    height[u] = 0;
    int h[3] = {0,0,0};

    for(auto v : adj[u]){
        if(v==par) continue;

        dfs(v,u);
        height[u] = max(height[u],height[v]+1);

        h[0] = height[v]+1;
        sort(h,h+3);
    }

    maxlen[u] = max( height[u],h[1]+h[2] );

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int ui,vi;
    for(int i = 1;i<=n-1;i++){
        cin >> ui >> vi;
        adj[ui].pbk(vi);
        adj[vi].pbk(ui);
    }

    dfs(1,-1);
    int ans = -1;
    for(int i = 1;i<=n;i++) ans = max(ans,maxlen[i]);
    cout << ans << endl;

}
