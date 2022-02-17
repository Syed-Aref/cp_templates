#include <bits/stdc++.h>
using namespace std;

const int nmax = 1000;
vector<pair<int,int>> adjlist[nmax + 10]; /// (vertex , weight)
int dist[nmax+10];
bool completed[nmax+10];
const int inf = 1e9;
bool prim(int u,int V)
{
    for(int i = 1;i<=V;i++) dist[i] = inf , completed[i] = 0;
    dist[u] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; /// (cost , vertex)
    pq.push(make_pair( 0,u ));

    int cnt = 0;
    while(pq.size()!=0)
    {
        auto p = pq.top();
        pq.pop();
        int v = p.second , w = p.first;
        /// if( dist[v] != w ) continue;
        if(completed[v]) continue;
        completed[v] = true;
        cnt++;
        cout << "TRAVELLING FROM " << v << endl;
        for(auto i : adjlist[v])
        {

            if( i.second < dist[i.first] )
            {
                dist[i.first] = i.second;
                pq.push( make_pair(i.second , i.first) );
                cout << "Took " << i.first << endl;
            }
        }

    }

    if(cnt==V-1) return 1;
    return 0;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, E;
    cin>>V>>E;

    for(int i = 0; i<E; i++){
        int u, v, c;
        char u1 , v1;
        cin>>u1>>v1>>c;
        u = u1 - 64;v = v1 - 64;
        adjlist[u].push_back(make_pair(v, c));
    }


    if(prim(1, V)) cout << "MST is possible" << endl;
    else cout << "MST is impossible" << endl;


}
