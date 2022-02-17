#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

string binary_lli(lli x){
    string ret;
    for(int i = 63; i>=0; i--){
        lli mask = ((lli)1<<i);
        if((x&mask) == 0)
            ret.push_back('0');
        else
            ret.push_back('1');
    }
    return ret;
}
/// Time complexity: O(c) [c means constant.Here, c = 63]

lli decimal_lli(string num){
    lli ret = 0;
    for(int i = 0, j = (int)num.size()-1; j >= 0; i++, j--){
        if(num[j] == '1')
            ret |= ((lli)1<<i);
    }
    return ret;
}
/// Time complexity: O(c) [c means constant.Here, c = 63]
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true)
    {
        string x;
        cin >> x;

        cout << decimal_lli(x) << endl;
    }

}
