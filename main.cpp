#include "Matrix/matrix.h"

int main() {

    Matrix A = std::vector<std::vector<double>>{{1,1,2},{2,1,3},{1,4,2}};
    Matrix B = std::vector<std::vector<double>>{{3},{1},{2}};

    std::cout << "Matrix A\n";
    A.Print();

    std::cout << "\nMatrix B\n";
    B.Print();

    Matrix R = A * B;
    std::cout << "\nAB:\n";
    R.Print();

    return 0;
}
