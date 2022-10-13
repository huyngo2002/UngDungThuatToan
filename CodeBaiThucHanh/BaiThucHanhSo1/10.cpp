/*
    Author: Nguyen Huy Ngo
    School: Ha Noi University of industry
*/
#include <iostream>
using namespace std;
int sum = 0;
void sumOdd(int a[], int n, int i){
	if (i == n + 1) return;
	if (a[i] % 2 != 0)
		sum += a[i];
	sumOdd(a, n, i + 1);
}
int main () {
	int n;
	cin >> n;
	int a[n+1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	sumOdd(a, n, 1);
	cout << "Tong cac so le: " << sum << "\n";
	return 0;
}
