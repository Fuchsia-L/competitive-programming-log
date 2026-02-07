#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    ll a, b, n;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> n;
        if (a + 2 * b - 2 >= n || (a * 3 <= n && n <= (a + 4 * b - 2)))
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    return 0;
}