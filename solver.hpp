#ifndef SOLVER_A_SOLVER_HPP
#define SOLVER_A_SOLVER_HPP

#include <complex>
using namespace std;

namespace solver{

    //Forward declaration
    class RealVariable;
    class ComplexVariable;

    double solve(RealVariable);//Function has to clear the varables of the reference
    complex<double> solve(ComplexVariable);

    class Variable{
    protected:
        double _a;//Coefficient of x^2
        double _b;//Coefficient of x
        double _c;//Free number

        Variable(): _a(0.0), _b(1.0), _c(0.0){}//Default C'tor
        Variable(double a, double b, double c): _a(a), _b(b), _c(c){}
        virtual ~Variable() = 0;//Yes i make it pure virtual => abstract class
    public:
        const double a() const {return _a;}
        const double b() const {return _b;}
        const double c() const {return _c;}
    };

    class RealVariable: public Variable{
        double solve_abc_formula(RealVariable & r);

    public:
        // Inherit Base's constructors, default ctor is Inherited by default(if not other Ctor implemented)
        using Variable::Variable;

        // Equivalent to:
        //RealVariable(double a, double b, double c): Variable(a,b,c){};

        //We want make it friend in order to enable something like 7 * RealVariable
        friend RealVariable operator +(const RealVariable &, const RealVariable &);
        friend RealVariable operator +(const RealVariable &, const int);
        friend RealVariable operator +(const int, const RealVariable &);
        friend RealVariable operator -(const RealVariable &, const RealVariable &);
        friend RealVariable operator -(const RealVariable &, const int);
        friend RealVariable operator *(const int, const RealVariable &);
        friend RealVariable operator /(const RealVariable &, const int);
        friend RealVariable operator ^(RealVariable const &, const int);
        friend RealVariable operator ==(const RealVariable &, const RealVariable &);
        friend RealVariable operator ==(const RealVariable &, const int);
    };

    class ComplexVariable: public Variable {
        double _im;
        ComplexVariable(double a, double b, double c, double im): Variable(a,b,c), _im(im){}

    public:
        ComplexVariable(): Variable(), _im(0.0){};
        friend ComplexVariable operator +(const ComplexVariable &, const ComplexVariable &);
        friend ComplexVariable operator +(const ComplexVariable &, const int);
        friend ComplexVariable operator +(const int, const ComplexVariable &);
        friend ComplexVariable operator +(const ComplexVariable &, complex<double>);
        friend ComplexVariable operator -(const ComplexVariable &, const ComplexVariable &);
        friend ComplexVariable operator -(const ComplexVariable &, const int);
        friend ComplexVariable operator *(const int, ComplexVariable const &);
        friend ComplexVariable operator /(ComplexVariable const &, const int);
        friend ComplexVariable operator^(ComplexVariable const &, const int);
        friend ComplexVariable operator ==(const ComplexVariable &, const int);
        friend ComplexVariable operator ==(const ComplexVariable &, const ComplexVariable &);
    };
}

#endif //SOLVER_A_SOLVER_HPP