#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5+10;
long long int tree[4*nmax];
long long int arr[nmax];

/// O(n)
void build(int id, int l, int r){
    if(l == r){
        tree[id] = arr[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*id, l, mid);
    build(2*id+1, mid+1, r);

    tree[id] = min(tree[2*id], tree[2*id+1]);       /// merge
    return;
}

/// O(log n)
void update(int id, int l, int r, int k, long long int u){
    if(l == r){
        tree[id] = u; /// assignment
        ///tree[id] += u;  /// add
        return;
    }

    int mid = (l+r)/2;

    if(k <= mid)
        update(2*id, l, mid, k, u);
    else
        update(2*id+1, mid+1, r, k, u);

    tree[id] = min(tree[2*id], tree[2*id+1]);       /// merge
    return;
}

/// O(log n)
long long int query(int id, int l, int r, int a, int b){
    if(b < l || r < a)  /// disjoint case
        return 1e18;       /// identity
    if(a <= l && r <= b)
        return tree[id];

    int mid = (l+r)/2;

    long long int p = query(2*id, l, mid, a, b);
    long long int q = query(2*id+1, mid+1, r, a, b);
    return min(p, q);
}

/// pair (arr[i], i) (arr[j], j)


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n,q ;
    cin>>n>>q;

    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }

//    for(int i = 1; i<=n; i++){
//        update(1, 1, n, i, arr[i]);
//    }

    build(1, 1, n);

    for(int i = 0; i<q; i++){
        int type;
        cin>>type;
        if(type == 1){
            int k, u;
            cin>>k>>u;

            update(1, 1, n, k, u);
        }
        else{
            int l, r;
            cin>>l>>r;

            long long int ans = query(1, 1, n, l, r);
            cout<<ans<<"\n";
        }
    }
}
/// O((n+q) log n)
