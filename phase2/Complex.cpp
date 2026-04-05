#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include "Complex.h"
using namespace std;

Complex:: Complex()
{
    this-> real =0;
    this-> imag = 0;
}
Complex:: Complex(double real, double imag)
{
    this-> real = real;
    this-> imag = imag;
}
Complex Complex:: add(const Complex c1 , const Complex c2)
{
     Complex c3;
     c3.real = c1.real + c2.real;
     c3.imag = c1.imag + c2.imag;
     return c3;
}
Complex Complex:: sub(const Complex c1 , const Complex c2)
{
     Complex c3;
     c3.real = c1.real - c2.real;
     c3.imag = c1.imag - c2.imag;
     return c3;
}
Complex Complex:: mul (const Complex c1 , const Complex c2)
{
     Complex c3;
     c3.real = (c1.real * c2.real) - (c1.imag * c2.imag);
     c3.imag = ( c1.real * c2.imag ) + (c1.imag * c2.real);
     return c3;
}
Complex Complex::div(const Complex c1 , const Complex c2)
{
     Complex c3;
     c3.real = ( (c1.real * c2.real) + (c1.imag * c2.imag) )/ (c2.real*c2.real+c2.imag*c2.imag);
     c3.imag = ( (-1*( c1.real * c2.imag )) + (c1.imag * c2.real) )/ (c2.real*c2.real+c2.imag*c2.imag);
     return c3;
}
double Complex:: magnitude() const
{
    return sqrt((real*real )+ (imag*imag ));
}
double Complex:: get_real() const
{
    return this->real;
}
double Complex:: get_imag() const
{
    return this->imag;
}

