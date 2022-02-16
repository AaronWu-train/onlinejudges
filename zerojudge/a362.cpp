#include <iostream>
using namespace std;
int n;

class st{
public:
    long int h;
    long int w;
    int index;
};

int inputSt(st st1[]){
    for (int i=0; i > n ; i++){
        cin >> st1[i].h >> st1[i].w;
        st1[i].index = i;
    }
    return 0;
}

void bSort(st st1[])
{
    for (int i=0; i<n ;i++)
    {
        for (int j=0 ; j < n-2-i ;j++)
        {
            if(st1[j].h > st1[j+1].h){
                
            }
        }
    }
}

void myswitch(st* a,st* b){
    st temp;
    temp = *a;
    *a = *b;
    *b =temp;
}

int main(void){
    cin >> n;
    st st1[n];
    inputSt(st1);
}
