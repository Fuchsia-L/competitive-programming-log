#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int f = 0, x = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            if (x == 100)
                f = 1;
        }
        if (f)
        {
            cout << "yes\n";
        }
        else
            cout << "no\n";
    }
    system("pause");
    return 0;
}