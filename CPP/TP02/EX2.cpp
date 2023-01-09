#include <iostream>

template <typename num>

num powiter (num x, unsigned n) {
    for (unsigned i = 0; i < n-1; i++) {
        x *= x;
    }
    return x;
}

template <typename num>

num powrec (num x, unsigned n) {
    if (n == 0) return 1;
    if (n%2 == 1) return x*powrec(powrec(x, (n-1)/2), 2);
    return powrec(powrec(x, (n-1)/2), 2);
}
