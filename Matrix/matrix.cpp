#include "matrix.h"

// ################
// # Constructors #
// ################ 


// Default Matrix::Matrix constructor
Matrix::Matrix() = default;

// Matrix::Matrix constructor with size parameters
// Initialised all fields to 0.0
Matrix::Matrix(unsigned rows, unsigned columns) {
    m_RowNumber = rows;
    m_ColumnNumber = columns;
    m_Matrix.resize(columns);
    for (unsigned i = 0; i < columns; i++) {
        m_Matrix[i].resize(rows, 0.0);
    }
}

// Matrix::Matrix constructor with size parameters
// Initialised all fields with an initial value
Matrix::Matrix(unsigned rows, unsigned columns, double initial) {
    m_RowNumber = rows;
    m_ColumnNumber = columns;
    m_Matrix.resize(columns);
    for (unsigned i = 0; i < columns; i++) {
        m_Matrix[i].resize(rows, initial);
    }
}

// Matrix::Matrix constructor from a 2D vector
Matrix::Matrix(std::vector<std::vector<double>> Other) {
    m_RowNumber = Other[0].size();
    m_ColumnNumber = Other.size();
    m_Matrix.resize(m_ColumnNumber);
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        m_Matrix[i].resize(m_RowNumber);
        for (unsigned j = 0; j < m_RowNumber; j++) {
            m_Matrix[i][j] = Other[i][j];
        }
    }
}

// #####################
// # Access Operations #
// #####################
double& Matrix::operator[](const unsigned &row, const unsigned &column) {
    if (row > m_RowNumber || column > m_ColumnNumber) {
        throw std::invalid_argument("Arguments out of range");
    }
    return this->m_Matrix[column][row];
}

double& Matrix::operator[](const unsigned &index) {
    if (m_RowNumber == 1 && m_ColumnNumber > index) {
        return m_Matrix[index][0];
    } else if (m_ColumnNumber == 1 && m_RowNumber > index) {
        return m_Matrix[0][index];
    } else {
        throw std::invalid_argument("Matrix must be unidimentional to access this method");
    }
}

// #####################
// # Matrix Operations #
// #####################

// Normal Opeartions
Matrix Matrix::operator+(Matrix &Other) {
    Matrix result = Matrix(m_RowNumber, m_ColumnNumber, 0.0);

    if (m_RowNumber == Other.GetRows() && m_ColumnNumber == Other.GetColumns()) {
        for (unsigned i = 0; i < m_ColumnNumber; i++) {
            for (unsigned j = 0; j < m_RowNumber; j++) {
                result[j,i] = this->m_Matrix[i][j] + Other[j,i];
            }
        }
    } else {
        throw std::invalid_argument("The matrices must be the same size");
    }

    return result;

}

Matrix Matrix::operator-(Matrix &Other) {
    Matrix result = Matrix(m_RowNumber, m_ColumnNumber, 0.0);

    if (m_RowNumber == Other.GetRows() && m_ColumnNumber == Other.GetColumns()) {
        for (unsigned i = 0; i < m_ColumnNumber; i++) {
            for (unsigned j = 0; j < m_RowNumber; j++) {
                result[j,i] = this->m_Matrix[i][j] - Other[j,i];
            }
        }
    } else {
        throw std::invalid_argument("The matrices must be the same size");
    }

    return result;

}

Matrix Matrix::operator*(Matrix &Other) {

    if (m_ColumnNumber == Other.GetRows()) {

        Matrix result = Matrix(Other.GetRows(), m_ColumnNumber);

        for (unsigned i = 0; i < m_ColumnNumber; i++) {
            for (unsigned j = 0; j < Other.GetRows(); j++) {
                for (unsigned k = 0; k < m_RowNumber; k++) {
                    result[j,i] += m_Matrix[i][k] * Other[j,k];
                }
            }
        }
        return result;
    } else {
        throw std::invalid_argument("The number of columns of A must be the same as the number of rows of B");
    }

}


// #####################
// # Scalar Operations #
// #####################

// Normal Operations
Matrix Matrix::operator+(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    Matrix result = Matrix(m_RowNumber, m_ColumnNumber, 0.0);
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            result[j, i] = m_Matrix[i][j] + scalar;
        }
    }

    return result;
}

Matrix Matrix::operator-(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    Matrix result = Matrix(m_RowNumber, m_ColumnNumber, 0.0);
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            result[j,i] = this->m_Matrix[i][j] - scalar;
        }
    }

    return result;
}

Matrix Matrix::operator*(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    Matrix result = Matrix(m_RowNumber, m_ColumnNumber, 0.0);
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            result[j,i] = this->m_Matrix[i][j] * scalar;
        }
    }

    return result;
}

Matrix Matrix::operator/(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    if (scalar == 0) {
        throw std::invalid_argument("Cannot divide matrix by 0");
    }

    Matrix result = Matrix(m_RowNumber, m_ColumnNumber, 0.0);
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            result[j,i] = this->m_Matrix[i][j] / scalar;
        }
    }

    return result;
}

// Inline Operations
Matrix& Matrix::operator+=(double scalar) {

    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            this->m_Matrix[i][j] = this->m_Matrix[i][j] + scalar;
        }
    }


    return *this;
}

Matrix& Matrix::operator-=(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            this->m_Matrix[i][j] = this->m_Matrix[i][j] - scalar;
        }
    }

    return *this;
}

Matrix& Matrix::operator*=(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            this->m_Matrix[i][j] = this->m_Matrix[i][j] * scalar;
        }
    }

    return *this;
}

Matrix& Matrix::operator/=(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    if (scalar == 0) {
        throw std::invalid_argument("Cannot divide matrix by 0");
    }

    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            this->m_Matrix[i][j] = this->m_Matrix[i][j] / scalar;
        }
    }

    return *this;
}

// ###########
// # Getters #
// ###########

unsigned Matrix::GetColumns() {
    return m_ColumnNumber;
}

unsigned Matrix::GetRows() {
    return m_RowNumber;
}

IdentityMatrix Matrix::GetIdentityMatrix() {
    if (m_RowNumber != m_ColumnNumber || m_RowNumber <=0) {
        throw std::invalid_argument("Cannot create identity matrix");
    }
    IdentityMatrix I = IdentityMatrix(m_RowNumber);
    return I;
}

// #############
// # Utilities #
// ############# 

// Prints the fomrated matrix 
void Matrix::Print() const {

    // If matrix is empty, throw an error
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::out_of_range("The matrix is empty!");
    }

    for (std::vector<double> v : m_Matrix) {
        std::cout << "| ";
        for (double d : v) {
            std::cout << d << " ";
        }
        std::cout << "|\n";
    }
}

// ###################
// # Identity Matrix #
// ###################

IdentityMatrix::IdentityMatrix() = default;

IdentityMatrix::IdentityMatrix(unsigned size) {
    if (size <= 0) {
        throw std::invalid_argument("Matrix size cannot be 0 or less");
    }


    m_RowNumber = size;
    m_ColumnNumber = size;
    m_Matrix.resize(size);
    for (unsigned i = 0; i < size; i++) {
        m_Matrix[i].resize(size, 0.0);
        m_Matrix[i][i] = 1.0;
    }

}

IdentityMatrix::IdentityMatrix(Matrix &A) {
    m_RowNumber = A.GetRows();
    m_ColumnNumber = A.GetColumns();
    m_Matrix.resize(m_ColumnNumber);
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        m_Matrix[i].resize(m_RowNumber, 0.0);
        for (unsigned j = 0; j < m_RowNumber; j++) {
            if (i == j) {
                m_Matrix[i][j] = 1.0;
            }
        }
    }
}