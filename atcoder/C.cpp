#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long mymax(long a,long b,long c,long d=0,long e=0,long f=0){
    return max(max(a,b),max(max(c,d),max(e,f)));
}

void findout(long i,vector<long>&a,vector<long>&b,vector<long>&c,vector<long>&outa,vector<long>&outb,vector<long>&outc){
    long temp = mymax(a[i-1]+b[i],a[i-1]+c[i],
                      b[i-1]+a[i],b[i-1]+c[i],
                      c[i-1]+a[i],c[i-1]+b[i]);
    return;
}

int main(){
    long N;
    cin >> N;
    vector<long>a(N);
    vector<long>b(N);
    vector<long>c(N);
    for(long i = 0;i<N; i++){cin>>a[i]>>b[i]>>c[i];}
    vector <long> outa(N);
    vector <long> outb(N);
    vector <long> outc(N);
    outa[0]= a[0];
    outb[0]= b[0];
    outc[0]= c[0];
    outa[1]= max(a[1]+b[0],a[1]+c[0]);
    outb[1]= max(b[1]+a[0],b[1]+c[0]);
    outc[1]= max(c[1]+a[0],c[1]+b[0]);
    for (long i =2; i < N; i++) {
        findout(i, a, b, c, outa,outb,outc);
    }
   // cout<<out[N-1]<<endl;
    
    
}
