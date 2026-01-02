#include <iostream>
using namespace std;
const int maxn = 5e5 + 2;
long long a[maxn];
long long m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    if (a[n] % 3)
    {
        cout << 0 << "\n";
        return 0;
    }
    m = a[n] / 3;
    long long ans = 0, pre1 = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 2 * m)
            ans += pre1;
        if (a[i] == m)
            pre1++;
    }
    cout << ans << "\n";
    return 0;
}