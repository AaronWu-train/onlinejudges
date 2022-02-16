#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define _ ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
int d1,d2;
vector<int> aaa;
int dp2(int);
int dp1(int n){
    if (n-d1<1){
        return 0;
    }else if (n-d1==1){
        aaa[n]=1;
        return 1;
    }else if (aaa[n]==1||aaa[n]==0){
        return aaa[n];
    }
    else{
        aaa[n]=dp1(n-d1)||dp2(n-d1);
        return dp1(n-d1)||dp2(n-d1);
    }
}
int dp2(int n){
    if (n-d2<1){
        return 0;
    }else if (n-d2==1){
        return 1;
    }else if (aaa[n]==1||aaa[n]==0){
        return aaa[n];
    }
    else{
        aaa[n]=dp1(n-d2)||dp2(n-d2);
        return dp1(n-d2)||dp2(n-d2);
    }
}
int main() {_
    aaa.resize(5005, 7122);
    int range;
    cin>>d1>>d2>>range;
    int a = dp1(range)||dp2(range);
    if (a) {
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;

    }
    return 0;
}

