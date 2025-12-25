#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        if (l * 2 <= r)
        {
            cout << l << " " << 2 * l << endl; // 找最小的倍数就ok
            continue;
        }
        cout << "-1" << " " << "-1" << endl;
    }
    return 0;
}