#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> book, tree[100002];
int main()
{
    cin >> n >> m;
    book.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> book[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    queue<pair<int, int>> q;
    q.push({1, book[1]});
    book[1] = m + 1;
    int ans = 0;
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        // cout << now.first << " ,cat= " << now.second << endl;
        if (now.second > m)
            continue;
        int ind = 0;
        for (int next : tree[now.first])
        {
            if (book[next] < m + 1)
            {
                ind++;
                if (book[next])
                    q.push({next, now.second + book[next]});
                else
                    q.push({next, 0});
                book[next] = m + 1;
            }
        }
        if (ind == 0)
        {
            ans++;
            continue;
        }
    }
    cout << ans;
    return 0;
}