#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 100000 + 10;
lli arr[nmax];
lli seg[4*nmax];
lli lazy[4*nmax];

void build(int l , int r , int id){
    lazy[id] = 0;
    if(l==r){
        seg[id] = arr[l];
        return;
    }
    int mid = (l+r) / 2;
    build(l,mid,2*id);
    build(mid+1,r,2*id+1);
    seg[id] = seg[2*id] + seg[2*id+1];
    return;

}
///Time complexity: O(N*LOG(N))

void propagate(int l , int r , int id){
    seg[id] += (r-l+1) * lazy[id];
    if(l!=r){
        lazy[2*id] += lazy[id];
        lazy[2*id+1] += lazy[id];
    }
    lazy[id] = 0;
    return;
}
///Time complexity: O(1))

void update(int l , int r , int id , int a , int b , lli k){
    propagate(l,r,id);
    if( l>b ||r<a ){
        return;
    }
    if( l>=a && r<=b ){
        lazy[id] += k;
        return;
    }
    int mid = (l+r) / 2;
    update(l,mid,2*id,a,b,k);
    update(mid+1,r,2*id+1,a,b,k);

    seg[id] = seg[2*id] + seg[2*id+1];
    return;
}
///Time complexity: O(LOG(N))

lli query(int l , int r , int id ,int a , int b){
    propagate(l,r,id);
    if( l>b || r<a ) return (lli)0;
    if(l>=a && r<=b) return seg[id];
    int mid = (l+r) / 2;
    return query(l,mid,2*id,a,b) + query(mid+1,r,2*id+1,a,b);
}
///Time complexity: O(LOG(N))

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t-->0){

        int n;
        cin >> n;
        /// for(int i = 1;i<=n;i++) cin >> arr[i];
        build(1,n,1);

        int q;
        cin >> q;
        for(int i = 1;i<=q;i++){
            int type;
            cin >> type;
            if(type==0){
                /// update
                int a,b;lli k;
                cin >> a >> b >> k;
                update(1,n,1,a,b,k);
            }
            else{
                /// query
                int a,b;
                cin >> a >> b;
                cout << query(1,n,1,a,b) << endl;
            }
        }

    }
}
