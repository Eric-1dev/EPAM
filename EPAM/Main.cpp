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
		\t5. ��������� ������������������\n \
		" << endl;

	cin >> task_num;
	cin.ignore(32767, '\n');


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
	case 5:
		task5();
		break;
	default:			// ���� ������� ������������ �����
		cout << "�������� �� ��������� 1-5!!!" << endl;
		break;
	}

	cin.get();
	cin.ignore();
	return 0;
}