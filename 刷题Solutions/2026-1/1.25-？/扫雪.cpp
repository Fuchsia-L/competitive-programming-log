#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[1009][1009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        ll ans[1009] = {0}, fushu = 0;

        for (int i = 1; i <= n; i++)
        {
            priority_queue<int> id;
            for (int j = 1; j <= m; j++)
            {
                ans[j] += a[i][j];
                if (ans[j] > 0)
                    id.push(j);
                else
                    while (ans[j] < 0)
                    {
                        if (id.empty())
                        {
                            fushu -= ans[j];
                            ans[j] = 0;
                            break;
                        }
                        int buid = id.top();
                        if (ans[buid] + ans[j] >= 0)
                        {
                            ans[buid] += ans[j];
                            ans[j] = 0;
                            if (!ans[buid])
                                id.pop();
                        }
                        else
                        {
                            ans[j] += ans[buid];
                            ans[buid] = 0;
                            id.pop();
                        }
                    }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            fushu += ans[i];
        }
        cout << fushu << "\n";
    }
    return 0;
}