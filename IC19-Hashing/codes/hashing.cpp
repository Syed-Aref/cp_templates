#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const ll P1 = 1e9+9;
const ll x1 = 1e5;

const ll P2 = 1e8+1e5+1;
const ll x2 = 1e6;

const int nmax = 1e5+10;
ll H1[nmax]; /// H[i] = hash of s[0..i]
ll power1[nmax]; /// power[i] = x^i
ll H2[nmax]; /// H[i] = hash of s[0..i]
ll power2[nmax]; /// power[i] = x^i

void precal(){
    power1[0] = power2[0] = 1;
    for(int i = 1; i<nmax; i++) {
        power1[i] = (power1[i-1] * x1) % P1;
        power2[i] = (power2[i-1] * x2) % P2;
    }
}

void buildHash(string& s){
    H1[0] = s[0]-'a'+1;        /// use the ascii value directly
    H2[0] = s[0]-'a'+1;

    for(int i = 1; i<s.size(); i++){
        H1[i] = (H1[i-1] * x1 + s[i]-'a'+1) % P1;
        H2[i] = (H2[i-1] * x2 + s[i]-'a'+1) % P2;
    }
}

pair<ll, ll> hashval(int l, int r){
    ll result1 = H1[r];
    ll result2 = H2[r];

    if(l != 0){
        result1 -= H1[l-1] * power1[r-l+1];
        result1 %= P1;
        if(result1 < 0) result1 += P1;

        result2 -= H2[l-1] * power2[r-l+1];
        result2 %= P2;
        if(result2 < 0) result2 += P2;
    }

    return {result1, result2};
}

int main(){

    precal();

    string s;
    cin>>s;

    buildHash(s);

    int q;
    cin>>q;

    for(int i = 0; i<q; i++){
        int l, r;
        cin>>l>>r;
        l--, r--;

        auto p = hashval(l, r);

        cout<<p.first<<" "<<p.second<<endl;
    }

}
