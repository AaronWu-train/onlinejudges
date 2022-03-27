#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <climits>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int arr[9][9];
bitset<10>small_area[10];
string whicharea[9] =  {"000111222","000111222","000111222",
                        "333444555","333444555","333444555",
                        "666777888","666777888","666777888"};
vector<pair<int, int>>tofill;

inline bool valid(int &, int &, int &);
void printArr();
void getArr();
void dfs(int);
int answerCount = 0;

int main() {_
    getArr();
    if (tofill.empty()) printArr();
    else dfs(0);
    cout << "there are a total of "<< answerCount <<" solution(s).\n";
    return 0;
}


inline bool valid(int &x, int &y, int &value){
    for (int i = 0; i < 9; ++i) {
        if (i==y) continue;
        if (arr[x][i] == value) {
            return 0;
        }
    }
    for (int i = 0; i < 9; ++i) {
        if (i==x) continue;
        if (arr[i][y] == value) {
            return 0;
        }
    }
    if (small_area[whicharea[x][y]-'0'][value]) {
        return 0;
    }
    return 1;
}

void printArr(){
    answerCount++;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void getArr(){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> arr[i][j];
            if (arr[i][j]!=0) {
                small_area[whicharea[i][j]-'0'][arr[i][j]] = 1;
            }else{
                tofill.push_back(make_pair(i, j));
            }
        }
    }
}

void dfs(int index){
    int& x = tofill[index].first;
    int& y = tofill[index].second;
    for (int i = 1; i <= 9; ++i) {
        if (valid(x, y, i)) {
            arr[x][y] = i;
            small_area[whicharea[x][y]-'0'][i] = 1;
            if (index == tofill.size()-1) printArr();
            else dfs(index+1);
            arr[x][y] = 0;
            small_area[whicharea[x][y]-'0'][i] = 0;
        }
    }
    return;
}
