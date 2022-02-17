#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

vector<int> coins;

ll memo[1000000+10];
ll dp(int x){
    if(x == 0) return 1;

    if(memo[x] != -1) return memo[x];

    ll ret = 0;
    for(int c : coins){
        if(x-c < 0) continue;
        ret += dp(x-c);
        ret %= mod;
    }

    memo[x] = ret;

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(memo, -1, sizeof(memo));

    int n, x;

    cin>>n>>x;

    for(int i = 0; i<n; i++){
        int c;
        cin>>c;
        coins.push_back(c);
    }


//    for(int i = 0; i<=11; i++){
//        cout<<"at "<<i<<" "<<dp(i)<<endl;
//    }

    ll ans = dp(x);
    cout<<ans<<endl;

}

