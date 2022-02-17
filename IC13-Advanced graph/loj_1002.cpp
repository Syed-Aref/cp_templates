#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 500 + 5;
int inf = 1e9;
vector< int > adj[nmax];
int dist[nmax];
/// bool visited[nmax];
int cost[nmax][nmax];

void bfs(int t)
{

    queue< int >q;
    /// (node,par_of_node)

    dist[t] = 0;
    q.push( t );

    while(q.size()!=0) {
        int u = q.front();
        q.pop();
        /// if(visited[u]==1) continue;
        /// visited[u] = 1;
        for(auto v : adj[u]) {
            /// if(visited[v]==1) continue;
            int w = max( cost[u][v] , dist[u] );
            if( w < dist[v] ) {
                q.push(v);
                dist[v] = w;
            }
        }

    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for(int cases = 1;cases <= t; cases++) {
        int n, m , t;
        cin >> n >> m;

        for(int i = 0;i<=n+2;i++) {
            dist[i] = inf;
            /// visited[i] = 0;
            adj[i].clear();
            for(int j = 0;j<=n+2;j++) {
                cost[i][j] = 0;
                cost[j][i] = 0;
            }
        }
        int u,v,w;

        for(int i = 0;i<m;i++) {
            cin >> u >> v >> w;
            adj[u].pbk( v );
            adj[v].pbk( u );

            if(cost[u][v] == 0) {
                cost[u][v] = w;
                cost[v][u] = w;
            }
            else{
                cost[u][v] = min(w,cost[u][v]);
                cost[v][u] = cost[u][v];
            }
        }
        cin >> t;
        bfs(t);
        cout << "Case " << cases << ":" << endl;
        for(int i = 0;i<n;i++) {
            if(dist[i] == inf) cout << "Impossible" << endl;
            else cout << dist[i] << endl;
        }
    }




}
