#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

const int nmax = 10000+10;
const lli inf = 1e18;

vector< pair<int,lli> > adj[nmax];    /// (vertex,weight)
lli dist[nmax];

void dijkstra(int u_,int V)
{
    for(int i = 1;i<=V;i++)
    {
        dist[i] = inf;
    }
    dist[u_] = 0;

    priority_queue<  pair<lli,int> , vector< pair<lli,int> > , greater< pair<lli,int> > >pq;     /// (distance,u)
    pq.push( make_pair((lli)0,u_) );
    while(pq.size()!=0) /// E
    {
        int u = pq.top().second;
        lli d = pq.top().first;
        pq.pop(); /// LOG(E)

        /// cout << "popped (" << d << "," << u << ")" << endl;
        if( dist[u] != d )
        {
            /// cout << "wrong pair" << endl;
            continue;
        }
        else{ /// cout << "correct pair" << endl;
        }
        for(auto p : adj[u])///E
        {
            int v = p.first;
            lli d1 = p.second;

            if( (d+d1) < dist[v]  )
            {
                dist[v] = d+d1;
                pq.push( make_pair(dist[v],v) ); ///LOG(E)
            }
        }
    }
}

/// O(N) = E*LOG(E)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    map<string , int > mp;

    cin >> t;
    while(t-->0)
    {
        int n;
        cin >> n;

        /// Intialize
        for(int i = 1;i<=n;i++)
        {

            adj[i].clear();
            dist[i] = 0;
        }
        mp.clear();

        for(int n1 = 1;n1<=n;n1++)
        {
            string name;int p;
            cin >> name >> p;

            mp[name] = n1;
            int city ;lli cost;
            for(int p1 = 1;p1<=p;p1++)
            {
                cin >> city >> cost;
                adj[n1].push_back( make_pair(city,cost) );
            }
        }
        int r;
        cin >> r;
        for(int q = 1;q<=r;q++)
        {
            string name1 , name2;
            cin >> name1 >> name2;

            int u = mp[name1] , v = mp[name2];
            dijkstra(u,n);
            cout << dist[v] << endl;
        }
    }
}
