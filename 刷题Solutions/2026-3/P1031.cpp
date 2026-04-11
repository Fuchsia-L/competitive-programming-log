#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    vector<int> a(n + 1), ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sum /= n;
    int d = 0;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = a[i] + ans[i - 1] - sum;
        if (ans[i] != 0)
            d++;
    }
    cout << d << "\n";
    return 0;
}
