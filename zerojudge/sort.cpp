#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector <string> b(40);
    for (int i=0; i<30; i++) {
        int temp;
        cin >>temp;
        cin >>b[temp];
    }
    for (int i=0; i<40; i++) {
        if (b[i]!="") {
            cout<<i<<" "<<b[i]<<endl;
        }
    }
}
