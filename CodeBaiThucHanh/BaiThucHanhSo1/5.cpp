/*
    Author: Nguyen Huy Ngo
    School: Ha Noi University of industry
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main () {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	vector<int> v;
	for(int i = 1; i <= n; i++) v.push_back(i);
	do {
		for (const auto& x : v) cout << x << ' ';
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}
