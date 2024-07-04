#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int d1,d2;
int dp2(int);
int a[5005];
int dp1(int n){
    if (n-d1==0){
        return 1;
    }else if (n-d1<0){
        return 2;
    }else if (a[n]!=0){
        return a[n];
    }else{
        if((dp1(n-d1)==1)||(dp2(n-d1)==1)){
            a[n]=1;
            return 1;
        }else{
            a[n]=2;
            return 2;
        }
    }
}
int dp2(int n){
    if (n-d2<0){
        return 2;
    }else if (n-d2==0){
        return 1;
    }else if (a[n]!=0){
        return a[n];
    }
    else{
        if((dp1(n-d2)==1)||(dp2(n-d2)==1)){
            a[n]=1;
            return 1;
        }else{
            a[n]=2;
            return 2;
        }
    }
}
int main() {_
    int range;
    cin>>d1>>d2>>range;
    int fff = (dp1(range)==1||dp2(range)==1);
    if (fff==1) {
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;

    }
    return 0;
}

