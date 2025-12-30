#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
long long n, f[maxn] = {0}, maxi, ans = 0;
long long dp[maxn] = {0};
int main()
{
    cin >> n;
    //    priority_queue<int, vector<int>, greater<>> a;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        f[x]++;
        maxi = max(maxi, x);
    }
    for (int i = 1; i <= maxi; i++)
    {
        dp[i] = max(dp[i - 2] + i * f[i], dp[i - 1]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}