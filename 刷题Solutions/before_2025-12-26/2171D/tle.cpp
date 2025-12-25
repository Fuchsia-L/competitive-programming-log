#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

vector<int> a, book, chi;
int ans;
int find(int x)
{
    if (book[x] == x)
        return x;
    return find(book[x]);
}
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return;
    if (chi[x] < chi[y])
        swap(x, y);
    book[y] = x;
    chi[x] += chi[y];
    ans = max(ans, chi[x]);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ans = 0;
        a.resize(n + 2);
        book.resize(n + 2);
        chi.resize(n + 2);
        bool f = true;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            book[i] = i;
            chi[i] = 1;
        }
        queue<int> left;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (a[i] < a[j])
                    unite(i, j);
            }
        }
        if (ans == n)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}