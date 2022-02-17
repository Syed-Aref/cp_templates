#include <bits/stdc++.h>
using namespace std;

const int nmax = 100000+10;
vector<int> adjlist[nmax];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v,e;
    cin >> v >> e;
    for(int i = 0;i<e;i++)
    {
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back( v );
        adjlist[v].push_back( u );
    }
    for(int i = 1;i<=v;i++)
    {
        cout << i << " :";
        for(auto j : adjlist[i]) cout << " " << j;
        cout << endl;
    }

}
