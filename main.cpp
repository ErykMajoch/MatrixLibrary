#include "Matrix/matrix.h"

int main() {

    Matrix A = std::vector<std::vector<double>>{{1,1,2},{2,1,3},{1,4,2}};
    Matrix B = std::vector<std::vector<double>>{{3},{1},{2}};

    std::cout << "Matrix A\n";
    A.Print();

    std::cout << "\nMatrix B\n";
    B.Print();

    // Matrix R = A * B;
    // std::cout << "\nAB:\n";
    // R.Print();

    Matrix X = std::vector<std::vector<double>>{{4,7}, {2,6}};
    std::cout << "\nInverse of X:\n";
    X.Inverse().Print();

    Matrix Y = std::vector<std::vector<double>>{{13,26}, {39,13}};
    Matrix Z = std::vector<std::vector<double>>{{7,4}, {2,3}};

    Matrix Prod = Y / Z;
    Prod.Print();


    return 0;
}
