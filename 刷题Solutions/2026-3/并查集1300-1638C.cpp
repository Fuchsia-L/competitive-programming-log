#include <bits/stdc++.h>
using namespace std;
vector<int> book;
int find(int x)
{
    if (book[x] == x)
        return x;
    return book[x] = find(book[x]);
}
void bound(int x, int y)
{
    book[find(x)] = find(y);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> maxnum, pos;
        cin >> n;
        for (int i = 1, c; i <= n; i++)
        {
            cin >> c;
            book.resize(n + 1);
            book[i] = i;
            auto it = upper_bound(maxnum.begin(), maxnum.end(), c);
            if (it == maxnum.end())
            {
                maxnum.push_back(c);
                pos.push_back(i);
            }
            else
            {
                auto its = it;
                while (its != maxnum.end())
                {
                    // cout << "will bound " << i << " and " << pos[it - maxnum.begin()] << "\n";
                    bound(i, pos[its - maxnum.begin()]);
                    its++;
                }
                maxnum.erase(it, maxnum.end() - 1);
                pos.erase(pos.begin() + (it - maxnum.begin()), pos.end() - 1);
            }
        }
        int cnt = 0;
        // cout << "strat cnt\n";
        for (int i = 1; i <= n; i++)
        {
            // cout << book[i] << " ";
            if (book[i] == i)
                cnt++;
        }
        cout
            << cnt << "\n";
    }

    return 0;
}