//cth element in a grammar
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string complement(string s)
{
    string s2="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
            s2+='1';
        else s2+='0';
    }
    return s2;
}

string generate(int r)
{
    if(r==1)
    {
        cout<<"0"<<endl;
         return "0";
    }
       
    else
    {
        string grammar=generate(r-1);
        grammar+=complement(grammar);
        cout<<grammar<<endl;
        return grammar;
    }
}
int cthelement(int r,int c)
{
    if(r==1||c==1)
        return 0;
    int mid=pow(2,r-1)/2;
    if(c<=mid)
        return cthelement(r-1,c);
    else
        return !cthelement(r-1,c-mid);
}
int main() {
    int r,c;
	cin>>r>>c;
	generate(r);
	cout<<endl;
	cout<<c<<"th element in grammar "<<cthelement(r,c);
	return 0;
}
