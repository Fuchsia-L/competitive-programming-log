#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int t;
    int n;
    cin >> t;
    vector<int> a;
    while (t--)
    {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (a[0] == -1 && a[n - 1] != -1)
            a[0] = a[n - 1];
        if (a[n - 1] == -1 && a[0] != -1)
            a[n - 1] = a[0];
        cout << abs(a[0] - a[n - 1]) << endl;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == -1)
                a[i] = 0;
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}