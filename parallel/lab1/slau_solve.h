#ifndef _SLAU_SOLVE_H_
#define _SLAU_SOLVE_H_
#include <algorithm>
#include <cmath>
#include "Matrix.h"
#include "MatrixMPI.h"
#include "Vector.h"
namespace matrix {
Vector<double> slauSolveIteration(  const Matrix<double>& mat,
                                    const Vector<double>& result,
                                    double epsilon = 0.00001,
                                    double tau = 0.01);
Vector<double> slauSolveMinUnbounds(const Matrix<double>& mat,
                                    const Vector<double>& result,
                                    double epsilon = 0.00001);
Vector<double> slauSolveGradients(const Matrix<double>& mat,
                                    const Vector<double>& result,
                                    double epsilon = 0.00001);
}
namespace matrixMPI {
Vector<double> slauSolveIteration(  const Matrix<double>& mat,
                                    const Vector<double>& result,
                                    double epsilon = 0.00001,
                                    double tau = 0.01);
Vector<double> slauSolveMinUnbounds(const Matrix<double>& mat,
                                    const Vector<double>& result,
                                    double epsilon = 0.00001);
Vector<double> slauSolveGradients(const Matrix<double>& mat,
                                    const Vector<double>& result,
                                    double epsilon = 0.00001);
}


#endif