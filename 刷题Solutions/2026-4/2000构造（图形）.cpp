#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string final[2009];
bool beginn[2009][2009] = {0};
int main()
{

    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> final[i];
        final[i] = " " + final[i];
    }

    int l = 0;
    while (l <= n / 2 + n % 2)
    {
        cout << "LAYER  " << l << " ------------\n"; ///////////
        for (int y = n - l; y > 1 + l; y--)
        {
            if (beginn[1 + l][y] != final[1 + l][y] - '0')
            {
                ans++;
                for (int yi = y; yi >= l + 1; yi--)
                {
                    beginn[l + 1][yi] = !beginn[l + 1][yi];
                }
                for (int xi = 1 + l; xi <= y; xi++)
                {
                    beginn[xi][y] = !beginn[xi][y];
                }
            }
            //
            cout << 1 + l << " " << y << ", ans = " << ans << "\n";
            for (int ii = 1; ii <= n; ii++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << beginn[ii][j] ? 1 : 0;
                }
                cout << "\n";
            }
            cout << "\n\n";
            //
        }
        for (int x = 1 + l; x < n - 1; x++)
        {
            if (beginn[x][n - 1] != final[x][n - l] - '0')
            {
                ans++;
            }
            for (int xi = x; xi <= n - 1; xi++)
            {
                beginn[xi][n - l] = !beginn[xi][n - 1];
            }
            for (int yi = n - l; yi >= x; yi--)
            {
                beginn[x][yi] = !beginn[x][yi];
            }
            //
            cout << ans << "\n";
            cout << x << " " << n - 1 << "\n";
            for (int ii = 1; ii <= n; ii++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << beginn[ii][j] ? 1 : 0;
                }
                cout << "\n";
            }
            cout << "\n\n";
            //
        }
        for (int x = n - l; x >= l + 1; x--)
        {
            if (beginn[x][1 + l] != final[x][1 + l] - '0')
            {
                ans++;
            }
            for (int xi = x; xi >= 1 + l; xi--)
            {
                beginn[xi][l + 1] = !beginn[xi][l + 1];
            }
            for (int yi = 1 + l; yi <= x; yi++)
            {
                beginn[x][yi] = !beginn[x][yi];
            }
            //
            cout << ans << "\n";
            cout << x << " " << 1 + l << "\n";
            for (int ii = 1; ii <= n; ii++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << beginn[ii][j] ? 1 : 0;
                }
                cout << "\n";
            }
            cout << "\n\n";
            //
        }

        for (int y = l + 1 + 1; y <= n - l; y++)
        {
            if (beginn[n - l][y] != final[n - l][y] - '0')
            {
                ans++;
                for (int yi = y; yi <= n - l; yi++)
                {
                    beginn[n - l][yi] = !beginn[n - l][yi];
                }
                for (int xi = n - l - 1; xi >= y; xi--)
                {
                    beginn[xi][y] = !beginn[xi][y];
                }
            }
            //
            cout << ans << "\n";
            cout << n - l << " " << y << "\n";
            for (int ii = 1; ii <= n; ii++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << beginn[ii][j] ? 1 : 0;
                }
                cout << "\n";
            }
            cout << "\n\n";
            //
        }

        l++;
    }
    cout << ans << "\n";
    return 0;
}