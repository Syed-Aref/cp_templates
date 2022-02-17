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

    int x = decimal("10101");

    /// what is the bit at index 2?

    int n = 2;          ///nth index
    int mask = (1<<n);

    if((x&mask) == 0)
        cout<<"bit is 0"<<endl;
    else
        cout<<"bit is 1"<<endl;


    /// change 1st bit to 1

    n = 1;
    mask = (1<<n);
    cout<<binary(x | mask)<<endl;



    /// change 2nd bit to 0
    n = 2;
    mask = ~(1<<n);
    cout<<binary(x&mask)<<endl;


    /// flip 2nd bit

    n = 1;
    mask = (1<<n);
    cout<<binary(x^mask)<<endl;

    return 0;
}


