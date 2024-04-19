#include <stdio.h>
#include "test-functions.h"

double bisection(double a, double b, double tol, double (*f)(double));

int main() {
    double root;
    double a = 0.0, b = 1.0, tol = 0.00005;

    root = bisection(a, b, tol, f);

    return 0;
}

double bisection(double a, double b, double tol, double (*f)(double)) {
    double mid;
    int steps = 0;
    int flops = 0; 

    double fa = (*f)(a);
    double fb = (*f)(b);
    flops += 28; // 2x f(x)
  
    if (fa * fb >= 0) {
        printf("Bisection method fails.\n");
        printf("Floating-point operations: %d\n", flops);
        return -1;
    }

    mid = a;

    while ((b - a) >= tol) {
        mid = (a + b) / 2;
        flops += 2; // 1 addition and 1 division

        double fmid = (*f)(mid);
        flops += 14; // f(x)

        if (fmid == 0.0) {
            break;
        } else if (fmid * fa < 0) {
            b = mid;
            fb = fmid;
        } else {
            a = mid;
            fa = fmid;
        }
        flops++; // 1 multiplication

        steps++;
    }

    printf("The root is approximately %.5f found in %d steps. (flops: %d)\n", mid, steps, flops);
    return mid;
}
