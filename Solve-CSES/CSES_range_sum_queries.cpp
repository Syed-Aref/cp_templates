
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 1000000 + 10;
//lli arr[nmax];
//lli dif[nmax];


int seg[4*nmax];




void update(int l,int r,int id,int k)
{
    if(l==r)
    {
        if(seg[id]==1) seg[id] = 0;
        else seg[id] = 1;
        return;
    }
    int mid = (l+r) / 2;
    if(k<=mid)
    {
        update(l,mid,2*id,k);
    }
    else update(mid+1,r,2*id+1,k);

    seg[id] = seg[2*id] + seg[2*id+1];
    return;
}


int sumf(int l,int r,int id,int a,int b)
{
    if( b<l || a>r ) return 0;
    if(l>=a && r<=b) return seg[id];
    int mid = (l+r) / 2;
    int p = sumf(l,mid,2*id,a,b);
    int q = sumf(mid+1,r,2*id+1,a,b);
    return p+q;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n , k;
    cin >> n >> k;


    char c;
    int a , b, u;
    for(int i = 0;i<k;i++)
    {
        cin >> c;
        if(c=='F'){
            cin >> u;
            update(1,n,1,u);
        }
        else{
            cin >> a >> b;
            cout << sumf(1,n,1,a,b) << endl;
        }
    }

}
