#include <bits/stdc++.h>
using namespace std;
double a, b, l;
double func(double x)
{
    return a * sin(x) + b * cos(x) - l * sin(x) * cos(x);
}
int main()
{
    double w, theta, lef = 0, rig = acos(-1.0) / 2, esp = 1e-8;
    bool f = true;
    cin >> a >> b >> l;
    while (lef + esp <= rig)
    {
        double m1 = lef + (rig - lef) / 3, m2 = lef + 2 * (rig - lef) / 3;
        double f1 = func(m1), f2 = func(m2);
        if (f1 < f2)
        {
            rig = m2;
        }
        else
        {
            lef = m1;
        }
        if (f1 < 0)
        {
            f = false;
            break;
        }
    }
    if (l <= max(a, b))
    {
        w = l;
        f = true;
    }
    if (f)
        printf("%.7lf\n", l <= max(a, b) ? min(l, min(a, b)) : func(lef));
    else
        cout << "My poor head =(\n";
    // system("pause");
    return 0;
}
