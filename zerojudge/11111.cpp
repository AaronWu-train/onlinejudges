#include <iostream>
using namespace std;
const float PI = 3.1415926 ;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long n;
    double sum = 0 ;
    cin >> n;
    long num[n][3];
    long index = 0;
    for(long i =0 ; i <n ; i++)
    {
        bool tf = 1;
        long k[2] ;
        cin >> k[0] >> k[1];
        for(long j=0 ; j<index ;j++)
        {
            if(k[0]==num[j][0] && k[1]==num[j][1])
            {
                num[j][2]+=1;
                tf = 0;
                break;
            }
        }
        if (tf)
        {
            num[index][0]=k[0];
            num[index][1]=k[1];
            num[index][2]=1;
            index++;
        }
    }
    for(long i=0; i<index; i++)
    {
        for(long j=i+1; j<index ;j++)
        {
            if(num[j][1]==0 && num[i][1]==0)
            {
                long x = num[j][0]-num[i][0];
                sum = sum + x*x*num[j][2]*num[i][2];
            }
            else
            {
                long x = num[j][0]-num[i][0];
                long y = num[j][1]-num[i][1];
                sum = sum + ((x)*(x) + (y)*(y))*num[j][2]*num[i][2];
            }
        }
    }
    sum = sum * 2 *PI;
    cout << sum << "\n";
    return 0;
}
