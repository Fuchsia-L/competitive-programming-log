#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, cnt1 = 0, cnt2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
            cnt1++;
        else
            cnt2++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 && cnt2)
        {
            cout << 2 << " ";
            cnt2--;
        }
        else if (i == 2 && cnt1)
        {
            cout << 1 << " ";
            cnt1--;
        }
        else
        {
            if (cnt2)
            {
                cout << 2 << " ";
                cnt2--;
            }
            else
            {
                cout << 1 << " ";
            }
        }
    }
    cout << "\n";
    system("pause");
    return 0;
}
