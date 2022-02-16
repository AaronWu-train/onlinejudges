#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <climits>
#define ll long long int
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;


int main() {_
    int n;
    cin >> n;
    int files[101];
    fill(files, files+101, 0);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        temp = (temp%1000-temp%10)/10;
        files[temp] += 1;
    }
    for (int i =0 ; i < 101; ++i) {
        if (files[i] != 0){
            cout << i << " " << files[i] << endl;
        }
    }
    return 0;
}
