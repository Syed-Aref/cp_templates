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

void dp(int n)
{

    memo[1] = 0;
    memo[2] = abs(height[2]-height[1]);
    for(int i = 3;i<=n;i++) memo[i] = min( memo[i-2]+abs(height[i]-height[i-2]) , memo[i-1]+abs(height[i]-height[i-1]) );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1;i<=n;i++) cin >> height[i];
    dp(n);
    cout << memo[n] << endl;

}

/// Time Complexity: O(N)
