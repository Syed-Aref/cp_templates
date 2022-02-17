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
    lli mod = 1e9+7;
    while(true)
    {
        cout << "give:a" << endl;
        lli a;
        cin >> a;

        cout << "give:n" << endl;
        lli n;
        cin >> n;

        cout << modexpo(a,n,mod) << endl;
    }
}
