#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 1e5;

bool mark[nmax+10];
int primeList[nmax+10];

int cnt = 0;

/// special sieve that stores primes in an array
void sieve(){
    mark[1] = true;


    for(int i = 4; i<=nmax; i+=2)
        mark[i] = true;

    for(int i = 3; i*i<=nmax; i+=2){
        if(mark[i])
            continue;

        for(int m = i*i; m<=nmax; m+=i+i){
            mark[m] = true;
        }
    }


    primeList[1] = 2;
    cnt = 1;
    for(int i = 3; i<=nmax; i+=2){
        if(mark[i] == false){
            if(cnt<nmax)
                primeList[++cnt] = i;

        }
    }
}
/// Time complexity: O( n * log( log(n) ) )

/// special factorizing method that checks only prime numbers
vector<ll> factorize(ll n){
    vector<ll> primes;
    for(ll i = 1; i<=cnt  && primeList[i]*primeList[i] <= n && n!=1; i++){
        if(n % primeList[i] == 0){
            while(n % primeList[i] == 0){
                n /= primeList[i];
                primes.push_back(primeList[i]);
            }
        }
    }
    if(n > 1){
        primes.push_back(n);
    }

    return primes;
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

    sieve();
    for(int i = 1;i<=10;i++)
        cout << primeList[i] << endl;

    cout << "======================================================" << endl;

    cout << "cnt : " << cnt << endl;
    cout << primeList[cnt] << " " << primeList[cnt+1] << endl;

    cout << "======================================================" << endl;

    while(1)
    {
        int num;
        cin >> num;

        auto v = factorize(num);

        for(auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

