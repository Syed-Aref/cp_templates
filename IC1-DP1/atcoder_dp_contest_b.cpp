#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
#define line "\n"

const int nmax = 100000;

int height[nmax+5];
int memo[nmax+5];
int kmax = 0;
void dp(int n)
{

    memo[1] = 0;

    for(int i = 2;i<=n;i++)
    {
        int right = (int)(1e9+100);
        int j;
        for(int k = 1;k<=kmax && i-k>=1;k++){
           j = i - k;
           right = min( right , memo[j]+abs(height[i]-height[j]) );
        }
        memo[i] = right;
    }
}

/// Time Complexity: O(N*K)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n , k;
    cin >> n >> k;

    kmax = k;

    for(int i = 1;i<=n;i++) cin >> height[i];
    dp(n);
    cout << memo[n] << endl;

}
