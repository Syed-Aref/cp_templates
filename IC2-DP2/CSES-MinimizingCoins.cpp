#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

int n = 0;
int coins[105];
const int xmax = 1000000;
int x[xmax + 5];
int inf = 1e7+7;

int dp(int target)
{
    ///cout << "dp is at : " << target << endl;

    if(target == 0) return 0;

    if( x[target] != -1 ) return x[target];


    int ans = inf;
    for(int i = 1;i<=n;i++){

        if(target - coins[i] >= 0){

            ans = min( ans , dp(target-coins[i]) );
        }
    }
    x[target] = ans+1;
    return x[target];
}

/// Time Complexity: O(N*SUM)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int target;
    cin >> target;
    /// target = desired sum of money(SUM)

    for(int i = 1;i<=target+2;i++) x[i] = -1;

    for(int i = 1;i<=n;i++) cin >> coins[i];


    int ans = dp(target);

    if(ans >= inf) cout << -1 << endl;
    else cout << ans << endl;

}
