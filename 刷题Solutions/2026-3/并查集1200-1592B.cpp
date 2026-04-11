#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<ll> v;
        v.push_back(-1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            v.push_back(a);
        }
        if (2 * x < n)
        {
            cout << "YES\n";
            continue;
        }
        // cout << "p-------\n";
        vector<ll> v2 = v;
        sort(v2.begin(), v2.end());
        int f = 1;
        // cout << "---start---\n";
        for (int i = max(n - x - 1, 0); i <= x - 1; i++)
        {
            // cout << "i= " << i << '\n';
            if (v[i] != v2[i])
            {
                f = 0;
                break;
            }
        }
        if (f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    system("pause");
    return 0;
}