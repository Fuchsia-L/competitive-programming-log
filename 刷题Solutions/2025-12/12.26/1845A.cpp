#include <iostream>
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        if (x != 1)
        {
            cout << "Yes\n"
                 << n << "\n";
            for (int i = 1; i <= n; i++)
                cout << "1 ";
            cout << "\n";
            continue;
        }
        if (n == 1 || k == 1 || (n % 2 == 1 && k < 3))
        {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        int num1 = n / 2;
        cout << num1 << "\n";
        if (n % 2 == 1)
        {
            cout << "3 ";
            num1--;
        }
        for (int j = 1; j <= num1; j++)
            cout << "2 ";
        cout << "\n";
    }
    return 0;
}