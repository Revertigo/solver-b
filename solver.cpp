#include "solver.hpp"

#include <iostream>
#include <exception>
namespace solver{
    //RealVariable class
    RealVariable operator +(const RealVariable & r1, const RealVariable & r2){
        return RealVariable(r1._a + r2._a, r1._b + r2._b, r1._c + r2._c);
    }

    RealVariable operator +(const RealVariable & r, const int num){
        return RealVariable(r._a, r._b, r._c + num);
    }

    RealVariable operator +(const int num, const RealVariable & r){
        return r + num; // :)
    }

    RealVariable operator -(const RealVariable & r1, const RealVariable & r2){
        return RealVariable(r1._a - r2._a, r1._b - r2._b, r1._c - r2._c);
    }

    RealVariable operator -(const RealVariable & r, const int num){
        return RealVariable(r._a, r._b, r._c - num);
    }

    RealVariable operator *(const int num, const RealVariable & r){
        return r._a > 0 ? RealVariable(num, r._b, r._c) : RealVariable(r._a, num, r._c);
    }

    RealVariable operator /(const RealVariable & r , const int num){
        if(num == 0){
            throw invalid_argument("Can't divide by zero");
        }
        return RealVariable(r._a, r._b / num, r._c);
    }

    RealVariable operator ^(RealVariable const & r, const int num){
        return RealVariable(1, 0, r._c); //Sign it as x^2(we don't want 1x also)
    }

    RealVariable operator ==(const RealVariable & r1, const RealVariable & r2){
        return r1 - r2;
    }

    RealVariable operator ==(const RealVariable & r, const int num){
        return r - num;
    }

    complex<double> RealVariable::solve_abc_formula(void)
    {
        double a(_a), b(_b), c(_c);
        double x1, x2, realPart, imaginaryPart, discriminant = b*b - 4*a*c;
        double result = 0.0;

        if(a == 0.0 && b == 0.0)
        {
            throw invalid_argument("No real soultion exists");
        }
        if(a != 0)//It is possible to be a Linear equation
        {
            if (discriminant >= 0) {
                x1 = (-b + sqrt(discriminant)) / (2 * a);
                x2 = (-b - sqrt(discriminant)) / (2 * a);
                //x1 = (-b + sqrt(discriminant)) / (2 * a);
                result = x1;
            } else {
//                realPart = -b / (2 * a);
//                imaginaryPart = sqrt(-discriminant) / (2 * a);
                throw exception(invalid_argument("There is no solution"));
            }
        } else{
            result = -c/b; //The only solution we have
        }

        return result;
    }

    double solve(RealVariable r) {
        return r.solve_abc_formula().real();
    }

    //ComplexVariable class
    ComplexVariable operator +(const ComplexVariable & c1, const ComplexVariable & c2){
        return ComplexVariable(c1._a + c2._a, c1._b + c2._b, c1._c + c2._c, c1._im + c2._im);
    }

    ComplexVariable operator +(const ComplexVariable & c, const int num ){
        return ComplexVariable(c._a, c._b, c._c + num, c._im);
    }

    ComplexVariable operator +(const int num, const ComplexVariable & c){
        return c + num;
    }

    ComplexVariable operator +(const ComplexVariable & c, complex<double> num){
        return ComplexVariable(c._a, c._b, c._c , c._im + num);
    }

    ComplexVariable operator -(const ComplexVariable & c1, const ComplexVariable & c2){
        return ComplexVariable(c1._a - c2._a, c1._b - c2._b, c1._c - c2._c, c1._im - c2._im);
    }

    ComplexVariable operator -(const ComplexVariable & c, const int num){
        return ComplexVariable(c._a, c._b, c._c - num, c._im);
    }

    ComplexVariable operator*(const int num, ComplexVariable const & c) {
        return c._a > 0 ? ComplexVariable(num, c._b, c._c, c._im) : ComplexVariable(c._a, num, c._c, c._im);
    }
    ComplexVariable operator /(ComplexVariable const & c, const int num){
        if(num == 0){
            throw invalid_argument("Can't divide by zero");
        }

        return ComplexVariable(c._a, c._b / num, c._c, c._im);
    }

    ComplexVariable operator^(ComplexVariable const & c, const int num) {
        return ComplexVariable(1, c._b, c._c, c._im);
    }

    ComplexVariable operator ==(const ComplexVariable & c, const int num){
        return ComplexVariable(c._a, c._b, c._c - num, c._im);
    }

    ComplexVariable operator ==(const ComplexVariable & c1, const ComplexVariable & c2){
        return ComplexVariable(c1._a - c2._a, c1._b - c2._b, c1._c - c2._c, c1._im - c2._im);
    }

    complex<double> ComplexVariable::solve_abc_formula(void)
    {
        return complex<double>();
    }

    complex<double> solve(ComplexVariable c) {
        return c.solve_abc_formula();
    }
}
