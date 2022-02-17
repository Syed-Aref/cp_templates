#include <bits/stdc++.h>
using namespace std;

vector<int> moves;

int mex(vector<int> &v){
    sort(v.begin(), v.end());
    int cur = 0;
    for(int x : v){
        if(cur == x){
            cur++;
        }
        else if(x > cur){
            return cur;
        }
    }

    return cur;
}


int memo[10000];
int grundy(int x){
    if(memo[x] != -1) return memo[x];

    vector<int> reachable;
    for(int m : moves){
        if(x-m < 0) continue;

        int g = grundy(x-m);
        reachable.push_back(g);
    }

    memo[x] = mex(reachable);

    return memo[x];
}

int main(){

    memset(memo, -1, sizeof(memo));

    int n, k;
    cin>>n>>k;

    for(int i = 0; i<k; i++){
        int x;
        cin>>x;
        moves.push_back(x);
    }


    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    int XOR = 0;
    for(int x : input){
        cout<<grundy(x)<<endl;
        XOR ^= grundy(x);
    }

    cout<<"xor "<<XOR<<endl;

    return 0;
}
