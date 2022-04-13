#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#define ll long long int
#define debug(x) cerr<<"DEBUG: " << #x << " ="<<(x)<<endl;
#define _ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
template <typename T>
void quick_sort(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    if (end-begin<=1) return;
    auto l = begin;
    auto r = end-1;
    srand(time(NULL));
    unsigned long long i= end-begin-1; //= rand()%(end-begin);
    swap(*r , *(l+i));
    T pivot = *r;
    r--;
    while (l < r)
    {
       while (*l < pivot && l < r)l++;
       while (*r > pivot && l < r)r--;
       swap(*l,*r);
    }
    swap(*l,pivot);
    quick_sort<T>(begin,l);
    quick_sort<T>(l+2,end);
    return;
}

int main(){_
    vector<int>v= {5,32,532,45623,523,122,121};
    quick_sort<int>(v.begin(), v.end());
    for (auto i : v) {
        cout << i << " ";
    }
    
    
    
    return 0;
}


