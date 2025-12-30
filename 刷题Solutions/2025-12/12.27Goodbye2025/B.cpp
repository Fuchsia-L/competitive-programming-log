#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int l = s.size() - 1;
        int ans = 0;
        if (s[0] == 'u')
        {
            ans++;
            s[0] = 's';
        }
        if (s[l] == 'u')
        {
            ans++;
            s[l] = 's';
        }
        for (int i = 1; i <= l; i++)
        {
            if (s[i] == 'u')
            {
                if (s[i + 1] == 'u')
                {
                    s[i + 1] = 's';
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}