// AC
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define AI(x) begin(x),end(x)
#ifdef DEBUG 
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
ll a[2][10005];
ll pre[2][10005];
int N,M;
const int mod = 1e8+7;
using namespace std;
vector<string>maze;

int main() {_
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>N>>M;
    maze.push_back("_");
    for (int i=0; i<N; i++) {
        string str;
        cin >> str;
        str="_"+str;
        maze.push_back(str);
    }
    a[1][1]=1;
	for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
			
            pre[i%2][j] = (pre[(i-1)%2][j]+pre[i%2][j-1]-pre[(i-1)%2][j-1]+mod)%mod;
			if (!(i == 1 && j == 1)) a[i%2][j] = 0;

            if (maze[i][j]=='x') {
                a[i%2][j]=0;
            }else{
                a[i%2][j] += ( a[(i-1)%2][j] + a[i%2][j-1]);
				a[i%2][j] += pre[i%2][j];
				a[i%2][j] %= mod;
            }
            if (maze[i][j]=='p') {
				pre[i%2][j] += a[i%2][j];
            }
			debug(i, j, a[i%2][j],  pre[i%2][j]);
        }
    }

    cout <<a[N%2][M]%mod<<endl;
    return 0;
}

