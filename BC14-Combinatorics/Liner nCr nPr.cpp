#include <bits/stdc++.h>
using namespace std;


typedef long long int lli;

lli linear_ncr(lli n,lli r)
{

    lli ret = 1;
    for( lli i = n,j=1 ; j<=r ; i--,j++ )
    {
        ret = ret*i;
        ret = ret/j;
    }
    return ret;
}
/// Time complexity: O(N)
/// (N = r)


lli linear_npr(lli n,lli r)
{

    lli ret = 1;
    for( lli i = n,j=1 ; j<=r ; i--,j++ )
    {
        ret = ret*i;
    }
    return ret;
}
/// Time complexity: O(N)
/// (N = r)







int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    for(int i = 0;i<=10;i++)
    {
        cout << "10P" << i << " : " << linear_npr( (lli)10,(lli)i ) << endl;
        cout << "10C" << i << " : " << linear_ncr( (lli)10,(lli)i ) << endl;
    }

}
