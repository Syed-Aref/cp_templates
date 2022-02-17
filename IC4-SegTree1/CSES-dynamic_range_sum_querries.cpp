#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 200000 + 10;

lli a[nmax];
lli seg[4*nmax];

void build(int l,int r,int id){

    if(l==r)
    {
        seg[id] = a[l];
        return;
    }
    int mid = (l+r) / 2;

    int child1 = 2*id;
    int child2 = 2*id + 1;

    build(l,mid,child1);
    build(mid+1,r,child2);

    seg[id] += (seg[child1] + seg[child2]);
    return;
}

///Time complexity: O(N*LOG(N))

void update(int l,int r,int id,int k,lli u)
{
    if(l==r)
    {
        seg[id] = u;
        return;
    }
    int mid = (l+r) / 2;
    if(k<=mid)
    {
        update(l,mid,2*id,k,u);
    }
    else update(mid+1,r,2*id+1,k,u);

    seg[id] = seg[2*id] + seg[2*id+1];
    return;
}

///Time complexity: O(LOG(N))

lli sumf(int l,int r,int id,int a,int b)
{
    if( b<l || a>r ) return 0;
    if(l>=a && r<=b) return seg[id];
    int mid = (l+r) / 2;
    lli p = sumf(l,mid,2*id,a,b);
    lli q = sumf(mid+1,r,2*id+1,a,b);
    return p+q;
}
///Time complexity: O(LOG(N))
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n , q;
    cin >> n >> q;

    for(int i = 1;i<=n;i++)
    {

        cin >> a[i];
    }
    build(1,n,1);
    int type,a,b,k;
    lli u;

    for(int i =0;i<q;i++)
    {
        cin >> type;
        if(type==1)
        {
            cin >> k >> u;
            update(1,n,1,k,u);

        }
        else
        {
            cin >> a >> b;
            lli ans = sumf(1,n,1,a,b);
            cout << ans << endl;
        }
    }



}
