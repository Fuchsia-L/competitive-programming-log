#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        int ans = 0;
        if (n >= 3)
            ans = 2;
        else
            ans = n;
        for (int i = 1; i <= n; i++)
            cin >> x;
        for (int i = 1; i <= n; i++)
            cout << ans << " ";
        cout << "\n";
    }
    return 0;
}