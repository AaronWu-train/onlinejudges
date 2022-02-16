#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
bool arr[8][8];
int put_queen(int y, bitset<8>level,bitset<15>diag,bitset<15>rdiag){
    int ways = 0;
    for (int x = 0; x < 8; x++) {
        if (!arr[x][y] && !level[x] && !diag[x+y] && !rdiag[x-y+8]) {
            if (y!=7) {
                auto new_level = level;
                new_level[x] = 1;
                auto new_diag = diag;
                new_diag[x+y] = 1;
                auto new_rdiag = rdiag;
                new_rdiag[x-y+8] = 1;
                ways += put_queen(y+1, new_level, new_diag, new_rdiag);
            }else{
                ways++;
            }
        }
    }
    return ways;
}

int main() {_
    for (int i = 0; i < 8; i++) {
        string temp ;
        cin >> temp;
        for (int j = 0; j < 8; j++) {
            arr[i][j] = (temp[j]=='*');
        }
    }
    bitset<8>level = 0;
    bitset<15>diag = 0;
    bitset<15>rdiag = 0;
    cout << put_queen(0, level, diag, rdiag) << endl;
    
    
    return 0;
}
