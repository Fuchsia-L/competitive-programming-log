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
        vector<long long> a(n + 1), b(n + 1), gr(n + 1, 0), le(n + 1, 0), ans(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        for (int i = 1; i <= n; i++)
            ans[i] = -100;
        sort(b.begin() + 1, b.end());
        long long mid = n / 2 + 1;
        mid = b[mid];
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > mid)
                gr[i]++;
            else if (a[i] < mid)
                le[i]++;
            gr[i] += gr[i - 1];
            le[i] += le[i - 1];
            for (int j = (i + 1) % 2; j < i; j += 2)
            {
                int cnt1 = gr[i] - gr[j];
                int cnt2 = le[i] - le[j];
                int len = i - j;
                if (cnt1 <= len / 2 && cnt2 <= len / 2 && ans[j] >= 0)
                {
                    ans[i] = max(ans[i], ans[j] + 1);
                }
            }
        }
        cout << ans[n] << "\n";
    }
    // system("pause");
    return 0;
}