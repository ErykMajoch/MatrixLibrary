#include "Matrix/matrix.h"

int main() {

    Matrix m1 = Matrix(2, 5, 2.1);
    Matrix m2 = Matrix(2, 5, 2.9);

    std::cout << "Matrix One:\n";
    m1.Print();
    std::cout << "\nMatrix Two:\n";
    m2.Print();

    Matrix m3 = m1 - m2;
    std::cout << "\nResult of matrices:\n";
    m3.Print();

    // std::cout << "Original Matrix\n";
    // Matrix m = Matrix(3, 3, 4.32);
    // m.Print();

    // std::cout << "\nAddition";
    // m = m + 3.3;
    // std::cout << "\n";
    // m.Print();

    // std::cout << "\nInline Addition";
    // m += 1.32;
    // std::cout << "\n";
    // m.Print();

    // std::cout << "\nSubtraction";
    // m = m - m[1,1];
    // std::cout << "\n";
    // m.Print();

    // std::cout << "\nInline Substraction";
    // m -= 3.1;
    // std::cout << "\n";
    // m.Print();

    // std::cout << "\nMultiplication";
    // m = m * -1;
    // std::cout << "\n";
    // m.Print();

    // std::cout << "\nInline Multiplication";
    // m *= 2;
    // std::cout << "\n";
    // m.Print();

    // std::cout << "\nDivision";
    // m = m / 6.2;
    // std::cout << "\n";
    // m.Print();

    // std::cout << "\nInline Division";
    // m /= 0.5;
    // std::cout << "\n";
    // m.Print();

    return 0;
}
