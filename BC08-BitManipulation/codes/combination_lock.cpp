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

    int n;
    cin>>n;

    vector<int> input(n);
    for(int i = 0; i<n; i++)
        cin>>input[i];

    for(int mask = 0; mask <= (1<<n)-1; mask++){    /// mask = some encoded assignment of +/-
        int sum = 0;
        for(int i = 0; i<n; i++){
            /// check if i-th index of mask is 1 or 0
            if((mask & (1<<i)) == 0){
                sum -= input[i];        /// bit was 1
            }
            else{
                sum += input[i];        /// bit was 0
            }
        }
////        cout<<sum<<endl;
        if(sum % 360 == 0){
            cout<<"YES";
            return 0;
        }

    }

    cout<<"NO";

    return 0;
}


/*
012
01
12
02
0
1
2

*/

