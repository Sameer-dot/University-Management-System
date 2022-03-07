#pragma once

template <class list>
static void Shrink(list**& arr, int ind, int& current) {
	for (int i = ind; i + 1 < current - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	list** temp = new list * [current - 1];
	for (int i = 0; i < current - 1; i++) {
		temp[i] = arr[i];
	}
	delete[]arr;
	arr = temp;
	current--;
}


template <class list>
static void Grow(list**& arr, int& ind) {
	list** temp = new list * [ind + 1];
	for (int i = 0; i < ind; i++) {
		temp[i] = arr[i];
	}
	delete[]arr;
	arr = temp;
	ind ++;
}

template <class list>
static void Grow1D(list*& arr,int& ind){
	list* temp = new list * [ind + 1];
	for (int i = 0; i < ind; i++) {
		temp[i] = arr[i];
	}
	delete []arr;
	arr = temp;
	ind++;
}

template <class list>
static void Shrink1D(list*& arr, int ind, int& current) {
	for (int i = ind; i + 1 < current - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	list* temp = new list * [current - 1];
	for (int i = 0; i < current - 1; i++) {
		temp[i] = arr[i];
	}
	delete[]arr;
	arr = temp;
	current--;
}