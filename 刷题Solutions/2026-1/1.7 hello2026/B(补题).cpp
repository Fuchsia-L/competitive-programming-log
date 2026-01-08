#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> a;
        a.resize(k + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x < k)
                a[x]++;
        }
        a[k - 1] = 0;
        for (int i = 0; i < k; i++)
        {
            if (a[i] == 0)
            {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}