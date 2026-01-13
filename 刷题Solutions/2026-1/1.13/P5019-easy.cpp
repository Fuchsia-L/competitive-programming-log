#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> v;
    v.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (v[i] > v[i - 1])
            ans += v[i] - v[i - 1];
    }
    cout << ans << "\n";
    return 0;
}