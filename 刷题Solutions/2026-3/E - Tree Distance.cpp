#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<vector<int>> treee(3001);
int wei[3001][3001];
vector<bool> book(3001);
bool dfs(int i)
{
    queue<pair<int, int>> q;
    q.push({i, 0});
    book[i] = 1;
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        for (auto nextt : treee[now.first])
        {
            if (book[nextt])
                continue;
            book[nextt] = 1;
            q.push({nextt, wei[now.first][nextt] + now.second});
            if (now.second + wei[now.first][nextt] != wei[nextt][i])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << "Yes";
        return 0;
    }
    for (int i = 1, x; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> wei[i][j];
            wei[j][i] = wei[i][j];
        }
    }

    for (int i = 2; i <= n; i++)
    {
        int len_form_1 = wei[i][1];
        int f = 1, minn = INT_MAX, minnidx = -1;
        for (int j = 2; (j <= n) && f; j++)
        {
            if (j == i)
                continue;
            if (wei[i][1] == wei[i][j] + wei[j][1])
            {
                if (minn > wei[i][j])
                {
                    minn = wei[i][j];
                    minnidx = j;
                }
            }
        }
        if (minnidx != -1)
        {
            treee[minnidx].push_back(i);
            treee[i].push_back(minnidx);
        }
        else
        {
            treee[1].push_back(i);
            treee[i].push_back(1);
        }
    }
    bool f = true;
    for (int i = 1; i <= n; i++)
    {
        book.assign(n + 9, 0);
        f = f & dfs(i);
    }
    if (f)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}