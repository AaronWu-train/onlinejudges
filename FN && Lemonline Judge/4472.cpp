#include <iostream>
#include <vector>
#include <string>
#define pii pair<int,int>
int a[10005][10005];
int N,M;
const int mod = 1e8+7;
using namespace std;
vector<string>maze;
int p_adding[10005][10005];
int main() {
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
            if (i==1&&j==1)continue;
            if (maze[i][j]=='x') {
                a[i][j]=0;
                p_adding[i][j] =(p_adding[i-1][j]+p_adding[i][j-1]-p_adding[i-1][j-1])%mod;
            }else{
                p_adding[i][j] =(p_adding[i-1][j]+p_adding[i][j-1]-p_adding[i-1][j-1])%mod;
                a[i][j]=(a[i-1][j]+a[i][j-1]+p_adding[i][j]) % mod;
            }
            if (maze[i][j]=='p'){
                p_adding[i][j]=(p_adding[i][j]+a[i][j])%mod;
            }
        }
    }
    cout <<a[N][M]%mod<<endl;
    return 0;
}

