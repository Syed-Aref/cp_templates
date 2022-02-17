#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 1e6;

int tau[nmax+10];
int sigma[nmax+10];

/// special sieve for counting sigma and tau
void sieve(){
    for(int i = 1; i<=nmax; i++){
        for(int m = i; m<=nmax; m+= i){
            tau[m]++;
            sigma[m] += i;
        }
    }

}
/// Time complexity: O( n * log( log(n) ) )
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();
    for(int i = 1;i<=110;i++)
    {
        cout << "Tau of " << i << " : " << tau[i] << endl;
    }

    return 0;
}

