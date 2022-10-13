/*
    Author: Nguyen Huy Ngo
    School: Ha Noi University of industry
*/
#include <iostream>
using namespace std;
void combinationUtil(int arr[], int n, int r, int index, int data[], int i) {
	if (index == r) {
		for (int j = 0; j < r; j++)
			cout << " " << data[j];
		cout <<"\n";
		return;
	}
	if (i >= n)
		return;
	data[index] = arr[i];
	combinationUtil(arr, n, r, index + 1, data, i + 1);
	combinationUtil(arr, n, r, index, data, i + 1);
}
void printCombination(int arr[], int n, int r) {
	int data[r];
	combinationUtil(arr, n, r, 0, data, 0);
}
int main () {
	int n, r;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap r: ";
	cin >> r;
	int a[n+1];
	cout << "Nhap mang gom " << n << " phan tu:\n";
	for (int i = 0; i < n; i++){
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	cout << "Cac tap con gom " << r << " phan tu:\n";
	printCombination(a, n, r);
	return 0;
}
