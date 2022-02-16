#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int destination(int a,int b){
    int c = a - b;
    return abs(c);
}

int findmincost(int i,vector<int> &high,vector<int>&min_hi){
    int sum1 = min_hi[i-1]+destination(high[i], high[i-1]);
    int sum2 = min_hi[i-2]+destination(high[i], high[i-2]);
    return min(sum1, sum2);

}

int main() {
    int N;
    cin >> N;
    vector<int> high(N);
    for(int i =0;i<N;i++){cin>>high.at(i);}
    vector<int>min_hi(N);
    min_hi[0]=0;
    min_hi[1]=destination(high[1], high[0]);
    for (int i=2;i<N;i++){
        min_hi[i]= findmincost(i, high, min_hi);
    }
    cout << min_hi[N-1]<<endl;
    return 0;
}
