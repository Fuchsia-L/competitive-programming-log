#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, a;
    cin >> n >> k;
    int bef, aft;
    cin >> bef;
    cout << bef << " ";
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> aft;
        if ((a > max(bef, aft) + 1) && k)
        {
            cout << a - 1 << " ";
            k--;
        }
        else
            cout << a << " ";
        cout << aft << " ";
        bef = aft;
    }
    return 0;
}