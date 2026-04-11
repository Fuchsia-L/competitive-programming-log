#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b[i] = c[b[i]];
    }
    vector<int> d(int(1e5 + 1));
    auto tail = d.begin() + 1;
    for (int i = 1; i <= n; i++)
    {
        auto it = upper_bound(d.begin(), tail, b[i]);
        *it = b[i];
        if (it == tail)
        {
            tail++;
            ans = it - d.begin();
        }
    }
    cout << ans << "\n";
    /*
    方法1，超时。a[i]b[i]含义为原始含义
    int dp[2][int(1e5 + 2)] = {0};
    int pre = 0, cur = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
            {
                dp[cur][j] = dp[pre][j - 1] + 1;
            }
            else
            {
                dp[cur][j] = max(dp[pre][j], dp[cur][j - 1]);
            }
        }
        swap(cur, pre);
    }
    cout << dp[pre][n] << " ";
    */
    /*方法2*/

    system("pause");
    return 0;
}