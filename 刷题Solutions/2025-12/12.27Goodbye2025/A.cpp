#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int c = 0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == 'Y')
                c++;
            if (c >= 2)
            {
                cout << "No\n";
                break;
            }
        }
        if (c < 2)
        {
            cout << "Yes\n";
        }
    }
    return 0;
}