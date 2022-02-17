#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 100;
    while(t-->0)
    {
        int n;
        cin >> n;
        vector<lli> pf(n+1);

        for(int i = 1;i<=n;i++)
        {
            cin >> pf[i];
            pf[i] = pf[i] + pf[i-1];
        }
        /// Time complexity: O(n)
        lli ans = -1e16;
        lli sum;
        lli min_so_far = 0;

        for(int i = 1;i<=n;i++)
        {
            sum = pf[i] - min_so_far;
            if(sum > ans)
                ans = sum;
            if(pf[i]<min_so_far)
                min_so_far = pf[i];
        }

        cout << ans << endl;

    }
}
