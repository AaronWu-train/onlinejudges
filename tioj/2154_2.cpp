#include<iostream>
#include <string>
using namespace std;

int main()
{
    long n;
    scanf("%ld",&n);
    string a[n];
    long min = 200001 ;
    long minstr = 0;
    for(long i =0;i<n;i++)
    {
        cin >> a[i];
        if (a[i].size()<min)
        {
            min = a[i].size();
            minstr = i;
        }
    }
    string cp;
    long tf;
    string b;
    for (long startword = 0 ; startword < min ;startword++)
    {
        cp = a[minstr].substr(startword,1);
        for(long i =0;i<n;i++)
        {
            if (i!=minstr)
            {
                tf = a[i].find(cp);
                if (tf == string::npos)
                {
                    cp ="";
                    break;
                }
                
            }
        }
        if (cp!="")
        {
            b+=cp;
        }
    }
    long bsize = b.size();
    for(int i=0; i<bsize; i++){
        
    }
}
