#include <iostream>
#include <vector> 
#define ll long long
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<ll> A(n);
	vector<ll> B(n);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	B[0] = A[0]; // 首項要特別處理！
	for (int i = 1; i < n; ++i) {
		B[i] = B[i-1] + A[i];
	}
	for (ll &i : B) {    // 神奇for 用法！
		cout << i << " \n"[&i == &B.back()]; 
		// 利用i的記憶體位置有沒有和B最後一項一樣來決定要不要換行
	}

}
