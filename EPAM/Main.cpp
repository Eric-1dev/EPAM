#include <iostream>
#include "tasks.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru_RU");

	unsigned short int task_num;

	cout << "�������� �������:\n \
		\t1. ����������\n \
		\t2. �����\n \
		\t3. ������\n \
		\t4. ���������\n \
		" << endl;

	cin >> task_num;


	switch (task_num) {
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	case 4:
		task4();
		break;
	default:			// ���� ������� ������������ �����
		cout << "�������� �� ��������� 1-4!!!" << endl;
	}

	return 0;
}