#include <iostream>
using namespace std;
long long sum, maxn, num;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> maxn >> num >> sum;
        long long maxans = 0, minans = 0;
        for (long long i = 0; i < num; i++)
        {
            maxans += maxn - i;
            minans += i + 1;
        }
        if (maxans < sum || minans > sum)
        {
            cout << "No\n";
        }
        else
            cout << "Yes\n";
    }
    return 0;
}