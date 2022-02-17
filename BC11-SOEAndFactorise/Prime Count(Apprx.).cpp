#include <bits/stdc++.h>
using namespace std;

const int bign = 10000000;
const int target = 10000000;

bool mark[bign+5];
int primes[target+5];
vector<int> vprimes;
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
    vprimes.push_back(0);
    vprimes.push_back(2);
    pcnt = 1;
    for(int i = 3; i<=n; i+=2){
        if(mark[i] == false){
            if(pcnt<target)
                primes[++pcnt] = i;
            vprimes.push_back(i);
        }
    }
}


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

    /**
    cout << "Total primes:" << pcnt << endl;
    **/

    for(int n = 2;n<=30;n++)
    {

        int total;
        if(n<2  || n>bign){
            ///cout << 0 << endl;
            continue;
        }
        auto it = lower_bound(vprimes.begin() , vprimes.end() , n);
        if( it == vprimes.end() )
            it--;
        if( *it > n )
            it--;
        cout << "Total primes from [1," << n <<"] : " << it - vprimes.begin() << endl;
        total = it - vprimes.begin();

        double ln_n = log(n);
        ///cout << n << "/ln(" << n << ") : " << (n*1.0) / ln_n << endl;
        double myexpectation;
        if(n<=10) myexpectation = (n*1.0) / log( n );
        else myexpectation = (n*1.0) / log( n*0.2 );
        cout << "My expectation :  " << myexpectation << endl;

    }

    cout << "=======================================" << endl;
    while(1){
        int n;
        cin >> n;
        int total;
        if(n<2  || n>bign){
            ///cout << 0 << endl;
            continue;
        }
        auto it = lower_bound(vprimes.begin() , vprimes.end() , n);
        if( it == vprimes.end() )
            it--;
        if( *it > n )
            it--;
        cout << "Total primes from [1," << n <<"] : " << it - vprimes.begin() << endl;
        total = it - vprimes.begin();

        double ln_n = log(n);
        ///cout << n << "/ln(" << n << ") : " << (n*1.0) / ln_n << endl;
        double myexpectation;
        if(n<=10) myexpectation = (n*1.0) / log( n );
        else myexpectation = (n*1.0) / log( n*0.2 );
        cout << "My expectation :  " << myexpectation << endl;

    }

}
