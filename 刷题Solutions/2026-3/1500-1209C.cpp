#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int len;
        string s, astr;
        cin >> len >> s;
        astr = s;
        s = " " + s;
        int ans = -1;
        for (int idx = 0; idx <= 9; idx++)
        {
            int f1 = 0, f2 = 0, fl = 1;
            for (int i = 1; i <= len && fl; i++)
            {
                int now = s[i] - '0';
                if (now == idx && now >= f2)
                {
                    f2 = now;
                    astr[i - 1] = '2';
                    continue;
                }
                if (now <= idx)
                {
                    if (now >= f1)
                    {
                        astr[i - 1] = '1';
                        f1 = now;
                        continue;
                    }
                    fl = 0;
                }
                if (now >= idx)
                {
                    if (now >= f2)
                    {
                        f2 = now;
                        astr[i - 1] = '2';
                    }
                    else
                    {
                        fl = 0;
                    }
                }
            }
            if (fl)
            {
                ans = fl;
                break;
            }
        }
        if (ans == -1)
        {
            cout << "-";
        }
        else
        {
            cout << astr;
        }
        cout << "\n";
    }
    return 0;
}

/*
 ans = s;
        if (len == 1)
        {
            cout << "1\n\n\n";
            continue;
        }
        queue<int> flag;
        for (int i = 1; i < len; i++)
        {
            if (s[i] > s[i + 1])
            {
                flag.push(i);
                ans[i] = '2';
                ans[i + 1] = '1';
            }
        }

        int left_1 = 0, left_2 = 0, right_1 = INT_MAX, right_2 = INT_MAX;
        int f = -1;
        if (!flag.empty())
        {
            f = flag.front();
            flag.pop();
            right_1 = s[f + 1];
            right_2 = s[f];
        }
        bool t = true;
        for (int i = 1; i <= len; i++)
        {
            cout << i << "-- 1(" << left_1 - '0' << " " << right_1 - '0' << ") 2(" << left_2 - '0' << " " << right_2 - '0' << ")\n"; ////////////////////////////
            if (i == f)
            {
                left_1 = right_1;
                left_2 = right_2;
                if (!flag.empty())
                {
                    f = flag.front();
                    flag.pop();
                    right_1 = s[i + 1];
                    right_2 = s[i];
                }
                else
                {
                    right_1 = right_2 = INT_MAX;
                }
                continue;
            }
            if (s[i] >= left_2 && s[i] <= right_2)
            {
                ans[i] = '2';
                left_2 = s[i];
            }
            else if (s[i] >= left_1 && s[i] <= right_1)
            {
                ans[i] = '1';
                left_1 = s[i];
            }
            else
            {
                cout << "-\n\n\n";
                t = false;
                break;
            }
        }
        if (t)
        {
            for (int i = 1; i <= len; i++)
            {
                cout << ans[i];
            }
            cout << "\n\n\n";
        }
        ////////////////
        cout << "\n----------\n";
*/