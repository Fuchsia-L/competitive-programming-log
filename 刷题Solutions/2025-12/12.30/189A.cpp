#include <bits/stdc++.h>
using namespace std;
int dp[4009] = {0}, n, ans = 0;
void next(int cut)
{
    for (int i = n - cut; i >= 0; i--)
    {
        if (i == n - cut || dp[i + cut] != 0)
            dp[i] = max(dp[i], dp[i + cut] + 1);
    }
    return;
}
int main()
{
    int a, b, c;
    cin >> n >> a >> b >> c;
    next(a);
    next(b);
    next(c);
    cout << dp[0] << "\n";
    return 0;
}