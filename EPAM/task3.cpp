/*
 * �� ������ �������, ��� ������� �������� ������������� ��������� �����.
 * �������� str.substr() ����� ���� �������� �� ������������ �����������.
 * � ������ ������� - ��� ����� ������ string, ����� ��, ��� ������������� �������� ==,
 * ������� ��� ���������� � ������� ������ string.
*/

#include <iostream>
#include <vector>
#include <string>
#include "tasks.h"

using namespace std;

void task3() {
	cout << "������" << endl << endl;

	vector<string> word_arr;

	string str = "���������� ������ ���������� � ����������� ��������� � ������ \
� �������� ����� ��� �� ��������� ������������. ����� ����� ��������� \
������������ ���, ��� ������������� � �����������, ��� ����������� ��������. \
�� ���� �������� ��� \"�������\" �� ������� �� �������� � ������������� ��. \
�� ������ ����������� ���������, �������� ��������������� �������� � ������ \
������������� ������������ �������� � ����� ������� ��� �������, �������, \
�������������� � ��������. ��������� ��� ������� �� 27 % �� 33 %. ����� \
��������� ���� ����������, ��������� ������������� ����������� ���� �� ���������, \
������ ��������. ��� ���� �� �������, ��� � ������ ���� ��� ���� ����� ������� \
��� �������� ������� ���. �� ��� ������, ���������� ������ ��������� ��������� \
������������� ���������� � ����� �� ����������� ������������.";

	cout << "�������� ������:\n" + str << endl;

	/*
	 * ������� �������� ������ �� ����� � ������� �� � ������.
	 * ��� ����� ���������� ������� � ���� ��, ������� ��������� �����:
	 * ������� � ����� ����������. ���������� ������� ������� ������� ����� (spos)
	 * � ��� ����� (j). ����� �������� ����� � ������.
	*/
	unsigned short int j = 0;
	uint16_t spos;
	for (uint16_t i = 0; i < str.length(); i++) {
		if (str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '!' && str[i] != '?') {
			if (j == 0)
				spos = i;
			j++;
		}
		else {
			if (j) {
				word_arr.push_back(str.substr(spos, j));
				j = 0;
			}
		}
	}

	cout << "\n�����, ������������� ������ ���� ���:\n" << endl;

	// ������ ���������� ������ ����� � ������������ � �������, ���� ��� �� �����������
	bool flag;
	for (uint16_t i = 0; i < word_arr.size() - 1; ++i) {
		flag = true;
		for (uint16_t j = i + 1; j < word_arr.size(); ++j) {
			if (word_arr[i] == word_arr[j])
				flag = false;
		}
		if (flag)
			cout << word_arr[i] << " ";
	}
	cout << endl;
}