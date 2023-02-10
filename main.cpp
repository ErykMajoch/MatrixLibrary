#include "Matrix/matrix.h"

int main() {

    Matrix A = std::vector<std::vector<double>>{{1,-2,1},{2,1,3}};
    Matrix B = std::vector<std::vector<double>>{{2,1},{3,2},{1,1}};
    std::vector<std::vector<double>> C = {{1,-2,1},{2,1,3}};

    std::cout << "Matrix A\n";
    A.Print();

    std::cout << "\nMatrix B\n";
    B.Print();

    Matrix R = A * B;
    std::cout << "\nAB:\n";
    R.Print();

    if (A == C) {
        std::cout << "A and C are the same!\n";
    }

    return 0;
}
