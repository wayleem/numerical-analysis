#include <stdio.h>
#include <math.h>
#include "test-functions.h"

double secantMethod(double x0, double x1, double tol, int maxIterations, double (*f)(double)) {
    double x2, fx0, fx1;
    int iteration = 0;

    fx0 = (*f)(x0);
    fx1 = (*f)(x1);

    while (iteration < maxIterations) {
        if (fabs(fx1 - fx0) < tol) {
            printf("Warning: Difference between function values is too small.\n");
            return x1;
        }

        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);

        if (fabs(x2 - x1) < tol) {
            printf("Approximated root: %f\n", x2);
            return x2;
        }

        x0 = x1;
        fx0 = fx1;
        x1 = x2;
        fx1 = (*f)(x2);

        iteration++;
    }

    printf("Maximum iterations reached (Last approximation: %f)\n", x2);
    return x2;
}

int main() {
    double root = secantMethod(1.0, 2.0, 0.0001, 100, f);
    return 0;
}
