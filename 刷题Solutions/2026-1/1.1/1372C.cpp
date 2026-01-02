#include <iostream>
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
        long long a, ans = 0, f = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            if (a != i && f == 0)
            {
                f = 1;
                ans++;
            }
            if (a == i)
                f = 0;
        }
        if (ans > 2)
            ans = 2;
        cout << ans << "\n";
    }
    return 0;
}