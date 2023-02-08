#include "Matrix/matrix.h"

int main() {

    Matrix A = std::vector<std::vector<double>>({{1,2},{4,5}});
    Matrix B = std::vector<std::vector<double>>({{7,8},{9,1}});

    std::cout << "Matrix One:\n";
    A.Print();
    std::cout << "\nMatrix Two:\n";
    B.Print();

    Matrix result = A * B;
    std::cout << "\nResult of matrices:\n";
    result.Print();

    return 0;
}
