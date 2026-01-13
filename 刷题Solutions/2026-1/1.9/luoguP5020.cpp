#include <bits/stdc++.h>
using namespace std;
int main()
{
    int maxn = 25000, t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        vector<bool> book;
        vector<int> dp;
        book.assign(v[n - 1] + 1, false);
        book[0] = true;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int now = v[i];
            // cout << "----" << now << endl;
            if (book[now])
            {
                sum++;
                continue;
            }
            for (int j = now; j <= v[n - 1]; j++)
            {
                book[j] = (book[j - now] ? true : false) || book[j];
            }
        }
        cout << n - sum << endl;
    }
    return 0;
}