#include <bits/stdc++.h>
using namespace std;

/// Finding cycle of length > K

const int nmax = 100000;

vector<int> adjlist[nmax+5];
bool visited[nmax+5];
vector<pair<int,int>> vp; /// (last,first)
int par[nmax+5];

void dfs(int u,int parent)
{
    visited[u] = 1;
    par[u] = parent;
    for(auto v : adjlist[u])
    {
        if( v==par[u] ) continue;
        if( visited[v]==1 ) vp.push_back( make_pair(u,v) );
        else dfs( v,u );
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t-->0)
    {
        for(int i = 0;i<nmax+5;i++)
        {
            adjlist[i].clear();
            visited[i] = 0;
            par[i] = 0;

        }
        vp.clear();

        int V,E;
        cin >> V >> E;

        int target;
        cin >> target;
        /// K = target
        for(int i = 0;i<E;i++)
        {
            int u,v;
            cin >> u >> v;
            adjlist[v].push_back(u);
            adjlist[u].push_back(v);
        }
        for(int i = 1;i<=V;i++)
        {
            if( visited[i]==0 ) dfs(i,-1);
        }
        /**
        if(vp.size()==0){ cout << "Impossible" << endl;continue; }
        for(auto p : vp) cout << "(" << p.first << "," << p.second << ")" << endl;
        cout << "=============================" << endl;
        **/
        bool printed = 0;

        /// This is where we find the cycle of that length
        for(auto p : vp)
        {
            ///cout << "(" << p.first << "," << p.second << ")" << endl;
            int i = p.first;
            vector<int> v;
            v.push_back(i);
            while( i!=p.second && i!=-1 )
            {
                i = par[i];
                v.push_back(i);
            }
            if(i==-1||v.size()<=target)
            {
                ///cout << "Invalid" << endl;
                continue;
            }


            cout << v.size() << endl;
            for(auto j : v) cout << j << " ";
            cout << endl;
            printed = 1;
            break;
        }
        /// Time complexity: 2*|E|*K
        /// (Maximum number of cycle in a graph: 2*|E|)

    }
}
