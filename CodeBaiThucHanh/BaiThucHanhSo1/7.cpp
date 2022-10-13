/*
    Author: Nguyen Huy Ngo
    School: Ha Noi University of industry
*/
#include <iostream>
#include <string.h>
using namespace std;
const int N = 1e3 + 5;
long long f[N];
long long fib(int n){
	if (f[n] != -1) return f[n];
	if (n <= 2) return f[n] = 1;
	return f[n] = fib(n-1) + fib(n-2);
}
int main () {
	int n;
	cin >> n;
	memset(f, -1, sizeof f);
	cout << fib(n) << "\n";
	return 0;
}
