#include <bits/stdc++.h>
using namespace std;


int a[1000];
bool isput[1000];
void rec( int pos , int n )
{

    if(pos==n)
    {
        for(int i = 0;i<n;i++) cout << a[i] << " ";
        cout << endl;
        return;
    }
    for(int i = 1;i<=n;i++)
    {

        if(isput[i]==0){
            a[pos] = i;
            isput[i] = true;
            rec(pos+1,n);
            a[pos] =  0;
            isput[i] = false;

        }

    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1)
    {
        for(int i = 0;i<1000;i++) a[i] = 0;
        int n;
        cin >> n;
        rec(0,n);
    }

}
