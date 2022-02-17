#include <bits/stdc++.h>
using namespace std;

///Link: https://codeforces.com/problemset/problem/1354/D?locale=en

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 1000000 + 10;
int freq[nmax];


int seg[4*nmax];

void build(int l,int r,int id){

    if(l==r)
    {
        seg[id] = freq[l];
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
/// Time complexity: O(N*LOG(N))

void update(int l,int r,int id,int k,int u)
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
/// Time complexity: O(LOG(N))

int element_at(int l,int r,int id,int k)
{
    if(l==r) return l;
    int mid = (l+r) / 2;
    if(k <= seg[2*id]) return element_at(l,mid,2*id , k);
    else return element_at(mid+1,r,2*id+1,k-seg[2*id]);
}
/// Time complexity: O(LOG(N))

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ///cout << "line 77" << endl;

    int n , q;
    cin >> n >> q;
    int x;
    for(int i = 0;i<n;i++)
    {
        cin >> x;
        freq[x]++;
    }

    build(1,n,1);

    int k;
    for(int i = 0;i<q;i++)
    {
        cin >> k;
        if(k > 0)
        {
            update(1,n,1,k,+1);
        }
        else{
            k = abs(k);
            int index = element_at(1,n,1,k);
            update(1,n,1,index,-1);
        }
    }
    if(seg[1]==0) cout << 0 << endl;
    else cout << element_at(1,n,1,1) << endl;

}

