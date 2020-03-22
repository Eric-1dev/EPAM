/*
 * ��� ��� ������ ������������, �����
 * ������������ �������� �����, �������
 * ����� �������� ������� ��������� �� ������� ��������.
 * ����� ��� ������ ���������� STL-�������� find
*/

#include <iostream>
#include <algorithm>
#include "tasks.h"

using namespace std;

// ������� ������ ������� �� ����� �� ������� �������,
// ������ ��������� SIZE ������ ����� ������������
void print_arr(const int16_t *arr, const uint16_t &size) {
	for (uint16_t i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void task2() {
	cout << "����� �����" << endl << endl;

	int16_t value;
	bool result;

	const uint16_t SIZE = 200;

	int16_t arr[SIZE];

	// ��������� ������ ���������� �������
	// ����� ���� ��������� ��� � ����� arr[i] = i, �� ��� ����������
	for (uint16_t i = 0; i < SIZE; ++i) {
		arr[i] = rand() % 30000;
	}

	/*
		���������. ������� ��������, ��� STL-������� ���������� ������������
		�� ��� ���������� ���������, ���������� � �������, � ��� ���������
		��������� �������������� ����
	*/
	sort(arr, arr + SIZE, [](int16_t a, int16_t b) {
		return a > b;
	});

	// ������� ���������� ������
	print_arr(arr, SIZE);

	cout << "������� �����, ������� ������� �����: " << endl;
	cin >> value;

	// ���� ����� � ������� ������-�������, ����������� �������� ��������� ������
	// ����� �������� ����������� ����������
	result = [arr, SIZE, value]() {
		uint16_t left = 0;
		uint16_t right = SIZE;
		uint16_t middle;

		// ������� ���������� �������. �� ����������� false
		bool order = arr[right] > arr[left] ? false : true;

		while (!(left >= right))
		{
			// ������� �������� ������� ����� �������, ����� �������� ������������ ����������
			middle = left + (right - left) / 2;

			if (arr[middle] == value)
				return true;

			/* 
			 * � ����������� �� ��������� �������� �����
			 * ������������ �������� �������� � ������� ����������,
			 * �������� ������ �������� ������� ��� ����������� ������
			*/
			if ((arr[middle] > value) ^ order)
				right = middle;
			else
				left = middle + 1;
		}

		return false;
	}();

	if (result)
		cout << "����� �������" << endl;
	else
		cout << "����� �� �������" << endl;
}