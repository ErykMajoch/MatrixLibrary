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

// ###################
// # Equals Operator #
// ###################
bool Matrix::operator==(Matrix &Other) {
    if (m_RowNumber != Other.GetRows() || m_ColumnNumber != Other.GetColumns()) {
        return false;
    }

    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            if (m_Matrix[i][j] != Other[j,i]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator==(std::vector<std::vector<double>> &Other) {
    if (m_RowNumber != Other[0].size() || m_ColumnNumber != Other.size()) {
        return false;
    }

    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            if (m_Matrix[i][j] != Other[i][j]) {
                return false;
            }
        }
    }
    return true;
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
                result[j, i] = this->m_Matrix[i][j] + Other[j, i];
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
                result[j, i] = this->m_Matrix[i][j] - Other[j, i];
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
                    result[j, i] += m_Matrix[i][k] * Other[j, k];
                }
            }
        }
        return result;
    }
    else {
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
            result[j, i] = this->m_Matrix[i][j] - scalar;
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
            result[j, i] = this->m_Matrix[i][j] * scalar;
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
            result[j, i] = this->m_Matrix[i][j] / scalar;
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
        throw std::invalid_argument("Cannot create identity matrix => matrix is not square or has no rows/columns");
    }
    return IdentityMatrix(m_RowNumber);
}

Matrix& Matrix::Transpose() {
    Matrix result = Matrix(m_ColumnNumber, m_RowNumber, 0.0);
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            result[i, j] = m_Matrix[i][j];
        }
    }
    m_Matrix = result.m_Matrix;
    m_RowNumber = result.m_RowNumber;
    m_ColumnNumber = result.m_ColumnNumber;
    return *this;
}

Matrix Matrix::Minor(unsigned row, unsigned column) {
    if (m_RowNumber != m_ColumnNumber || row >= m_RowNumber || column >= m_ColumnNumber) {
        throw std::invalid_argument("Cannot create minor matrix => matrix is not square or row/column is out of bounds");
    }

    Matrix Minor = Matrix(m_RowNumber - 1, m_ColumnNumber - 1, 0.0);
    unsigned minor_row = 0;
    unsigned minor_column = 0;
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            if (i != column && j != row) {
                Minor[minor_row, minor_column] = m_Matrix[i][j];
                minor_row++;
                if (minor_row == m_RowNumber - 1) {
                    minor_row = 0;
                    minor_column++;
                }
            }
        }
    }

    return Minor;
}

double Matrix::Determinant() {
    if (m_RowNumber != m_ColumnNumber) {
        throw std::invalid_argument("Cannot calculate determinant => matrix is not square");
    }

    if (m_RowNumber == 1) {
        return m_Matrix[0][0];
    }

    double determinant = 0;
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        determinant += pow(-1, i) * m_Matrix[i][0] * Minor(0, i).Determinant();
    }

    return determinant;
}

Matrix Matrix::Inverse() {
    if (m_RowNumber != m_ColumnNumber) {
        throw std::invalid_argument("Cannot calculate inverse => matrix is not square");
    }

    double determinant = Determinant();
    if (determinant == 0) {
        throw std::invalid_argument("No inverse exists as the determinant is 0");
    }

    Matrix inverse = Matrix(m_RowNumber, m_ColumnNumber, 0.0);
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            inverse[j, i] = pow(-1, i + j) * Minor(i, j).Determinant() / determinant;
        }
    }

    return inverse;
}



// #############
// # Utilities #
// #############

size_t Matrix::NumberOfDigits(double n) {
	std::ostringstream current;
	current << n;
	return current.str().size();
}

void Matrix::Print() {
    size_t max_len_per_column[100];
	for (size_t j = 0; j < m_RowNumber; ++j) {
		size_t max_len {};

		for (size_t i = 0; i < m_ColumnNumber; ++i) {
			if (const auto num_length {NumberOfDigits(m_Matrix[i][j])}; num_length > max_len) {
                max_len = num_length;
            }
        }

		max_len_per_column[j] = max_len;
	}

	for (size_t i = 0; i < m_ColumnNumber ; ++i) {
		for (size_t j = 0; j < m_RowNumber; ++j) {
			std::cout << (j == 0 ? "| " : "") << std::setw(max_len_per_column[j]) << m_Matrix[i][j] << (j == m_RowNumber - 1 ? " |\n" : " ");
        }
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
