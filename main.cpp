#include "Matrix/matrix.h"

int main() {

    Matrix A = std::vector<std::vector<double>>{{1,1,2},{2,1,3},{1,4,2}};
    Matrix B = std::vector<std::vector<double>>{{3},{1},{2}};

    std::cout << "Matrix A\n";
    A.Print();

    std::cout << "\nMatrix B\n";
    B.Print();

    Matrix X = std::vector<std::vector<double>>{{4,7}, {2,6}};
    std::cout << "\nInverse of X:\n";
    X.Inverse().Print();
    std::cout << "\n";
    Matrix Y = std::vector<std::vector<double>>{{1,2},{3,4},{5,6}};
    Y.Print();
    std::cout << "\n";
    Y.Transpose();
    Y.Print();




    return 0;
}
