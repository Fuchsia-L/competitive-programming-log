#include <iostream>
#include <cmath>
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
        vector<int> a, b, ans, ansp;
        a.resize(n);
        b.resize(n);
        ans.resize(22);
        ansp.resize(22);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (a[i] != b[i])
            {
                int who = i % 2;
                for (int k = 0; k <= 21; k++)
                {
                    if (((a[i] >> k) & 1) != ((b[i] >> k) & 1))
                    {
                        ans[k]++;
                        ansp[k] = who;
                    }
                }
            }
        }
        bool f = true;
        for (int i = 21; i >= 0; i--)
        {
            if (ans[i] % 2)
            {
                if (ansp[i] == 0)
                {
                    cout << "Ajisai\n";
                }
                else
                    cout << "Mai\n";
                f = false;
                break;
            }
        }
        if (f)
            cout << "Tie\n";
    }
    return 0;
}