// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// string final[2009];
// bool beginn[2009][2009] = {0};
// int main()
// {

//     int n, ans = 0;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> final[i];
//         final[i] = " " + final[i];
//     }

//     int l = 0;
//     while (l <= n / 2 + n % 2)
//     {
//         cout << "LAYER  " << l << " ------------\n"; ///////////
//         for (int y = n - l; y > 1 + l; y--)
//         {
//             if (beginn[1 + l][y] != final[1 + l][y] - '0')
//             {
//                 ans++;
//                 for (int yi = y; yi >= l + 1; yi--)
//                 {
//                     beginn[l + 1][yi] = !beginn[l + 1][yi];
//                 }
//                 for (int xi = 1 + l; xi <= y; xi++)
//                 {
//                     beginn[xi][y] = !beginn[xi][y];
//                 }
//             }
//             //
//             cout << 1 + l << " " << y << ", ans = " << ans << "\n";
//             for (int ii = 1; ii <= n; ii++)
//             {
//                 for (int j = 1; j <= n; j++)
//                 {
//                     cout << beginn[ii][j] ? 1 : 0;
//                 }
//                 cout << "\n";
//             }
//             cout << "\n\n";
//             //
//         }
//         for (int x = 1 + l; x < n - 1; x++)
//         {
//             if (beginn[x][n - 1] != final[x][n - l] - '0')
//             {
//                 ans++;
//             }
//             for (int xi = x; xi <= n - 1; xi++)
//             {
//                 beginn[xi][n - l] = !beginn[xi][n - 1];
//             }
//             for (int yi = n - l; yi >= x; yi--)
//             {
//                 beginn[x][yi] = !beginn[x][yi];
//             }
//             //
//             cout << ans << "\n";
//             cout << x << " " << n - 1 << "\n";
//             for (int ii = 1; ii <= n; ii++)
//             {
//                 for (int j = 1; j <= n; j++)
//                 {
//                     cout << beginn[ii][j] ? 1 : 0;
//                 }
//                 cout << "\n";
//             }
//             cout << "\n\n";
//             //
//         }
//         for (int x = n - l; x >= l + 1; x--)
//         {
//             if (beginn[x][1 + l] != final[x][1 + l] - '0')
//             {
//                 ans++;
//             }
//             for (int xi = x; xi >= 1 + l; xi--)
//             {
//                 beginn[xi][l + 1] = !beginn[xi][l + 1];
//             }
//             for (int yi = 1 + l; yi <= x; yi++)
//             {
//                 beginn[x][yi] = !beginn[x][yi];
//             }
//             //
//             cout << ans << "\n";
//             cout << x << " " << 1 + l << "\n";
//             for (int ii = 1; ii <= n; ii++)
//             {
//                 for (int j = 1; j <= n; j++)
//                 {
//                     cout << beginn[ii][j] ? 1 : 0;
//                 }
//                 cout << "\n";
//             }
//             cout << "\n\n";
//             //
//         }

//         for (int y = l + 1 + 1; y <= n - l; y++)
//         {
//             if (beginn[n - l][y] != final[n - l][y] - '0')
//             {
//                 ans++;
//                 for (int yi = y; yi <= n - l; yi++)
//                 {
//                     beginn[n - l][yi] = !beginn[n - l][yi];
//                 }
//                 for (int xi = n - l - 1; xi >= y; xi--)
//                 {
//                     beginn[xi][y] = !beginn[xi][y];
//                 }
//             }
//             //
//             cout << ans << "\n";
//             cout << n - l << " " << y << "\n";
//             for (int ii = 1; ii <= n; ii++)
//             {
//                 for (int j = 1; j <= n; j++)
//                 {
//                     cout << beginn[ii][j] ? 1 : 0;
//                 }
//                 cout << "\n";
//             }
//             cout << "\n\n";
//             //
//         }

//         l++;
//     }
//     cout << ans << "\n";
//     return 0;
// }

