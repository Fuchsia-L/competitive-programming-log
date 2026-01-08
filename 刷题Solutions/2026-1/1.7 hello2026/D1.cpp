#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<vector<int>> a;
        a.resize(n + 1);
        int x, y;
        for (int i = 1; i < n; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        a[1].push_back(0);
        vector<bool> book;
        vector<int> level;
        book.resize(n + 2, true);
        level.resize(n + 2);
        queue<pair<int, int>> q;
        q.push({1, 1});
        book[1] = false;
        level[1]++;
        int depth = 1, width = 1, child = 1;
        while (!q.empty())
        {
            auto now = q.front();
            q.pop();
            child = max(child, int(a[now.first].size() - 1));
            for (int x : a[now.first])
            {
                if (book[x])
                {
                    q.push({x, now.second + 1});
                    book[x] = false;
                    level[now.second + 1]++;
                }
            }
            width = max(width, int(level[now.second]));
        }
        int ans = max(child + 1, width);
        cout << ans << endl;
        // cout << "宽： " << width << "  // child:" << child << endl;
    }
    return 0;
}