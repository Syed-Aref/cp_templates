#include <bits/stdc++.h>
using namespace std;

double cb_root(double d)
{
    double s = 0;
    double l = d;
    double mid;

    while(l-s>=0.00001)
    {
        mid = (l+s) / 2;
        if( mid*mid*mid == d )
        {
            s = mid;
            break;
        }
        else if( mid*mid*mid > d )
            l = mid;
        else
            s = mid;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << "Hello world"<<"\n";

    while(true)
    {
        double d;
        cin >> d;

        cout << cb_root(d) << endl;
    }

}
