/*
 * Здесь мне удобнее было работать с динамическим массивом,
 * но чтобы не использовать STL, написал свою примитивную
 * реализацию вектора, имеющую только необходимый для решения
 * задачи функционал. Видел готовую реализацию с использованием стэка,
 * но хотелось что-то своё. Возможно получилась дичь, но, вроде, работает :)
*/

#include <iostream>
#include <string>
#include "tasks.h"

using namespace std;

// Реализуем свой простой вектор, чтобы не пользоваться стандартным решением STL
class MyVector {
public:
	MyVector() {
		this->arr = new char;
	}
	// Подчищаем за собой
	~MyVector() {
		delete[] arr;
	}
	/* 
	 * Добавляем элемент в конец массива.
	 * Для этого создаем новый массив, на 
	 * один элемент больше предыдущего,
	 * и копируем в него предыдущий массив.
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
	// Метод удаляет 2 элемента с индексами sIndex и sIndex + 1
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
	// Перегрузим оператор [], чтобы можно было обращаться к элементам по индексу
	char operator[](uint16_t index) {
		return arr[index];
	}

	// Возращает размер массива
	uint16_t get_size() {
		return this->size;
	}
private:
	uint16_t size = 0;
	char *arr;
};

/* 
 * Основная функция, реализующая требование задания.
 * Ищем пары скобок, проходя по массиву.
 * Если находим - удаляем пару и высталяем флаг
 * Если флаг == true - рекурсивно вызываем go,
 * передавая в качестве параметра ссылку на тот же вектор.
 * Если после выхода из функции go в векторе остались
 * элементы, то последовательность неправильная.
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
	cout << "Скобочная последовательность" << endl << endl;

	MyVector vector;
	string str;

	str = "()[(33) 3]{( (sdf f{dg[g]})e r)(g)[asd]}";
	//cout << "Введите скобочную последовательность" << endl; // Ввод последовательности с клавиатуры
	//getline(cin, str);

	for (uint16_t i = 0; i < str.length(); i++) {
		if (str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] == ')')
			vector.push_back(str[i]);
	}

	cout << "Получившаяся скобочная последовательность: " << endl;
	vector.print_arr();

	go(vector);

	if (!vector.get_size())
		cout << "Это правильная скобочная последовательность" << endl;
	else
		cout << "Это неправильная скобочная последовательность" << endl;
}