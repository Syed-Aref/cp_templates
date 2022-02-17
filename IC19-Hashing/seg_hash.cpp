
/// Link: https://vjudge.net/problem/URAL-1989


#include <algorithm>
#include <bitset>
#include <iterator>
#include <list>
#include <locale>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 1e5+10;
const lli x = 1e5+67;
const lli p = 1e9+7;
string s;
lli powx[nmax];
lli hashf[4*nmax];
lli revhashf[4*nmax];

void build(int l,int r,int id){

    if(l==r)
    {
        hashf[id] = s[l];
        revhashf[id] = s[l];
        return;
    }
    int mid = (l+r) / 2;

    int child1 = 2*id;
    int child2 = 2*id + 1;

    build(l,mid,child1);
    build(mid+1,r,child2);

    hashf[id] = ( (hashf[child1]* powx[ r-(mid+1)+1 ] )%p + hashf[child2] )%p;
    revhashf[id] = ( revhashf[child1] + (revhashf[child2]*powx[mid-l+1])%p )%p;
    return;
}



void update_hash(int l,int r,int id,int k )
{
    if(l==r)
    {
        hashf[id] = s[l];
        return;
    }
    int mid = (l+r) / 2;

    int child1 = 2*id;
    int child2 = 2*id + 1;

    if(k<=mid)
    {
        update_hash(l,mid,2*id,k);
    }
    else update_hash(mid+1,r,2*id+1,k);

    hashf[id] = ( (hashf[child1]*powx[ r-(mid+1)+1 ]  )%p + hashf[child2] )%p;
    return;
}

void update_revhash(int l,int r,int id,int k )
{
    if(l==r)
    {
        revhashf[id] = s[l]%p;
        return;
    }
    int mid = (l+r) / 2;

    int child1 = 2*id;
    int child2 = 2*id + 1;

    if(k<=mid)
    {
        update_revhash(l,mid,2*id,k);
    }
    else update_revhash(mid+1,r,2*id+1,k);

    revhashf[id] = ( revhashf[child1] + (revhashf[child2]*powx[mid-l+1])%p )%p;
    return;
}



lli gethash(int l,int r,int id,int a,int b)
{
    if( b<l || a>r ) return 0;
    if(l>=a && r<=b) return (hashf[id]*powx[abs(b-r)])%p;
    int mid = (l+r) / 2;
    lli p1 = gethash(l,mid,2*id,a,b);
    lli q = gethash(mid+1,r,2*id+1,a,b);
    return (p1+q) % p;
}

lli getrevhash(int l,int r,int id,int a,int b)
{
    if( b<l || a>r ) return 0;
    if(l>=a && r<=b) return (revhashf[id]*powx[abs(l-a)])%p;
    int mid = (l+r) / 2;
    lli p1 = getrevhash(l,mid,2*id,a,b);
    lli q = getrevhash(mid+1,r,2*id+1,a,b);
    return (p1+q) % p;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    hashf[0] = revhashf[0] = 0;

    powx[0] = 1;
    for(int i = 1;i<=nmax;i++) powx[i] = (powx[i-1] * x) % p;

    int n,m;

    cin >> s >> m;

    n = s.length();
    s = "*"+s;

    ///for( int i = 1;i<=n;i++ ) cout << s[i];
    ///cout << endl;

    ///for( int i = 1;i<=n;i++ ) cout << revs[i];
    ///cout << endl;
    build(1,n,1);
    for(int i = 0;i<m;i++){
        string type;
        cin >> type;

        if(type == "palindrome?"){
            int a,b;
            cin >> a >> b;
            if( gethash(1,n,1,a,b) == getrevhash(1,n,1,a,b) ) cout << "Yes" << "\n";
            else cout << "No" << "\n";
        }
        else{
            int ind;
            char c;
            cin >> ind >> c;
            s[ind] = c;
            ///revs[n-ind+1] = c;
            update_hash(1,n,1,ind);
            update_revhash(1,n,1,ind);
        }
    }

}

