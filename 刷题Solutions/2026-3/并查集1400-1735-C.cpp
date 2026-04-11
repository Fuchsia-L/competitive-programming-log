#include <bits/stdc++.h>
using namespace std;
char table['z' + 1];
void table_init()
{
    for (char i = 'a'; i <= 'z'; i++)
        table[i] = i;
    return;
}
char find(char x)
{
    if (table[x] == x)
        return x;
    else
        return table[x] = find(table[x]);
}
void connect(char x, char y)
{
    table[find(x)] = find(y);
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        table_init();
        int l, find_num = 0;
        string s;
        char sw['z' + 1] = {0};
        cin >> l >> s;
        s = ' ' + s;
        for (int i = 1, f = 1; i <= l; i++)
        {
            f = 1;
            for (char idx = 'a'; idx <= 'z' && (f == 1); idx++)
            {
                if (table[s[i]] != s[i])
                {
                    f = 0;
                    continue;
                }
                if (idx == s[i] || sw[idx] != 0 || (find(idx) == find(s[i]) && find_num < 25))
                    continue;
                find_num++;
                connect(s[i], idx);
                sw[idx] = s[i];
                f = 0;
            }
        }
        for (int i = 1; i <= l; i++)
        {
            for (char j = 'a'; j <= 'z'; j++)
            {
                if (sw[j] == s[i])
                {
                    cout << j;
                    break;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}