#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x1, x2, mid;
        cin >> n;
        int left = 0, right = INT_MAX;
        cin >> x1;
        for (int i = 1; i < n; i++)
        {
            cin >> x2;
            mid = (x1 + x2) / 2;
            if (x2 > x1)
            {
                right = min(right, mid);
            }
            else if (x1 > x2)
            {
                left = max(left, mid + (x1 - x2) % 2);
            }
            x1 = x2;
        }
        if (left <= right)
        {
            cout << left << "\n\n\n";
        }
        else
            cout << "-1\n\n\n";
    }
    system("pause");
    return 0;
}
