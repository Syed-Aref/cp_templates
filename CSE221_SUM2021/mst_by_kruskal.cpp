#include <bits/stdc++.h>
using namespace std;


const int nmax = 1000;
int sz[nmax+5];
int master[nmax+5];
int findmaster(int u)
{
    if( master[u]==u ) return u;
    int ret = findmaster(master[u]);
    master[u] = ret; /// path compression
    return ret;
}
bool unite( int u,int v )
{
    int mastu = findmaster(u);
    int mastv = findmaster(v);
    if( mastu==mastv ) return false; /// same component
    if( sz[mastu] > sz[mastv] )
    {
        master[mastv] = mastu;
        sz[mastu]+=sz[mastv];
    }
    else
    {
        master[mastu] = mastv;
        sz[mastv]+=sz[mastu];
    }
    return true;
}
bool insamecomponent(int u,int v)
{
    int mastu = findmaster(u);
    int mastv = findmaster(v);
    if( mastu==mastv ) return true;
    return false;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        sz[i] = 1;
        master[i] = i;
    }

    int a , b , c;
    vector< pair<int,pair<int,int>> > vp;

    for(int i = 0;i<m;i++)
    {
        cin >> a >> b >> c;
        vp.push_back( make_pair(  c , make_pair(a,b) ) );
    }
    int cnt = 0;
    int sum = 0;
    sort( vp.begin() , vp.end() );
    for(auto i : vp)
    {
        int u = i.second.first , v = i.second.second , w = i.first;
        if(findmaster(u)==findmaster(v)) continue;
        unite(u,v);
        cnt++;
        sum += w;
    }
    if(cnt==n-1) cout << "MST is possible" << endl;
    else cout << "MST is impossible" << endl;
    cout << sum << endl;

}
