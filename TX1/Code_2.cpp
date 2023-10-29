#include <iostream>
#include <algorithm>
#include <vector>
class Computer {
	private:
		std::string brandName;
		double importPrice, sellingPrice;
	public:
		Computer() {
			this->brandName = "";
			this->importPrice = this->sellingPrice = 0.0;
		}
		Computer(std::string brandName, double importPrice, double sellingPrice) {
			this->brandName = brandName;
			this->importPrice = importPrice;
			this->sellingPrice = sellingPrice;
		}
		std::string toString() const {
			return "{BrandName=" + this->brandName + "; ImportPrice=" + std::to_string(this->importPrice) + "; SellingPrice=" + std::to_string(this->sellingPrice) + "}\n";
		}
		std::string display_() const {
			return "{BrandName=" + this->brandName + "; Interest=" + std::to_string(this->getInterest()) + "}";
		}
		std::string getBrandName() const {
			return this->brandName;
		}
		int getInterest() const {
			return this->sellingPrice - this->importPrice;
		}
};
void print(Computer* computers, int n) {
	if (n == 1) {
		std::cout << computers[0].toString();
		return;
	}
	print(computers, n - 1);
	std::cout << computers[n - 1].toString();
}
void swap(int &a, int &b) {
	int tg = a;
	a = b;
	b = tg;
}
void view_config(Computer* computers, int x[], int n) {
	for (int i = 1; i <= n; i++) {
		std::cout << "Index " << i << ": " << computers[x[i] - 1].getBrandName() << '\t';
	}
	std::cout << std::endl;
}
void next_config(int x[], int n, int i) {
	int k = n;
	while (x[k] < x[i]) {
		k--;
	}
	swap(x[i], x[k]);
	int j = n;
	i++;
	while (i < j) {
		swap(x[i], x[j]);
		i++;
		j--;
	}
}
void listing_configs(Computer* computers, int n) {
	int i, x[n] = {0};
	for (int i = 1; i <= n; i++) {
		x[i] = i;
	}
	do {
		view_config(computers, x, n);
		i = n - 1;
		while (i > 0 && x[i] > x[i + 1]) i--;
		if (i > 0) {
			next_config(x, n, i);
		}
	} while (i > 0);
}
std::vector<Computer> greedy(Computer* computers, int n, int q) {
	std::vector<Computer> ans;
	for (int i = 0; i < n; ++i) {
		if (q >= computers[i].getInterest()) {
			ans.push_back(computers[i]);
			q -= computers[i].getInterest();
		}
		if (q == 0) {
			break;
		}
	}
	if (q > 0) ans.clear();
	return ans;
}
void quick_sort(Computer* a, int left, int right, std::string type) {
	if (type == "brandName") {
		if (left < right) {
			int k = (left + right) / 2;
			std::string t = a[k].getBrandName();
			int i = left, j = right;
			do {
				while (a[i].getBrandName() < t) i = i + 1;
				while (a[j].getBrandName() > t) j = j - 1;
				if (i <= j) {
					Computer tg = a[i];
					a[i] = a[j];
					a[j] = tg;
					i = i + 1;
					j = j - 1;
				}
			} while (i <= j);
			quick_sort(a, left, j, type);
			quick_sort(a, i, right, type);
		}
	}
	if (type == "Interest") {
		if (left < right) {
			int k = (left + right) / 2;
			double t = a[k].getInterest();
			int i = left, j = right;
			do {
				while (a[i].getInterest() > t) i = i + 1;
				while (a[j].getInterest() < t) j = j - 1;
				if (i <= j) {
					Computer tg = a[i];
					a[i] = a[j];
					a[j] = tg;
					i = i + 1;
					j = j - 1;
				}
			} while (i <= j);
			quick_sort(a, left, j, type);
			quick_sort(a, i, right, type);
		}
	}
}
int main() {
	// Cau 1.1
	int n = 7;
	Computer* computers = new Computer[n];
	*(computers + 0) = Computer("MT1", 10, 15);
	*(computers + 1) = Computer("MT2", 11, 14);
	*(computers + 2) = Computer("MT3", 12, 13);
	*(computers + 3) = Computer("MT4", 13, 20);
	*(computers + 4) = Computer("MT5", 14, 26);
	*(computers + 5) = Computer("MT6", 15, 23);
	*(computers + 6) = Computer("MT7", 16, 18);
	// Cau 1.2
	std::cout << "Danh sach cac may tinh:\n";
	print(computers, n);
	std::cout << "--------------------------------------------------------------\n";
	quick_sort(computers, 0, n - 1, "Interest");
	print(computers, n);
	std::cout << "--------------------------------------------------------------\n";
	// Cau 2.1
	int q = 32;
	std::vector<Computer> res = greedy(computers, n, q);
	if (res.empty()) {
		std::cout << "Khong co cach nao de tong so tien lai dung bang " << q << std::endl;
	} else {
		std::cout << "Can it nhat " << (int)res.size() << " may tinh de tong so tien lai dung bang " << q << std::endl;
		std::cout << "Gom cac may tinh: " << std::endl;
		for (int i = 0; i < (int)res.size(); ++i) {
			std::cout << res[i].display_() << std::endl;
		}
	}
	std::cout << "--------------------------------------------------------------\n";
	// Cau 2.2
	quick_sort(computers, 0, n - 1, "brandName");
	listing_configs(computers, n);
	return 0;
}