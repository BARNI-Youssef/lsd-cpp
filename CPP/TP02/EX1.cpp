#include <iostream>
#include <ostream>

template <typename t>

t multiply (t x, int y) {
    t final;
    final = x*y;
    return final;
}

int main (int argc, char *argv[]) {
    double x =  3.45;
    int y = 2;
    int z = 3;
    std::cout << multiply(x, y) << "\n" << multiply(z, y) << std::endl;
    return 0;
}
