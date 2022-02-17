#include <bits/stdc++.h>
using namespace std;

/// Problem statement: https://lightoj.com/problem/extreme-gcd

typedef long long int ll;

const int bign = 10000;
const int target = 10000;

bool mark[bign+5];
int primes[target+5];
int pcnt = 0;
void optimizedSieve(int n){
    mark[0] = mark[1] = true;

    for(int i = 4; i<=n; i+=2)
        mark[i] = true;

    for(int i = 3; i*i<=n; i+=2){
        if(mark[i])
            continue;

        for(int m = i*i; m<=n; m+=i+i){
            mark[m] = true;
        }
    }
    primes[1] = 2;
    pcnt = 1;
    for(int i = 3; i<=n; i+=2){
        if(mark[i] == false){
            if(pcnt<target)
                primes[++pcnt] = i;

        }
    }
}
/// Time complexity: O(n*log( log(n) ))
int mobius[bign+5];
void setmobius()
{
    mobius[1] = 1;
    for(int i = 2;i<=10000;i++)
    {
        int n = i;
        int cnt = 0;
        int zero = 0;
        for(int j = 1;primes[j]<=100 && n!=1;j++)
        {
            if( n%primes[j] == 0 )
            {
                cnt++;
                n/=primes[j];
                if( n%primes[j]==0 )
                {
                    zero = 1;
                    mobius[i] = 0;
                    break;
                }
            }
        }
        if(n!=1)
            cnt++;
        if( zero )
            continue;
        if(cnt%2==0)
            mobius[i] = 1;
        else mobius[i] = -1;
    }
}
/// NP = #of primes in sqrt(n) = sqrt(n) /  log( c*sqrt(n) )
/// Time complexity: O(n*NP))


vector<int> factorise(int n){
    vector<int> ret;
    if(n == 1)
        return ret;

    for(int i = 2;i*i <= n;i++){
        if( n%i==0 )
        {
            ret.push_back(i);
            if( i != (n/i) ) ret.push_back(n/i);

        }
    }

    ret.push_back(n);

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    optimizedSieve(bign);
    setmobius();

    /**
    int T;
    cin >> T;
    while(T-->0)
    {
        int n;
        cin >> n;
        auto v = factorise(n);
        for(auto i : v) cout << i << " ";
        cout << endl;
    }
    **/

    int t;
    cin >> t;
    for(int tc = 1;tc<=t;tc++)
    {
        int n;
        cin >> n;
        vector<int> input(n);
        for(int i = 0;i<n;i++) cin >> input[i];

        map<int,int> mp;

        for(int i = 0;i<n;i++)
        {
            auto v = factorise(input[i]);
            for(auto j : v) mp[j]++;
        }

        ll ans = ((ll)n) * ( (ll)(n-1) )*( (ll)(n-2) )*( (ll)(n-3) );
        ans /= 24;

        for(auto i : mp)
        {
            int num = i.first;
            ll occur = (ll)i.second;
            if(occur<4)
                continue;
            ll comb = occur*(occur-1)*(occur - 2)*(occur - 3);
            comb /= 24;
            comb = comb * mobius[num];
            ans += comb;

        }
        cout <<"Case " <<tc << ": " << ans << endl;

    }

}
