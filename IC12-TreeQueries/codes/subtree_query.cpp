#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5+10;

vector<int> adj[nmax];
int val[nmax];

int clk = 0;
int st[nmax], en[nmax];
int dfsarr[nmax];

void dfs(int u, int par){
    clk++;
    st[u] = clk;
    dfsarr[clk] = u;

    for(int v : adj[u]){
        if(v == par) continue;
        dfs(v, u);
    }

    en[u] = clk;
}


///---------------segtree--------------------------

long long int tree[4*nmax];

/// O(n)
void build(int id, int l, int r){
    if(l == r){
        tree[id] = val[dfsarr[l]];
        return;
    }

    int mid = (l+r)/2;

    build(2*id, l, mid);
    build(2*id+1, mid+1, r);

    tree[id] = (tree[2*id] + tree[2*id+1]);       /// merge
    return;
}

/// O(log n)
void update(int id, int l, int r, int k, long long int u){
    if(l == r){
        tree[id] = u;
        return;
    }

    int mid = (l+r)/2;

    if(k <= mid)
        update(2*id, l, mid, k, u);
    else
        update(2*id+1, mid+1, r, k, u);

    tree[id] = (tree[2*id] + tree[2*id+1]);       /// merge
    return;
}

/// O(log n)
long long int query(int id, int l, int r, int a, int b){
    if(b < l || r < a)  /// disjoint case
        return 0;
    if(a <= l && r <= b)
        return tree[id];

    int mid = (l+r)/2;

    long long int p = query(2*id, l, mid, a, b);
    long long int q = query(2*id+1, mid+1, r, a, b);
    return (p + q);
}
///---------------------------------------------------------


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin>>n>>q;

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

    build(1, 1, n);

    for(int i = 0; i<q; i++){
        int t;
        cin>>t;

        if(t == 1){
            int s, x;
            cin>>s>>x;
            update(1, 1, n, st[s] , x);
        }
        else{
            int s;
            cin>>s;

            long long int ans = query(1, 1, n, st[s], en[s]);

            cout<<ans<<"\n";
        }
    }

    return 0;
}
