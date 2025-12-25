#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    while (n--)
    {
        cin >> s;
        int l = 0;
        l = s.size();
        if (l > 10)
        {
            cout << s[0] << l - 2 << s[l - 1] << endl;
        }
        else
            cout << s << endl;
    }
    return 0;
}