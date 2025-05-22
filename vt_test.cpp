#include <iostream>
#include "CUTE/cute/cute.h"
#include "CUTE/cute/cute_runner.h"
#include "CUTE/cute/ide_listener.h"
#include "vt_func.h"
#include <sstream>
#include <stdexcept>
using namespace cute;

// Mock для тестирования функции ввода
void testInputPositiveNumberValid() {
    std::istringstream input("5.5\n");
    std::cin.rdbuf(input.rdbuf());
    double result = inputPositiveNumber("Enter number: ");
    ASSERT_EQUAL(5.5, result);
}

void testInputPositiveNumberNegativeThenValid() {
    std::istringstream input("-2\n3.14\n");
    std::cin.rdbuf(input.rdbuf());
    double result = inputPositiveNumber("Enter number: ");
    ASSERT_EQUAL(3.14, result);
}

void testInputPositiveNumberInvalidThenValid() {
    std::istringstream input("abc\n7.8\n");
    std::cin.rdbuf(input.rdbuf());
    double result = inputPositiveNumber("Enter number: ");
    ASSERT_EQUAL(7.8, result);
}

// Тесты для вычисляющих функций
void testArithmeticMean() {
    double x = 4.0;
    double y = 6.0;
    double expected = 5.0;
    double result = arithmeticMean(x, y);
    ASSERT_EQUAL_DELTA(expected, result, 1e-9);
}

void testGeometricMean() {
    double x = 4.0;
    double y = 9.0;
    double expected = 6.0;
    double result = geometricMean(x, y);
    ASSERT_EQUAL_DELTA(expected, result, 1e-9);
}

bool runAllTests(int argc, char const *argv[]) {
    cute::suite s;
    
    s.push_back(CUTE(testInputPositiveNumberValid));
    s.push_back(CUTE(testInputPositiveNumberNegativeThenValid));
    s.push_back(CUTE(testInputPositiveNumberInvalidThenValid));
    s.push_back(CUTE(testArithmeticMean));
    s.push_back(CUTE(testGeometricMean));

    cute::ide_listener<> lis;
    cute::makeRunner(lis, argc, argv)(s, "All Tests");
    return true;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
