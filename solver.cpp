#include "solver.hpp"

#include <iostream>
#include <exception>
namespace solver{

    //We have to "implement the virtual method" in order to avoid implement unnecessary dtors in subclasses
    Variable:: ~Variable(){}

    //RealVariable class
    RealVariable operator +(const RealVariable & r1, const RealVariable & r2){
        return RealVariable(r1._a + r2._a, r1._b + r2._b, r1._c + r2._c);
    }

    RealVariable operator +(const RealVariable & r1, const int num){
        return RealVariable(r1._a, r1._b, r1._c + num);
    }

    RealVariable operator +(const int num, const RealVariable & r1){
        return r1 + num; // :)
    }

    RealVariable operator -(const RealVariable & r1, const RealVariable & r2){
        return RealVariable(r1._a - r2._a, r1._b - r2._b, r1._c - r2._c);
    }

    RealVariable operator -(const RealVariable & r1, const int num){
        return RealVariable(r1._a, r1._b, r1._c - num);
    }

    RealVariable operator *(const int num, const RealVariable & r1){
        return r1._a > 0 ? RealVariable(num, r1._b, r1._c) : RealVariable(r1._a, num, r1._c);
    }

    RealVariable operator /( const RealVariable & r1 ,const int num){
        if(num == 0)
        {
            throw invalid_argument("Can't divide by zero");
        }
        return RealVariable(r1._a, r1._b/num, r1._c);
    }

    RealVariable operator ^(RealVariable const & r1, const int num){
        return RealVariable(r1._a + 1, 0, r1._c); //Sign it as x^2(we don't want 1x also)
    }

    RealVariable operator ==(const RealVariable & r1, const RealVariable & r2){
        return r1 - r2;
    }

    RealVariable operator ==(const RealVariable & r1, const int num){
        return r1 - num;
    }

    double solve_abc_formula(RealVariable & r)
    {
        double a(r.a()), b(r.b()), c(r.c());
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
//                cout << "Roots are real and different." << endl;
//                cout << "x1 = " << x1 << endl;
//                cout << "x2 = " << x2 << endl;
                //cout << "Roots are real and same." << endl;
                //x1 = (-b + sqrt(discriminant)) / (2 * a);
                //cout << "x1 = x2 =" << x1 << endl;
                result = x1;
            } else {
//                realPart = -b / (2 * a);
//                imaginaryPart = sqrt(-discriminant) / (2 * a);
//                cout << "Roots are complex and different." << endl;
//                cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
//                cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
                throw exception(invalid_argument("There is no solution"));
            }
        } else{
            result = -c/b; //The only solution we have
        }

        return result;
    }
    double solve(RealVariable r) {
        return solve_abc_formula(r);
    }

    //ComplexVariable class
    ComplexVariable operator +(const ComplexVariable &, const ComplexVariable &){return ComplexVariable();}
    ComplexVariable operator +(const ComplexVariable &, const int){return ComplexVariable();}
    ComplexVariable operator +(const int, const ComplexVariable &){return ComplexVariable();}
    ComplexVariable operator +(const ComplexVariable &, complex<double>){return ComplexVariable();}
    ComplexVariable operator -(const ComplexVariable &, const ComplexVariable &){return ComplexVariable();}
    ComplexVariable operator -(const ComplexVariable &, const int){return ComplexVariable();}
    ComplexVariable operator*(const int, ComplexVariable const &) {return ComplexVariable();}
    ComplexVariable operator /(ComplexVariable const &, const int){return ComplexVariable();}
    ComplexVariable operator^(ComplexVariable const &, const int) {return ComplexVariable();}
    ComplexVariable operator ==(const ComplexVariable &, const int){return ComplexVariable();}
    ComplexVariable operator ==(const ComplexVariable &, const ComplexVariable &){return ComplexVariable();}

    complex<double> solve(ComplexVariable) {return complex<double>();}
}
