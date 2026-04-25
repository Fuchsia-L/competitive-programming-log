// CF 510C Fox And Names
// https://codeforces.com/problemset/problem/510/C

#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int cmp()
{
    int l = min(s1.length(), s2.length()) - 1;
    for (int i = 1; i <= l; i++)
    {
        if (s1[i] != s2[i])
        {
            return i;
        }
    }
    if (s1.length() > s2.length())
    {
        return -1;
    }
    return 0;
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    cin >> n;
    cin >> s1;
    s1 = " " + s1;
    vector<vector<int>> v(27);
    vector<int> cnt(27, 0);
    bool f = false;
    for (int i = 1; i < n; i++)
    {
        cin >> s2;
        s2 = " " + s2;
        int idx = cmp();
        if (idx == -1)
        {
            f = true;
        }
        else if (idx)
        {
            v[s1[idx] - 'a'].push_back(s2[idx] - 'a');
            cnt[s2[idx] - 'a']++;
        }
        s1 = s2;
    }
    if (f)
    {

        cout << "Impossible\n";
        return 0;
    }
    queue<int> q;
    string ans = "";
    for (int i = 0; i <= 'z' - 'a'; i++)
    {
        // cout << char('a' + i) << " :" << cnt[i] << "\n";
        if (cnt[i] == 0)
        {
            q.push(i);
            ans += ('a' + i);
        }
    }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int next : v[now])
        {
            cnt[next]--;
            if (cnt[next] == 0)
            {
                // cout << char('a' + now) << "-->" << char('a' + next) << "\n";
                q.push(next);
                ans += ('a' + next);
            }
        }
    }
    for (int i = 0; i <= 'z' - 'a'; i++)
    {
        if (cnt[i] != 0)
        {
            f = true;
        }
    }
    if (f)
    {
        cout << "Impossible\n";
        return 0;
    }
    cout << ans << "\n";
    system("pause");
    return 0;
}
