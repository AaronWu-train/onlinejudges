#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long n;
    cin >> n;
    vector<long> vec(n);
    for (long i=0; i<n ;i++){cin >> vec[i];}
    sort(vec.begin(), vec.end(), less<int>());
    for (long i:vec){cout << i <<" ";}
    return 0;
}
