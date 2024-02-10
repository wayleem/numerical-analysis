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

    if ((*f)(a) * (*f)(b) >= 0) {
        printf("Bisection method fails.\n");
        return -1; 
    }

    mid = a;

    while ((b - a) >= tol) {
        mid = (a + b) / 2;

        if ((*f)(mid) == 0.0) {
            break;
        } else if ((*f)(mid) * (*f)(a) < 0) {
            b = mid;
        } else {
            a = mid;
        }

        steps++;
    }

    printf("The root is approximately %.5f found in %d steps.\n", mid, steps);
    return mid;
}
