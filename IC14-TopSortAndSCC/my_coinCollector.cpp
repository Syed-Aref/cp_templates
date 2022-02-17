#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const  int nmax = 1e5+10;
int n = 0 , m = 0;
int scc_cnt = 0;

vector<int> adj[nmax];
vector<int> rev_adj[nmax];
int visited[nmax];
int rev_visited[nmax];
vector<int> semitopsort;
vector<int> scc[nmax];
lli val[nmax];
lli comp_val[nmax];
int where[nmax];
vector<int> comp_adj[nmax];
lli memo[nmax];

void dfs( int u ){

    visited[u] = 1;
    for(auto v : adj[u]){
        if( visited[v] == 0 ) dfs(v);
    }
    visited[u] = 2;
    semitopsort.push_back(u);

}

lli dfs_dp(int u,int par){
    if( memo[u]!=-1 ) return memo[u];
    lli x = comp_val[u];
    lli y = 0;
    for(auto v : comp_adj[u]){
        if(v==par) continue;
        y = max(y,dfs_dp(v,u));
    }
    memo[u] = x + y;
    return memo[u];
}

void dfs_(int u){

    rev_visited[u] = 1;
    for(auto v : rev_adj[u]) {
        if( rev_visited[v] == 0 ) dfs_(v);
    }
    rev_visited[u] = 2;
    scc[scc_cnt].push_back(u);
    comp_val[scc_cnt] += val[u];
    where[u] = scc_cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
     /// cin >> t;
    while(t-->0){

        cin >> n >> m;

        for(int i  =0;i<=n+2;i++){
            adj[i].clear();
            rev_adj[i].clear();
            visited[i] = 0;
            rev_visited[i] = 0;
            scc[i].clear();
            val[i] = 0;
            comp_val[i] = 0;
            where[i] = 0;
            comp_adj[i].clear();
            memo[i] = -1;
        }
        scc_cnt = 0;
        semitopsort.clear();

        for(int i = 1;i<=n;i++) cin >> val[i];
        for(int i = 0;i<m;i++){
            int ui,vi;
            cin >> ui >> vi;

            adj[ui].push_back(vi);
            rev_adj[vi].push_back(ui);
        }

        for(int i = 1;i<=n;i++){
            if( visited[i] == 0 ) dfs(i);
        }
        reverse( semitopsort.begin() , semitopsort.end() );
        for(auto i : semitopsort){
            if( rev_visited[i]==0 ){
                ++scc_cnt;
                dfs_(i);
            }
        }
        /**
        for(int i = 1;i<=scc_cnt;i++){
            cout << "#" << i <<" comp:";
            for(auto j : scc[i]) cout << " " << j;
            cout << endl;
        }
        **/
        ///for(int i = 1;i<=n;i++) cout << "comp_val[where[" << i << "]] = " << comp_val[where[i]] << endl;

        for(int i = 1;i<=n;i++){
            for(auto j : adj[i]){
                if( where[i] == where[j] ) {}
                else comp_adj[ where[i] ].push_back( where[j] );
            }
        }

        lli ans = -1;
        for(int i = 1;i<=scc_cnt;i++) ans = max(ans,dfs_dp(i,-1));
        cout << ans << endl;

    }
}
