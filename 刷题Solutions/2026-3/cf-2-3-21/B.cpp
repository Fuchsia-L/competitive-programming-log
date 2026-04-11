#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> ans1(n + 1), ans2(n + 1), a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = n; i >= 1; i--)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                if (a[i] > a[j])
                    ans1[j]++;
                else if (a[i] < a[j])
                    ans2[j]++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << max(ans1[i], ans2[i]) << " ";
        }
        cout << "\n\n";
    }
    return 0;
}