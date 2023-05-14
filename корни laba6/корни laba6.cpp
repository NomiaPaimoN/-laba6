#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return sin(x) * sin(x) - x / 5 - 1;
}

double secant_method(double a, double b, double eps) {
    double fa = f(a);
    double fb = f(b);
    double x, fx;
    int iter = 0;
    while (abs(b - a) >= eps) {
        x = b - fb * (b - a) / (fb - fa);
        fx = f(x);
        a = b;
        b = x;
        fa = fb;
        fb = fx;
        iter++;
    }
    return x;
}

int main() {
    double a = -4, b = 0;
    double eps = 0.0001;
    double x1 = secant_method(a, -3.5, eps);
    double x2 = secant_method(-3.5, -1.5, eps);
    double x3 = secant_method(-1.5, 0, eps);
    cout << "Roots: " << x1 << " " << x2 << " " << x3 << endl;
    return 0;
}
