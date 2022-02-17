#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll mod = 1e9+7;

/// returns a^n % m
ll modexpo(ll a, ll n, ll m){
    if(n == 0){
        return 1;
    }

    ll y = modexpo(a, n/2, m);

    y = y * y % m;

    if(n % 2 == 1){
        y = y * a % m;
    }

    return y;
}

ll fact[1000000+10];
ll factinv[1000000+10];

ll nCr(int n, int r){
    ll ans = fact[n];

    ans = ans * factinv[r] % mod;
    ans = ans * factinv[n-r] % mod;
    return ans;
}
/// nCr return
/// nCr = n!/(r! * (n-r)!)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin>>n;

    fact[0] = 1;
    for(int i = 1; i<=1000000; i++){
        fact[i] = i * fact[i-1] % mod;
    }

    for(int i = 0; i<=1000000; i++){
        factinv[i] = modexpo(fact[i], mod-2, mod);
    }

    /// Pre-calculation
    /// Time complexity: O(N)

    return 0;
}

