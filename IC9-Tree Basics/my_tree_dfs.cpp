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

int subtree[nmax+10];
int height[nmax+10];
int depth[nmax+10];

vector<int> adj[nmax+10];



int dfs(int u,int par){

    subtree[u] = 1;
    height[u] = 0;

    if(par == -1)
        depth[u] = 0;
    else
        depth[u] = depth[par]+1;

    for(auto v : adj[u]){
        if(v==par) continue;

        dfs(v,u);
        subtree[u] += subtree[v];
        height[u] = max( height[u],height[v]+1 );
    }
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
    for(int i = 1; i<=n; i++){
        cout<<i<<" => "<< "Height: " <<height[i]<< " , Depth : " <<depth[i]<< " , Subtree : " <<subtree[i]<<endl;
    }


}
