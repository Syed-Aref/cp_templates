#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

/// Application of segment tree.

const int nmax = 200000 + 100;

///lli a[nmax];
lli seg[4*nmax];

void build(int l,int r,int id){

    if(l==r)
    {
        seg[id] = 0;
        return;
    }
    int mid = (l+r) / 2;

    int child1 = 2*id;
    int child2 = 2*id + 1;

    build(l,mid,child1);
    build(mid+1,r,child2);

    seg[id] = (seg[child1] + seg[child2]);
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

lli query(int l,int r,int id,int a,int b)
{
    if( b<l || a>r ) return 0;
    if(l>=a && r<=b) return seg[id];
    int mid = (l+r) / 2;
    lli p = query(l,mid,2*id,a,b);
    lli q = query(mid+1,r,2*id+1,a,b);
    return p+q;
}


void print(int l,int r,int id){
    cout << "Id : " << id << "[" << l << "," << r << "] = " << seg[id] << endl;
    if(l==r) return;
    int mid = (l+r) / 2;
    print(l,mid,2*id);
    print(mid+1,r,2*id+1);
}

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
        vector<int> v(n);
        vector<int> ori(n);
        for(int i = 0;i<n;i++){
            cin >> v[i];
            ori[i] = v[i];
        }
        sort( v.begin() , v.end() );
        map<int , int> mp;
        int n1 = 0;
        for(auto i : v){
            if( mp[i]==0 ){
                mp[i] = ++n1;
            }
        }

        /// Reverse map
        vector<int> revmap(n1+1);
        for(auto p : mp){
            revmap[p.sec] = p.fir;
        }

        /**
        for(auto p : mp){
            cout << "mp[" << p.fir << "] = " << p.sec << endl;
        }
        for(int i = 1;i<=n1;i++){
            cout << "revmap[" << i << "] = " << revmap[i] << endl;
        }
        **/
        int last = n1+5;

        build(1,last,1);

        ///print(1,last,1);
        ///cout << "--------------" << endl;
        lli sum = 0;
        for(auto i : ori){
            int k = mp[i];
            update(1,last,1,k,1);
            sum += query(1,last,1,k+1,last);
        }
        ///print(1,last,1);
        ///cout << "--------------" << endl;
        cout << sum << endl;

    }

}
