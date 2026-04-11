#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int m, v[int(1e5) + 4] = {0};
    cin >> s >> m;
    s = ' ' + s;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i + 1])
            v[i]++;
        v[i] += v[i - 1];
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << v[r - 1] - v[l - 1] << "\n";
    }
    //    system("pause");
    return 0;
}