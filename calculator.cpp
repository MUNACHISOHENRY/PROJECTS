#include<iostream>
using namespace std;
//using switch operator to build a simple calculator
int main(){
    char sign;
    double num1;
    double num2;
    double result;

    cout << "----------- MINI CALCULATOR -----------\n";

    cout << "Choose between (+ - * / %): \n";
    cin >> sign;
    cout << "Enter the first number: \n";
    cin >> num1;
    cout << "Enter the second number: \n";
    cin >> num2;

    switch (sign)
    {
    case '+':
        result = num1 + num2;
        cout << "Answer is " << result << endl;
        break;
    case '-':
        result = num1 - num2;
        cout << "Answer is " << result << endl;
        break;
    case '*':
        result = num1 * num2;
        cout << "Answer is " << result << endl;
        break;
    case '/':
        if(num2 == 0) {
            cout << "Division by zero is not allowed." << endl;
        } else {
            result = num1 / num2;
            cout << "Answer is " << result << endl;
        }
        break;
    case '%':
        if(num2 == 0) {
            cout << "Division by zero is not allowed." << endl;
        } else {
            result = (num1/num2) * 100;
            cout << "Answer is " << result << "%" << endl;
        }
        break;
    default:
        cout << "Select the right operator!" << endl;
        break;
    }
    cout << "\n-----------------------------------------" << endl;
    return 0;
}