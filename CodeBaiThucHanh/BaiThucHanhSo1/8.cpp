/*
    Author: Nguyen Huy Ngo
    School: Ha Noi University of industry
*/
#include <iostream>
using namespace std;
#define MAX 20
// Hàm in ma tr?n
void inmt(int a[][MAX], int d, int c) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			cout.width(4);
			cout << a[i][j];
		}
		cout << endl;
	}
}
/*
Hàm tìm du?ng di du l?ch theo phuong pháp tham lam
Hàm tr? v? 0 n?u không tim du?c du?ng di, ngu?c l?i tr? v? t?ng chi phí c?a du?ng di tìm du?c
Ð?nh xu?t phát có th? t? là start
Th? t? các d?nh di qua luu trong m?ng path
Ð? dài du?ng di tìm du?c luu trong bi?n np
*/

int timduong(int a[][MAX], int n, int start, int path[], int &np) {
	// Cac bien can thiet va khoi tao
	np = 0; // ban dau chua di qua dinh nao ca
	int mark[MAX]; // mang co hieu danh dau cac dinh da duoc di qua chua
	int cur = start; // dinh hien tai dang dung
	int next; // co hieu ghi nhan xem co di tiep duoc nua khong
	int tongcp = 0; // tong chi phi cua duong di
	// ban dau, xu ly dinh xuat phat
	path[np++] = start; // them dinh nay vao danh sach duong di
	for (int i = 0; i < n; i++)	mark[i] = 0;
	mark[start] = 1; // da di qua dinh xuat phat roi
	// bat dau hanh trinh tim duong di
	do {
		// tim dinh dau tien co the di duoc tu dinh cur
		int i = 0;
		while(i < n && (a[cur][i] == 0 || mark[i] == 1)) i++;
		// xet ket qua
		if (i >= n) next = -1; // het duong di roi
		else {
			next = i; // dinh i se la dinh tiep theo co the di
			// tim dinh co the di duoc co chi phi thap nhat
			for (; i < n; i++)	// duyet tiep
				if(mark[i] == 0 && a[cur][i] < a[cur][next])
					next = i;
			// di toi dinh next
			path[np++] = next; // them vao ds duong di
			mark[next] = 1; // danh dau da di
			tongcp += a[cur][next]; // cap nhat lai tong chi phi
			cur = next; // luc nay dinh next tro thanh dinh hien tai
		}
	} while(next != -1); // next  == -1 tuc la da het duong di
	// xem xet de ket luan
	if (np < n)	// chua di qua het cac dinh
		return 0;
	else {
		if (a[cur][start]) { // co duong di tu dinh cuoi ve dinh dau
			tongcp += a[cur][start];
			return tongcp; // thanh cong
		} else
			return 0; // khong co duong quay ve
	}
}
int main() {
	int a[MAX][MAX];
	int n;
	do {
		cout << "Nhap so nguyen duong n: ";
		cin >> n;
		if (n <= 0) cout << "Ban nhap sai. Moi nhap lai:\n";
	} while(n <= 0);
	cout << "Moi ban nhap ma tran chi phi:\n";
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "\ta[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
	inmt(a, n, n);
	// tim duong di du lich
	int tongcp;	// tong chi phi bo ra
	int path[MAX]; // thu tu cac dinh di qua
	int np; // do dai duong di
	tongcp = timduong(a, n, 0, path, np);
	// ket luan
	if(tongcp == 0) cout << "khong tim duoc duong di!\n";
	else {
		cout << "Tim duoc duong di: ";
		for (int i = 0; i < np; i++)
			cout << path[i] << "-->";
		cout << "0" << endl; // dinh xuat phat cung la dinh cuoi cung
		cout << "Tong chi phi: " << tongcp << endl;
	}
	return 0;
}
/*
0 0 10 10 9 0 0 0 0
0 0 0 0 0 0 8 12 5
10 0 0 6 0 0 0 20 0
10 0 6 0 7 7 8 0 0
9 0 0 7 0 0 0 0 6
0 0 0 7 0 0 10 15 0 
0 8 0 8 0 10 0 0 5
0 12 20 0 0 15 0 0 0
0 5 0 0 6 0 5 0 0
*/
