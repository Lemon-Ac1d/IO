#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

double a, b, c, d;
double f(double x)
{
    return a*x*x*x + b * x * x + c * x + d;
}

int main()
{

    cin >> a >> b >> c >> d;

    double x1, x2, mid;

    for (double i = -100; i <= 100; i++)
    {
        x1 = i;
        x2 = i + 1;
        if (f(x1) == 0)
            printf("%.2lf ", i);
        if (f(x1) * f(x2) < 0)
        {
            while (x2 - x1 >= 0.001)
            {
                mid = (x1 + x2) / 2;
                if (f(x1) * f(mid) <= 0)
                    x2 = mid;
                else
                    x1 = mid;
            }
            printf("%.2lf ", x1);
        }
    }

    return 0;
}