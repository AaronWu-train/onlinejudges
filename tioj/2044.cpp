// MLE
#include <stdio.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define AI(x) begin(x),end(x)

int min(int a, int b) {
	if (a <= b) return a;
	return b;
}
int arr[1005][1005];
signed main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &arr[i][j]);
			}
		}
		bool check = 1;
		for (int d = 0; d < min(m, n); ++d) {
			int ck = arr[0][d];
			for (int i = 0, j = d; i < n && j < m; ++i, ++j) {
				if (arr[i][j] != ck) {
					check = 0;
					break;
				}	
			}	
			if (!check) break;
			ck = arr[d][0];
			for (int i = d, j = 0; i < n && j < m; ++i, ++j) {
				if (arr[i][j] != ck) {
					check = 0;
					break;
				}
			}
		}
		if (!check) puts("No");
		else puts("Yes");
	}

	return 0;
}
