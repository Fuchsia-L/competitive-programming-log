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
        vector<long long> a, b;
        a.resize(n + 2, 0);
        b.resize(n + 2, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            int index = a[i] + i;
            if (index > n)
                index = n + 1;
            b[index] = max(b[index], b[i] + a[index]);
            ans = max(ans, b[index]);
        }
        cout << ans << "\n";
    }
    return 0;
}