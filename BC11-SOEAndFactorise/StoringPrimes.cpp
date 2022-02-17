#include <bits/stdc++.h>
using namespace std;

const int bign = 2000000;
const int target = 2000000;

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
    int total = 0;
    for(int i = 1;i<=pcnt;i++)
    {
        cout << primes[i] << endl;
        total++;
    }
    cout << "Total : " << total << endl;
}
