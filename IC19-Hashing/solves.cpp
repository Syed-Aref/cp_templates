#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"


const int nmax = 5e6;
const lli x = 1e5+67;
const lli p = 1e9 + 7;
string s , revs;
int lens = 0;

lli power[nmax+10];
lli hpf[nmax+10] , revhpf[nmax+10];

void calcPower() {
    power[0] = 1;
    for(int i = 1;i<=nmax;i++) power[i] = (power[i-1]*x) % p;
}

void calc_hash() {
    hpf[0] = 0;
    for(int i = 0;i<lens;i++) {
        hpf[i+1] = ( (hpf[i] * x)%p + s[i] ) % p;
        revhpf[i+1] = ( (revhpf[i] * x)%p + revs[i] ) % p;
    }
}

lli hashf(int l,int r) {
    lli ret = (hpf[r] - (hpf[l-1]*power[r-l+1])%p)%p;
    if(ret < 0) ret += p;
    return ret;
}
lli revhashf(int l,int r) {
    int tl = l , tr = r;
    l = min( lens-tl+1 , lens-tr+1 );
    r = max(lens-tl+1,lens-tr+1);
    lli ret = (revhpf[r] - (revhpf[l-1]*power[r-l+1])%p)%p;
    if(ret < 0) ret += p;
    return ret;
}

map< pair<int,int> , lli > mp;



lli dp(int l ,int r){

    if( mp[ mpr(l,r) ] != 0 ) return mp[ mpr(l,r) ];
    if( hashf(l,r) != revhashf(l,r) ){
         mp[ mpr(l,r) ] = -1;
    }
    else {
        int total = r-l+1;
        int mid = (l+r)/2;
        int l1,r1,l2,r2;
        l1 = l , r2 = r;
        if( total == 1 ) mp[ mpr(l,r) ] = 1;
        else{
            if( total%2 == 1 ) r1 = mid-1 , l2 = mid+1;
            else r1 = mid , l2 = mid+1;

            if( dp(l1,r1) == dp(l2,r2) ) {

                if( mp[ mpr(l1,r1) ] ==-1 ) mp[ mpr(l,r) ] = -1;
                else mp[ mpr(l,r) ] = mp[ mpr(l1,r1) ] + 1;
            }
            else mp[ mpr(l,r) ] = -1;
        }
    }
    return mp[ mpr(l,r) ];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    calcPower();

    cin >> s;
    revs = s;
    reverse(revs.begin() , revs.end());
    lens = s.length();
    calc_hash();



    for(int i = 1;i<=lens;i++) mp[ mpr(i,i) ] = 1;

    lli sum = 0;
    for(int i = 1;i<=lens;i++){
        lli x = dp(1,i);
        if( x==-1) x = 0;
        sum += x;
    }
    cout << sum << line;

}
