#include <iostream>
#include <cstdlib> // system("pause");
#include"ArrayList.h"
#define N 10
using namespace std;

void meny() {
	cout << "0 - Выйти из программы" << endl;
	cout << "1 - Добавляет элемент в конец" << endl; 
	cout << "2 - Добавляет элемент в позицию index" << endl; 
	cout << "3 - Добавляет все элементы из списка list в конец" << endl; 
	cout << "4 - Добавляет все элементы из списка list, начиная с позиции index" << endl; 
	cout << "5 - Удалить все элементы из списка" << endl; 
	cout << "6 - Содержится ли эл-т в списке" << endl;
	cout << "7 - Получить элемент по индексу" << endl;
	cout << "8 - Поиск элемента в списке" << endl;
	cout << "8 - Проверка списка на пустоту" << endl; 
	cout << "10 - Вывести список" << endl;
	cout << "11 - Удаление элемента из списка " << endl;
	cout << "12 - Поменять местами элементы " << endl;
}

int* initArray(int capacity)
{
	int* result = new int[capacity + 2]{ 0 };
	result += 2;
	*(result - 2) = capacity;
	return result;
}

void check(ArrayList& a, int x) {
	if (x == 1) {
		int element = 0;
		cout << "Введите число, которое Вы хотите добавить?" << endl;
		cin >> element;
		a.add(element);
	}

	if (x == 2) {
		int  element = 0;
		int index = 0;
		cout << "Какой элемент Вы хотите добавить?" << endl;
		cin >> element;
		cout << "Какой индекс должен иметь элемент?" << endl;
		cin >> index;
		cout << a.add(index, element) << endl;
		system("pause");
	}
	if (x == 3) {
		ArrayList list;
		cout << "Введите список, который Вы хотите добавить?" << endl;
		cout << "Введите -1000 когда заходите прекратить пополнение массива" << endl;
		int x = 0;
		cin >> x;
		while (x != -1000) {
			list.add(x);
			cin >> x;
		}
		cout << a.addAll(list) << endl;
		system("pause");
	}
	if (x == 4) {
		ArrayList list;
		cout << "Введите список, который Вы хотите добавить?" << endl;
		cout << "Введите -1000 когда заходите прекратить пополнение массива" << endl;
		int x = 0;
		int index = 0;
		cin >> x;
		while (x != -1000) {
			list.add(x);
			cin >> x;
		}
		cout << "С какого индекса необходимо вставить этот список?" << endl;
		cin >> index;
		cout << a.addAll(index, list) << endl;
		system("pause");
	}
	if (x == 5) {
		a.clear();
	}
	if (x == 6) {
		int element = 0;
		cout << "Наличие какого эл-та Вы хотите проверить?" << endl;
		cin >> element;
		cout << a.contains(element) << endl;
		system("pause");
	}
	if (x == 7) {
		int index = 0;
		cout << "Введите индекс эл-та" << endl;
		cin >> index;
		cout << a.get(index) << endl;
		system("pause");
	}
	if (x == 8) {
		int element = 0;
		cout << "Наличие какого эл-та Вы хотите проверить?" << endl;
		cin >> element;
		cout << a.indexOf(element) << endl;
		system("pause");
	}
	if (x == 9) {
		cout << a.isEmpty() << endl;
		system("pause");
	}
	if (x == 10) {
		a.print();
	}
	if (x == 11) {
		int index = 0;
		cout << "Введите индекс эл-та,который надо удалить" << endl;
		cin >> index;
		cout << a.remove(index) << endl;
		system("pause");
	}
	if (x == 12) {
		int index1 = 0;
		int index2 = 0;
		cout << "Введите индексы 2х эл-тов,который надо поменять местами" << endl;
		cin >> index1 >> index2;
		cout << a.swap(index1, index2) << endl;
		system("pause");
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ArrayList a;
	int x = 1;
	int n = 0;

	while (x != 0) {
		system("cls");
		meny();
		cin >> x;
		check(a, x);
		system("pause");
	}
	return 0;
}