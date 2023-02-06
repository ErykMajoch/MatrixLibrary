#include "Matrix/matrix.h"

int main() {
    Matrix m = Matrix(5, 1, 4.32);
    m.Print();
    std::cout << m[2] << "\n";
    return 0;
}
