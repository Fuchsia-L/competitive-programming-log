#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    ll val = 0;
    int pre_x = 1, pre_y = 1;
};
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> road(n + 1);
        vector<vector<node>> ans(n + 1);
        road[0].resize(n + 1, 0);
        ans[0].resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            road[i].resize(m + 1, 0);
            ans[i].resize(m + 1);
            for (int j = 1; j <= m; j++)
            {
                cin >> road[i][j];
            }
        }
        //
        ans[1][1].val = road[1][1];
        for (int i = 2; i <= n; i++)
        {
            ans[i][1].val = ans[i - 1][1].val + road[i][1];
            ans[i][1].pre_x = i - 1;
            ans[i][1].pre_y = 1;
        }
        for (int i = 2; i <= m; i++)
        {
            ans[1][i].val = ans[1][i - 1].val + road[1][i];
            ans[1][i].pre_x = 1;
            ans[1][i].pre_y = i - 1;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j <= m; j++)
            {
                ans[i][j].val = max(ans[i - 1][j].val, ans[i][j - 1].val) + road[i][j];
                if (ans[i - 1][j].val > ans[i][j - 1].val)
                {
                    ans[i][j].pre_x = i - 1;
                    ans[i][j].pre_y = j;
                }
                else
                {
                    ans[i][j].pre_x = i;
                    ans[i][j].pre_y = j - 1;
                }
            }
        } /////
        ///
        int nowx = n, nowy = m, maxx = n, maxy = m, maxval = road[n][m];
        for (int i = 1; i <= m + n - 1; i++)
        {
            if (maxval < road[nowx][nowy])
            {
                maxx = nowx;
                maxy = nowy;
                maxval = road[nowx][nowy];
            }
            //////////////////////
            int xx = nowx, yy = nowy;
            // cout << "nowx/y = " << nowx << " " << nowy << " val= " << maxval << "\n";
            nowx = ans[xx][yy].pre_x;
            nowy = ans[xx][yy].pre_y;
        }
        road[maxx][maxy] = 0 - road[maxx][maxy];
        /////
        ans[1][1].val = road[1][1];
        for (int i = 2; i <= n; i++)
        {
            ans[i][1].val = ans[i - 1][1].val + road[i][1];
        }
        for (int i = 2; i <= m; i++)
        {
            ans[1][i].val = ans[1][i - 1].val + road[1][i];
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j <= m; j++)
            {
                ans[i][j].val = max(ans[i - 1][j].val, ans[i][j - 1].val) + road[i][j];
            }
        }

        /////

        cout << ans[n][m].val << "\n\n";
    }

    system("pause");
    return 0;
}
