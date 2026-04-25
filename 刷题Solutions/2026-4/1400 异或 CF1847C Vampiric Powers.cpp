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
        int maxx = 0;
        vector<int> v(n + 1, 0);
        set<int> s;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            v[i] = (v[i] xor v[i - 1]);
            s.insert(v[i]);
            maxx = max(maxx, v[i]);
        }
        for (int x1 : s)
        {
            for (int x2 : s)
            {
                maxx = max(maxx, x1 xor x2);
            }
        }
        cout
            << maxx << "\n";
    }
    // system("pause");
    return 0;
}
