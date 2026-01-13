#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, p = 0, q = 0;
    cin >> n;
    vector<long long> diff;
    diff.resize(n + 1, 0);
    for (long long i = 1, a = 0, b = 0; i <= n; i++)
    {

        cin >> a;
        diff[i] = a - b;
        if (i != 1)
            if (diff[i] > 0)
                p += diff[i];
            else
                q += diff[i];
        b = a;
    }
    cout << max(p, abs(q)) << "\n"
         << abs(p + q) + 1 << "\n";
    return 0;
}