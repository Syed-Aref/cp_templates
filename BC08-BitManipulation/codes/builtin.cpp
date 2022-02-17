#include <bits/stdc++.h>
using namespace std;
string binary(int x){
    string ret;
    for(int i = 31; i>=0; i--){
        int mask = (1<<i);
        if((x&mask) == 0)
            ret.push_back('0');
        else
            ret.push_back('1');
    }
    return ret;
}

/// 31 30 29 ...... 3 2 1 0

/// 000000000000000000001110
/// 000000000000000010000000
/// 000000000000000000000000 == 0

int decimal(string num){
    int ret = 0;
    for(int i = 0, j = (int)num.size()-1; j >= 0; i++, j--){
        if(num[j] == '1')
            ret |= (1<<i);
    }
    return ret;
}


/// 0
/// 110100
/// 543210


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x = decimal("11000100");

    cout<<binary(-1)<<endl;


    /// O(1)
    cout<<__builtin_popcount(x)<<endl;      /// count of 1's
    cout<<__builtin_clz(x)<<endl;           /// leading 0 count
    cout<<__builtin_ctz(x)<<endl;           /// trailing 0 count


    /// long long
    cout<<__builtin_popcountll(x)<<endl;      /// count of 1's
    cout<<__builtin_clzll(x)<<endl;           /// leading 0 count
    cout<<__builtin_ctzll(x)<<endl;           /// trailing 0 count



    return 0;
}

