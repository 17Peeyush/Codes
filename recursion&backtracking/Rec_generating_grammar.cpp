#include <iostream>
#include <string>
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
int main() {
    int r,c;
    cin>>r;
// 	cin>>r>>c;
	generate(r);
	return 0;
}
