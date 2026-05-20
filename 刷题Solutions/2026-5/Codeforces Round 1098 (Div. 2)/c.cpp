#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, aa;
        int b[11] = {0};
        int n;
        cin >> a >> n;
        aa = a;
        for (int i = 1; i <= n; i++)
        {
            int c;
            cin >> c;
            b[c]++;
        }
        bool f = 0, div = 0;
        ll maxx = 0, minn = 0;
        int maxid, minid;
        for (int i = 0; i <= 9; i++)
        {
            if (b[i] != 0)
            {
                minid = i;
                break;
            }
        }
        for (int i = 9; i >= 0; i--)
        {
            if (b[i] != 0)
            {
                maxid = i;
                break;
            }
        }

        ll m = 1e17, k2 = 0, k3 = 0;
        k3 *= 10;
        k3 += minid;
        for (int i = 17; i >= 0; i--, m /= 10)
        {

            // cout << "max = " << maxx << " , min=" << minn << "\n";
            int idx = a / m;
            a %= m;
            // cout << "idx = " << idx << " \n";
            if (idx == 0 && f == 0)
            {
                continue;
            }
            f = 1;
            k3 *= 10;
            k3 += minid;
            if (i != 0)
            {
                k2 *= 10;
                k2 += maxid;
            }
            if (div == 0)
            {
                if (b[idx] != 0)
                {
                    maxx += m * idx;
                    minn += m * idx;
                    continue;
                }
                div = 1;
                for (int ii = idx; ii >= 0; ii--)
                {
                    if (b[ii] != 0)
                    {
                        // cout << "ii max=" << ii << "\n"; //////////////
                        minn += ii * m;
                        break;
                    }
                    if (ii == 0)
                    {
                        if (minn == 0)
                        {
                            minn = -1;
                        }
                        else
                        {
                            int last = (m < 10) ? 0 : minn % (m / 10);
                            for (int j = last; j >= 0; j--)
                            {
                                if (b[j] != 0)
                                {
                                    minn -= last * (m / 10);
                                    minn += j * (m / 10);
                                    break;
                                }
                                if (j == 0)
                                {
                                    minn = -1;
                                }
                            }
                        }
                        if (minn != -1)
                        {
                            minn += m * maxid;
                        }
                    }
                }

                for (int ii = idx; ii <= 9; ii++)
                {
                    if (b[ii] != 0)
                    {
                        maxx += ii * m;
                        // cout << "ii min=" << ii << "\n"; //////////////
                        break;
                    }
                    if (ii == 9)
                    {
                        if (maxx == 0)
                        {
                            maxx = -1;
                        }
                        else
                        {
                            int last = (m < 10) ? 0 : maxx % (m / 10);
                            for (int j = last; j <= 9; j++)
                            {
                                if (b[j] != 0)
                                {
                                    maxx -= last * (m / 10);
                                    maxx += j * (m / 10);
                                    break;
                                }
                                if (j == 9)
                                {
                                    maxx = -1;
                                }
                            }
                            if (maxx != -1)
                            {
                                maxx += m * minid;
                            }
                        }
                    }
                }
            }
            else
            {
                if (minn != -1)
                {
                    minn += m * maxid;
                }
                if (maxx != -1)
                {
                    maxx += m * minid;
                }
            }
        }
        ll ans = LONG_LONG_MAX;
        if (aa <= 9)
            k2 = k3;
        // cout << k2 << " " << k3 << " max = " << maxx << " min = " << minn << "\n--";
        if (maxx != -1)
        {
            ans = abs(aa - maxx);
        }
        if (minn != -1)
        {
            ans = min(ans, abs(aa - minn));
        }
        ans = min(ans, abs(aa - k2));
        ans = min(ans, abs(aa - k3));

        cout << ans << "\n";
    }

    // system("pause");
    return 0;
}
