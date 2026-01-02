#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long ans = 0, f = 0;
        vector<long long> a;
        a.resize(n + 2, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = n; i >= 1; i--)
        {
            int index = a[i] + i;
            if (index > n)
                index = n + 1;
            a[i] += a[index];
            ans = max(a[i], ans);
        }
        cout << ans << "\n";
    }
    return 0;
}