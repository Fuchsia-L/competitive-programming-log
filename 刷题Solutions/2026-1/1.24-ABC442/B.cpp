#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, v = 0;
    bool p = false;
    cin >> n;
    while (n--)
    {
        cin >> a;
        if (a == 1)
            v++;
        else if (a == 2)
        {
            if (v)
                v--;
        }
        else
        {
            p = !p;
        }
        if (p && v >= 3)
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }
    return 0;
}