#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5+10;
long long int tree[4*nmax];
long long int lazy[4*nmax];
long long int arr[nmax];

/// O(n)
void build(int id, int l, int r){
    lazy[id] = 0;
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

void propagate(int id, int l, int r){
    tree[id] += lazy;

    if(l != r){
        lazy[2*id] += lazy[id];
        lazy[2*id+1] += lazy[id];
    }

    lazy[id] = 0;
}

/// O(log n)
long long int query(int id, int l, int r, int a, int b){
    propagate(id, l, r);

    if(b < l || r < a)  /// disjoint case
        return 1e18;
    if(a <= l && r <= b)
        return tree[id];

    int mid = (l+r)/2;

    long long int p = query(2*id, l, mid, a, b);
    long long int q = query(2*id+1, mid+1, r, a, b);
    return min(p, q);
}

void update(int id, int l, int r, int a, int b, long long int k){
    propagate(id, l, r);

    if(b < l || r < a)  /// disjoint case
        return ;
    if(a <= l && r <= b){
        lazy[id] += k;
        propagate(id, l, r);
        return;
    }

    int mid = (l+r)/2;

    update(2*id, l, mid, a, b, k);
    update(2*id+1, mid+1, r, a, b, k);

    tree[id] = min(tree[2*id], tree[2*id+1]);
    return;
}


/// range query : sum ?
/// range update : add x to range

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int tc;
    cin>>tc;
    for(int cs = 1; cs <= tc; cs++){
        int n, q;
        cin>>n>>q;

        build(1, 1, n);

        for(int i = 1; i<=q; i++){
            int type;
            cin>>type;
            if(type == 1){
                int l, r;
                cin>>l>>r;

                cout<<query(1, 1, n, l, r)<<"\n";
            }
            else{
                int l, r, k;
                cin>>l>>r>>k;

                update(1, 1, n, l, r, k);
            }
        }
    }


}
/// O((n+q) log n)




