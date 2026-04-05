#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include "Complex.h"

bool check_argument_count (int argc , string operation);
bool check_operand (string operand);
bool check_complex(string operand);
bool check_operation(string ope);
Complex calc (string operation , Complex, Complex);
double calc(string , Complex);
bool check_divbyzero(string , double , double);

int main(int argc , char* argv[])
{
    string operation = argv[1];
    if (!check_argument_count(argc , operation))
    {
        cout << "ERROR:Invalid arguments";
        return 0;
    }
    else
    {
        if (argc == 3)
        {
            string c33r= argv[2];
            string c33i= c33r.substr(c33r.length() - 3 , 2);
            if (check_operand(c33r) && check_complex(c33r))
            {
                double num3real = stod(c33r);
                double num3imag = stod(c33i);
                Complex c5(num3real,num3imag);
                cout << fixed << setprecision(6) <<  calc(operation,c5);
            }
        }
        else
        {
        string c11r = argv[2];
        string c22r = argv[3];
        string c11i = c11r.substr(c11r.length() -3 , 2);
        string c22i = c22r.substr(c22r.length() -3 , 2);
        if (!check_operation(argv[1]))
        {
            cout << "ERROR:Unknown operation";
        }
        else if (!check_operand(c11r) || !check_operand(c11i) || !check_operand(c22r) || !check_operand(c22i) )
        {
            cout << "ERROR:Invalid complex number" << endl;
            return 0;
        }
        else if (!check_complex(c11r) || !check_complex(c22r))
        {
            cout << "ERROR:Invalid complex number";
            return 0;
        }
        else
        {
            double num1real = stod(c11r);
            double num1imag = stod(c11i);
            double num2real = stod(c22r);
            double num2imag = stod(c22i);
            if (!check_divbyzero(operation, num2real, num2imag))
            {
                cout << "ERROR:Division by zero";
                return 0;
            }
            else
            {
            Complex c1(num1real,num1imag);
            Complex c2(num2real,num2imag);
            Complex c3;
            if (argc == 4)
            {
               c3 = calc(operation, c1,c2);
               cout << fixed << setprecision(6) << c3.get_real();
               if (c3.get_imag() >= 0)
               {
                   cout << "+" << fixed << setprecision(6) << c3.get_imag() << "i";
               }
               else
               {
                   cout << fixed << setprecision(6) << c3.get_imag() << "i";
               }
            }

            }
        }

    }
    }
    return 0;
}
bool check_argument_count (int argc , string operation)
{
    if ((operation == "magnitude" && argc == 3) ||
        (operation != "magnitude" && argc == 4))
    {
        return true;
    }
    return false;
}
bool check_operation(string ope)
{
    if (ope == "add" || ope == "sub" || ope == "mul" || ope == "div" || ope == "magnitude")
    {
        return true;
    }
    return false;
}
bool check_operand (string operand)
{
    try
    {
        double x = stod(operand);
        return true;
    }
    catch (...)
    {
        return false;
    }
}
bool check_complex(string operand)
{
    if (operand.length() == 4 )
    {
        if (operand[3] == 'i' && ( operand[1] == '+' || operand[1] == '-'))
        {
        return true;
        }
        else
        {
            return false;
        }
    }
    if (operand.length() == 5)
    {
        if (operand[4] == 'i' && ( operand[2] == '+' || operand[2] == '-') && operand[0] == '-')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
Complex calc (string operation , Complex c1 , Complex c2)
{
    if (operation == "add")
    {
        Complex c3;
        return c3.add(c1,c2);
    }
    else if (operation == "sub")
    {
        Complex c3;
        return c3.sub(c1,c2);
    }
    else if (operation == "mul")
    {
        Complex c3;
        return c3.mul(c1,c2);
    }
    else if (operation == "div")
    {
        Complex c3;
        return c3.div(c1,c2);
    }
    else
    {
        Complex c3;
        return c3;
    }
}
double calc(string operation , Complex c1)
{
    if (operation == "magnitude")
    {
        return c1.magnitude();
    }
    else
    {
        return 0;
    }
}
bool check_divbyzero(string operation, double num2real , double num2imag)
{
    if (operation == "div" && num2real == 0 && num2imag == 0)
    {
        return 0;
    }
    return 1;
}

