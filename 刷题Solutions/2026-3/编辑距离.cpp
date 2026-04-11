#include <bits/stdc++.h>
using namespace std;
int dp[2009][2009];
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = " " + a;
    b = " " + b;
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int j = 1; j <= m; j++)
        dp[0][j] = j;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }
    cout << dp[n][m] << "\n";
    system("pause");
    return 0;
}