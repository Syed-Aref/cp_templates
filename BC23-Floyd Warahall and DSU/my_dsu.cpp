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
/// Time complexity(unite operation): O(1)
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


    /// basically make-set operation in main method
    for(int i = 0;i<nmax+5;i++)
    {
        sz[i]=  1;
        master[i] = i;
    }

    int n,m;
    cin >> n >> m;

    for(int i = 0;i<m;i++)
    {
        int u , v;
        cin >> u >> v;
        bool res = unite(u, v);
        if(res){
            cout<<"edge was between two different components"<<endl;
        }
        else{
            cout<<"edge was between same component"<<endl;
        }

    }

}


