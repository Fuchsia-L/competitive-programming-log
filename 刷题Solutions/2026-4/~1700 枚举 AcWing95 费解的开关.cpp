#include <bits/stdc++.h>
using namespace std;
string s[9], ss[9];
int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
void tr(int x, int y)
{
    ss[x][y] = '0' + !bool(ss[x][y] - '0');
    ss[x + 1][y] = '0' + !bool(ss[x + 1][y] - '0');
    ss[x][y + 1] = '0' + !bool(ss[x][y + 1] - '0');
    ss[x - 1][y] = '0' + !bool(ss[x - 1][y] - '0');
    ss[x][y - 1] = '0' + !bool(ss[x][y - 1] - '0');
}
int count_ans()
{
    int ans = a1 + a2 + a3 + a4 + a5;
    for (int i = 1; i <= 5; i++)
    {
        ss[i] = s[i];
    }
    ss[0] = "             ";
    ss[6] = "           ";
    if (a1)
        tr(1, 1);

    if (a2)
        tr(1, 2);
    if (a3)
        tr(1, 3);
    if (a4)
        tr(1, 4);
    if (a5)
        tr(1, 5);
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (ss[i][j] != '1')
            {
                tr(i + 1, j);
                ans++;
                if (ans > 6)
                {
                    return INT_MAX;
                }
            }
            // cout << i << " " << j << " ,ans=" << ans << "\n";
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        if (ss[5][i] != '1')
        {
            return INT_MAX;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 5; i++)
        {
            cin >> s[i];
            s[i] = " " + s[i] + "   ";
        }
        int minans = INT_MAX;
        a1 = 0;
        while (a1 < 2)
        {
            a2 = 0;
            while (a2 < 2)
            {
                a3 = 0;
                while (a3 < 2)
                {
                    a4 = 0;
                    while (a4 < 2)
                    {
                        a5 = 0;
                        while (a5 < 2)
                        {
                            minans = min(count_ans(), minans);
                            a5++;
                        }
                        a4++;
                    }
                    a3++;
                }
                a2++;
            }
            a1++;
        }
        if (minans <= 6)
        {
            cout << minans << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}