//permutation with space
#include <iostream>
#include <string> 
using namespace std;

void perSpace(string input,string output)
{
    if(output.size()==0)
    {
        perSpace(input.substr(1),string(1,input[0]));
        return;
    }
    if(input.size()==0)
    {
        cout<<output<<endl;
        return;
    }
    perSpace(input.substr(1),output+" "+input[0]);
    perSpace(input.substr(1),output+input[0]);
    return;
}
int main() {
	string s="ABC";
	//cout<<s<<" "<<"now"<<s.substr(s.length())<<"er";
	perSpace(s,"");
	return 0;
}
