#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
class Job {
	private:
		std::string code; 
		double start, finish;
	public:
		Job() {
			code = "";
			start = finish = 0;
		}
		Job(std::string code, double start, double finish) {
			this->code = code;
			this->start = start;
			this->finish = finish;
		}
		std::string toString() {
			std::string res = "";
			res += "[Code = ";
			res += code;
			res += ", Start = ";
			res += std::to_string(start);
			res += ", finish = ";
			res += std::to_string(finish);
			res += "]";
			return res;
		}
		double timeWork() {
			return this->finish - this->start;
		}
		bool operator<(const Job& other) {
			return this->finish < other.finish;
		}
		double getStart() {
			return this->start;
		}
		double getFinish() {
			return this->finish;
		}
		std::string getMa() {
			return this->code;
		}
};
double caculate(Job* jobs, int n) {
	if (n == 1) {
		return jobs[0].timeWork();
	}
	return caculate(jobs, n - 1) + jobs[n - 1].timeWork();
}
void combination(std::map<int, std::string> mp, int n, int r, int index, std::map<int, std::string> data, int i){
	if (index == r){
		for (int j = 0; j < r; j++){
			std::cout << data[j] << ' ';
		}
		std::cout << "\n";
		return;
	}
	if (i >= n)	return;
	data[index] = mp[i];
	combination(mp, n, r, index + 1, data, i + 1);
	combination(mp, n, r, index, data, i + 1);
}
void print(std::map<int, std::string> mp, int n, int r) {
	std::map<int, std::string> data;
	combination(mp, n, r, 0, data, 0);
}
int main() {
	int n = 7;
	Job* jobs = new Job[7];
	jobs[0] = Job("code1", 8, 8.5);
	jobs[1] = Job("code3", 10, 11.5);
	jobs[2] = Job("code7", 14, 14.5);
	jobs[3] = Job("code2", 9, 11);
	jobs[4] = Job("code4", 11, 12.5);
	jobs[5] = Job("code5", 12, 13);
	jobs[6] = Job("code6", 13, 13.5);
	// Cau 1.1:
	std::cout << "Danh sach cac cong viec la:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << jobs[i].toString() << '\n';
	}
	std::cout << "----------------------------------------------------\n";
	// Cau 1.2:
	std::cout << "Tong thoi gian thuc hien tat ca cac cong viec: " << caculate(jobs, n) << '\n';
	std::cout << "----------------------------------------------------\n";
	// Cau 2.1
	std::sort(jobs, jobs + n); 
	std::vector<int> ans; 
	for (int i = 0; i < n; ++i) {
		Job job = jobs[i];
		bool check = true;
		for (int j = 0; j < (int) ans.size(); ++j) {
			if (job.getFinish() >= jobs[ans[j]].getStart()
			&& job.getStart() <= jobs[ans[j]].getFinish()) {
				check = false;
				break;
			}
		}
		if (check) {
			ans.push_back(i);
		}
	}
	std::cout << "So luong cong viec thuc hien duoc nhieu nhat la: " << (int) ans.size() << '\n';
	std::cout << "Gom cac cong viec la:\n";
	for (int i = 0; i < (int) ans.size(); ++i) {
		std::cout << jobs[ans[i]].toString() << '\n';
	}
	std::cout << "----------------------------------------------------\n";
	// Cau 2.2
	std::vector<std::string> s;
	for (int i = 0; i < n; ++i) {
		s.push_back(jobs[i].getMa());
	}
	n = 7;
	int r = 5;
	std::map<int, std::string> mp;
	for (int i = 0; i < n; ++i) mp[i] = s[i];
	print(mp, n, r);
	return 0;
}

