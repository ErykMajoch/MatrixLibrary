#include "Matrix/matrix.h"

int main() {

    Matrix A = std::vector<std::vector<double>>({{1,2},{4,5}});
    Matrix I = A.GetIdentityMatrix();

    std::cout << "Matrix A\n";
    A.Print();

    std::cout << "\nIdentity Matrix of A\n";
    I.Print();

    return 0;
}
