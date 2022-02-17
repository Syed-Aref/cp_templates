#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

/// without any links,weighted,directed
/// for directed graph , algorithm will be exactly same,just we need to take input
/// according to undirected graph
const int nmax = 100;  /// max(nmax) <= 500

lli dist[nmax+3][nmax+3];
lli inf = (lli)(1e17);

void floydwarshall(int V)
{
    for(int k = 1;k<=V;k++)
    {
        for(int i = 1;i<=V;i++)
        {
            for(int j = 1;j<=V;j++) dist[i][j] = min( dist[i][j],( dist[i][k]+dist[k][j] ) );
        }
    }
}
/// Time complexity: O(|V|^3)
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 1;i<=nmax;i++)
    {
        for(int j = 1;j<=nmax;j++)
        {
            if( i==j ) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }


    int n,m;
    cin >> n >> m;
    int ui,vi;lli ci;
    for(int i = 0;i<m;i++)
    {
        cin >> ui >> vi >> ci;
        dist[ui][vi] = min(ci,dist[ui][vi]);
    }

}
