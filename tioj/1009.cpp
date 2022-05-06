#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <bitset>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main() {_
    string a[3];
    getline(cin, a[0], ':');
    getline(cin, a[1], ':');
    getline(cin, a[2], '\n');
    string b[3];
    getline(cin, b[0], ':');
    getline(cin, b[1], ':');
    getline(cin, b[2], '\n');
    int c = stoi(a[0])*60*60 + stoi(a[1])*60+stoi(a[2]);
    int d = stoi(b[0])*60*60 + stoi(b[1])*60+stoi(b[2]);
    if (d < c) d+=24*60*60;
    int e = d-c;
    if (e/3600 < 10) cout << 0;
    cout << e/3600 << ':';
    e%=3600;
    if (e/60 < 10) cout << 0;
    cout << e/60 << ':';
    e%=60;
    if (e < 10) cout << 0;
    cout << e << endl;
    return 0;
}
