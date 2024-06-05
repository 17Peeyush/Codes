#include <iostream>
#include <string>
using namespace std;

void subset(string in,string out)
{
    if(in.length()==0)
    {
        cout<<"\""<<out<<"\""<<",";
        return;
    }
    string op1=out;
    string op2=out;
    op2.push_back(in[0]);
    in.erase(in.begin());
    subset(in,op1);
    subset(in,op2);
}
int main() {
	string input="abc";
	string output="";
	subset(input,output);
	return 0;
}
