#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, b, g;
        string s = "012";
        int idx = 3;
        cin >> r >> g >> b;
        while (r || g || b)
        {
            // cout << " try-->";
            if ((r >= g) && (r >= b) && (r != 0) && ('R' != s[idx - 1]) && ('R' != s[idx - 3]))
            {

                s = s + 'R';
                idx++;
                r--;
                cout << "R";
            }
            else if ((g >= b) && (g != 0) && ('G' != s[idx - 1]) && ('G' != s[idx - 3]))
            {

                s = s + 'G';
                idx++;
                g--;
                cout << "G";
            }
            else if (b && ('B' != s[idx - 1]) && ('B' != s[idx - 3]))
            {
                s = s + 'B';
                idx++;
                b--;
                cout << "B";
            }
            else
            {
                // cout << "\nend with r= " << r << " b= " << b << " g= " << g << "\n";

                break;
            }
        }
        cout << "\n\n";
    }
    return 0;
}