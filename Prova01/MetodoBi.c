#include <stdio.h>
#include <math.h>
//nessa eu entedi errado e tentei fazer uma bisseccao para cada formula. O que me atrapalhou mais do que deveria.

#define EPS 1e-6 //limite maximo

double f1(double x) { return x*x*x - x - 2; } //na prova eu usei o pow()
double f2(double x) { return cos(x) - x; } //
double f3(double x) { return exp(-x) - x; }//acredito que tambem usei o pow() na prova
double f4(double x) { return x*x - 4; }
double f5(double x) { return log(x) + x - 2; }

double bisseccao(double (*f)(double), double l, double r)
{
    double m;

    while ((r - l) > EPS)
    {
        m = (l + r) / 2;

        if (f(m) == 0.0)
            return m;

        if (f(l) * f(m) < 0)
            r = m;
        else
            l = m;
    }

    return (l + r) / 2;
}

int main()
{
    printf("%.6f\n", bisseccao(f1, 1, 2));
    printf("%.6f\n", bisseccao(f2, 0, 1));
    printf("%.6f\n", bisseccao(f3, 0, 1));
    printf("%.6f\n", bisseccao(f4, 0, 3));
    printf("%.6f\n", bisseccao(f5, 1, 2));

    return 0;
}