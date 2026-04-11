#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[5009][5009] = {0};
ll ans[5009][5009] = {0};
ll mod = 1e8;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    string x, y;
    cin >> x >> y;
    int lx = x.size() - 1, ly = y.size() - 1;
    x = " " + x;
    y = " " + y;
    // ll dp[5009][5009][2] = {0};
    for (int i = 0; i <= lx; i++)
        ans[i][0] = 1;
    for (int i = 0; i <= ly; i++)
        ans[0][i] = 1;
    for (int i = 1; i <= lx; i++)
    {
        for (int j = 1; j <= ly; j++)
        {
            if (x[i] == y[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans[i][j] = ans[i - 1][j - 1];
                if (dp[i - 1][j] == dp[i][j])
                    ans[i][j] += ans[i - 1][j];
                if (dp[i][j - 1] == dp[i][j])
                    ans[i][j] += ans[i][j - 1];
                // if (dp[i - 1][j] == dp[i][j - 1])
                //     ans[i][j] -= ans[i - 1][j - 1];
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    ans[i][j] = ans[i - 1][j];
                    dp[i][j] = dp[i - 1][j];
                }
                else if (dp[i - 1][j] < dp[i][j - 1])
                {
                    ans[i][j] = ans[i][j - 1];
                    dp[i][j] = dp[i][j - 1];
                }
                else
                {
                    ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    cout << dp[lx][ly] << "\n"
         << ans[lx][ly] << "\n\n";
    system("pause");
    return 0;
}