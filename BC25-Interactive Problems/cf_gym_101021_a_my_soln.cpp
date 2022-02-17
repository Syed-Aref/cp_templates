#include <bits/stdc++.h>
using namespace std;

#define mpr make_pair
#define pbk push_back
#define psh push
#define fir first
#define sec second
typedef long long int lli;
int cnt = 1;
bool make_query(int a)
{
    cout << a << endl;
    string read;
    cin >> read;
    if( read=="<" ) return 0;
    else return 1;
}


int main()
{

    int lo = 1 , high = 1000000;
    int mid = 0;
    while(lo<high) /// && cnt<=25)
    {
        if(high-lo==1){
            if( make_query(high)==1 && make_query(lo)==1 )
            {
                lo = high;

            }
            else {}
            break;
        }
        mid = (lo+high) / 2;
        bool b = make_query(mid);
        if(b==0) high = mid-1;
        else{
            if(lo==mid) break;
            lo = mid;
        }
        cnt++;
    }
    cout << "! " << lo << endl;
}
