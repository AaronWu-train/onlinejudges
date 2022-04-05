#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;
int main() {
    while (true) {
        unsigned int n;
        cin >> n;
        if (n==0)break;
        cout << ((sqrt(n) == floor(sqrt(n)))?"yes\n":"no\n");
    }
    return 0;
}
