#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

const int nmax = 100000+10;
const lli inf = 1e18;

vector< pair<int,lli> > adj[nmax];    /// (vertex,weight)
lli dist[nmax];
int link[nmax];

void dijkstra(int u_,int V)
{
    for(int i = 1;i<=V;i++)
    {
        dist[i] = inf;
        link[i] = -1;
    }
    dist[u_] = 0;

    priority_queue<  pair<lli,int> , vector< pair<lli,int> > , greater< pair<lli,int> > >pq;     /// (distance,u)
    pq.push( make_pair((lli)0,u_) );
    while(pq.size()!=0)
    {
        int u = pq.top().second;
        lli d = pq.top().first;
        pq.pop(); /// LOG(E)

        cout << "popped (" << d << "," << u << ")" << endl;
        if( dist[u] != d )
        {
            cout << "wrong pair" << endl;
            continue;
        }
        else cout << "correct pair" << endl;

        for(auto p : adj[u]) ///E
        {
            int v = p.first;
            lli d1 = p.second;

            if( (d+d1) < dist[v]  )
            {
                dist[v] = d+d1;
                pq.push( make_pair(dist[v],v) );  ///LOG(E)
                link[v] = u;
            }
        }
    }
}
/// OVERALL : O(N) = E*LOG(E)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E;
    cin >> V >> E;
    for(int i = 0;i<E;i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back( make_pair(v,c) );
        adj[v].push_back( make_pair(u,c) );
    }

    dijkstra(1,V);
    for(int i = 1;i<=V;i++) cout << "dist[" << i << "] : " << dist[i] << endl;

    cout << "-----------------------------------------------------" << endl;

    int target = 4;
    vector<int> path;

    path.push_back(target);
    while(target!=-1 && target!=1)
    {
        target = link[target];
        path.push_back(target);
    }

    if(target==-1)
    {
        cout << "no path exists" << endl;
    }
    else
    {
        for(auto i: path) cout << i << " ";
        cout << endl;
    }

}
