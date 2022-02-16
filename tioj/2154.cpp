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
    long tf ;
    string cp;
    string outstr = "";
    string outstr2 = "";
    string outstr3 = "";
    for (long startword = 0 ; startword < min ;startword++)
    {
        for(long j = 1; j<=(min-startword) ; j++)
        {
            cp = a[minstr].substr(startword,j);
            outstr = cp;
            for(long i =0;i<n;i++)
            {
                if (i!=minstr)
                {
                    tf = a[i].find(cp);
                    if (tf == string::npos)
                    {
                        outstr = "";
                        break;
                    }
                    else
                    {
                        outstr = cp;
                    }
                }
            }
            if(outstr != "")
                outstr2 = outstr;
        }
        
        if(outstr2 != "" && outstr2.size()>outstr3.size()){
            outstr3 = outstr2;
        }
    }
    if (outstr3=="")
    {
        cout << 7122;
        
    }
    else
    {
        cout <<outstr3;
    }
}
