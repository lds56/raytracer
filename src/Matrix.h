//
// Created by Rui Chen on 9/29/15.
//

#ifndef RAYTRACER_MATRIX_H
#define RAYTRACER_MATRIX_H

#include <vector>

using namespace std;

template <typename T>
class Matrix {
public:
    Matrix(): Matrix(0, 0, NULL) {}
    Matrix(unsigned int row, unsigned int col, const T& initial):
            row(row), col(col) {
        mat.resize(row);
        for (unsigned int i=0; i<mat.size(); i++) {
            mat[i].resize(col, initial);
        }
    }

    Matrix(unsigned int row, unsigned int col, vector<vector<T>>& dat):
            row(row), col(col), mat(dat) {}

    Matrix(const Matrix<T>& rhs) {
        mat = rhs.mat;
        row = rhs.getRow();
        col = rhs.getCol();
    }

    virtual ~Matrix() {}

    Matrix<T>& operator=(const Matrix<T>& rhs);

    Matrix<T> operator+(const Matrix<T>& rhs);
    Matrix<T>& operator+=(const Matrix<T>& rhs);
    Matrix<T> operator-(const Matrix<T>& rhs);
    Matrix<T>& operator-=(const Matrix<T>& rhs);
    Matrix<T> operator*(const Matrix<T>& rhs);
    Matrix<T>& operator*=(const Matrix<T>& rhs);
    Matrix<T> transpose();

    Matrix<T> operator+(const T& rhs);
    Matrix<T> operator-(const T& rhs);
    Matrix<T> operator*(const T& rhs);
    Matrix<T> operator/(const T& rhs);

    T& operator()(const unsigned& row, const unsigned& col);
    const T& operator()(const unsigned& row, const unsigned& col) const;

    vector<T> diagVector();

    unsigned int getRow() const;
    unsigned int getCol() const;

    T toNumber();

    static Matrix<T> getIdentityMatrix(unsigned int dim, const T zero);

protected:
    vector<vector<T> > mat;
    unsigned int row;
    unsigned int col;

};

template <typename T>
class DiagonalMatrix : public Matrix<T> {
public:
    DiagonalMatrix(unsigned int dim, vector<T> diagVector, const T zero):
            Matrix<T>(dim, dim, zero) {
        for (unsigned int i=0; i<dim; i++)
            Matrix<T>::mat[i][i] = diagVector[i];
    }
};
#endif //RAYTRACER_MATRIX_H
