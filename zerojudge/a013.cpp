#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,int> mp;

int main(){
	mp['I'] = 1; 
	mp['V'] = 5;
	mp['X'] = 10;
	mp['L'] = 50;
	mp['C'] = 100;
	mp['D'] = 500;
	mp['M'] = 1000;

	string a,b;
    cin >> a ;
    do {
        cin >>b;
        int suma=0, sumb=0;
        
        for (int i= 0; i<a.size();i++)
        {
            if (mp[a[i]] < mp[a[i+1]]) suma-= mp[a[i]];
            else{suma += mp[a[i]];}
        }
        for (int i= 0; i<b.size();i++)
        {
            if (mp[b[i]] < mp[b[i+1]]) sumb-= mp[b[i]];
            else{sumb += mp[b[i]];}
        }
        
        int sumc = suma - sumb;
        int sumd = sumc;
        sumc = (sumc<0)?(-sumc):(sumc);
        //cout << "sumc:" << sumc <<"\n";   //
        string c = "";
        string romenum [] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int numar [] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        for (int i= 0; i<13;i++)
        {
            int num = numar[i];
            //cout <<"num:"<<num <<"\n"<< "romenum[i]:"<< romenum[i]<<endl;  //
            while (sumc>=num)
            {
                c = c+romenum[i];
                sumc -= num ;
                //cout <<"sumc: "<<sumc<< "\nc: " << c<<endl; //
            }
        }
        
        if (sumd == 0) c = "ZERO";
        cout << c <<endl;
        cin >> a;
    } while (a != "#");
	
	return 0;
}
    
