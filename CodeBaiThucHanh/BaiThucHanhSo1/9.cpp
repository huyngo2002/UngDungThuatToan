/*
    Author: Nguyen Huy Ngo
    School: Ha Noi University of industry
*/
#include <iostream>
using namespace std;
int sumDigit(long long n){
	if (n / 10 == 0) return n;
	return (n % 10) + sumDigit(n / 10); 
}
int main () {
	long long n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Tong chu so cua " << n << " la: " << sumDigit(n);
	return 0;
}
