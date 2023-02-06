#include "Matrix/matrix.h"

int main() {
    Matrix m = Matrix(2, 5, 4.32);
    m.Print();
    std::cout << m[1, 1] << "\n";
    return 0;
}
