#include <bits/stdc++.h>
using namespace std;


typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<int,lli> pil;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 1e5 + 10;
int n = 0;int m = 0;int clk = 0;

vector< int > adj[nmax]; ///(node)
bool visited[nmax];
int low[nmax];
int st[nmax];
set< pii > bridges;

/// This solution does not handle same edges

void dfs(int u,int par){
    ///cout << "At dfs(" << u << "," << par << ")" << endl;
    ++clk;
    low[u] = st[u] = clk;
    visited[u] = 1;
    for(auto p : adj[u]) {

        int v = p;

        if(v==par) continue;
        if( visited[v] ){
            low[u] = min( low[u] , st[v] );
        }
        else{
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if( st[u] < low[v] ) bridges.insert( mpr(min(u,v) ,max(u,v)) );
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 100;
    while(cin >> n){
        /// cin >> n;

        for(int i = 0;i<=n+2;i++) {
            adj[i].clear();
            visited[i] = 0;
            low[i] = -1;
            st[i] = -1;
        }
        clk = 0;
        bridges.clear();


        // int edgeCnt = 0;
        for(int i = 0;i<=n-1;i++){
            int u,edgesFrom_u;
            char c;
            cin >> u >> c >> edgesFrom_u >> c;
            for(int j = 0;j<edgesFrom_u;j++){
                int v;
                cin >> v;
                adj[ u ].pbk( v );
                /// adj[ v ].pbk( u );

                /// we do not need to put edge(v,u) when edge(u,v) is given
                /// as for this problem both edge(u,v) and edge(v,u) are given separately
                /// But we still may put one edge more than once since the algorithm does not
                /// care about same edges
            }


        }

        /**
        for(int i = 0;i<=n-1;i++){
            cout << "# of edges from " << i << " : ";
            int k = 0;
            for(auto p : adj[i]){
                if(k>0) cout<< ",";
                cout << "(" << p.first << "," << p.second <<")";
                ++k;
            }
            cout << endl;
        }
        **/
        for(int i = 0;i<=n-1;i++) {
            if(visited[i] == 0){
                dfs(i,-1);
            }
        }
        cout << (int)bridges.size() << " critical links" << endl;
        for(auto p : bridges){
            cout << p.first << " - " << p.second << endl;
        }
        cout << endl;
    }


}
