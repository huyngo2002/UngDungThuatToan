/*
    Author: Nguyen Huy Ngo
    School: Ha Noi University of industry
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main () {
	string s[6] = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
	sort(s, s + 6);
	do {
		for (const auto& x : s) cout << x << ' ';
		cout << "\n";
	} while (next_permutation(s, s + 6));
	return 0;
}
