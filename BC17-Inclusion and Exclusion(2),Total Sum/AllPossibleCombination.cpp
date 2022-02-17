#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while(1)
    {

        /// All possible combination of n slots
        int n;
        cin >> n;
        int limit = 1<<n;
        for(int i = 0;i<limit;i++)
        {
            bitset<32> bits = bitset<32>(i);
            for(int j = n-1;j>=0;j--)
                cout << bits[j];
            cout << endl;
        }
        ///Time complexity: O( (2^n)*c*n )
        /// (c= # of bits in bitset = 32)

    }

}
