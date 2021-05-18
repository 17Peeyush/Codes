//Generating balanced paranthesis
#include <iostream>
using namespace std;
void balance(int o,int c,string out)
{
    if(o==0&&c==0)
    {
        cout<<out<<" "<<endl;
        return;
    }
    else if(o==c)
    {
        out+="(";
        o--;
        balance(o,c,out);
        return;
    }
    else if(o==0)
    {
        while(c!=0)
        {
            out+=")";c--;
        }   
        balance(o,c,out);
        return;
    }
    else if(o<c)
    {
        balance(o-1,c,out+"(");
        balance(o,c-1,out+")");
        return;
    }
}

int main() {
	int n;
	cin>>n;
	balance(n,n,"");
	return 0;
}
