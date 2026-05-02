#include <bits/stdc++.h>
using namespace std;
int p[22000010];
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    string s, s2 = "@#";
    cin >> s;
    for (int i = 0; s[i] != '\0'; i++)
    {
        s2 += s[i];
        s2 += "#";
    }
    s2 += "*";
    int c = 1, r = 1;
    // cout << s << " " << s2 << "\n";
    for (int i = 1; s2[i] != '*'; i++)
    {
        if (i <= r)
        {
            int j = 2 * c - i;
            if (j - p[j] <= 2 * c - r)
            {
                p[i] = r - i;
                int il = 2 * i - r - 1;
                int ir = r + 1;
                while (s2[il] == s2[ir])
                {
                    p[i]++;
                    il--;
                    ir++;
                }
                c = i;
                r = ir - 1;
            }
            else
            {
                p[i] = p[2 * c - i];
            }
        }
        else
        {
            int il = i - 1;
            int ir = i + 1;
            while (s2[il] == s2[ir])
            {
                p[i]++;
                il--;
                ir++;
            }
            c = i;
            r = ir - 1;
        }
    }
    int ans = 0;
    for (int i = 1; s2[i] != '*'; i++)
    {
        // cout << p[i] << " ";
        ans = max(ans, p[i]);
    }
    cout
        << ans << "\n";
    // system("pause");
    return 0;
}
