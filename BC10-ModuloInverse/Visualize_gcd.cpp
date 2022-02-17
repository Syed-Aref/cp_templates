#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int v_gcd(int lr,int sm)
{
    if(sm>lr)
        return v_gcd(sm,lr);
    cout << lr << " = " << lr/sm<<"*"<<sm << "+" << lr%sm << endl;
    if(lr%sm==0)
    {
        cout << "gcd:" << sm << endl;
        cout << "....................................." << endl;
        return sm;
    }
    return v_gcd(sm,lr%sm);
}


int v_gcd2(int lr,int sm)
{
    if(sm>lr)
        return v_gcd(sm,lr);
    cout << "(" << lr << "," << sm << ")" << endl;

    if(sm==0)
    {
        cout << lr  << " = " << 1 << "*" << lr << "+" << 0 << endl;
        cout << "gcd:" << lr << endl;
        cout << "....................................." << endl;
        return lr;
    }
    cout << lr << " = " << lr/sm<<"*"<<sm << "+" << lr%sm << endl;
    return v_gcd2(sm,lr%sm);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        int a,b;
        cin >> a >> b;
        v_gcd2(a,b);

    }


}
