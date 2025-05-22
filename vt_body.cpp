#include "vt_func.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <cctype> // Для tolower()

using namespace std;

// Прототипы функций (должны быть объявлены перед main)
double inputPositiveNumber(const string& prompt);
inline double arithmeticMean(double x, double y);
inline double geometricMean(double x, double y);
void printResults(double x, double y);

int main() {
    do {
        cout << "\n=== Программа вычисления средних значений ===\n";
        
        // Ввод данных
        double x = inputPositiveNumber("Введите положительное число X: ");
        double y = inputPositiveNumber("Введите положительное число Y: ");
        
        // Вывод результатов
        printResults(x, y);
        
        // Запрос на продолжение
        cout << "\nПродолжить вычисления? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (tolower(choice) != 'y') {
            cout << "Завершение программы.\n";
            break;
        }
        
    } while (true);

    return 0;
}