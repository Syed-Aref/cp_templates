#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 5e5+10;
vector<pii> adj[nmax]; /// (distance , node)
int inf = 1e9;
int dist[nmax];


int n = 0;

pii dijkstra(int s, int n){
    for(int i = 0; i<=n+2; i++) dist[i] = 1e9;

    /// (shortest distance to u, u)
    priority_queue< pii, vector<pii>, greater<pii> > pq; /// (distance , node)

    dist[s] = 0;
    pq.push( mpr(0,s) );


    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d != dist[u]) continue;

        for(pii p : adj[u]){
            int c = p.first;
            int v = p.second;

            if(d+c < dist[v]){
                dist[v] = d+c;
                pq.push({d+c, v});

            }
        }
    }

    int cnt= 0;
    int max_ = -1;
    for(int i = 0;i<n;i++){
        if( dist[i] == inf ) continue;
        max_ = max(max_,dist[i]);
    }
    for(int i = 0;i<n;i++){
        if( dist[i] == max_ ) cnt++;
    }
    return mpr(max_,cnt);

}

///Time complexity: O(V+ E*LOG(E))

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m,q;
    cin >> n >> m >> q;
    for(int i = 0;i<m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        if(u==v) continue;
        adj[v].pbk( mpr(w,u) );
        adj[u].pbk( mpr(w,v) );
    }

    for(int i = 0;i<n;i++) sort( adj[i].begin() , adj[i].end() );
    ///Time complexity: O(E*LOG(E))

    for(int i = 0;i<q;i++) {
        int city;
        cin >> city;
        auto p = dijkstra(city , n);
        cout << p.first << " " << p.second << endl;
    }
}
