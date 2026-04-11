#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int good_char(int l, int r, char c)
{
    int mid = (l + r) / 2;
    if (l == r)
    {
        if (s[l] == c)
            return 0;
        else
            return 1;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = l; i <= mid; i++)
    {
        if (s[i] != c)
            cnt1++;
    }
    for (int i = mid + 1; i <= r; i++)
    {
        if (s[i] != c)
            cnt2++;
    }
    return min(cnt1 + good_char(mid + 1, r, c + 1), cnt2 + good_char(l, mid, c + 1));
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        s = " " + s;
        cout << good_char(1, n, 'a') << "\n";
        cout << "\n"; /////////////////
    }
    return 0;
}