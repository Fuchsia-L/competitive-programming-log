#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> road(n + 1);
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            road[u].push_back({v, w});
            if (w >= 0)
            {
                road[v].push_back({u, w});
            }
        }

        queue<int> place;
        int book[2009], cnt[2009] = {0};
        for (int i = 1; i <= n; i++)
        {
            book[i] = INT_MAX;
        }

        book[1] = 0;
        bool f = true, in_q[2009] = {0};
        place.push(1);

        while (!place.empty())
        {
            int now = place.front();
            place.pop();
            in_q[now] = 0;
            cnt[now]++;
            if (cnt[now] == n)
            {
                f = false;
                cout << "YES\n";
                break;
            }
            for (auto [next, w] : road[now])
            {
                if (book[next] > book[now] + w)
                {
                    book[next] = book[now] + w;
                    if (in_q[next] == 0)
                    {
                        place.push(next);
                        in_q[next] = 1;
                    }
                }
            }
        }
        if (f)
        {
            cout << "NO\n";
        }
    }
    return 0;
}