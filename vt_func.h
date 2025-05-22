#ifndef _VT_FUNC_H_
#define _VT_FUNC_H_
#include <iostream>
#include <cmath>
#include <limits>
#include <cctype> // Для tolower()
using namespace std;
double inputPositiveNumber(const string& prompt) {
    double number;
    while (true) {
        cout << prompt;
        cin >> number;
        
        if (cin.fail() || number <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите положительное число!\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }
    }
}

inline double arithmeticMean(double x, double y) {
    return (x + y) / 2.0;
}

inline double geometricMean(double x, double y) {
    return sqrt(x * y);
}

void printResults(double x, double y) {
    cout << "\nРезультаты:\n";
    cout << "Числа: X = " << x << ", Y = " << y << endl;
    cout << "Среднее арифметическое: " << arithmeticMean(x, y) << endl;
    cout << "Среднее геометрическое: " << geometricMean(x, y) << endl;
}
#endif _VT_FUNC_H_