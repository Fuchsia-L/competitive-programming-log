#include <bits/stdc++.h>
using namespace std;

int n, k, d;
long long memo[102][2];
long long dp(long long sum, int check)
{
    if (sum > n)
        return 0;
    if (sum == n)
    {
        return check;
    }
    if (memo[sum][check] != -1)
    {
        return memo[sum][check];
    }
    long long ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int c = check;
        if (i >= d)
            c = 1;
        ans = (ans + dp(sum + i, c)) % int(1e9 + 7);
    }
    memo[sum][check] = ans;
    return ans;
}
int main()
{

    cin >> n >> k >> d;
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0) % int(1e9 + 7);
    return 0;
}