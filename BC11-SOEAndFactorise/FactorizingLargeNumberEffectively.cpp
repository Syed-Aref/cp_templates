#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

const int bign = 1e6+50;
const int target = 1e5;

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
/// Time complexity: O( n * log( log(n) ) )
void func_(lli N)
{
    lli n = N;
    map<lli,int> mp;
    for(int i = 1;i<=pcnt && n!=1;i++)
    {
        if(n%(lli)primes[i]==0)
        {
            int c = 0;
            while(n%(lli)primes[i]==0)
            {
                n = n/(lli)primes[i];
                c++;
            }
            int x = primes[i];
            mp[x] = c;
        }
    }
    if(n!=1)
        mp[n] = 1;
    int first = 1;
    for(auto i : mp)
    {
        if(first)
        {
            cout << i.first << "^" << i.second;
            first = 0;
            continue;
        }
        cout << " " <<  i.first << "^" << i.second;
    }
    cout << "\n";
}
/**
NP = # of primes from 1 to N = N / log(c*N)
Time complexity : O( N / log(c*N) )
N = bign
**/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    optimizedSieve(bign);
    /**
    for(int i = 1;i<=target;i++)
        cout << primes[i] << " ";

    cout << endl;
    **/

    lli num;
    cin >> num;
    while(num!=0)
    {

        func_(num);
        cin >> num;
    }

}
