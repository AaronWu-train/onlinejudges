#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define _ ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main() {_
    string a;
    cin >> a;
    int arr[26] = {0};
    for (auto i : a) {
        arr[i-'A']++;
    }
    bool odd = 0;
    char oddchr = '-';
    string newstr = "";
    for (int i = 0;i<26;i++) {
        if (arr[i]&1) {
            if (odd) {
                cout << "NO SOLUTION" << endl;
                return 0;
            }else{
                odd = 1;
                oddchr = 'A'+i;
            }
        }
        for (int j = 0; j < arr[i]/2; j++) {
            newstr.push_back((char)('A'+i));
        }
    }
    string b = newstr;
    reverse(newstr.begin(),newstr.end());
    if (odd) {
        b.push_back(oddchr);
    }
    b+=newstr;
    cout << b << endl;
    return 0;
}
