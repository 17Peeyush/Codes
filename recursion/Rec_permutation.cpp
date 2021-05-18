//permutation recursion
#include <iostream>
#include <string.h>

using namespace std;

void permutation(string input,string output)
{
    if(input.size()==0)
    {
        cout<<output<<" ";
        return;
    }
    for(int i=0;i<input.length();i++)
    {
        string op=output+input[i];
        string newin=input.substr(0,i)+input.substr(i+1,input.length());
        permutation(newin,op);
    }
}
int main() {
    string st="ABCD";
    permutation(st,"");
	return 0;
}
