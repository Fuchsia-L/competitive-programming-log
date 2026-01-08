#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        n -= 2;
        int a, b, c;
        cin >> a;
        while (n--)
        {
            cin >> b;
        }
        cin >> c;
        if (a + c == 0)
        {
            cout << "Bob" << endl;
        }
        else
            cout << "Alice" << endl;
    }
    return 0;
}