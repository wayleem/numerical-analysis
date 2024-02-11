#include <stdio.h>
#include <math.h>
#include "test-functions.h"

double fixedPointIteration(double x0, double tol, int maxIterations, double (*f)(double)) {
    double x1;
    int iteration = 0;

    while (iteration < maxIterations) {
        x1 = (*f)(x0); 

        if (fabs(x1 - x0) < tol) {
            printf("Convergence reached (%d iterations)\n", iteration);
            return x1;
        }

        x0 = x1; 
        iteration++;
    }

    printf("Maximum iterations reached (Last approximation: %f)\n", x1);
    return x1;
}

int main() {
    double initialGuess = 0.5; 
    double tolerance = 0.0001;
    int maxIterations = 100;
    double root = fixedPointIteration(initialGuess, tolerance, maxIterations, g);

    printf("Approximated root: %f\n", root);
    return 0;
}
