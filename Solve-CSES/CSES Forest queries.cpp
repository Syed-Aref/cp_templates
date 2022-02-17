#include <bits/stdc++.h>
using namespace std;

char charr[1005][1005];
int arr[1005][1005];
int pf[1005][1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int q;
    cin >> q;
    //int cnt = 0;


    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> charr[i][j];
            if( charr[i][j]=='*' )
                arr[i][j] = 1;
        }
    }

    for(int r = 1;r<=n;r++)
    {
        for(int c = 1;c<=n;c++)
        {
            pf[r][c] = arr[r][c] + pf[r-1][c] + pf[r][c-1] - pf[r-1][c-1];
        }
    }

    while(q-->0)
    {
        int i1,j1,i2,j2;

        cin >> i1 >> j1 >> i2 >> j2;
        int ans;
            ans = pf[i2][j2] - pf[i1-1][j2] - pf[i2][j1-1] + pf[i1-1][j1-1];

        cout << ans << endl;
    }
}
