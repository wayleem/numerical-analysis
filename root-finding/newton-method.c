#include <stdio.h>
#include <math.h>
#include "test-functions.h"

// Newton's method function prototype declaration
double newtonsMethod(double x0, double tol, double (*f)(double), double (*f_prime)(double));

int main() {
    double root;
    double x0 = 0.4, tol = 0.00005;

    root = newtonsMethod(x0, tol, f, f_prime);

    return 0;
}

// Define Newton's method
double newtonsMethod(double x0, double tol, double (*f)(double), double (*f_prime)(double)) {
    double x1;
    int steps = 0;

    while (1) {
        double fx = (*f)(x0);
        double fpx = (*f_prime)(x0);
        if (fabs(fpx) < tol) {
            printf("Warning: Derivative is close to zero. Solution could be inaccurate.\n");
            return x0;
        }

        // Newton's method formula
        x1 = x0 - fx / fpx;

        // Check for convergence
        if (fabs(x1 - x0) < tol) {
            break;
        }

        x0 = x1;
        steps++;
    }

    printf("The root is approximately %.5f found in %d steps.\n", x1, steps);
    return x1;
}
