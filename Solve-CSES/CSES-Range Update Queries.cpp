
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
lli arr[nmax];
lli dif[nmax];


lli seg[4*nmax];

void build(int l,int r,int id){

    if(l==r)
    {
        seg[id] = dif[l];
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



void update(int l,int r,int id,int k,lli u)
{
    if(l==r)
    {
        seg[id] += u;
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


lli sumf(int l,int r,int id,int a,int b)
{
    if( b<l || a>r ) return 0;
    if(l>=a && r<=b) return seg[id];
    int mid = (l+r) / 2;
    lli p = sumf(l,mid,2*id,a,b);
    lli q = sumf(mid+1,r,2*id+1,a,b);
    return p+q;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ///cout << "line 77" << endl;

    int n , q;
    cin >> n >> q;
    for(int i = 1;i<=n;i++) cin >> arr[i];
    for(int i = 1;i<=n;i++) dif[i] = arr[i] - arr[i-1];

    build(1,n,1);

    int t,a,b,k;
    lli u;
    for(int i = 0;i<q;i++)
    {
        cin >> t;
        if(t==1)
        {
            cin >> a >> b >> u;
            /// range update
            update(1,n,1,a,u);
            if(b+1<=n) update(1,n,1,b+1,-u);
        }
        else
        {
            cin >> k;
            cout << sumf(1,n,1,1,k) << endl;
        }
    }

}
