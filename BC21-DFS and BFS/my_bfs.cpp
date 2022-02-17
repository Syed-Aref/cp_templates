#include <bits/stdc++.h>
using namespace std;

const int nmax = 100000+10;
vector<int> adjlist[nmax];
bool visitd[nmax];


void bfs(int U)
{
    queue<int> q;
    cout << "bfs at " << U << endl;
    q.push(U);
    visitd[U] = 1;
    while(q.size()!=0)
    {
        int u = q.front();
        q.pop();
        cout << u << " popped from list" << endl;
        cout << "Now push all unvisited adjacent vertices of " << u << endl;
        for(auto v : adjlist[u])
        {
            if( visitd[v]==0 )
            {
                q.push(v);
                visitd[v] = 1;
                cout << v << " pushed ";
            }
            else cout << v << " not pushed ";
        }
        cout << endl;
    }
}
///Time complexity: O(|V| + |E|)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin>>V>>E;
    for(int i = 0;i<E;i++)
    {
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back( v );
        adjlist[v].push_back( u );
    }
    for(int i = 1;i<=V;i++)
    {
        cout << i << " :";
        for(auto j : adjlist[i]) cout << " " << j;
        cout << endl;
    }
    cout << "========================================================================================" << endl;
    for(int i = 1;i<=V;i++)
    {
        if( visitd[i]==0 ) bfs(i);
    }
}
