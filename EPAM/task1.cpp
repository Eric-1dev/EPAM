/*
 * Сортировку будем производить методом пузырька,
 * хотя для этого можно использовать готовый
 * STL алгоритм sort()
*/

#include <iostream>
//#include <algorithm>
#include "tasks.h"

using namespace std;

// Функция вывода массива на экран
void print_arr(const int16_t *arr, const uint8_t &size) {
	for (uint8_t i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Функция сортировки
void mysort(int16_t *arr, const uint8_t &size) {
	int16_t swap;

	for (uint8_t i = 0; i < size - 1; ++i) {
		for (uint8_t j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap = arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = swap;
			}
		}
	}
}

void task1() {
	cout << "Сортировка" << endl << endl;

	const uint8_t SIZE = 12;

	int16_t arr[SIZE];

	// Заполняем массив случайными числами
	for (uint8_t i = 0; i < SIZE; ++i) {
		arr[i] = rand() % 400 - 200;
	}

	cout << "Исходный массив:" << endl;

	// Выводим получившийся массив
	print_arr(arr, SIZE);

	// Теперь сортируем его
	mysort(arr, SIZE);
	
	/* А можно было так
	sort(arr, arr + SIZE, [](int16_t a, int16_t b) {
		return a < b;
	});
	*/

	cout << "Отсортированный массив:" << endl;

	// Выводим отсортированный массив
	print_arr(arr, SIZE);
}