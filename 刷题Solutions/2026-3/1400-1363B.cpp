#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        s = " " + s;
        int idx1 = 0, len = s.length();
        int re1[1009] = {0}, re0[1009] = {0};
        int bre0[1009] = {0}, bre1[1009] = {0};
        for (int i = 1; s[i] != '\0'; i++)
        {
            if (s[i] == '1')
            {
                idx1++;
                re0[i]++;
            }
            else
            {
                re1[i]++;
            }
            re0[i] += re0[i - 1];
            re1[i] += re1[i - 1];
        }
        for (int i = len - 1; i >= 1; i--)
        {
            if (s[i] == '1')
                bre0[i]++;
            else
                bre1[i]++;
            bre0[i] += bre0[i + 1];
            bre1[i] += bre1[i + 1];
        }
        int ans = min(idx1, len - idx1 - 1);
        for (int i = 0; i < len; i++)
        {
            ans = min(ans, min(bre0[i + 1] + re1[i], bre1[i + 1] + re0[i]));
        }
        cout << ans << "\n";
    }
    return 0;
}