/*
    Author: Nguyen Huy Ngo
    School: Ha Noi University of industry
*/
#include <iostream>
using namespace std;
void show(char arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}
void binary(int n, char arr[], int i) {
	if (i == n) {
		show(arr, n);
		return;
	}
	arr[i] = 'a';
	binary(n, arr, i + 1);
	arr[i] = 'b';
	binary(n, arr, i + 1);
}
int main () {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	char a[n];
	cout << "Cac chuoi nhi phan co do dai " << n << " la:\n";
	binary(n, a, 0);
	return 0;
}
