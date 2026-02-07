#include <bits/stdc++.h>
using namespace std;
int len[200008], chinum[200009];
bool book[200009];
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> r(n + 2);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        r[u].push_back(v);
        r[v].push_back(u);
    }
    queue<int> q;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> sq; // len,id,fa
    q.push(1);
    book[1] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int next : r[now])
        {
            if (!book[next])
            {
                book[next] = true;
                len[next] = len[now] + 1;
                q.push(next);
                sq.push({len[next], {next, now}});
            }
        }
    }
    while (!sq.empty())
    {
        auto now = sq.top();
        sq.pop();
        chinum[now.second.second] += chinum[now.second.first] + 1;
    }

    return 0;
}
