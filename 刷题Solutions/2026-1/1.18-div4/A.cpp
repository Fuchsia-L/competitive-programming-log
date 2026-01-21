#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        for (int i = 1; i <= x; i++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}