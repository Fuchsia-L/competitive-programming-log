#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, idx1 = -1, valb = 0, valc = 0, ans = INT_MAX;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                if (valb <= 1 && valc <= 1 && idx1 != i && idx1 != -1)
                {
                    ans = min(ans, i - idx1 + 1);
                }
                idx1 = i;
                valb = valc = 0;
            }
            else
            {
                if (s[i] == 'b')
                    valb++;
                else
                    valc++;
            }
        }
        if (ans == INT_MAX)
            for (int i = 0; i + 7 <= n; i++)
            {
                if (s[i] == 'a' && s[i] == s[i + 3] && s[i + 3] == s[i + 6])
                {
                    int book[3] = {0};
                    for (int j = 0; j <= 6; j++)
                    {
                        book[s[i + j] - 'a']++;
                    }
                    if (book[1] == 2 && book[2] == 2)
                    {
                        ans = 7;
                        break;
                    }
                }
            }
        if (ans < INT_MAX)
            cout << ans;
        else
            cout << "-1";
        cout << "\n";
    }
    return 0;
}