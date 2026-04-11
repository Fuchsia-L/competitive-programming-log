#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string a, b;
char c;
ll book[100][26];
vector<ll> len(91);
ll search_num(ll x, int cj)
{
    if (x == 0)
        return 0;
    if (len[cj] > x)
    {
        return search_num(x, cj - 1);
    }
    return book[cj][c] + search_num(x - len[cj], cj - 2);
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int q;
    cin >> a >> b >> q;
    len[0] = 1;
    len[1] = 1;
    len[2] = 2;
    for (int i = 0; a[i] != '\0'; i++)
    {
        book[0][a[i] - 'a']++;
    }
    for (int i = 0; b[i] != '\0'; i++)
    {
        book[1][b[i] - 'a']++;
    }
    for (int i = 2; i <= 90; i++)
    {
        len[i] = len[i - 1] + len[i - 2];
        for (int j = 0; j < 26; j++)
        {
            book[i][j] = book[i - 1][j] + book[i - 2][j];
        }
    }

    while (q--)
    {
        ll l, r;
        int p = 0;
        cin >> l >> r >> c;
        cout << "left-1 = " << search_num(l - 1, 90) << "  right = " << search_num(r, 90) << "\n";
        cout << search_num(r, 90) - search_num(l - 1, 90) << "\n------------\n";
    }
    return 0;
}