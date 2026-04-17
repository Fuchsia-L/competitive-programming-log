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
        int n;
        cin >> n;
        vector<vector<int>> v(n + 1);
        for (int i = 0; i <= n; i++)
            v[i].push_back(0);
        for (int i = 1; i <= n; i++)
        {
            int k;
            cin >> k;
            for (int j = 1; j <= k; j++)
            {
                int x;
                cin >> x;
                v[x].push_back(i);
                v[i][0]++;
            }
        }
        // cout << "\n1---\n";
        bool f = true;
        vector<bool> used(n + 1, false);
        int d = 0;
        queue<int> q;
        vector<int> pass(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (v[i][0] == 0)
            {
                q.push(i);
                used[i] = true;
                pass[i] = 1;
            }
        }
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int idx : v[now])
            {
                v[idx][0]--;
                pass[idx] = idx > now ? max(pass[idx], pass[now]) : max(pass[idx], pass[now] + 1);
                if (v[idx][0] == 0 && !used[idx])
                {
                    q.push(idx);
                    used[idx] = true;
                }
            }
        }
        // cout << "\n2---\n";
        for (int i = 1; i <= n; i++)
            d = max(d, pass[i]);
        for (int i = 1; i <= n; i++)
        {
            if (!used[i])
                d = -1;
        }

        cout << d << "\n";
    }
    // system("pause");
    return 0;
}