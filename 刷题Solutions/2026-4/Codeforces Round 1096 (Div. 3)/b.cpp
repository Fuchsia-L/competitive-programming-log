#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = " " + s;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '(')
                cnt1++;
            else
                cnt2++;
        }
        if (cnt1 == cnt2)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    // system("pause");
    return 0;
}
