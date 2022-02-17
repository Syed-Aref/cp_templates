#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

/// SPOJ - NHAY

const int nmax = 1e6;
const lli x = 1e5+67;
const lli p = 1e9 + 7;
lli rolling_k = 0;
string s , k;
int lens = 0;int lenk = 0;

lli power[nmax+10];
lli hpf[nmax+10];

void calcPower() {
    power[0] = 1;
    for(int i = 1;i<=nmax;i++) power[i] = (power[i-1]*x) % p;
}

void calc_rolling_k(){

    rolling_k = 0;
    for(int i = 0,j = lenk-1;i<lenk;i++ , j--) {

        rolling_k = ( rolling_k + ((power[j]*k[i])%p) ) % p;
    }

}
void calc_hash() {
    hpf[0] = 0;
    for(int i = 0;i<lens;i++) {
        hpf[i+1] = ( (hpf[i] * x)%p + s[i] ) % p;
    }
}

lli hashf(int l,int r) {
    lli ret = (hpf[r] - (hpf[l-1]*power[r-l+1])%p)%p;
    if(ret < 0) ret += p;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    calcPower();
    bool flag = 0;




    while(cin >> lenk >> k >> s) {
        lens = s.length();

        calc_rolling_k();
        calc_hash();

        vector<int> print;
        for(int i = 1 , j = lenk;j<=lens;i++ , j++) {
            if( rolling_k == hashf(i,j) ) print.push_back(i-1);
        }
        if(flag) cout << endl;

        for(auto i : print) cout<<i<<endl;
        flag = 1;
    }

}
