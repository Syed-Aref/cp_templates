#include <bits/stdc++.h>
using namespace std;


const int nmax = 1000+10;

bool adjmat[nmax][nmax];


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
        adjmat[u][v] = 1;
        adjmat[v][u] = 1;
    }
    for(int i = 1;i<=v;i++)
    {
        cout << i << ":";
        for(int j = 1;j<=v;j++)
        {
            if( adjmat[i][j] ) cout << " " << j;

        }
        cout << endl;
    }
}
