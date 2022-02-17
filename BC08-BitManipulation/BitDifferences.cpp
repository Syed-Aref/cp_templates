#include <bits/stdc++.h>
using namespace std;

int bit_differ(int A, int B)
{
    int count = 0;

    // since, the numbers are less than 2^31
    // run the loop from '0' to '31' only
    for (int i = 0; i < 32; i++) {

        // right shift both the numbers by 'i' and
        // check if the bit at the 0th position is different
        if ( ((A >> i) & 1) != ((B >> i) & 1) ) {
            count++;
        }
    }

    return count;
}
/// Time complexity: O(c) [c means constant.Here, c = 31]

int bit_differ_(int A, int B)
{
    int count = 0;

    for (int i = 0; i < 32; i++) {
        int x = (1<<i);
        if( (A&x) != (B&x) ) count++;
    }

    return count;
}
/// Time complexity: O(c) [c means constant.Here, c = 31]

int main()
{

    while(true)
    {
        int a,b;
        cin >> a >> b;

        cout << bit_differ(a,b) << endl;
        cout << bit_differ_(a,b) << endl;
    }
}
