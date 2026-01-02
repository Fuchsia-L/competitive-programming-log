#include <bits/stdc++.h>
using namespace std;
long long maxn = 1e5 + 3;
int main()
{
    int n, m;
    vector<long long> a;
    cin >> n;
    a.resize(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        auto it = lower_bound(a.begin() + 1, a.begin() + n + 1, x);
        cout << it - a.begin() << "\n";
    }
    return 0;
}