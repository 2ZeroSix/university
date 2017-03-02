#include "slau_solve.h"
namespace matrix {
Vector<double> slauSolveIteration(  const Matrix<double>& mat,
                                    const Vector<double>& result,
                                    double epsilon,
                                    double tau) {
    Vector<double> x(result.getSize());
    double prevCriterion = (mat*x - result).norm2() / result.norm2();
    double tauSign = 1.;
    while(true) {
        double criterion = (mat*x - result).norm2() / result.norm2();
        if ( criterion < epsilon ) break;
        if ( criterion > prevCriterion ) tauSign = -1.;
        x -= tau * tauSign * (mat * x - result);
    }
    return x;
}

Vector<double> slauSolveMinUnbounds(const Matrix<double>& mat,
                                    const Vector<double>& result,
                                    double epsilon) {
    Vector<double> x(result.getSize());
    while(true) {
        if ( (mat*x - result).norm2() / result.norm2() < epsilon ) break;
        Vector<double> y = mat*x - result;
        Vector<double> Ay = mat*y;
        double tau = (y*Ay) / (Ay*Ay);
        x -= tau * y;
    }
    return x;
}

Vector<double> slauSolveGradients(const Matrix<double>& mat,
                                    const Vector<double>& result,
                                    double epsilon) {
    Vector<double> x(result.getSize());
    Vector<double> r = result - mat*x;
    Vector<double> z = r;
    Vector<double> previousR(result.getSize());
    double alpha;
    double beta;
    while(true) {
        Vector<double> Az = mat * z;
        alpha = (r * r) / (Az * z);
        x += alpha * z;
        previousR = r;
        r -= alpha * Az;
        if ( r.norm2() / result.norm2() < epsilon ) break;
        beta = (r * r) / (previousR * previousR);
        z = r + beta * z;
    }
    return x;
}
}

namespace matrixMPI {
Vector<double> slauSolveIteration(  const Matrix<double>& mat,
                                    const Vector<double>& result,
                                    double epsilon,
                                    double tau) {
    Vector<double> x(result.getSize());
    double prevCriterion = (mat*x - result).norm2() / result.norm2();
    double tauSign = 1.;
    while(true) {
        double criterion = (mat*x - result).norm2() / result.norm2();
        if ( criterion < epsilon ) break;
        if ( criterion > prevCriterion ) tauSign = -1.;
        x -= tau * tauSign * (mat * x - result);
    }
    return x;
}

Vector<double> slauSolveMinUnbounds(const Matrix<double>& mat,
                                    const Vector<double>& result,
                                    double epsilon) {
    Vector<double> x(result.getSize());
    while(true) {
        if ( (mat*x - result).norm2() / result.norm2() < epsilon ) break;
        Vector<double> y = mat*x - result;
        Vector<double> Ay = mat*y;
        double tau = (y*Ay) / (Ay*Ay);
        x -= tau * y;
    }
    return x;
}

Vector<double> slauSolveGradients(const Matrix<double>& mat,
                                    const Vector<double>& result,
                                    double epsilon) {
    Vector<double> x(result.getSize());
    Vector<double> r = result - mat*x;
    Vector<double> z = r;
    Vector<double> previousR(result.getSize());
    double alpha;
    double beta;
    while(true) {
        Vector<double> Az = mat * z;
        alpha = (r * r) / (Az * z);
        x += alpha * z;
        previousR = r;
        r -= alpha * Az;
        if ( r.norm2() / result.norm2() < epsilon ) break;
        beta = (r * r) / (previousR * previousR);
        z = r + beta * z;
    }
    return x;
}
}
