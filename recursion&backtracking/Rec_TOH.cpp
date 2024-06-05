#include <iostream>
using namespace std;

void TOI(char s,char d,char h,int n)
{
    if(n==1)
    {
        cout<<s<<"->"<<d<<endl;
        return;
    }
    TOI(s,h,d,n-1);
    cout<<s<<"->"<<d<<endl;
    TOI(h,d,s,n-1);
    return;
}
int main() {
	int n;
	cin>>n;
	TOI('S','D','H',n);
	return 0;
}
