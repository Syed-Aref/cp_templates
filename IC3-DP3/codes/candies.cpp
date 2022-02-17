#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int mod = 1e9+7;
const int nmax = 1e5+10;
int A[nmax];
ll dp[110][nmax];        /// dp[i][s] = first i children have received s candies
ll pref[110][nmax];      /// pref[i][s] = sum of all dp[i][s'] where s' <= s

ll solve(int n, int k){
    for(int i = 0; i<=n; i++){
        for(int s = 0; s <= k; s++){
            if(i == 0){
                if(s == 0) dp[i][s] = 1;
                else dp[i][s] = 0;
                continue;
            }

//            for(int s2 = s; s2 >= s-A[i] && s2 >= 0; s2--){
//                dp[i][s] += dp[i-1][s2];
//                dp[i][s] %= mod;
//            }
            ///[s-A[i], s] (if s-A[i] < 0- [0, s])

            int l = max(s-A[i], 0);
            int r = s;

            /// pref[r] - pref[l-1]; (if l == 0 , pref[r])

            dp[i][s] += pref[i-1][r];
            dp[i][s] %= mod;

            if(l != 0) {
                dp[i][s] -= pref[i-1][l-1];
                dp[i][s] %= mod;
                if(dp[i][s] < 0) dp[i][s] += mod;
            }
        }

        pref[i][0] = dp[i][0];
        for(int s = 1; s <= k; s++)
            pref[i][s] = (pref[i][s-1] + dp[i][s]) % mod;
    }

    return dp[n][k];
}

int main(){


    int n, k;
    cin>>n>>k;
    for(int i = 1; i<=n; i++) cin>>A[i];


    ll ans = solve(n, k);

    cout<<ans<<endl;

}


