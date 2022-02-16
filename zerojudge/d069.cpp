#include <iostream>
using namespace std;

int main(){
    int n,i = 0,input = 0;
    cin >> n;
    while (i < n) {
        cin >> input;
        if ((input % 4 == 0) && (input % 100 !=0 || input % 400 ==0)){
            cout << "a leap year" << endl;
        }
        else {
            cout << "a normal year";
        }
        i++;
    }
}
