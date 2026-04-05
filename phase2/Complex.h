#ifndef COMPLEX_H
#define COMPLEX_H

using namespace std;
class Complex
{
private:
    double real;
    double imag;
public:
    Complex();
    Complex(double, double);
    void set_real(const double) ;
    void set_imag(const double) ;
    double get_real() const;
    double get_imag() const;
    Complex add(const Complex,const Complex);
    Complex sub(const Complex,const Complex);
    Complex mul(const Complex,const Complex);
    Complex div(const Complex,const Complex);
    double magnitude() const;
};


#endif
