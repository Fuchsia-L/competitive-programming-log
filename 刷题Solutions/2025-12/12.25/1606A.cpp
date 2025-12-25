#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char s[102];
        int l;
        cin >> s;
        l = strlen(s);
        if (s[0] != s[l - 1]) // 只要首尾相同就可以符合条件
            s[0] = s[l - 1];
        cout << s << endl;
    }
    return 0;
}