#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define INT_MAX_ 99999
using namespace std;
void show(vector<vector<int>>d, int n)
{
    cout<<"   ";
    for(int i=0;i<n;i++)
        cout<<i<<"\t";
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<n;j++)
        {
            cout<<d[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<endl;
}


vector<vector<int>> FlyodWarshal(vector<vector<int>>&ad, int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ad[i][j]=ad[i][j]>(ad[i][k]+ad[k][j])?(ad[i][k]+ad[k][j]):ad[i][j];
            }
        }
    }
    return ad;
}
int main()
{
    int n,t;
    cout<<"Enter the number of nodes in the graph: ";
    cin>>n;
    cout<<"Enter the distance in the form of adjacency matrix and enter -1 if no path exist : "<<endl;
    vector<vector<int>> ad(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>t;
            if(t==-1)
            {
                ad[i][j]=INT_MAX_;
            }
            else
            {
                ad[i][j]=t;
            }
        }
    }
    show(ad,n);
    vector<vector<int>> distance=FlyodWarshal(ad,n);
    show(distance,n);
    return 0;
}
