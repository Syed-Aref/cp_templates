#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005];

int pf[1005][1005];

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);

    int row = 4;
    int col = 9;

    for(int r = 1;r<=row;r++)
    {
        for(int c = 1;c<=col;c++)
            cin >> arr[r][c];
    }

    for(int r = 1;r<=row;r++)
    {
        for(int c = 1;c<=col;c++)
            printf("%5d",arr[r][c]);
        printf("\n");
    }

    for(int r = 1;r<=row;r++)
    {
        for(int c = 1;c<=col;c++)
        {
            pf[r][c] = arr[r][c] + pf[r-1][c] + pf[r][c-1] - pf[r-1][c-1];

            //pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
        }
    }
    /// Time complexity: O(N*N)
    for(int r = 1;r<=row;r++)
    {
        for(int c = 1;c<=col;c++)
            printf("%5d",pf[r][c]);
        printf("\n");
    }

    /*
    Two given co-ordinates: (i1,j1),(i2,j2) [i2>=i1,j2>=j1]
    Pf under the rectangle :
        i1,j1         i2,j1
        - - - - - - - - - -
        - - - - - - - - - -
        - - - - - - - - - -
        i1,j2         i2,j2

        Prefix sum = pf[i2][j2] - pf[i1-1][j2] - pf[i2][j1-1] + pf[i1-1][j1-1]
    */
}

/*

56 46 44 67 7 44 67 5 34
45 67 35 53 4 353 35 64 5
45 6 53 2 53 35 2 13 64
23 4 32 4 34 23 445 38 89

for(int r = 1;r<=row;r++)
{
    for(int c = 1;c<=col;c++)
    {

    }
}

*/
