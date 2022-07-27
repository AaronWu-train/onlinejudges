#include <cstdio>
using namespace std;
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


signed main() {
    int k, x, ans = 0;
    scanf("%d", &k);
    for (int i = 0; i <= k; ++i) {
        scanf("%d", &x);
        if (ans >= (1<<i) - 1) ans += x * (1 << i);
    }
    printf("%d", ans+1);
    return 0;
}

// http://cbdcoding.blogspot.com/2015/03/tioj-1634.html
