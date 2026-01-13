#include <bits/stdc++.h>
using namespace std;
long long x1 = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a = -1, num1 = 0, num2 = 0;
    cin >> n;
    vector<int> ai;
    ai.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> ai[i];
    sort(ai.begin() + 1, ai.end());
    for (int i = 1; i <= n; i++)
    {
        int now = ai[i];
        if (a == -1)
            a = now;
        if (now == a)
            num1++;
        else if (now == a + 1)
            num2++;
        else
        {
            cout << "No\n";
            return 0;
        }
    }

    if (num2 == 0)
    {
        if (a == n - 1)
        {
            cout << "Yes\n";
        }
        else if (a * 2 <= n)
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
        return 0;
    }

    if (a - num1 + 1 > 0 && num2 >= 2 * (a - num1 + 1))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}