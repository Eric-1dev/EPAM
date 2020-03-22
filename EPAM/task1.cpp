/*
 * ���������� ����� ����������� ������� ��������,
 * ���� ��� ����� ����� ������������ �������
 * STL �������� sort()
*/

#include <iostream>
//#include <algorithm>
#include "tasks.h"

using namespace std;

// ������� ������ ������� �� �����
void print_arr(const int16_t *arr, const uint8_t &size) {
	for (uint8_t i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// ������� ����������
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
	cout << "����������" << endl << endl;

	const uint8_t SIZE = 12;

	int16_t arr[SIZE];

	// ��������� ������ ���������� �������
	for (uint8_t i = 0; i < SIZE; ++i) {
		arr[i] = rand() % 400 - 200;
	}

	cout << "�������� ������:" << endl;

	// ������� ������������ ������
	print_arr(arr, SIZE);

	// ������ ��������� ���
	mysort(arr, SIZE);
	
	/* � ����� ���� ���
	sort(arr, arr + SIZE, [](int16_t a, int16_t b) {
		return a < b;
	});
	*/

	cout << "��������������� ������:" << endl;

	// ������� ��������������� ������
	print_arr(arr, SIZE);
}