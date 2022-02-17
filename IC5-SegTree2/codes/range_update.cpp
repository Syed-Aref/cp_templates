#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5+10;
long long int tree[4*nmax];
long long int arr[nmax];
long long int diff[nmax];

/// O(n*log(n))
void build(int id, int l, int r){
    if(l == r){
        tree[id] = diff[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*id, l, mid);
    build(2*id+1, mid+1, r);

    tree[id] = (tree[2*id] + tree[2*id+1]);       /// merge
    return;
}

/// O(log n)
void update(int id, int l, int r, int k, long long int u){
    if(l == r){
        tree[id] += u;
        return;
    }

    int mid = (l+r)/2;

    if(k <= mid)
        update(2*id, l, mid, k, u);
    else
        update(2*id+1, mid+1, r, k, u);

    tree[id] = (tree[2*id] + tree[2*id+1]);       /// merge
    return;
}

/// O(log n)
long long int query(int id, int l, int r, int a, int b){
    if(b < l || r < a)  /// disjoint case
        return 0;
    if(a <= l && r <= b)
        return tree[id];

    int mid = (l+r)/2;

    long long int p = query(2*id, l, mid, a, b);
    long long int q = query(2*id+1, mid+1, r, a, b);
    return (p + q);
}

/// pair (arr[i], i) (arr[j], j)


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin>>n>>q;

    for(int i = 1; i<=n; i++) cin>>arr[i];
    for(int i = 1; i<=n; i++)
        diff[i] = arr[i] - arr[i-1];

    build(1, 1, n);

    for(int i = 1; i<=q; i++){
        int t;
        cin>>t;

        if(t == 1){
            int a, b, u;
            cin>>a>>b>>u;
            update(1, 1, n, a, +u);
            if(b+1 <= n) update(1, 1, n, b+1, -u);
        }
        else{
            int k;
            cin>>k;
            cout<<query(1, 1, n, 1, k)<<"\n";
        }
    }

}
