#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
bool check_argument_count (int argc);
bool check_operand (string operand);
bool check_operation(string ope);
double calc (string operation , double num1, double num2);
bool check_result(double res);
bool check_divbyzero(string operation, double num2);
int main(int argc , char* argv[])
{
    if (!check_argument_count(argc))
    {
        cout << "ERROR: Invalid arguments";
        return 0;
    }
    else
    {
        if (!check_operation(argv[1]))
        {
            cout << "ERROR: Unknown operation";
        }
        else if (!check_operand(argv[2]) || !check_operand(argv[3]))
        {
            cout << "ERROR: Invalid arguments";
            return 0;
        }
        else
        {
            string operation = argv[1];
            double num1 = stod(argv[2]);
            double num2 = stod(argv[3]);
            if (!check_divbyzero(operation, num2))
            {
                cout << "ERROR: Division by zero";
                return 0;
            }
            else
            {
            double result = calc(operation ,num1 , num2 );
            if (!check_result(result))
            {
                cout << "ERROR: Invalid result";
            }
            else
            {
            cout << fixed << setprecision(6) << result;
            }
            }
        }

    }
    return 0;
}
bool check_argument_count (int argc)
{
    if (argc != 4)
    {
        return false;
    }
    return true;
}
bool check_operation(string ope)
{
    if (ope == "add" || ope == "sub" || ope == "mul" || ope == "div" || ope == "pow")
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
double calc (string operation , double num1, double num2)
{
    if (operation == "add")
    {
        return num1 + num2;
    }
    else if (operation == "sub")
    {
        return num1 - num2;
    }
    else if (operation == "mul")
    {
        return num1 * num2;
    }
    else if (operation == "div")
    {
        return num1 / num2;
    }
    else if (operation == "pow")
    {
        return pow(num1, num2);
    }
    else
    {
        return 0;
    }
}
bool check_result(double res)
{
    if (isinf(res) || isnan(res))
    {
        return 0;

    }
    else
    {
        return 1;
    }
}
bool check_divbyzero(string operation, double num2)
{
    if (operation == "div" && num2 == 0)
    {
        return 0;
    }
    return 1;
}
