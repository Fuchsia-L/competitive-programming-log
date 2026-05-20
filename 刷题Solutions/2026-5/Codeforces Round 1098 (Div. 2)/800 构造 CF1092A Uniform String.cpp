#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int l = n / k;
        for (int i = 1; i <= l; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cout << char('a' + j);
            }
        }
        for (int i = 1; i <= n % k; i++)
        {
            cout << 'a';
        }
        cout << "\n";
    }

    system("pause");
    return 0;
}