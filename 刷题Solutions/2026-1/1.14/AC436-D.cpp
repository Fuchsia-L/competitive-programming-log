#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    vector<vector<pair<int, int>>> s;
    s.resize('z' + 1);
    cin >> h >> w;
    char map[1090][1090];
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != '.' && map[i][j] != '#')
            {
                s[map[i][j]].push_back({i, j});
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({1, 1});
    vector<vector<int>> book;
    book.resize(h + 1, vector<int>(w + 1, INT_MAX));
    book[1][1] = 0;
    int po[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        // cout << now.first << " " << now.second << "  book=" << book[now.first][now.second] << "\n";
        if (now.first == h && now.second == w)
        {
            cout << book[h][w] << "\n";
            return 0;
        }
        for (int i = 0; i <= 3; i++)
        {
            int h1 = now.first + po[i][0];
            int w1 = now.second + po[i][1];
            if (h1 <= h && h1 >= 1 && w1 <= w && w1 >= 1 && map[h1][w1] != '#' && book[h1][w1] == INT_MAX)
            {
                book[h1][w1] = book[now.first][now.second] + 1;
                q.push({h1, w1});
            }
        }
        if (map[now.first][now.second] != '.')
        {
            char c = map[now.first][now.second];
            map[now.first][now.second] = '.';
            for (auto next : s[c])
            {
                int i = next.first;
                int j = next.second;

                if (map[i][j] == c)
                {
                    if (book[i][j] == INT_MAX)
                    {
                        q.push({i, j});
                        book[i][j] = book[now.first][now.second] + 1;
                    }
                    map[i][j] = '.';
                }
                s[c].clear();
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}