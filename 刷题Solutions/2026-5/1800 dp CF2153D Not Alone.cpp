#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll dp(int head, int tail, vector<ll> &cost, ll val1)
{
    if (tail < head)
    {
        return val1;
    }
    if (tail == head)
        return LONG_LONG_MAX - 1;

    vector<ll> dp(n + 1, 1e15);
    dp[head - 1] = val1;
    for (int i = head + 1; i <= tail; i++)
    {
        if (i == head + 1)
        {
            dp[i] = dp[i - 2] + abs(cost[i] - cost[i - 1]);
        }
        else
        {
            ll k1 = dp[i - 2] + abs(cost[i] - cost[i - 1]);
            ll k2 = dp[i - 3] + max(cost[i], max(cost[i - 1], cost[i - 2])) - min(cost[i], min(cost[i - 1], cost[i - 2]));
            dp[i] = min(k1, k2);
        }
    }
    return dp[tail];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> cost(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> cost[i];
        }
        ll ans = LONG_LONG_MAX - 1;
        ans = min(ans, dp(2, n - 1, cost, abs(cost[1] - cost[n])));
        ans = min(ans, dp(2, n - 2, cost, max(cost[1], max(cost[n - 1], cost[n])) - min(cost[1], min(cost[n], cost[n - 1]))));
        ans = min(ans, dp(3, n, cost, abs(cost[1] - cost[2])));
        ans = min(ans, dp(4, n, cost, max(cost[1], max(cost[2], cost[3])) - min(cost[1], min(cost[2], cost[3]))));
        ans = min(ans, dp(3, n - 1, cost, max(cost[1], max(cost[2], cost[n])) - min(cost[1], min(cost[n], cost[2]))));

        cout << ans << "\n";
    }
    // system("pause");
    return 0;
}
