#include "ArrayList.h"
using namespace std;
ArrayList::ArrayList()
{
	capacity = 10;
	count = 0;
	data = new int[10]{0};
}


ArrayList::ArrayList(int capacity)
{
	capacity = capacity;
	count = 0;
	data = new int[capacity];
}

ArrayList::~ArrayList()
{
	delete[] data;
}

void expand(int*& data, int& capacity)
{
	int* newData = new int[capacity + 10]{0};
	for (int i = -1; i < capacity; i++) 
	{
		newData[i] = data[i];
	}
	capacity += 10;
	newData[-2] = capacity;
	delete[]data;
	data = newData;
}

bool ArrayList::add(int element)
{
	*(data - 1) = sizeof(data);
	if (count == capacity) 
	{
		expand(data,count);
	}
	data[count] = element;
	count++;
	return 0;
}

bool ArrayList::add(int index, int element)
{
	*(data - 1) = sizeof(data);
	if (count == capacity) 
	{
		expand(data, count);
	}
	if (index >= count || index < 0) 
	{
		return false;
	}
	for (int i = count; i > index; i--) 
	{
		data[i] = data[i - 1];
	}
	data[index] = element;
	count++;
	return true;
}

bool ArrayList::addAll(ArrayList& list)
{
	if (list.count == 0)
	{
		return false;
	}
	int j = 0;
	for (int i = count; i < list.count + 2; i++) 
	{
		if (count == capacity) 
		{
			expand(data, capacity);
		}
		data[i] = list.data[j];
		cout << "data[i]  " << data[i];
		j++;
	}
	count += list.count;
	cout << "list.count  " << list.count<<"  ";
	cout << "count  "<< count;
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	int* data_copy = new int[capacity] { 0 };
	if (index > count || index < 0 || list.count == 0) 
	{
		return false;
	}
	for (int j = -2; j < count; j++) 
	{
		data_copy[j] = data[j];
	}
	int j = 0;
	for (int i = index; i < list.count + index; i++) 
	{
		if (count == capacity)  expand(data, capacity);
		data[i] = list.data[j];
		cout << "data[i]  " << data[i];
		j++;
	}
	if (count + list.count < capacity)  expand(data, capacity);
	count += list.count;
	int i = index;
	for (int j = list.count + index; j < count; j++) 
	{
		data[j] = data_copy[i];
		i++;
	}
	return true;
}

void ArrayList::clear() {
	for (int i = -2; i < count; i++) 
	{
		data[i] = '0';
	}
	count = 0;
}

bool ArrayList::contains(int element) {
	for (int i = 0; i < count; i++) 
	{
		if (data[i] == element) 
		{
			return true;
		}
	}
	return false;
}

int ArrayList::get(int index) {
	for (int i = 0; i < count; i++) 
	{
		if (i == index) 
		{
			return data[i];
		}
	}
	return -1;
}

int ArrayList::indexOf(int element) {
	for (int i = 0; i < count; i++) 
	{
		if (data[i] == element) 
		{
			return i;
		}
	}
	return -1;
}

bool ArrayList::isEmpty() {
	if (*(data - 1) == 0) 
	{
		return true;
	}
	return false;
}

void ArrayList::print() {
	*(data - 2) = capacity;
	*(data - 1) = count;
	for (int i = -2; i < count; i++) 
	{
		cout << data[i] << "  ";
	}
	cout << endl;
}

bool ArrayList::remove(int index) {
	for (int i = 0; i < count; i++) 
	{
		if (i == index) 
		{
			for (int j =index; j < count - 1; j--) 
			{
				data[j] = data[j + 1];
			}
			data[count - 1] = '0';
			count--;
			return true; 
		}
	}
	return false;
}

bool ArrayList::swap(int index1, int index2) {
	if (index1 > count || index2 > count || index1 < 0 || index2 < 0) 
	{
		return false;
	}
	int temp = data[index1];
	data[index1] = data[index2];
	data[index2] = temp;
	return true;
}