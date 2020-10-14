#include <iostream>
#include <cstdlib> // system("pause");
#include"ArrayList.h"
#define N 10
using namespace std;

void meny() {
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - ��������� ������� � �����" << endl; 
	cout << "2 - ��������� ������� � ������� index" << endl; 
	cout << "3 - ��������� ��� �������� �� ������ list � �����" << endl; 
	cout << "4 - ��������� ��� �������� �� ������ list, ������� � ������� index" << endl; 
	cout << "5 - ������� ��� �������� �� ������" << endl; 
	cout << "6 - ���������� �� ��-� � ������" << endl;
	cout << "7 - �������� ������� �� �������" << endl;
	cout << "8 - ����� �������� � ������" << endl;
	cout << "8 - �������� ������ �� �������" << endl; 
	cout << "10 - ������� ������" << endl;
	cout << "11 - �������� �������� �� ������ " << endl;
	cout << "12 - �������� ������� �������� " << endl;
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
		cout << "������� �����, ������� �� ������ ��������?" << endl;
		cin >> element;
		a.add(element);
	}

	if (x == 2) {
		int  element = 0;
		int index = 0;
		cout << "����� ������� �� ������ ��������?" << endl;
		cin >> element;
		cout << "����� ������ ������ ����� �������?" << endl;
		cin >> index;
		cout << a.add(index, element) << endl;
		system("pause");
	}
	if (x == 3) {
		ArrayList list;
		cout << "������� ������, ������� �� ������ ��������?" << endl;
		cout << "������� -1000 ����� �������� ���������� ���������� �������" << endl;
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
		cout << "������� ������, ������� �� ������ ��������?" << endl;
		cout << "������� -1000 ����� �������� ���������� ���������� �������" << endl;
		int x = 0;
		int index = 0;
		cin >> x;
		while (x != -1000) {
			list.add(x);
			cin >> x;
		}
		cout << "� ������ ������� ���������� �������� ���� ������?" << endl;
		cin >> index;
		cout << a.addAll(index, list) << endl;
		system("pause");
	}
	if (x == 5) {
		a.clear();
	}
	if (x == 6) {
		int element = 0;
		cout << "������� ������ ��-�� �� ������ ���������?" << endl;
		cin >> element;
		cout << a.contains(element) << endl;
		system("pause");
	}
	if (x == 7) {
		int index = 0;
		cout << "������� ������ ��-��" << endl;
		cin >> index;
		cout << a.get(index) << endl;
		system("pause");
	}
	if (x == 8) {
		int element = 0;
		cout << "������� ������ ��-�� �� ������ ���������?" << endl;
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
		cout << "������� ������ ��-��,������� ���� �������" << endl;
		cin >> index;
		cout << a.remove(index) << endl;
		system("pause");
	}
	if (x == 12) {
		int index1 = 0;
		int index2 = 0;
		cout << "������� ������� 2� ��-���,������� ���� �������� �������" << endl;
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