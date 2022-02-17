#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int bign = 1e5;
const int target = 5000000;

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

vector<int> factorise_(lli n)
{
    vector<int> ret;
    for(int i = 1;i<=pcnt && ((lli)primes[i]*(lli)primes[i])<=n && n!=1;i++)
    {
        if( n%(lli)primes[i]==0 )
        {
            ret.push_back( primes[i] );
            while(  n%(lli)primes[i]==0 )
                n /= (lli)primes[i];
        }
    }
    if(n>1)
        ret.push_back( (int)n );
    return ret;
}
/**
NP = # of primes from 1 to N = N / log(c*N)
Time complexity : O( N / log(c*N) )
N = bign
**/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    optimizedSieve(bign);
    /**
    cout << pcnt << "\n";
    cout << primes[1] << "\n";
    cout << primes[2] << "\n";
    cout << primes[pcnt] << "\n";
    cout << primes[pcnt+1] << "\n";
    **/


    while(1){

        lli n;
        cin >> n;
        vector<int> v = factorise_(n);
        for(auto i : v)
            cout << i << " ";
        cout << endl;

    }
    return 0;
}

