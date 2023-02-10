#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

class IdentityMatrix;

class Matrix
{
public:
    // Constructors
    Matrix();
    Matrix(unsigned rows, unsigned columns);
    Matrix(unsigned rows, unsigned columns, double initial);
    Matrix(std::vector<std::vector<double>> Other);
    
    // Access Operations
    double& operator[](const unsigned &, const unsigned &);
    double& operator[](const unsigned &);

    // Matrix Operations
    Matrix operator+(Matrix &); // <= Implement all features
    Matrix operator-(Matrix &); // <= Implement all features
    Matrix operator*(Matrix &);
    // TODO => Matrix operator/(Matrix &);

    // TODO => Matrix& operator+=(Matrix &);
    // TODO => Matrix& operator-=(Matrix &);
    // TODO => Matrix& operator*=(Matrix &);
    // TODO => Matrix& operator/=(Matrix &);

    // Scalar Operations
    Matrix operator+(double);
    Matrix operator-(double);
    Matrix operator*(double);
    Matrix operator/(double);

    Matrix& operator+=(double);
    Matrix& operator-=(double);
    Matrix& operator*=(double);
    Matrix& operator/=(double);

    // Getters
    unsigned GetRows();
    unsigned GetColumns();
    IdentityMatrix GetIdentityMatrix();

    // Print Matrix
    void Print() const;

protected:
    unsigned m_ColumnNumber = 0;
    unsigned m_RowNumber = 0;
    std::vector<std::vector<double>> m_Matrix = {};
};

// ###################
// # Identity Matrix #
// ###################

class IdentityMatrix : public Matrix {
public:
    IdentityMatrix();
    IdentityMatrix(unsigned size);
    IdentityMatrix(Matrix &A);
};