// TLE
//  #include <bits/stdc++.h>
//  using namespace std;
//  using ll = long long;
//  string s[2009], b[2009];
//  int ans = 0;
//  bool if_same(int x, int y)
//  {
//      return s[x][y] == b[x][y];
//  }
//  void fill(int x, int y)
//  {
//      ans++;
//      if (y >= x)
//      {
//          for (int i = y; i >= x; i--)
//          {
//              b[x][i] = b[x][i] == '0' ? '1' : '0';
//          }
//          for (int i = x + 1; i <= y; i++)
//          {
//              b[i][y] = b[i][y] == '0' ? '1' : '0';
//          }
//      }
//      else
//      {
//          for (int i = y; i <= x; i++)
//          {
//              b[x][i] = b[x][i] == '0' ? '1' : '0';
//          }
//          for (int i = x - 1; i >= y; i--)
//          {
//              b[i][y] = b[i][y] == '0' ? '1' : '0';
//          }
//      }
//  }
//  int main()
//  {
//      int n;
//      cin >> n;
//      string c;
//      for (int i = 1; i <= n + 4; i++)
//          c += '0';
//      for (int i = 1; i <= n; i++)
//      {
//          cin >> s[i];
//          s[i] = ' ' + s[i] + "  ";
//          b[i] = c;
//      }
//      int l = n / 2;
//      for (int i = 0; i < l; i++)
//      {
//          int x1 = 1 + i, y1 = n - i;
//          int x2 = n - i, y2 = i + 1;
//          if (!if_same(x1, y1))
//          {
//              fill(x1, y1);
//          }
//          if (!if_same(x2, y2))
//          {
//              fill(x2, y2);
//          }
//          for (int d = 1; x1 + d != y1; d++)
//          {
//              if (!if_same(x1 + d, y1))
//              {
//                  fill(x1 + d, y1);
//              }
//              if (!if_same(x1, y1 - d))
//              {
//                  fill(x1, y1 - d);
//              }
//              if (!if_same(x2 - d, y2))
//              {
//                  fill(x2 - d, y2);
//              }
//              if (!if_same(x2, y2 + d))
//              {
//                  fill(x2, y2 + d);
//              }
//          }
//      }
//      for (int i = 1; i <= n; i++)
//      {
//          if (!if_same(i, i))
//          {
//              fill(i, i);
//          }
//      }
//      cout << ans << "\n";
//      return 0;
//  }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s[2009];
bool b1[2009][2], b2[2009][2];
int ans = 0;
bool if_same(int x, int y)
{
    if (x > y)
        return bool(s[x][y] - '0') == (b1[x][0] xor b1[y][1]);
    if (x == y)
        return bool(s[x][y] - '0') == (b1[x][0] xor b1[y][1] xor b2[x][0] xor b2[y][1]);
    return bool(s[x][y] - '0') == (b2[x][0] xor b2[y][1]);
}
void fill(int x, int y)
{
    // cout << x << " " << y << "\n\n";
    ans++;
    if (x >= y)
    {
        b1[x][0] = !b1[x][0];
        b1[y][1] = !b1[y][1];
    }
    else
    {
        b2[x][0] = !b2[x][0];
        b2[y][1] = !b2[y][1];
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    int l = n / 2;
    for (int i = 0; i < l; i++)
    {
        int x1 = 1 + i, y1 = n - i;
        int x2 = n - i, y2 = i + 1;
        if (!if_same(x1, y1))
        {
            fill(x1, y1);
        }
        if (!if_same(x2, y2))
        {
            fill(x2, y2);
        }
        for (int d = 1; x1 + d != y1; d++)
        {
            if (!if_same(x1 + d, y1))
            {
                fill(x1 + d, y1);
            }
            if (!if_same(x1, y1 - d))
            {
                fill(x1, y1 - d);
            }
            if (!if_same(x2 - d, y2))
            {
                fill(x2 - d, y2);
            }
            if (!if_same(x2, y2 + d))
            {
                fill(x2, y2 + d);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!if_same(i, i))
        {
            fill(i, i);
        }
    }
    cout << ans << "\n";
    return 0;
}