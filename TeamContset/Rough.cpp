#include <bits/stdc++.h>
using namespace std;

int main()
{


    cout << char(65) << endl;

    int ind = 'A' + 0;
    cout << ind << endl; ///ind = index of 'A'

    /// char digit('0' , '1' , ... ,'8') to digit
    cout << '0' - 48 << endl; /// 0
    cout << '1' - 48 << endl; /// 1

    /// digit to char
    cout << char(0+48) << endl; /// 0
    cout << char(2+48) << endl; /// 2

    string s1 = "45a";
    string s2 = "33a";
    cout << (s1==s2) << endl; /// 0

    s2 = "45a";
    cout << (s1==s2) << endl; ///1
}
