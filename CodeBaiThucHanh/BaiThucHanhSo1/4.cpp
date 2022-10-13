/*
    Author: Nguyen Huy Ngo
    School: Ha Noi University of industry
*/
#include <map>
#include <iostream>
using namespace std;
int n = 6, r = 4;
void combination(map<int, string> mp, int n, int r, int index, map<int, string> data, int i){
	if (index == r){
		for (int j = 0; j < r; j++){
			cout << data[j] << ' ';
		}
		cout << "\n";
		return;
	}
	if (i >= n)	return;
	data[index] = mp[i];
	combination(mp, n, r, index + 1, data, i + 1);
	combination(mp, n, r, index, data, i + 1);
}
void print(map<int, string> mp, int n, int r) {
	map<int, string> data;
	combination(mp, n, r, 0, data, 0);
}
int main () {
	string s[6] = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
	map<int, string> mp;
	for (int i = 0; i < 6; i++) mp[i] = s[i];
	print(mp, n, r);
	return 0;
}
