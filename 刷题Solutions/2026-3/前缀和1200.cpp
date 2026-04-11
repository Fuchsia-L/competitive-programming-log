#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a1(n + 1);
    vector<long long> a2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a1[i];
    }
    a2 = a1;
    sort(a2.begin() + 1, a2.end());
    for (int i = 2; i <= n; i++)
    {
        a2[i] += a2[i - 1];
        a1[i] += a1[i - 1];
    }
    int m;
    cin >> m;
    while (m--)
    {
        int l, r, k;
        cin >> k >> l >> r;
        if (k == 1)
            cout << a1[r] - a1[l - 1] << "\n";
        else
            cout << a2[r] - a2[l - 1] << "\n";
    }
    return 0;
}