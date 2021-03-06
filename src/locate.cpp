#include "locate.h"

void
locate(double x, double *xx, int *j, int n) {
//    From Numerical recipes:
//    -----------------------
//    Given an array XX of length N, and a given value of X, returns a
//    value of J such that X is between XX(J) and XX(J+1).  XX must be
//    monotonic, either increasing or decreasing. J=0 or J=N is
//     returned to indicate that X is out of range.

    unsigned long ju, jm, jl;
    int ascnd;
    jl = 0;
    ju = n + 1;
    ascnd = (xx[n] > xx[1]);
    while (ju - jl > 1) {
        jm = (ju + jl) >> 1;
        if (x > xx[jm] == ascnd)
            jl = jm;
        else
            ju = jm;
    }
    *j = jl;
}
