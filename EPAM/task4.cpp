/*
 * Нахождение факториала - классический пример
 * задачи, при изучении рекурсивного вызова функций
*/

#include <iostream>
#include "tasks.h"

using namespace std;

uint64_t factorial(unsigned short int n) {
	if (n < 0) {
		cout << "N должно быть натуральным числом" << endl;
		return -1;
	}
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return n * factorial(n - 1);
}

void task4() {
	unsigned short int n;

	cout << "Факториал" << endl << endl;

	cout << "Введите число: " << endl;
	cin >> n;

	cout << "Факториа N = " << n << " равен: " << factorial(n) << endl;
}