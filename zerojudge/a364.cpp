#include <iostream>
#include <vector>
using namespace std;
vector<int> nC2;
vector<int> nC3;

int fnC2(int n){
    if (n<2){
        return 0;
    }else if(n == 2){
        return 1;
    }else{
        return nC2[n-1] + n-1;
    }
}

int fnC3(int n){
    if (n<3){return 0;}
    else if (n==3){return 1;}
    else {return nC3[n-1]*n/(n-3); }
}

int main(){
    for (int i=0;i<=32;i++){nC2.push_back(fnC2(i));}
    for (int i=0;i<=15;i++){nC3.push_back(fnC3(i));}
    int times ;
    cin >> times;
    while (times --){
        int a=0,b=0,c=0,in=0;
        cin >> in;
        for (int i=15 ; i>0;i--){
            if(nC3[i]<=in){
                a = i;
                in -= nC3[i];
                break;
            }
        }
        
        for (int i=32 ; i>0;i--){
            if(nC2[i]<=in){
                b = i;
                in -= nC2[i];
                break;
            }
        }
        
        c = in;
        cout <<a<<b<<c<<endl;
    }
    return 0;
}
