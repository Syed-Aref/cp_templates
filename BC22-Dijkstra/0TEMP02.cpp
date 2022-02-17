#include <bits/stdc++.h>
using namespace std;


int arr[10];

bool compf(int a,int b){
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    arr[1] = 5;
    arr[2] = 6;
    sort(arr , arr+10,compf);
    for(int i = 0;i<10;i++) cout << arr[i] << endl;


}
