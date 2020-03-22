/*
 * Так как массив отсортирован, будем
 * использовать бинарный поиск, который
 * будет работать быстрее линейного на больших массивах.
 * Также для поиска существует STL-алгоритм find
*/

#include <iostream>
#include <algorithm>
#include "tasks.h"

using namespace std;

// Функция вывода массива на экран из первого задания,
// только константа SIZE теперь будет двухбайтовой
void print_arr(const int16_t *arr, const uint16_t &size) {
	for (uint16_t i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void task2() {
	cout << "Поиск числа" << endl << endl;

	int16_t value;
	bool result;

	const uint16_t SIZE = 200;

	int16_t arr[SIZE];

	// Заполняем массив случайными числами
	// Можно было заполнить его в цикле arr[i] = i, но так интереснее
	for (uint16_t i = 0; i < SIZE; ++i) {
		arr[i] = rand() % 30000;
	}

	/*
		Сортируем. Обращаю внимание, что STL-функция сортировки используется
		не для реализации алгоритма, указанного в задании, а для упрощения
		написания сопутствующего кода
	*/
	sort(arr, arr + SIZE, [](int16_t a, int16_t b) {
		return a > b;
	});

	// Выводим полученный массив
	print_arr(arr, SIZE);

	cout << "Введите число, которое следует найти: " << endl;
	cin >> value;

	// Ищем число с помощью лямбда-функции, реализующей алгоритм бинарного поиска
	// Также возможна рекурсивная реализация
	result = [arr, SIZE, value]() {
		uint16_t left = 0;
		uint16_t right = SIZE;
		uint16_t middle;

		// порядок сортировки массива. По возрастанию false
		bool order = arr[right] > arr[left] ? false : true;

		while (!(left >= right))
		{
			// находим середину массива таким образом, чтобы избежать переполнения переменной
			middle = left + (right - left) / 2;

			if (arr[middle] == value)
				return true;

			/* 
			 * В зависимости от положения искомого числа
			 * относительно среднего элемента и порядка сортировки,
			 * выбираем нужную половину массива для продолжения поиска
			*/
			if ((arr[middle] > value) ^ order)
				right = middle;
			else
				left = middle + 1;
		}

		return false;
	}();

	if (result)
		cout << "Число найдено" << endl;
	else
		cout << "Число не найдено" << endl;
}