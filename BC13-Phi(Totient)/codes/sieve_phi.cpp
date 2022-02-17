#include <bits/stdc++.h>
using namespace std;

int phi[2000000+5];
bool mark[2000000+5];

void sieve(){
    for(int i = 1; i<=2000000; i++)
        phi[i] = i;

    for(int i = 2; i<=2000000; i++){
        if(mark[i])
            continue;
        phi[i] = i-1;
        for(int j = i+i; j<=2000000; j+=i){
            mark[j] = true;

            phi[j] = phi[j] - phi[j]/i;
        }
    }
}
/// Time complexity: O( n * log( log(n) ) )

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve();



    return 0;
}

