#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define pii pair<int,int>
int a[2005][2005];
const int mod = 1e8+7;
using namespace std;
vector<string> maze;
int p_adding[2005];
/*void update(int t,int d){
    whlie(t<=M){
        
    }
}*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >>N>>M;
    maze.push_back("_");
    p_adding[0]=0;
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
            }else{
                a[i][j]=(a[i-1][j]+a[i][j-1]+p_adding[j]) % mod;
            }
            if (maze[i][j]=='p'){
                for (int k = j; k<=M; k++){
                    p_adding[k]=(p_adding[k]+a[i][j])%mod;
                }
            }
        }
    }
    cout <<a[N][M]<<endl;
    return 0;
}

