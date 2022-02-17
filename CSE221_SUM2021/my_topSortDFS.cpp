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

vector<int> adj[nmax];
int visited[nmax];
vector<int> topsort;

bool dfs( int u ){
    visited[u] = 1;
    bool ret = true;
    for(auto v : adj[u]){
        if( visited[v] == 1 ) return false;
        if( visited[v]==2 )continue;
        ret = ret & dfs(v);
        if(ret==false) break;
    }
    visited[u] = 2;
    topsort.push_back(u);
    return ret;
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
            visited[i] = 0;
        }
        topsort.clear();

        for(int i = 0;i<m;i++){
            int ui,vi;
            cin >> ui >> vi;

            adj[ui].push_back(vi);
        }
        for(int i = 1;i<=n;i++){
            sort( adj[i].begin() , adj[i].end() ) ;
            /// reverse(adj[i].begin() , adj[i].end());
        }
        /// call dfs
        /// reverse the list
        bool isPossible = true;
        for(int i = 1;i<=n && isPossible==true;i++){
            if( visited[i] == 0 ) isPossible = dfs(i);
        }
        if(isPossible){
            reverse( topsort.begin() , topsort.end() );
            for(auto u : topsort)cout<< char(u+64) << " ";
            cout << endl;
        }
        else cout << "IMPOSSIBLE" << endl;


    }


}
