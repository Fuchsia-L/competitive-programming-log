#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<long long> diff;
    diff.resize(n + 1, 0);
    for (long long i = 1, a = 0, b = 0; i <= n; i++)
    {
        cin >> a;
        diff[i] = a - b;
        b = a;
    }
    long long f = 0, ans1 = 0, ans2 = 1; // 先抵消正负
    for (long long i = 2, j = 1; i <= n && j <= n;)
    {
        while (i <= n && diff[i] <= 0)
            i++;
        while (j <= n && diff[j] >= 0)
            j++;
        if (i == n + 1 || j == n + 1)
        {
            if (i != j)
                f = 1;
            break;
        }
        long long c = min(diff[i], -diff[j]);
        ans1 += c;
        diff[i] -= c;
        diff[j] += c;
    }
    if (f) // 再把抵消不了的拿走
        for (long long i = 2; i <= n; i++)
        {
            if (diff[i] != 0)
            {
                ans1 += abs(diff[i]);
                ans2 += abs(diff[i]);
            }
        }
    cout << ans1 << "\n"
         << ans2 << "\n";
    return 0;
}