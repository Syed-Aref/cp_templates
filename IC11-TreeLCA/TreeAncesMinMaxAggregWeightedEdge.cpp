#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"


const int nmax = 1e5+10;
vector< pair<int,int> > adj[nmax]; /// pair(node,distance)
int val[nmax+10];
int depth[nmax];
pair<int,int> ancestor_min[nmax][20]; /// pair(node,distance)
pair<int,int> ancestor_max[nmax][20]; /// pair(node,distance)
int inf = 1e9;


void dfs(int u,int par) {
    if(par!=-1) {
        depth[u] = depth[par] + 1;
    }
    for(auto p : adj[u]) {
        int v = p.first;
        int w = p.second;
        if(v==par) continue;
        val[v] = w;
        dfs(v,u);
    }
}

void mindfs(int u, int par){

    ///cout << "called mindfs(" << u << "," << par << ")" << endl;
    if(par != -1){

        ancestor_min[u][0].first = par;
        ancestor_min[u][0].second = val[u];
        ///cout << "set " << "2^" << 0 << " th ancestor_min[ " << u << "]" << ": " << "(" << ancestor_min[u][0].first << "," << ancestor_min[u][0].second  << ")" << endl;
        for(int i = 1; i<20; i++){
            auto p = ancestor_min[u][i-1];
            int v = p.first;
            int w = p.second;
            if(v == -1) break;
            ancestor_min[u][i].first = ancestor_min[v][i-1].first;
            ancestor_min[u][i].second = min( w,ancestor_min[v][i-1].second );

            ///cout << "set " << "2^" << i << " th ancestor_min[ " << u << "]" << ": " << "(" << ancestor_min[u][i].first << "," << ancestor_min[u][i].second << ")" << endl;
        }
    }

    for(auto p : adj[u]){
        int v = p.first;
        if(v == par) continue;
        mindfs(v, u);
    }
}


void maxdfs(int u, int par){
    ///cout << "called maxdfs(" << u << "," << par << ")" << endl;
    if(par != -1){

        ancestor_max[u][0].first = par;
        ancestor_max[u][0].second = val[u];


        ///cout << "set " << "2^" << 0 << " th ancestor_max[ " << u << "]" << ": " << "(" << ancestor_max[u][0].first << "," << ancestor_max[u][0].second  << ")" << endl;

        for(int i = 1; i<20; i++){
            auto p = ancestor_max[u][i-1];
            int v = p.first;
            int w = p.second;
            if(v == -1) break;
            ancestor_max[u][i].first = ancestor_max[v][i-1].first;
            ancestor_max[u][i].second = max( w,ancestor_max[v][i-1].second );

            ///cout << "set " << "2^" << i << " th ancestor_max[ " << u << "]" << ": " << "(" << ancestor_max[u][i].first << "," << ancestor_max[u][i].second  << ")" << endl;
        }
    }

    for(auto p : adj[u]){
        int v = p.first;
        if(v == par) continue;
        maxdfs(v, u);
    }
}


void dfs_(int u,int par){

        ///cout << "called maxdfs(" << u << "," << par << ")" << endl;
    if(par != -1){

        ancestor_max[u][0].first = par;
        ancestor_max[u][0].second = val[u];

        ancestor_min[u][0].first = par;
        ancestor_min[u][0].second = val[u];
        ///cout << "set " << "2^" << 0 << " th ancestor_max[ " << u << "]" << ": " << "(" << ancestor_max[u][0].first << "," << ancestor_max[u][0].second  << ")" << endl;

        for(int i = 1; i<20; i++){
            auto pmax = ancestor_max[u][i-1];
            auto pmin = ancestor_min[u][i-1];

            int v = pmax.first;
            int wmax = pmax.second;
            int wmin = pmin.second;

            if(v == -1) break;
            ancestor_max[u][i].first = ancestor_max[v][i-1].first;
            ancestor_min[u][i].first = ancestor_min[v][i-1].first;

            ancestor_max[u][i].second = max( wmax , ancestor_max[v][i-1].second );
            ancestor_min[u][i].second = min( wmin , ancestor_min[v][i-1].second );
            ///cout << "set " << "2^" << i << " th ancestor_max[ " << u << "]" << ": " << "(" << ancestor_max[u][i].first << "," << ancestor_max[u][i].second  << ")" << endl;
        }
    }

    for(auto p : adj[u]){
        int v = p.first;
        if(v == par) continue;
        dfs_(v, u);
    }
}



