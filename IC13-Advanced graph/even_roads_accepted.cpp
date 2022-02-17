#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 10000 + 5;
lli inf = 1e17;

vector< pair<int,lli> > adj[nmax]; /// (node,distance)
pair<int,int> par[nmax][2]; ///(node,state)
lli dist[nmax][2];


void bfs(int src) {


    priority_queue< pair<lli,pair<int,int>> , vector<pair<lli,pair<int,int>>> , greater<pair<lli,pair<int,int>>> > pq;
    /// ( dist[node][state] , (node,state) )
    dist[src][0] = (lli)0;
    par[src][0] = mpr(-1,-1);
    /// cout << "pushed (" << 0 << " , (" << src << ", " << 0 << ") )"<< endl;
    pq.push( mpr(0,mpr(src,0)) );

    while(pq.size()!=0) {
        auto p = pq.top();
        pq.pop();

        int u = p.second.first;
        int state = p.second.second;
        /// cout << "testing (" << dist[u][state] << " , (" << u << ", " << state << ") )"<< endl;
        int nxt_state = (state+1)%2;
        for(auto p : adj[u]) {
            int v = p.first;
            lli w = p.second;
            if( dist[v][nxt_state] > dist[u][state] + w ) {
                dist[v][nxt_state] = dist[u][state] + w;
                par[v][nxt_state] = mpr( u,state  );
                /// cout << "pushed (" << dist[v][nxt_state] << " , (" << v << ", " << nxt_state << ") )"<< endl;
                pq.push( mpr(dist[v][nxt_state] , mpr(v,nxt_state ) ) );
            }
        }
    }
}

/// Time complexity: O(ts*E*LOG(ts*E))
/// ts = total states(# of graphs we assumed)
/// Here, s = 2

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;

    while(cin >> n && cin >> m) {

        /// Initializing
        for(int i = 0;i<=n+2;i++) {
            adj[i].clear();

            par[i][0].first = 0;par[i][0].second = 0;
            par[i][1].first = 0;par[i][1].second = 0;

            dist[i][0] = inf;dist[i][1] = inf;
        }
        /// Time complexity: O(ts*V)
        /// ts = total states(# of graphs we assumed)
        /// Here, s = 2

        for(int i = 0;i<m;i++) {
            int u,v;lli w;
            cin >> u >> v >> w;
            adj[u].pbk( mpr(v,w) );
            adj[v].pbk( mpr(u,w) );
        }
        bfs(1);
        if(dist[n][0] == inf) cout << -1 << endl;
        else cout << dist[n][0] << endl;
    }
    /**
    cout << " ====================== " << endl;
    for(int i = 1;i<=n;i++)
    {
        int target = i;
        if(dist[target][0] == inf) {
            cout << -1 << endl;
            continue;
        }
        cout << "Cost "<<i<< ": " << dist[target][0] << endl;
        cout << "Path:";

        vector<int> path;
        path.pbk(target);

        int x = target , state = 0;
        while(1) {
            int tmpx = par[x][state].first;
            int tmpstae = par[x][state].second;

            x = tmpx;
            if(x==-1) break;
            state = tmpstae;
            path.pbk(x);
        }
        reverse( path.begin() , path.end() );
        for(auto i : path) cout << " " << i;
        cout << endl;
    }
    cout << " ====================== " << endl;
    **/

}
