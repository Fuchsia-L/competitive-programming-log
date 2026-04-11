#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ans = 0;
        cin >> n >> m;
        int a[203][203] = {0}, sum1[404] = {0}, sum2[204][2] = {0};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                sum1[i + j] += a[i][j];
                if (i - j >= 0)
                    sum2[i - j][0] += a[i][j];
                else
                    sum2[j - i][1] += a[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int sum3;
                if (i - j >= 0)
                    sum3 = sum2[i - j][0];
                else
                    sum3 = sum2[j - i][1];
                ans = max(ans, sum1[i + j] + sum3 - a[i][j]);
            }
        }
        cout << ans << "\n\n\n";
    }
    // system("pause");
    return 0;
}