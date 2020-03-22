/*
 * ���������� ���������� - ������������ ������
 * ������, ��� �������� ������������ ������ �������
*/

#include <iostream>
#include "tasks.h"

using namespace std;

uint64_t factorial(unsigned short int n) {
	if (n < 0) {
		cout << "N ������ ���� ����������� ������" << endl;
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

	cout << "���������" << endl << endl;

	cout << "������� �����: " << endl;
	cin >> n;

	cout << "�������� N = " << n << " �����: " << factorial(n) << endl;
}