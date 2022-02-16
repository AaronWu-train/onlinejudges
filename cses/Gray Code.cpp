
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    int n;
    cin >> n;
    vector<string>arr;
    vector<string>arrnew;
    arr.push_back("0");
    arr.push_back("1");
    for (int i = 2; i <= n; i++) {
        for (auto i : arr) {
            arrnew.push_back(i+"0");
        }
        for (auto i = arr.rbegin(); i!=arr.rend(); i++) {
            arrnew.push_back(*i+"1");
        }
        arr = arrnew;
        arrnew.clear();ㄊ
    }
    for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}
