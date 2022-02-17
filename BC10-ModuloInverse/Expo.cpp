#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli expo(lli a,lli n)
{
    lli ans = 1;
    while(n>0)
    {
        if(n%2==1){
            ans = (ans*a);
            n--;

        }
        a = (a*a);
        n = n/2;

    }
    return ans;
}
/// Time complexity: O(log(n))

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



}
