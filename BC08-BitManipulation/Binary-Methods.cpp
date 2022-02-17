#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


const int I = -2147483648;
const lli L = -9223372036854775808;

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
/// Time complexity: O(c) [c means constant.Here, c = 31]

int decimal(string num){
    int ret = 0;
    for(int i = 0, j = (int)num.size()-1; j >= 0; i++, j--){
        if(num[j] == '1')
            ret |= (1<<i);
    }
    return ret;
}
/// Time complexity: O(c) [c means constant.Here, c = 31]

int main()
{

    cout << ( (lli)1<<62 ) << endl;

}
