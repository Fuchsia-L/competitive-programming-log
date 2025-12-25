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
        vector<int> a, b;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (a[i] != b[i])
            {
                if (i % 2 == 0)
                    ans = 1;
                else
                    ans = 2;
                sum++;
            }
        }

        if (sum % 2 == 1)
        {
            if (ans == 1)
                cout << "Ajisai\n";
            else
                cout << "Mai\n";
        }
        else
            cout << "Tie\n";
    }
    return 0;
}