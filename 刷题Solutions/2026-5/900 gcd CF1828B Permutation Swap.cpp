#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
            if (p[i] != i)
            {
                ans = gcd(ans, abs(p[i] - i));
            }
        }
        cout << ans << "\n\n";
    }
    // system("pause");
    return 0;
}