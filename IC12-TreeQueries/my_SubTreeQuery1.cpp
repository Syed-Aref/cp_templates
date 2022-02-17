#include<bits/stdc++.h>
using namespace std;


typedef long long int lli;

const int nmax = 2e5+10;
vector<int> adj[nmax];
lli v[nmax];
int dfs_arr[nmax];

int time_ = 0;
int start[nmax];
int finish[nmax];

void dfs(int src,int par) {
    time_++;
    dfs_arr[time_] = src;
    start[src] = time_;
    for(auto u : adj[src]) {
        if(u==par) continue;
        dfs(u,src);
    }
    finish[src] = time_ ;
}
///Time complexity: O(N))

lli seg[4*nmax];
void build(int l,int r,int id){

    if(l==r)
    {
        seg[id] = v[ dfs_arr[l] ];
        return;
    }
    int mid = (l+r) / 2;

    /// int child1 = 2*id;
    /// int child2 = 2*id + 1;

    build(l,mid,2*id);
    build(mid+1,r,2*id + 1);

    seg[id] += (seg[2*id] + seg[2*id + 1]);
    return;
}
///Time complexity: O(N*LOG(N))

void update(int l,int r,int id,int k,lli u)
{
    if(l==r)
    {
        seg[id] = u;
        return;
    }
    int mid = (l+r) / 2;
    if(k<=mid)
    {
        update(l,mid,2*id,k,u);
    }
    else update(mid+1,r,2*id+1,k,u);

    seg[id] = seg[2*id] + seg[2*id+1];
    return;
}
///Time complexity: O(LOG(N))

lli sumf(int l,int r,int id,int a,int b)
{
    if( b<l || a>r ) return 0;
    if(l>=a && r<=b) return seg[id];
    int mid = (l+r) / 2;
    lli p = sumf(l,mid,2*id,a,b);
    lli q = sumf(mid+1,r,2*id+1,a,b);
    return p+q;
}
///Time complexity: O(LOG(N))

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int q;
    cin >> q;

    for(int i = 1;i<=n;i++) {
        cin >> v[i];
    }

    int ui,vi;
    for(int i = 1;i<=n-1;i++) {
        cin >> ui >> vi;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }

    dfs(1,-1);
    build(1,n,1);

    for(int t = 0;t<q;t++) {
        int type;
        cin >> type;
        if(type==1) {
            /// change
            int node;lli x;
            cin >> node >> x;
            update(1,n,1,start[node],x);
        }
        else{
            /// summation of sub-tree
            int node;
            cin >> node;
            cout<< sumf(1,n,1,start[node],finish[node]) << "\n";
        }
    }


}
