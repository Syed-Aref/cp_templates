#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
const lli mod = 1e9+7;

lli egcd(lli a, lli b, lli& x, lli& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    lli x1, y1;
    lli d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
/// Time complexity: O(log(max(a,b)))

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli mod = 5;

    /// gcd(71, 100) = 1;
    /// 71x + 100y = 1
    /// x -> inverse


    lli x, y;
    lli a = 2;
    lli b = mod;
    cout<<egcd(a, b, x, y)<<endl;
    x %= mod;
    if(x < 0){
        x += mod;
    }

    cout<<x<<endl;
    cout<<(a*x) % b<<endl;

    return 0;

}
