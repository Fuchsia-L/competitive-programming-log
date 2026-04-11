#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        long long sum = 0;
        cin >> a >> b;
        sum = (a + a + b - 1) * b / 2;
        vector<long long> fa;
        vector<pair<long long, long long>> book;
        for (long long i = 1; i <= sqrt(sum); i++)
        {
            if (sum % i == 0)
            {
                fa.push_back(i);
                if (i != sum / i)
                    fa.push_back(sum / i);
            }
        }
        for (long long i = 1; i <= b - 1; i++)
        {
            long long maxx, minn;
            minn = (a + a + i - 1) * i / 2;
            maxx = (a + b - 1 + a + b - i) * i / 2;
            book.push_back({minn, maxx});
            // cout << minn << " " << maxx << " ";
        }
        sort(fa.begin(), fa.end(), greater());
        long long k = 0;
        int f = 1;
        for (long long i = 0; f && (fa.begin() + i != fa.end()); i++)
        {
            k = fa[i];
            // cout << "check k = " << k << "\n";
            for (long long j = 0; j <= b - 2 && f; j++)
            {
                // cout << k * idx << "-- j = " << j << "\n";
                if (book[j].second % k != book[j].first % k)
                {
                    cout << k << "\n";
                    f = 0;
                }
            }
        }
        if (f)
            cout << "1\n";
    }
    return 0;
}