#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x0, y0;
    set<pair<int, int>> s1, s2;
    cin >> n >> x0 >> y0;
    for (int i = 1; i <= n; i++)
    {
        int x, y, g;
        cin >> x >> y;
        x = x - x0;
        y = y - y0;
        g = gcd(abs(x), abs(y));
        if (x * y > 0)
        {
            s1.insert({abs(x / g), abs(y / g)});
        }
        else
        {
            s2.insert({abs(x / g), abs(y / g)});
        }
    }
    cout << s1.size() + s2.size() << "\n";
    system("pause");
}
/*
5 0 0
1 1
-1 -1
33 33
2 -4
-2 4


*/