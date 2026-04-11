#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0, a[109], pre[109] = {0};
        cin >> n;
        for (int i = 2; i <= n; i++)
        {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        sum = pre[n];
        int numm[109] = {0};
        int maxi = 0;
        for (maxi = 1; maxi * maxi <= sum; maxi++)
            numm[maxi] = maxi * maxi;
        maxi--;
        int dp[109][109];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= maxi; j++)
                dp[i][j] = INT_MAX;
        }
        for (int j = 0; j <= maxi; j++)
        {
            dp[1][j] = abs(pre[1] - j * j);
        }
        for (int i = 2; i <= n; i++)
        {
            int minc = dp[n][0];
            for (int j = 0; j <= maxi; j++)
            {
            }
        }
    }
    return 0;
}
