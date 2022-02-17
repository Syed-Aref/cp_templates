#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e6+10;
int tree[4*nmax];

///// O(n)
//void build(int id, int l, int r){
//    if(l == r){
//        tree[id] = arr[l];
//        return;
//    }
//
//    int mid = (l+r)/2;
//
//    build(2*id, l, mid);
//    build(2*id+1, mid+1, r);
//
//    tree[id] = op(tree[2*id], tree[2*id+1]);       /// merge
//    return;
//}

/// O(log n)
void update(int id, int l, int r, int k, int u){
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
//long long int query(int id, int l, int r, int a, int b){
//    if(b < l || r < a)  /// disjoint case
//        return identity;
//    if(a <= l && r <= b)
//        return tree[id];
//
//    int mid = (l+r)/2;
//
//    long long int p = query(2*id, l, mid, a, b);
//    long long int q = query(2*id+1, mid+1, r, a, b);
//    return op(p, q);
//}

int query(int id, int l, int r, int k){
    if(l == r){
        return l;
    }

    int mid = (l+r)/2;
    if(k <= tree[2*id]){
        return query(2*id, l, mid, k);
    }
    else{
        return query(2*id+1, mid+1, r, k - tree[2*id]);
    }

}

/// pair (arr[i], i) (arr[j], j)


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin>>n>>q;

    for(int i = 1; i<=n; i++){
        int x;
        cin>>x;
        update(1, 1, 1e6, x, +1);
    }


    for(int i = 0; i<q; i++){
        int k;
        cin>>k;
        if(k > 0){
            update(1, 1, 1e6, k, +1);
        }
        else{
            k = abs(k);

            int x = query(1, 1, 1e6, k);

//            cout<<"x = "<<x<<endl;
            update(1, 1, 1e6, x, -1);
        }
    }

    if(tree[1] == 0){
        cout<<0<<endl;
    }
    else{
        cout<<query(1, 1, 1e6, 1)<<endl;
    }


}
/// O((n+q) log n)


