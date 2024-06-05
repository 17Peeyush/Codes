//Print N-bit binary numbers having more 1’s than 0’s for any prefix
#include <iostream>
using namespace std;
void nbin(int n,int z,int o,int m,string out)
{
    if(z>m) return;
    if(z<=o && !(z==0&&o==0))
        cout<<out<<" ";
    if(n==0) return;
    nbin(n-1,z+1,o,m,out+"0");
    nbin(n-1,z,o+1,m,out+"1");
}

int main() {
	int n;
	cin>>n;
    nbin(n,0,0,n/2,"");
	return 0;
}
