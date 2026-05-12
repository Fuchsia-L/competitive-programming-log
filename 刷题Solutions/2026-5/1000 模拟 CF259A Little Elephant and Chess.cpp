#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool f = true;
    for (int i = 1; i <= 8; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j <= 6; j++)
        {
            if (s[j] == s[j + 1])
            {
                f = false;
            }
        }
        if (s[0] == s[7])
        {
            f = false;
        }
    }
    if (f)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    // system("pause");
    return 0;
}