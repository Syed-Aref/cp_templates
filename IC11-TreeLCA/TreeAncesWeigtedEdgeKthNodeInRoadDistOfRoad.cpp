#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int nmax = 1e4+10;
vector<int> adj[nmax];
vector< pair<int,lli> > adjpair[nmax]; /// (Node,weight)
lli sum[nmax];
int depth[nmax];
int ancestor[nmax][15];


void dfs_(int a,int par) {
    if(par!=-1) depth[a] = depth[par] + 1;

    for(auto p : adjpair[a]){
        int v = p.first;
        lli w = p.second;
        if( v==par ) continue;
        sum[v] = sum[a] + w;
        dfs_(v,a);
    }
}



void dfs(int u, int par){


    if(par != -1){
        depth[u] = depth[par] + 1;
        ancestor[u][0] = par;
        for(int i = 1; i<15; i++){
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
    if(k==0) return u;
    for(int i = 0; i<15; i++){
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

lli dist_lca(int u, int v){
    int u1 = u , v1 = v;
    if(depth[u] > depth[v]){
        u = getAncestor(u, depth[u] - depth[v]);
        if(u==v) return sum[u1] - sum[v];
    }
    else if(depth[v] > depth[u]){
        v = getAncestor(v, depth[v] - depth[u]);
        if(u==v) return sum[v1] - sum[u];
    }

    if(u == v) return 0;

    for(int i = 14; i>=0; i--){
        if(ancestor[u][i] == ancestor[v][i]) continue;

        u = ancestor[u][i];
        v = ancestor[v][i];
    }
    u = ancestor[u][0];
    return (sum[u1]+sum[v1] - 2*sum[u]);
}

bool same_parent_check(int u, int v) {
    if(depth[u] > depth[v]){
        u = getAncestor(u, depth[u] - depth[v]);

    }
    else if(depth[v] > depth[u]){
        v = getAncestor(v, depth[v] - depth[u]);

    }
    if(u==v) return 1;
    else return 0;
}

int LCA(int u, int v){
    if(depth[u] > depth[v]){
        u = getAncestor(u, depth[u] - depth[v]);
    }
    else if(depth[v] > depth[u]){
        v = getAncestor(v, depth[v] - depth[u]);
    }

    if(u == v) return u;

    for(int i = 14; i>=0; i--){
        if(ancestor[u][i] == ancestor[v][i]) continue;

        u = ancestor[u][i];
        v = ancestor[v][i];
    }

    return ancestor[u][0];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t-->0) {
        int n;
        cin >> n;
        for(int i =0;i<=n+2;i++) {
            for(int j = 0;j<15;j++) {
                ancestor[i][j] = -1;
            }

            sum[i] = 0;
            depth[i] = 0;
            adjpair[i].clear();
            adj[i].clear();

        }
        for(int i = 1;i<=n-1;i++) {
            int a,b,c;
            cin >> a >> b >> c;

            adj[a].push_back(b);
            adj[b].push_back(a);

            adjpair[a].push_back( make_pair(b,c) );
            adjpair[b].push_back( make_pair(a,c) );
        }


        sum[1] = 0;
        depth[1] = 0;
        dfs_(1,-1);
        /// for(int i = 1;i<=n;i++) cout << "sum[" << i << "] : " << sum[i] << endl;
        dfs(1,-1);
        /// cout << "completed" << endl;

        string str;
        cin >> str;
        while(str!="DONE") {
            int a,b;
            cin >> a >> b;


            if(str=="DIST") {
                cout << dist_lca(a,b) << endl;
            }
            else{
                int depa = depth[a];
                int depb = depth[b];
                int k;
                cin >> k;k--;
                bool spc = same_parent_check(a,b);


                if(depa > depb && spc) {
                    cout << getAncestor(a,k) << endl;
                }
                else if(depb > depa && spc){
                    int dif = abs( depb - depa );
                    cout << getAncestor(b,dif-k) << endl;
                }
                else {
                    int r = LCA(a,b);
                    int da = depa - depth[r];
                    int db = depb - depth[r];
                    if(k<=da) cout << getAncestor(a,k) << endl;
                    else{
                        int x = k-da;
                        /// cout << "To find : b = " << b << ", k = " << depb-x << endl;
                        /// cout << "depb : " << depb << " x : " << x << endl;
                        /// cout << "r:" << r <<endl;
                        cout << getAncestor(b,db-x) << endl;
                    }
                }
            }
            cin >> str;
        }
        cout << endl;
    }

}
