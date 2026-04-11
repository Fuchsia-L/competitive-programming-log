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
        int a, b, l, f = 1, nab[2] = {0}, cnt = 0;
        cin >> a >> b;
        l = a + b;
        string s;
        cin >> s;
        s = " " + s;
        if (a % 2 == 1 && b % 2 == 1)
            f = 0;
        for (int i = 1; i <= l / 2 && f; i++)
        {
            if (i == l - i + 1)
            {
                break;
            }
            if (s[i] != '?' && s[l - i + 1] != '?')
            {
                if (s[i] != s[l - i + 1])
                {
                    f = 0;
                    break;
                }
                nab[s[i] - '0'] += 2;
            }
            else if (s[i] != '?')
            {
                nab[s[i] - '0'] += 2;
                s[l - i + 1] = s[i];
            }
            else if (s[l - i + 1] != '?')
            {
                nab[s[l - i + 1] - '0'] += 2;
                s[i] = s[l - i + 1];
            }
        }
        if (l % 2)
        {
            if (s[l / 2 + 1] == '?')
            {
                if (a % 2)
                {
                    a--;
                    s[l / 2 + 1] = '0';
                }
                else
                {
                    b--;
                    s[l / 2 + 1] = '1';
                }
            }
            else
            {
                if ((a % 2) && s[l / 2 + 1] == '0')
                    a--;
                else if ((b % 2) && s[l / 2 + 1] == '1')
                    b--;
                else
                    f = 0;
            }
        }
        if (nab[0] > a || nab[1] > b)
            f = 0;
        if (f == 0)
        {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i <= l; i++)
        {
            if (s[i] == '?')
            {
                if (nab[0] < a)
                {
                    s[i] = s[l - i + 1] = '0';
                    nab[0] += 2;
                }
                else
                {
                    s[i] = s[l - i + 1] = '1';
                }
            }
            cout << s[i];
        }
        cout << "\n";
    }
    // system("pause");
    return 0;
}