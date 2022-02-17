#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli modexpo(lli a,lli n,lli m)
{
    lli ans = 1;
    while(n>0)
    {
        if(n%2==1){
            ans = (ans*a)%m;
            n--;

        }
        a = (a*a)%m;
        n = n/2;

    }
    return ans;
}
/// Time complexity: O(log(n))

int main()
{
    /**
    if a , m both are coprime and m is a prime then mod inverse of a will be : modexpo(a,m-2,m)
    **/
}
