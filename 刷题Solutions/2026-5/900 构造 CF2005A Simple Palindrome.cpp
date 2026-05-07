#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    char a[9] = {'a', 'e', 'i', 'o', 'u'};
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        cin >> n;
        while (n--)
        {
            cout << a[cnt];
            cnt++;
            cnt %= 5;
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}