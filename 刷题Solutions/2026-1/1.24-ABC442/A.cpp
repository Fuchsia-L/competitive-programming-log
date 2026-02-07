#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char s[90];
    int ans = 0;
    cin >> s;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'i' || s[i] == 'j')
            ans++;
    }
    cout << ans << "\n";
    return 0;
}