#include <iostream>
using namespace std;
int main()
{
    int n, a[2003] = {0}, maxline = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != -1)
        {
            int now = a[i], line = 2;
            while (a[now] != -1)
            {
                now = a[now];
                line++;
            }
            maxline = max(maxline, line);
        }
    }
    cout << maxline << "\n";
    return 0;
}