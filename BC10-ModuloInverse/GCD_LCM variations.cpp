//#include <bits/stdc++.h>

#include <algorithm>
#include <bitset>
#include <iterator>
#include <list>
#include <locale>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int gcd(int a , int b)
{
   int lr = max(a,b);
   int sm = min(a,b);

   if(sm==0)
    return lr;
   if(lr%sm==0)
    return sm;
   return gcd(b,a%b);
}
/// Time complexity: O(log(min(a,b)))
int gcdIterativeMethod1(int a, int b) {
    int temp = 0;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
/// Time complexity: O(log(min(a,b)))
int lcm_01(int a,int b)
{
    int lr = max(a,b);
    int sm = min(a,b);
    int ans = 1;
    for(int i = 1;i<=sm;i++)
    {
        if( (lr*i)%sm == 0 )
        {
            ans = lr*i;
            break;
        }
    }
    return ans;
}
/// Time complexity: O(min(a,b))
int lcm_02(int a,int b)
{
    int g = gcd(a,b);
    if(g==0)
        return -1;
    int ans = (a/g)*b;
    return ans;

}
/// Time complexity: O(log(min(a,b)))
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    while(true)
    {
        int a,b;

        cin >> a >> b;
        cout << gcd(a,b) << endl;
        cout << gcdIterativeMethod1(a,b) << endl;
        cout << __gcd(a,b) << endl;
    }
}