pair<int, pair<int,int> > getAncestor(int u, int k){
    int mn = inf, mx = -inf;
    for(int i = 0; i<20; i++){
        if((k & (1<<i)) != 0){
            auto p1 = ancestor_min[u][i];
            auto p2 = ancestor_max[u][i];
            u = p1.first;
            if(u == -1) return mpr(-1,mpr(-1,-1));
            mn = min(mn,p1.second);
            mx = max(mx,p2.second);
        }
    }
    return mpr(u,mpr(mn,mx));
}
/// (node,minimum,maximum)
/// log n

/// binary lifting

pair<int,int> LCA(int u, int v){
    int mn = inf , mx = -inf;
    if(depth[u] > depth[v]){

        auto p = getAncestor(u, depth[u] - depth[v]);
        u = p.first;
        mn = min(mn,p.second.first);
        mx = max(mx,p.second.second);
    }
    else if(depth[v] > depth[u]){

        auto p = getAncestor(v, depth[v] - depth[u]);
        v = p.first;
        mn = min(mn,p.second.first);
        mx = max(mx,p.second.second);
    }

    if(u == v) return mpr(mn,mx);
    int du = depth[u];
    int dv = depth[v];
    int u_ = u;
    int v_ = v;
    for(int i = 19; i>=0; i--){
        if(ancestor_min[u][i].first == ancestor_min[v][i].first) continue;

        u = ancestor_min[u][i].first;
        v = ancestor_min[v][i].first;
    }
    auto cand1 = getAncestor(u_,abs( depth[u]-depth[u_] )+1);
    auto cand2 = getAncestor(v_,abs( depth[u]-depth[v_] )+1);

    mn = min(mn , min( cand1.second.first,cand2.second.first ) );
    mx = max(mx , max( cand1.second.second,cand2.second.second ) );

    return mpr(mn,mx);
}

void print(int i) {
    cout << "#" << i << " :" << endl;
    for(int j = 0;j<20;j++) {
        int ances1 = ancestor_min[i][j].first;
        int mn = ancestor_min[i][j].second;

        int ances2 = ancestor_max[i][j].first;
        int mx = ancestor_max[i][j].second;

        if(ances1==-1 || ances2==-1) break;
        cout << "2^" << j << " th ancestor_min : " << "(" << ances1 << "," << mn << ")" << endl;
        cout << "2^" << j << " th ancestor_max : " << "(" << ances2 << "," << mx << ")" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1;i<=n;i++) {
        for(int j = 0;j<20;j++) {
            ancestor_min[i][j].first = ancestor_max[i][j].first = -1;
            ancestor_min[i][j].second = inf;ancestor_max[i][j].second = -inf;
        }
    }
    int ui,vi,wi;
    for(int i = 1;i<=n-1;i++) {
        cin >> ui >> vi >> wi;
        adj[ui].pbk( mpr(vi,wi) );
        adj[vi].pbk( mpr(ui,wi) );
    }

    depth[1] = 0;
    val[1] = 0;
    dfs(1,-1);
    /**
    for(int i = 1;i<=n;i++) {
        cout << "val[" << i << "] : " << val[i] << endl;
        cout << "depth[" << i << "] : " << depth[i] << endl;
    }
    **/

    /***
    val[1] = inf;
    mindfs(1,-1);

    val[1] = -inf;
    maxdfs(1,-1);
    **/

    val[1] = 0;
    dfs_(1,-1);

    ///cout << "dfs done" << endl;
    /// for(int i = 1;i<=n;i++) print(i);


    cout << "Final queries : " << endl;
    int m;
    cin >> m;
    int u,v;
    for(int i = 0;i<m;i++) {
        cin >> u >> v;
        auto p = LCA(u,v);
        cout << p.first << " " << p.second << endl;
    }

}
