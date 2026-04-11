#include <bits/stdc++.h>
using namespace std;
int dp[2][10009] = {0};
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = " " + a;
    b = " " + b;
    int cur = 0, pre = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                dp[cur][j] = dp[pre][j - 1] + 1;
            }
            else
                dp[cur][j] = max(dp[pre][j], dp[cur][j - 1]);
        }
        swap(cur, pre);
    }
    cout << dp[pre][m];
    return 0;
}