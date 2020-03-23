/*
 * ����� ��� ������� ���� �������� � ������������ ��������,
 * �� ����� �� ������������ STL, ������� ���� �����������
 * ���������� �������, ������� ������ ����������� ��� �������
 * ������ ����������. ����� ������� ���������� � �������������� �����,
 * �� �������� ���-�� ���. �������� ���������� ����, ��, �����, �������� :)
*/

#include <iostream>
#include <string>
#include "tasks.h"

using namespace std;

// ��������� ���� ������� ������, ����� �� ������������ ����������� �������� STL
class MyVector {
public:
	MyVector() {
		this->arr = new char;
	}
	// ��������� �� �����
	~MyVector() {
		delete[] arr;
	}
	/* 
	 * ��������� ������� � ����� �������.
	 * ��� ����� ������� ����� ������, �� 
	 * ���� ������� ������ �����������,
	 * � �������� � ���� ���������� ������.
	*/
	void push_back(char c) {
		char *new_arr = new char[this->size + 1];
		for (uint16_t i = 0; i < this->size; ++i) {
			new_arr[i] = this->arr[i];
		}
		new_arr[this->size] = c;
		this->size++;
		delete[] arr;
		arr = new_arr;
	}
	void print_arr() {
		for (uint16_t i = 0; i < this->size; ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	// ����� ������� 2 �������� � ��������� sIndex � sIndex + 1
	int8_t erase_two(uint16_t sIndex) {
		if (this->size < 2)
			return -1;
		if (this->size == 2) {
			this->size = 0;
			return 0;
		}
		char *new_arr = new char[size - 2];
		uint16_t j = 0;
		for (uint16_t i = 0; i < this->size; ++i) {
			if (i != sIndex && i != (sIndex + 1))
				new_arr[j++] = this->arr[i];
		}
		this->size-=2;
		delete[] arr;
		arr = new_arr;

		return 1;
	}
	// ���������� �������� [], ����� ����� ���� ���������� � ��������� �� �������
	char operator[](uint16_t index) {
		return arr[index];
	}

	// ��������� ������ �������
	uint16_t get_size() {
		return this->size;
	}
private:
	uint16_t size = 0;
	char *arr;
};

/* 
 * �������� �������, ����������� ���������� �������.
 * ���� ���� ������, ������� �� �������.
 * ���� ������� - ������� ���� � ��������� ����
 * ���� ���� == true - ���������� �������� go,
 * ��������� � �������� ��������� ������ �� ��� �� ������.
 * ���� ����� ������ �� ������� go � ������� ��������
 * ��������, �� ������������������ ������������.
*/
void go(MyVector &_vector) {
	bool flag = false;
	for (uint16_t i = 0; i < _vector.get_size() - 1; i++) {
		if ((_vector[i] == '{' && _vector[i + 1] == '}') || \
			(_vector[i] == '(' && _vector[i + 1] == ')') || \
			(_vector[i] == '[' && _vector[i + 1] == ']')) {
			if (_vector.erase_two(i) > 0)
				flag = true;
		}
	}
	if (flag)
		go(_vector);
}

void task5() {
	cout << "��������� ������������������" << endl << endl;

	MyVector vector;
	string str;

	str = "()[(33) 3]{( (sdf f{dg[g]})e r)(g)[asd]}";
	//cout << "������� ��������� ������������������" << endl; // ���� ������������������ � ����������
	//getline(cin, str);

	for (uint16_t i = 0; i < str.length(); i++) {
		if (str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] == ')')
			vector.push_back(str[i]);
	}

	cout << "������������ ��������� ������������������: " << endl;
	vector.print_arr();

	go(vector);

	if (!vector.get_size())
		cout << "��� ���������� ��������� ������������������" << endl;
	else
		cout << "��� ������������ ��������� ������������������" << endl;
}