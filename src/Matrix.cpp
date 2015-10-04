//
// Created by Rui Chen on 9/29/15.
//

#include "Matrix.h"
#include "Utils.h"

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
    if (&rhs == this)
        return *this;

    unsigned int newRow = rhs.getRow();
    unsigned int newCol = rhs.getCol();

    mat.resize(newRow);
    for (unsigned i=0; i<mat.size(); i++) {
        mat[i].resize(newCol);
    }

    for (unsigned i=0; i<newRow; i++) {
        for (unsigned j=0; j<newCol; j++) {
            mat[i][j] = rhs(i, j);
        }
    }
    row = newRow;
    col = newCol;

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) {
    Matrix result(row, col, 0.0);

    for (unsigned i=0; i<row; i++) {
        for (unsigned j=0; j<col; j++) {
            result(i,j) = this->mat[i][j] + rhs(i,j);
        }
    }

    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs) {
    unsigned theRow = rhs.getRow();
    unsigned theCol = rhs.getCol();

    for (unsigned i=0; i<theRow; i++) {
        for (unsigned j=0; j<theCol; j++) {
            this->mat[i][j] += rhs(i,j);
        }
    }

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) {
    Matrix result(row, col, 0.0);

    for (unsigned i=0; i<row; i++) {
        for (unsigned j=0; j<col; j++) {
            result(i,j) = this->mat[i][j] - rhs(i,j);
        }
    }

    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs) {
    unsigned theRow = rhs.getRow();
    unsigned theCol = rhs.getCol();

    for (unsigned i=0; i<theRow; i++) {
        for (unsigned j=0; j<theCol; j++) {
            this->mat[i][j] -= rhs(i,j);
        }
    }

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) {
    unsigned int theRow = rhs.getRow();
    unsigned int theCol = rhs.getCol();
    Matrix result(theRow, theCol, 0.0);

    for (unsigned i=0; i<theRow; i++) {
        for (unsigned j=0; j<theCol; j++) {
            for (unsigned k=0; k<theRow; k++) {
                result(i,j) += this->mat[i][k] * rhs(k,j);
            }
        }
    }

    return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& rhs) {
    Matrix result = (*this) * rhs;
    (*this) = result;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::transpose() {
    Matrix result(row, col, 0.0);

    for (unsigned i=0; i<row; i++) {
        for (unsigned j=0; j<col; j++) {
            result(i,j) = this->mat[j][i];
        }
    }

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const T& rhs) {
    Matrix result(row, col, 0.0);

    for (unsigned int i=0; i<row; i++) {
        for (unsigned int j=0; j<col; j++) {
            result(i,j) = this->mat[i][j] + rhs;
        }
    }

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T& rhs) {

    Matrix result(row, col, 0.0);

    for (unsigned int i=0; i<row; i++) {
        for (unsigned int j=0; j<col; j++) {
            result(i,j) = this->mat[i][j] - rhs;
        }
    }

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& rhs) {
    Matrix result(row, col, 0.0);

    for (unsigned int i=0; i<row; i++) {
        for (unsigned int j=0; j<col; j++) {
            result(i,j) = this->mat[i][j] * rhs;
        }
    }

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T& rhs) {
    Matrix result(row, col, 0.0);

    for (unsigned int i=0; i<row; i++) {
        for (unsigned int j=0; j<col; j++) {
            result(i,j) = this->mat[i][j] / rhs;
        }
    }

    return result;
}

template<typename T>
T& Matrix<T>::operator()(const unsigned& r, const unsigned& c) {
    return this->mat[r][c];
}

template<typename T>
const T& Matrix<T>::operator()(const unsigned& r, const unsigned& c) const {
    return this->mat[r][c];
}

template<typename T>
vector<T> Matrix<T>::diagVector() {
    vector<T> result(row, 0.0);

    for (unsigned i=0; i<row; i++) {
        result[i] = this->mat[i][i];
    }

    return result;
}

template<typename T>
unsigned int Matrix<T>::getRow() const {
    return this->row;
}

template<typename T>
unsigned int Matrix<T>::getCol() const {
    return this->col;
}

template<typename T>
T Matrix<T>::toNumber() {
    if (row == 1 && col == 1) return mat[1][1];
    else {
        Utils::logError("The size should be 1x1!");
        exit(1);
    }
}

template<typename T>
Matrix<T> Matrix<T>::getIdentityMatrix(unsigned int dim, const T zero) {
    return DiagonalMatrix<T>(dim, vector<T>(dim, zero));
}